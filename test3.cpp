#include <iostream>
#include <fstream>
#include <string>
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
// 观察者接口
class Observer {
public:
    virtual ~Observer() {}
    virtual void update(const string& obstacleStatus) = 0;
};

// 主题接口
class Subject {
private:
    vector<Observer*> observers;

public:
    virtual ~Subject() {}
    void attach(Observer* observer) {
        observers.push_back(observer);
    }
    // void detach(Observer* observer) {
    //     pass
    // }
    void notify(const string& obstacleStatus) {
        for (Observer* observer : observers) {
            observer->update(obstacleStatus);
        }
    }
};
// 轮胎类
class Tire {
private:
    string type; // 类型
    int size; // 尺寸

public:
    void setType(const string& newType) {
        type = newType;
    }

    void setSize(int newSize) {
        size = newSize;
    }

    void print() {
        cout << "轮胎类型: " << type << ", 尺寸: " << size << "mm" << endl;
    }

    void save(ofstream& file) {
        file << "轮胎类型: " << type << ", 尺寸: " << size << "mm" << endl;
    }
};

// 底盘类
class Chassis : public Observer {
private:
    string material; // 材质
    string model; // 型号
    int width; // 宽度
    int length; // 长度
    int groundClearance; // 最小离地间隙
    double turnRadius; // 最小转弯半径
    string driveType; // 驱动形式
    int maxRange; // 最大行程
    vector<Tire> tires; // 轮胎

public:
    void setMaterial(const string& newMaterial) {
        material = newMaterial;
    }

    void setModel(const string& newModel) {
        model = newModel;
    }

    void setWidth(int newWidth) {
        width = newWidth;
    }

    void setLength(int newLength) {
        length = newLength;
    }

    void setGroundClearance(int newGroundClearance) {
        groundClearance = newGroundClearance;
    }

    void setTurnRadius(double newTurnRadius) {
        turnRadius = newTurnRadius;
    }

    void setDriveType(const string& newDriveType) {
        driveType = newDriveType;
    }

    void setMaxRange(int newMaxRange) {
        maxRange = newMaxRange;
    }

    void print() {
        cout << "底盘材质: " << material
                  << ", 型号: " << model
                  << ", 宽度: " << width << "mm"
                  << ", 长度: " << length << "mm"
                  << ", 最小离地间隙: " << groundClearance << "mm"
                  << ", 最小转弯半径: " << turnRadius << "m"
                  << ", 驱动形式: " << driveType
                  << ", 最大行程: " << maxRange << "KM" << endl;
    }

    void save(ofstream& file) {
        file << "底盘材质: " << material
             << ", 型号: " << model
             << ", 宽度: " << width << "mm"
             << ", 长度: " << length << "mm"
             << ", 最小离地间隙: " << groundClearance << "mm"
             << ", 最小转弯半径: " << turnRadius << "m"
             << ", 驱动形式: " << driveType
             << ", 最大行程: " << maxRange << "KM" << endl;
    }
    
    void update(const string& obstacleStatus) override {
        if (obstacleStatus == "前方") {
            cout << "执行后退操作。" << endl;
        } else if (obstacleStatus == "右前方") {
            cout << "执行左转操作。" << endl;
        } else if (obstacleStatus == "左前方") {
            cout << "执行右转操作。" << endl;
        }
    }
};

// AGX套件类
class AGXKit {
private:
    string model; // 型号
    int ai; // AI性能
    int cudaCores; // CUDA核心数
    int tensorCores; // Tensor核心数
    int memory; // 显存
    int storage; // 存储

public:
    void setModel(const string& newModel) {
        model = newModel;
    }

    void setAI(int newAI) {
        ai = newAI;
    }

    void setCUDACores(int newCUDACores) {
        cudaCores = newCUDACores;
    }

    void setTensorCores(int newTensorCores) {
        tensorCores = newTensorCores;
    }

    void setMemory(int newMemory) {
        memory = newMemory;
    }

    void setStorage(int newStorage) {
        storage = newStorage;
    }

    void print() {
        cout << "AGX套件型号: " << model
                  << ", AI性能: " << ai << " TOPS"
                  << ", CUDA核心数: " << cudaCores
                  << ", Tensor核心数: " << tensorCores
                  << ", 显存: " << memory << "G"
                  << ", 存储: " << storage << "G" << endl;
    }

    void save(ofstream& file) {
        file << "AGX套件型号: " << model
             << ", AI性能: " << ai << " TOPS"
             << ", CUDA核心数: " << cudaCores
             << ", Tensor核心数: " << tensorCores
             << ", 显存: " << memory << "G"
             << ", 存储: " << storage << "G" << endl;
    }
};

