#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
const char* equipmentInfo = 
    "（2）底盘\n"
    "b)型号：SCOUT MINI\n"
    "c)轴距：451mm\n"
    "d)轮距：490mm\n"
    "e)最小离地间隙：115mm\n"
    "f)最小转弯半径：0m\n"
    "g)驱动形式：四轮四驱\n"
    "h)最大行程：10KM\n"
    "i)轮胎（4个）\n"
    "i.型号：公路轮、麦克纳姆轮\n"
    "ii.尺寸：175mm\n"
    "（3）AGX套件（1个）\n"
    "a)型号：AGX Xavier\n"
    "b)AI：32 TOPS\n"
    "c)CUDA核心：512\n"
    "d)Tensor CORE：64\n"
    "e)显存：32G\n"
    "f)存储：32G\n"
    "（4）双目摄像头（1个）\n"
    "a)型号：RealSense D435i\n"
    "b)摄像头：D430\n"
    "c)RGB帧分辨率：1920*1080\n"
    "d)RGB帧率：30\n"
    "e)FOV：87*58\n"
    "f)深度帧率：90\n"
    "（5）多线激光雷达（1个）\n"
    "a)型号：RS-Helios-16p\n"
    "b)通道数：16\n"
    "c)测试范围：100m\n"
    "d)功耗：8W\n"
    "（6）9轴陀螺仪（1个）\n"
    "a)型号：CH110\n"
    "b)厂家：NXP\n"
    "（7）液晶显示屏（1个）\n"
    "a)尺寸：11.6\n"
    "b)型号：super\n"
    "（8）电池模块（1个）\n"
    "a)参数：24V/15Ah\n"
    "b)对外供电：24V\n"
    "c)充电时长：2H";
struct Student {
    int id;
    string name;
    string car_id;
};
struct SmartCar {
    string id;
    string chassis_id;
    string other_info;
};

class StudentManager {
public:
	vector<Student> students;
	vector<SmartCar> smartcars;
	vector<string> lines;
    vector<fstream> files;
	void addSmartCar(string id,string chassis_id,string other_info){
		SmartCar smartcar;
		smartcar.id=id;
		smartcar.chassis_id=chassis_id;
		smartcar.other_info=other_info;
		smartcars.push_back(smartcar);
        int num=lines.size()+1;
        string filname ="car"+to_string(num)+".txt";
        ofstream file(filname);
        if (!file.is_open()) {
            cout << "无法打开文件 "  << endl;
            return;
        }
            file << "小车id"<<smartcar.id<<endl
			<<"小车底盘id"<<smartcar.chassis_id <<endl
			 <<"小车其他信息"<<endl<<smartcar.other_info<<endl;
        lines.push_back(filname);
        file.close();
        cout << "小车信息已保存到文件 "<< filname<<endl;
		cout << "小车信息已添加: " << smartcar.id << endl;
	} 
    void addStudent(int id, string name, string car_id,size_t i) {
        Student student;
        student.id = id;
        student.name = name;
        student.car_id = car_id;
        students.push_back(student);
        cout << "学生信息已添加: " << student.name << endl;
    }

    void saveToFile(const string& filename) {
        ofstream file(filename.c_str()); // 将 std::string 转换为 const char*
        if (!file.is_open()) {
            cout << "无法打开文件 " << filename << endl;
            return;
        }
        for (size_t i = 0; i < students.size(); ++i) {
            file << "领用学生学号："<<students[i].id <<"   "
			<<"领用学生姓名："<<students[i].name << "   "
			 <<"领用小车编号："<<students[i].car_id<<endl;
        }
        file.close();
        cout << "学生信息已保存到文件 " << filename << endl;
    }
	void load(const string& filename){
   		int currentIndex =0;
		while (true) {
        cout<<"打开文件"<<lines[currentIndex]<<endl;
        ifstream car(lines[currentIndex]);
        string temp;
        while (getline(car, temp)) {
	        cout<<temp<<endl;
	    }
        if(currentIndex >= students.size())
            cout<<"未分配学生"<<endl;
        else
            cout << "ID: " << students[currentIndex].id << ", 姓名: " << students[currentIndex].name << ", 车辆编号: " << students[currentIndex].car_id << endl;
        char command;
        cout << "输入 'n' 下一个, 'p' 上一个, 'q' 退出 ";
        cin >> command;
        if (command == 'n') {
            if (currentIndex < lines.size()-1) {
                currentIndex++;
            } else {
                cout << "已经最后一个了" << endl;
            }
        } else if (command == 'p') {
            if (currentIndex > 0) {
                currentIndex--;
            } else {
                cout << "已经第一个了" << endl;
            }
        } else if (command == 'q') {
            break;
        } else {
            cout << "无效指令" << endl;
        }
    }
	}
    void displayStudents() {
        cout << "当前学生信息:" << endl;
        for (size_t i = 0; i < students.size(); ++i) {
            cout << "ID: " << students[i].id << ", 姓名: " << students[i].name << ", 车辆编号: " << students[i].car_id << endl;
        }
    }
};

int main() {
    StudentManager manager;
    string filename = "students.txt";

    int choice;
    do {
        cout << "1. 添加小车入库" << endl;
        cout << "2. 添加学生信息并分配小车" << endl;
        cout << "3. 显示所有学生信息" << endl;
        cout << "4. 保存到文件" << endl;
        cout << "5. 显示单条信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        	case 1:
            {
                string id;
                string chassis_id;
                string other_info;
                cout << "输入小车ID: ";
                cin >> id;
                cout << "输入小车底盘ID: ";
                cin >> chassis_id;
                cout << "请检查其他信息是否正确 "<<endl;
                cout << equipmentInfo<<endl;
                cout <<"信息是否正确[Y/N]:"<<endl;
				char c;
				cin >>c;
				if(c=='Y'){
					cout << "OK"<<endl; 
					other_info=equipmentInfo;
					manager.addSmartCar(id, chassis_id, other_info);
				}
                else{
                	cout <<"不予入库"<<endl;
				}
                break;
            }
        	
            case 2:
            {
                int id;
                string name;
                string car_id;
                cout << "输入学生ID: ";
                cin >> id;
                cout << "输入学生姓名: ";
                cin >> name;
                bool flag = false;
                cout << "输入分配的车的编号: ";
                cin >> car_id;
      			for (size_t i = 0; i < manager.smartcars.size(); ++i) {
           			if(manager.smartcars[i].id==car_id){
           				flag = true;
           				manager.addStudent(id, name, car_id, i);
           				break;
					}
        		}
        		if(!flag)
        		cout << "没有该车"<<endl; 
                break;
            }
            case 3:
            	manager.displayStudents();
                break;
            case 4:
            	manager.saveToFile(filename);
                break;
            case 5: 
            	manager.load(filename);
                break;
            case 0:
                cout << "退出系统" << endl;
                break;
            default:
                cout << "无效选择，请重新输入" << endl;
        }
    } while (choice != 0);

    return 0;
}