// 双目摄像头类
class DualCamera {
private:
    string model; // 型号
    string camera; // 摄像头型号
    string resolution; // 分辨率
    int frameRate; // 帧率
    string fov; // 视场角
    int depthRate; // 深度帧率

public:
    void setModel(const string& newModel) {
        model = newModel;
    }

    void setCamera(const string& newCamera) {
        camera = newCamera;
    }

    void setResolution(const string& newResolution) {
        resolution = newResolution;
    }

    void setFrameRate(int newFrameRate) {
        frameRate = newFrameRate;
    }

    void setFOV(const string& newFOV) {
        fov = newFOV;
    }

    void setDepthRate(int newDepthRate) {
        depthRate = newDepthRate;
    }

    void print() {
        cout << "双目摄像头型号: " << model
                  << ", 摄像头型号: " << camera
                  << ", 分辨率: " << resolution
                  << ", 帧率: " << frameRate
                  << ", 视场角: " << fov
                  << ", 深度帧率: " << depthRate << endl;
    }

    void save(ofstream& file) {
        file << "双目摄像头型号: " << model
             << ", 摄像头型号: " << camera
             << ", 分辨率: " << resolution
             << ", 帧率: " << frameRate
             << ", 视场角: " << fov
             << ", 深度帧率: " << depthRate << endl;
    }
};

// 多线激光雷达类
class MultiLineLidar : public Subject {
private:
    string model; // 型号
    int channels; // 通道数
    int range; // 测试范围
    int power; // 功耗
    string obstacleStatus;
public:
    void setModel(const string& newModel) {
        model = newModel;
    }

    void setChannels(int newChannels) {
        channels = newChannels;
    }

    void setRange(int newRange) {
        range = newRange;
    }

    void setPower(int newPower) {
        power = newPower;
    }

    void print() {
        cout << "多线激光雷达型号: " << model
                  << ", 通道数: " << channels
                  << ", 测试范围: " << range << "m"
                  << ", 功耗: " << power << "W" << endl;
    }

    void save(ofstream& file) {
        file << "多线激光雷达型号: " << model
             << ", 通道数: " << channels
             << ", 测试范围: " << range << "m"
             << ", 功耗: " << power << "W" << endl;
    }
    void setObstacleStatus(const string& status) {
        obstacleStatus = status;
        notify(status);
    }
};

// 9轴陀螺仪类
class NineAxisGyroscope {
private:
    string model; // 型号
    string manufacturer; // 厂家

public:
    void setModel(const string& newModel) {
        model = newModel;
    }

    void setManufacturer(const string& newManufacturer) {
        manufacturer = newManufacturer;
    }

    void print() {
        cout << "9轴陀螺仪型号: " << model
                  << ", 厂家: " << manufacturer << endl;
    }

    void save(ofstream& file) {
        file << "9轴陀螺仪型号: " << model
             << ", 厂家: " << manufacturer << endl;
    }
};

// 液晶显示屏类
class LCDScreen {
    private:
    double size; // 尺寸
    string model; // 型号

    public:
    void setSize(double newSize) {
    size = newSize;
    }
    void setModel(const string& newModel) {
    model = newModel;
    }

    void print() {
        cout << "液晶显示屏尺寸: " << size << "英寸"
                << ", 型号: " << model << endl;
    }

    void save(ofstream& file) {
        file << "液晶显示屏尺寸: " << size << "英寸"
            << ", 型号: " << model << endl;
    }
};
// 电池模块类
class BatteryModule {
    private:
    string parameters; // 参数
    int outputVoltage; // 对外供电
    int chargeTime; // 充电时长

    public:
    void setParameters(const string& newParameters) {
    parameters = newParameters;
    }

    void setOutputVoltage(int newOutputVoltage) {
        outputVoltage = newOutputVoltage;
    }

    void setChargeTime(int newChargeTime) {
        chargeTime = newChargeTime;
    }

    void print() {
        cout << "电池模块参数: " << parameters
                << ", 对外供电: " << outputVoltage << "V"
                << ", 充电时长: " << chargeTime << "小时" << endl;
    }

    void save(ofstream& file) {
        file << "电池模块参数: " << parameters
            << ", 对外供电: " << outputVoltage << "V"
            << ", 充电时长: " << chargeTime << "小时" << endl;
    }
};
class StudentInfo {
public:
    string name;
    string studentid;
    string smartcarid;
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(string newstudentid) {
        studentid = studentid;
    }

    void setSmartcarid(const string& newsmartcarid) {
        smartcarid = newsmartcarid;
    }

    void print() {
        cout << "Student Name: " << name << endl;
    }

    void save(ofstream& file) {
        file << "Student Name: " << name  << endl;
    }

};
class SmartCar {
public:
    string id;
    string other_info;
    Chassis chassis;
    Tire tire;
    AGXKit agxKit;
    DualCamera dualCamera;
    NineAxisGyroscope nineAxisGyroscope;
    MultiLineLidar multiLineLidar;
    LCDScreen lcdScreen;
    BatteryModule batteryModule;
    string studid;
    void set(string newID,string newinfo) {
        id = newID;
        other_info = newinfo;
        chassis.setWidth(451);
        chassis.setLength(490);
        chassis.setMaterial("dp12345678");
        chassis.setModel("SCOUT MINI");
        chassis.setWidth(451);
        chassis.setLength(490);
        chassis.setGroundClearance(115);
        chassis.setTurnRadius(0);
        chassis.setDriveType("四轮四驱");
        chassis.setMaxRange(10000);

        tire.setType("公路轮、麦克纳母轮");
        tire.setSize(175);

        agxKit.setModel("AGX Xavier");
        agxKit.setAI(32);
        agxKit.setCUDACores(512);
        agxKit.setTensorCores(64);
        agxKit.setMemory(32);
        agxKit.setStorage(32);

        dualCamera.setModel("RealSense D435i");
        dualCamera.setCamera("D430");
        dualCamera.setResolution("1920*1080");
        dualCamera.setFrameRate(30);
        dualCamera.setFOV("87*58");
        dualCamera.setDepthRate(90);

        multiLineLidar.setModel("RS-Helios-16p");
        multiLineLidar.setChannels(16);
        multiLineLidar.setRange(100);
        multiLineLidar.setPower(8);

        nineAxisGyroscope.setModel("CH110");
        nineAxisGyroscope.setManufacturer("NXP");

        lcdScreen.setSize(11.6);
        lcdScreen.setModel("super");

        batteryModule.setParameters("24V/15Ah");
        batteryModule.setOutputVoltage(24);
        batteryModule.setChargeTime(2);

    }
    void print() {
        cout << "Smart Car ID: " << id << endl;
        //cout <<other_info<<endl;
        chassis.print();
        tire.print();
        agxKit.print();
        dualCamera.print();
        nineAxisGyroscope.print();
        multiLineLidar.print();
        lcdScreen.print();
        batteryModule.print();
    }

    void save(const string& filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "智能小车信息：" <<endl;
            file << "编号：" << id <<endl;
            chassis.save(file);
            agxKit.save(file);
            dualCamera.save(file);
            multiLineLidar.save(file);
            nineAxisGyroscope.save(file);
            lcdScreen.save(file);
            batteryModule.save(file);
            file.close();
        } else {
            cerr << "无法打开文件进行写入。" << endl;
        }
    }
};
class Student {
public:
    string name;
    string studentid;
    string smartcarid;
    void setName(const string& newName) {
        name = newName;
    }

    void setAge(string newstudentid) {
        studentid = newstudentid;
    }

    void setSmartcarid(const string& newsmartcarid) {
        smartcarid = newsmartcarid;
    }

    void print() {
        cout << "学生姓名: " <<name<<"   "<<"学生学号："<<studentid<<"   "<<"分配的小车："<<smartcarid<<endl;
    }

    void save(const string& filename) {
        ofstream file(filename,ios ::app);
        file << "学生姓名: " <<name<<"   "<<"学生学号："<<studentid<<"   "<<"分配的小车："<<smartcarid<<endl;
    }

};
class StudentManager {
public:
	vector<Student> students;
	vector<SmartCar> smartcars;
	vector<string> lines;

	void addSmartCar(){
		string id;
        string other_info;
        cout << "输入小车ID: ";
        cin >> id;
        cout << "请检查其他信息是否正确 "<<endl;
        cout << equipmentInfo<<endl;
        cout <<"信息是否正确[Y/N]:"<<endl;
        char c;
        cin >>c;
        if(c=='Y'){
            cout << "OK"<<endl; 
            other_info=equipmentInfo;
            SmartCar smartcar;
            smartcar.set(id,other_info);
            smartcars.push_back(smartcar);
            // int num=lines.size()+1;
            // string filname ="car"+to_string(num)+".txt";
            // ofstream file(filname);
            // if (!file.is_open()) {
            //     cout << "无法打开文件 "  << endl;
            //     return;
            // }
            // file << "小车id"<<smartcar.id<<endl
            // <<"小车其他信息"<<endl<<smartcar.other_info<<endl;
            // lines.push_back(filname);
            // file.close();
            // cout << "小车信息已保存到文件 "<< filname<<endl;
            cout << "小车信息已添加: " << smartcar.id << endl;
        }
        else{
            cout <<"不予入库"<<endl;
        }
        
	} 
    void addStudent() {
        string id;
        string name;
        string car_id;
        cout << "输入学生ID: ";
        cin >> id;
        cout << "输入学生姓名: ";
        cin >> name;
        bool flag = false;
        cout << "输入分配的车的编号: ";
        cin >> car_id;
        for (size_t i = 0; i < smartcars.size(); ++i) {
            if(smartcars[i].id==car_id){
                flag = true;
                smartcars[i].studid=id;
                Student student;
                student.studentid = id;
                student.name = name;
                student.smartcarid = car_id;
                students.push_back(student);
                cout << "学生信息已添加: " << student.name << endl;
                break;
            }
        }
        if(!flag)
        cout << "没有该车"<<endl;
    }

    void saveToFile(const string& filename) {
        // ofstream file(filename.c_str()); // 将 string 转换为 const char*
        // if (!file.is_open()) {
        //     cout << "无法打开文件 " << filename << endl;
        //     return;
        // }
        // for (size_t i = 0; i < students.size(); ++i) {
        //     file << "领用学生学号："<<students[i].studentid <<"   "
		// 	<<"领用学生姓名："<<students[i].name << "   "
		// 	 <<"领用小车编号："<<students[i].smartcarid<<endl;
        // }
        // file.close();
        for (size_t i = 0; i < smartcars.size(); i++)
        {
            int num=lines.size()+1;
            string filname ="info"+to_string(num)+".txt";
            smartcars[i].save(filname);
            cout<<"id为"<<smartcars[i].id<<"的" << "小车信息已保存到文件 "<< filname<<endl;
            bool flag =false;
            for (size_t j = 0; j < students.size(); j++)
            {
                if(students[j].studentid==smartcars[i].studid){
                    flag=true;
                    students[j].save(filname);
                    cout << "相应学生信息已保存到文件 " <<filname << endl;
                }
                /* code */
            }
            if(!flag){
                ofstream file(filname,ios ::app);
                file << "还没有领取的学生"<<endl;
                cout << "该车还没有被领取"  << endl;
            }
            lines.push_back(filname);
            /* code */
        }
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
        char command;
        cout << "输入 'n' 下一个, 'p' 上一个, 'q' 退出 ";
        cin >> command;
        if (command == 'n') {
            if (currentIndex < lines.size()-1) {
                currentIndex++;
            } else {
                cout << "***已经最后一个了***" << endl;
            }
        } else if (command == 'p') {
            if (currentIndex > 0) {
                currentIndex--;
            } else {
                cout << "***已经第一个了***" << endl;
            }
        } else if (command == 'q') {
            break;
        } else {
            cout << "***无效指令***" << endl;
        }
    }
    }
    void displayAll() {
        cout << "当前学生信息:" << endl;
        if(students.size()>0){
            for (size_t i = 0; i < students.size(); ++i) {
                students[i].print();
                //cout << "ID: " << students[i].studentid << ", 姓名: " << students[i].name << ", 车辆编号: " << students[i].smartcarid << endl;
            }
        }else
            cout <<"还没有学生"<<endl;
        cout << endl;
        cout << "当前小车信息:" << endl;
        if(smartcars.size()>0){ 
            for (size_t i = 0; i < smartcars.size(); ++i) {
            smartcars[i].print();
            }
        }else
            cout <<"还没有小车"<<endl;
        
    }
};
int main() {
    StudentManager manager;
    string filename = "students.txt";
    MultiLineLidar lidar;
    Chassis chassis;
    lidar.attach(&chassis);
    // 模拟命令行输入障碍物状态
    string obstacleStatus;
    int choice;
    do {
        cout << "1. 添加小车入库" << endl;
        cout << "2. 添加学生信息并分配小车" << endl;
        cout << "3. 显示所有信息" << endl;
        cout << "4. 保存到文件" << endl;
        cout << "5. 显示单条信息" << endl;
        cout<<  "6.执行小车雷达与底盘的交互"<<endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        	case 1:
            {
                manager.addSmartCar();
                break;
            }
        	
            case 2:
            {
                manager.addStudent();
                break;
            }
            case 3:
            	manager.displayAll();
                break;
            case 4:
            	manager.saveToFile(filename);
                break;
            case 5: 
            	manager.load(filename);
                break;
            case 6:
                cout << "输入障碍物状态（1：前方，2：左前方，3：右前方）: ";
                cin >> obstacleStatus;
                if (obstacleStatus == "1") {
                    lidar.setObstacleStatus("前方");
                } else if (obstacleStatus == "2") {
                    lidar.setObstacleStatus("左前方");
                } else if (obstacleStatus == "3") {
                    lidar.setObstacleStatus("右前方");
                }
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