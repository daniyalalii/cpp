#include <iostream>
#include <string>
using namespace std;

// using constant to set the status
const int OPERATIONAL = 0;
const int MAINTENANCE = 1;
const int OUT_OF_SERVICE = 2;
const int DRIVER = 0;
const int CONDUCTOR = 1;
const int LOGISTICS_OPERATOR = 2;
const int FIRE = 0;
const int MEDICAL = 1;
const int POLICE = 2;
const int DISASTER = 3;
const int FIRE_INCIDENT = 0;
const int MEDICAL_INCIDENT = 1;
const int TRAFFIC_INCIDENT = 2;
const int ENVIRONMENTAL = 0;
const int TRAFFIC = 1;
const int STRUCTURAL = 2;

// to set coordinatess pairs
struct Coordinate
{
    double latitude;
    double longitude;

    Coordinate(double lat = 0.0, double lon = 0.0) : latitude(lat), longitude(lon) {}
};

// for boarding entry
struct BoardingEntry
{
    string timestamp;
    string passengerInfo;

    BoardingEntry() {}
    BoardingEntry(const string &time, const string &info) : timestamp(time), passengerInfo(info) {}
};

// base class
class Person
{
protected:
    string id;
    string name;
    int type;
    string certifications[10];
    int certCount;
    string authorizations[10];
    int authCount;

public:
    Person(const string &id, const string &name, int type)
        : id(id), name(name), type(type), certCount(0), authCount(0) {}

    // getters
    string getId() const { return id; }
    string getName() const { return name; }
    int getType() const { return type; }

    // Add certification
    void addCertification(const string &cert)
    {
        if (certCount < 10)
        {
            certifications[certCount++] = cert;
        }
    }

    // authorization
    void addAuthorization(const string &auth)
    {
        if (authCount < 10)
        {
            authorizations[authCount++] = auth;
        }
    }

    virtual void displayInfo() const
    {
        cout << "ID: " << id << ", Name: " << name << ", Type: ";
        switch (type)
        {
        case DRIVER:
            cout << "Driver";
            break;
        case CONDUCTOR:
            cout << "Conductor";
            break;
        case LOGISTICS_OPERATOR:
            cout << "Logistics Operator";
            break;
        }
        cout << endl;
    }
    virtual ~Person() {}
};

// driver class
class Driver : public Person
{
private:
    string licenseClass;
    bool heavyVehicleLicense;

public:
    Driver(const string &id, const string &name, const string &license, bool heavy = false)
        : Person(id, name, DRIVER), licenseClass(license), heavyVehicleLicense(heavy) {}

    void displayInfo() const
    {
        Person::displayInfo();
        cout << "License Class: " << licenseClass << ", Heavy Vehicle: " << (heavyVehicleLicense ? "Yes" : "No") << endl;
    }
};

// conductor class
class Conductor : public Person
{
private:
    string authorizedRoutes[20];
    int routeCount;

public:
    Conductor(const string &id, const string &name) : Person(id, name, CONDUCTOR), routeCount(0) {}

    // authorizational route
    void addAuthorizedRoute(const string &route)
    {
        if (routeCount < 20)
        {
            authorizedRoutes[routeCount++] = route;
        }
    }

    void displayInfo() const
    {
        Person::displayInfo();
        cout << "Authorized Routes: ";
        for (int i = 0; i < routeCount; i++)
        {
            cout << authorizedRoutes[i] << " ";
        }
        cout << endl;
    }
};

// logistic opertor class
class LogisticsOperator : public Person
{
private:
    string specializations[5];
    int specCount;

public:
    LogisticsOperator(const string &id, const string &name)
        : Person(id, name, LOGISTICS_OPERATOR), specCount(0) {}

    // specialization for logistic operator
    void addSpecialization(const string &spec)
    {
        if (specCount < 5)
        {
            specializations[specCount++] = spec;
        }
    }

    void displayInfo() const
    {
        Person::displayInfo();
        cout << "Specializations: ";
        for (int i = 0; i < specCount; i++)
        {
            cout << specializations[i] << " ";
        }
        cout << endl;
    }
};

//  base vehicle class
class Vehicle
{
protected:
    string vehicleId;
    int seating;
    string makeModel;
    Coordinate location;
    int status;
    string maintenanceSchedule;

public:
    Vehicle(const string &id, int seats, const string &make,
            double lat = 0.0, double lon = 0.0)
        : vehicleId(id), seating(seats), makeModel(make), location(lat, lon), status(OPERATIONAL) {}

    // getters
    string getId() const { return vehicleId; }
    int getStatus() const { return status; }
    // setters
    void setStatus(int newStatus) { status = newStatus; }
    void setLocation(double lat, double lon)
    {
        location.latitude = lat;
        location.longitude = lon;
    }

    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId << ", Seats: " << seating
             << ", Make/Model: " << makeModel << ", Location: ("
             << location.latitude << ", " << location.longitude << ")" << endl;
    }

    virtual string getVehicleType() const = 0;
    virtual ~Vehicle() {}
};

// passenger class
class PassengerVehicle : public Vehicle
{
private:
    int currentOccupancy;
    // boarding structure used
    BoardingEntry boardingLog[100];
    int logCount;

public:
    PassengerVehicle(const string &id, int seats, const string &make)
        : Vehicle(id, seats, make), currentOccupancy(0), logCount(0) {}

    void boardPassenger(const string &passengerInfo)
    {
        if (currentOccupancy < seating && logCount < 100)
        {
            currentOccupancy++;
            // time for boarding entry
            boardingLog[logCount++] = BoardingEntry("time_", passengerInfo);
        }
    }

    void alightPassenger()
    {
        if (currentOccupancy > 0)
            currentOccupancy--;
    }

    int getAvailableSeats() const { return seating - currentOccupancy; }

    string getVehicleType() const { return "Passenger Vehicle"; }

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Current Occupancy: " << currentOccupancy
             << ", Available Seats: " << getAvailableSeats() << endl;
    }
};

// route class
class RouteVehicle : public Vehicle
{
private:
    string routeId;
    string stops[50];
    string stopTimings[50];
    int stopCount;
    string estimatedArrival;

public:
    RouteVehicle(const string &id, int seats, const string &make, const string &route)
        : Vehicle(id, seats, make), routeId(route), stopCount(0) {}

    void addStop(const string &stop, const string &timing)
    {
        if (stopCount < 50)
        {
            stops[stopCount] = stop;
            stopTimings[stopCount] = timing;
            stopCount++;
        }
    }

    void setEstimatedArrival(const string &arrival) { estimatedArrival = arrival; }

    string getVehicleType() const { return "Route Vehicle"; }

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Route ID: " << routeId << ", Stops: " << stopCount
             << ", ETA: " << estimatedArrival << endl;
    }
};

// fuel class for vehicle
class FuelVehicle : public Vehicle
{
private:
    double fuelLevel; // car fuel
    string fuelType;
    double maxCapacity;

public:
    FuelVehicle(const string &id, int seats, const string &make,
                const string &fuel, double capacity)
        : Vehicle(id, seats, make), fuelLevel(100.0), fuelType(fuel), maxCapacity(capacity) {}

    void updateFuelLevel(double level)
    {
        if (level < 0.0)
            fuelLevel = 0.0;
        else if (level > 100.0)
            fuelLevel = 100.0;
        else
            fuelLevel = level;
    }

    bool needsRefueling() const { return fuelLevel < 20.0; }

    string getVehicleType() const { return "Fuel Vehicle"; }

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Fuel Type: " << fuelType << ", Fuel Level: " << fuelLevel
             << "%, Needs Refueling: " << (needsRefueling() ? "Yes" : "No") << endl;
    }
};

// cargo class for vehicle
class CargoVehicle : public Vehicle
{
private:
    double weightCapacity;
    double currentWeight;
    string deliverySchedule[30];
    string shipmentDetails[30];
    int deliveryCount;
    int shipmentCount;

public:
    CargoVehicle(const string &id, int seats, const string &make, double capacity)
        : Vehicle(id, seats, make), weightCapacity(capacity), currentWeight(0.0),
          deliveryCount(0), shipmentCount(0) {}

    // loading the weight
    bool loadCargo(double weight, const string &details)
    {
        if (currentWeight + weight <= weightCapacity && shipmentCount < 30)
        {
            currentWeight += weight;
            shipmentDetails[shipmentCount++] = details;
            return true;
        }
        return false;
    }

    void addDelivery(const string &delivery)
    {
        if (deliveryCount < 30)
        {
            deliverySchedule[deliveryCount++] = delivery;
        }
    }

    string getVehicleType() const { return "Cargo Vehicle"; }

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Weight Capacity: " << weightCapacity << "kg, Current Weight: "
             << currentWeight << "kg, Deliveries: " << deliveryCount << endl;
    }
};

// Base class for emergency unit
class EmergencyUnit
{
protected:
    string unitId;
    int type;
    bool available;
    Coordinate location;
    string currentAssignment;

public:
    EmergencyUnit(const string &id, int t)
        : unitId(id), type(t), available(true), location(0.0, 0.0) {}

    // getters
    string getId() const { return unitId; }
    bool isAvailable() const { return available; }
    // setters
    void setAvailable(bool status) { available = status; }
    void setAssignment(const string &assignment) { currentAssignment = assignment; }

    virtual void displayInfo() const
    {
        cout << "Unit ID: " << unitId << ", Type: ";
        switch (type)
        {
        case FIRE:
            cout << "Fire";
            break;
        case MEDICAL:
            cout << "Medical";
            break;
        case POLICE:
            cout << "Police";
            break;
        case DISASTER:
            cout << "Disaster";
            break;
        }
        cout << ", Available: " << (available ? "Yes" : "No") << endl;
    }

    virtual void respond() = 0;
    virtual ~EmergencyUnit() {}
};

// fire class for emergency
class FireUnit : public EmergencyUnit
{
private:
    double waterTankLevel;
    double ladderLength;
    string specialEquipment[10];
    int equipmentCount;

public:
    FireUnit(const string &id, double tankLevel, double ladder)
        : EmergencyUnit(id, FIRE), waterTankLevel(tankLevel), ladderLength(ladder), equipmentCount(0) {}

    void addEquipment(const string &equipment)
    {
        if (equipmentCount < 10)
        {
            specialEquipment[equipmentCount++] = equipment;
        }
    }

    void respond()
    {
        cout << "Fire Unit " << unitId << " responding with " << waterTankLevel
             << "L water and " << ladderLength << "m ladder." << endl;
    }

    void displayInfo() const
    {
        EmergencyUnit::displayInfo();
        cout << "Water Tank: " << waterTankLevel << "L, Ladder: " << ladderLength << "m" << endl;
    }
};

// medical class for emergency
class MedicalUnit : public EmergencyUnit
{
private:
    string medicalEquipment[20];
    int equipmentCount;
    int patientCapacity;
    bool responseReady;

public:
    MedicalUnit(const string &id, int capacity)
        : EmergencyUnit(id, MEDICAL), equipmentCount(0), patientCapacity(capacity), responseReady(true) {}

    void addMedicalEquipment(const string &equipment)
    {
        if (equipmentCount < 20)
        {
            medicalEquipment[equipmentCount++] = equipment;
        }
    }

    void respond()
    {
        cout << "Medical Unit " << unitId << " responding with capacity for "
             << patientCapacity << " patients." << endl;
    }

    void displayInfo() const
    {
        EmergencyUnit::displayInfo();
        cout << "Patient Capacity: " << patientCapacity
             << ", Equipment Count: " << equipmentCount << endl;
    }
};

// police class for emergency
class PoliceUnit : public EmergencyUnit
{
private:
    string patrolArea;
    string violationRecords[50];
    int violationCount;
    double averageResponseTime;

public:
    PoliceUnit(const string &id, const string &area)
        : EmergencyUnit(id, POLICE), patrolArea(area), violationCount(0), averageResponseTime(0.0) {}

    void recordViolation(const string &violation)
    {
        if (violationCount < 50)
        {
            violationRecords[violationCount++] = violation;
        }
    }

    void respond()
    {
        cout << "Police Unit " << unitId << " responding from patrol area: " << patrolArea << endl;
    }

    void displayInfo() const
    {
        EmergencyUnit::displayInfo();
        cout << "Patrol Area: " << patrolArea
             << ", Violations Recorded: " << violationCount << endl;
    }
};

// base incident class
class Incident
{
protected:
    string incidentId;
    int type;
    string timestamp;
    string location;
    string responsePersonnel[10];
    string resourceAllocation[20];
    int personnelCount;
    int resourceCount;

public:
    Incident(const string &id, int t, const string &loc)
        : incidentId(id), type(t), location(loc), personnelCount(0), resourceCount(0)
    {
        // time stamp
        timestamp = "time_";
    }

    void addResponsePersonnel(const string &personnel)
    {
        if (personnelCount < 10)
        {
            responsePersonnel[personnelCount++] = personnel;
        }
    }

    void allocateResource(const string &resource)
    {
        if (resourceCount < 20)
        {
            resourceAllocation[resourceCount++] = resource;
        }
    }

    virtual void displayInfo() const
    {
        cout << "Incident ID: " << incidentId << ", Type: ";
        switch (type)
        {
        case FIRE_INCIDENT:
            cout << "Fire";
            break;
        case MEDICAL_INCIDENT:
            cout << "Medical";
            break;
        case TRAFFIC_INCIDENT:
            cout << "Traffic";
            break;
        }
        cout << ", Location: " << location << ", Time: " << timestamp << endl;
    }
    virtual ~Incident() {}
};

// medical class for incident
class MedicalIncident : public Incident
{
private:
    string patientCondition;
    int patientsCount;

public:
    MedicalIncident(const string &id, const string &loc, const string &condition, int count)
        : Incident(id, MEDICAL_INCIDENT, loc), patientCondition(condition), patientsCount(count) {}

    void displayInfo() const
    {
        Incident::displayInfo();
        cout << "Patient Condition: " << patientCondition
             << ", Patients Count: " << patientsCount << endl;
    }
};

// fire class for incident
class FireIncident : public Incident
{
private:
    string fireIntensity;
    string buildingType;

public:
    FireIncident(const string &id, const string &loc, const string &intensity, const string &building)
        : Incident(id, FIRE_INCIDENT, loc), fireIntensity(intensity), buildingType(building) {}

    void displayInfo() const
    {
        Incident::displayInfo();
        cout << "Fire Intensity: " << fireIntensity
             << ", Building Type: " << buildingType << endl;
    }
};

// traffic class for incident
class TrafficIncident : public Incident
{
private:
    int vehiclesInvolved;
    string roadCondition;

public:
    TrafficIncident(const string &id, const string &loc, int vehicles, const string &condition)
        : Incident(id, TRAFFIC_INCIDENT, loc), vehiclesInvolved(vehicles), roadCondition(condition) {}

    void displayInfo() const
    {
        Incident::displayInfo();
        cout << "Vehicles Involved: " << vehiclesInvolved
             << ", Road Condition: " << roadCondition << endl;
    }
};

// base monitoring class
class MonitoringDevice
{
protected:
    string deviceId;
    int type;
    string lastSyncTime;
    bool operational;
    Coordinate location;

public:
    MonitoringDevice(const string &id, int t, double lat, double lon)
        : deviceId(id), type(t), operational(true), location(lat, lon)
    {
        // last time
        lastSyncTime = "lastTime_";
    }

    // getters
    string getId() const { return deviceId; }
    bool isOperational() const { return operational; }
    void setOperational(bool status) { operational = status; }

    virtual void collectData() = 0;
    virtual void displayInfo() const
    {
        cout << "Device ID: " << deviceId << ", Type: ";
        switch (type)
        {
        case ENVIRONMENTAL:
            cout << "Environmental";
            break;
        case TRAFFIC:
            cout << "Traffic";
            break;
        case STRUCTURAL:
            cout << "Structural";
            break;
        }
        cout << ", Operational: " << (operational ? "Yes" : "No")
             << ", Location: (" << location.latitude << ", " << location.longitude << ")" << endl;
    }
    virtual ~MonitoringDevice() {}
};

// environmental class for monitoring
class EnvironmentalSensor : public MonitoringDevice
{
private:
    double airQualityIndex;
    double noiseLevel;
    double temperature;
    double humidity;

public:
    EnvironmentalSensor(const string &id, double lat, double lon)
        : MonitoringDevice(id, ENVIRONMENTAL, lat, lon),
          airQualityIndex(0.0), noiseLevel(0.0), temperature(0.0), humidity(0.0) {}

    void collectData()
    {
        // hardcoded values
        airQualityIndex = 75.5;
        noiseLevel = 45.3;
        temperature = 22.8;
        humidity = 65.2;
    }

    void displayInfo() const
    {
        MonitoringDevice::displayInfo();
        cout << "AQI: " << airQualityIndex << ", Noise: " << noiseLevel
             << "dB, Temp: " << temperature << "C, Humidity: " << humidity << "%" << endl;
    }
};

// traffic class for monitoring
class TrafficSensor : public MonitoringDevice
{
private:
    int vehicleFlow;
    double congestionLevel;
    string peakHours;

public:
    TrafficSensor(const string &id, double lat, double lon)
        : MonitoringDevice(id, TRAFFIC, lat, lon),
          vehicleFlow(0), congestionLevel(0.0), peakHours("08:00-10:00, 17:00-19:00") {}

    void collectData()
    {
        vehicleFlow = 250;
        congestionLevel = 6.8;
    }

    void displayInfo() const
    {
        MonitoringDevice::displayInfo();
        cout << "Vehicle Flow: " << vehicleFlow << "/hour, Congestion: "
             << congestionLevel << "%, Peak Hours: " << peakHours << endl;
    }
};

// health class for monitoring
class StructuralHealthMonitor : public MonitoringDevice
{
private:
    double vibrationLevel;
    double structuralStress;
    string structureType;
    bool integrityAlert;

public:
    StructuralHealthMonitor(const string &id, double lat, double lon, const string &structure)
        : MonitoringDevice(id, STRUCTURAL, lat, lon),
          vibrationLevel(0.0), structuralStress(0.0), structureType(structure), integrityAlert(false) {}

    void collectData()
    {
        vibrationLevel = 2.3;
        structuralStress = 4.7;
        integrityAlert = (structuralStress > 8.0 || vibrationLevel > 4.0);
    }

    void displayInfo() const
    {
        MonitoringDevice::displayInfo();
        cout << "Structure: " << structureType << ", Vibration: " << vibrationLevel
             << ", Stress: " << structuralStress << ", Alert: " << (integrityAlert ? "Yes" : "No") << endl;
    }
};

// UOMS class
class UOMS
{
private:
    Vehicle *vehicles[100];
    int vehicleCount;
    Person *personnel[100];
    int personnelCount;
    EmergencyUnit *emergencyUnits[50];
    int emergencyUnitCount;
    Incident *incidents[200];
    int incidentCount;
    MonitoringDevice *monitoringDevices[100];
    int deviceCount;

public:
    UOMS() : vehicleCount(0), personnelCount(0), emergencyUnitCount(0), incidentCount(0), deviceCount(0) {}

    // Vehicle Management
    void addVehicle(Vehicle *vehicle)
    {
        if (vehicleCount < 100)
        {
            vehicles[vehicleCount++] = vehicle;
        }
    }

    void addPersonnel(Person *person)
    {
        if (personnelCount < 100)
        {
            personnel[personnelCount++] = person;
        }
    }

    void addEmergencyUnit(EmergencyUnit *unit)
    {
        if (emergencyUnitCount < 50)
        {
            emergencyUnits[emergencyUnitCount++] = unit;
        }
    }

    void addIncident(Incident *incident)
    {
        if (incidentCount < 200)
        {
            incidents[incidentCount++] = incident;
        }
    }

    void addMonitoringDevice(MonitoringDevice *device)
    {
        if (deviceCount < 100)
        {
            monitoringDevices[deviceCount++] = device;
        }
    }

    // display functions
    void displayAllVehicles() const
    {
        cout << "=== VEHICLE FLEET ===" << endl;
        for (int i = 0; i < vehicleCount; i++)
        {
            vehicles[i]->displayInfo();
            cout << "Type: " << vehicles[i]->getVehicleType() << endl;
            cout << "------------------------" << endl;
        }
    }

    void displayPersonnel() const
    {
        cout << "=== PERSONNEL ===" << endl;
        for (int i = 0; i < personnelCount; i++)
        {
            personnel[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void displayEmergencyUnits() const
    {
        cout << "=== EMERGENCY UNITS ===" << endl;
        for (int i = 0; i < emergencyUnitCount; i++)
        {
            emergencyUnits[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void displayIncidents() const
    {
        cout << "=== INCIDENTS ===" << endl;
        for (int i = 0; i < incidentCount; i++)
        {
            incidents[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void displayMonitoringDevices() const
    {
        cout << "=== MONITORING DEVICES ===" << endl;
        for (int i = 0; i < deviceCount; i++)
        {
            monitoringDevices[i]->displayInfo();
            cout << "------------------------" << endl;
        }
    }

    void collectAllSensorData()
    {
        cout << "=== COLLECTING SENSOR DATA ===" << endl;
        for (int i = 0; i < deviceCount; i++)
        {
            monitoringDevices[i]->collectData();
            cout << "Data collected from device: " << monitoringDevices[i]->getId() << endl;
        }
    }

    void generateSystemReport() const
    {
        cout << "=== ISLAMABAD UOMS SYSTEM REPORT ===" << endl;
        cout << "Total Vehicles: " << vehicleCount << endl;
        cout << "Total Personnel: " << personnelCount << endl;
        cout << "Total Emergency Units: " << emergencyUnitCount << endl;
        cout << "Total Incidents: " << incidentCount << endl;
        cout << "Total Monitoring Devices: " << deviceCount << endl;

        // counting availible emergenct units
        int availableUnits = 0;
        for (int i = 0; i < emergencyUnitCount; i++)
        {
            if (emergencyUnits[i]->isAvailable())
                availableUnits++;
        }
        cout << "Available Emergency Units: " << availableUnits << "/" << emergencyUnitCount << endl;

        // to count operational devices
        int operationalDevices = 0;
        for (int i = 0; i < deviceCount; i++)
        {
            if (monitoringDevices[i]->isOperational())
                operationalDevices++;
        }
        cout << "Operational Monitoring Devices: " << operationalDevices << "/" << deviceCount << endl;
    }

    void addVehicleInteractive()
    {
        string id, make;
        int seats, type;

        cout << "=== ADD NEW VEHICLE ===" << endl;
        cout << "Enter Vehicle ID: ";
        cin >> id;
        cout << "Enter Make/Model: ";
        cin.ignore();
        getline(cin, make);
        cout << "Enter Seating Capacity: ";
        cin >> seats;

        cout << "Select Vehicle Type:" << endl;
        cout << "1. Passenger Vehicle" << endl;
        cout << "2. Route Vehicle" << endl;
        cout << "3. Fuel Vehicle" << endl;
        cout << "4. Cargo Vehicle" << endl;
        cout << "Enter choice (1-4): ";
        cin >> type;

        switch (type)
        {
        case 1:
            addVehicle(new PassengerVehicle(id, seats, make));
            cout << "Passenger Vehicle added successfully!" << endl;
            break;
        case 2:
        {
            string routeId;
            cout << "Enter Route ID: ";
            cin >> routeId;
            addVehicle(new RouteVehicle(id, seats, make, routeId));
            cout << "Route Vehicle added successfully!" << endl;
            break;
        }
        case 3:
        {
            string fuelType;
            double capacity;
            cout << "Enter Fuel Type (Petrol/Diesel/Electric): ";
            cin >> fuelType;
            cout << "Enter Fuel Capacity: ";
            cin >> capacity;
            addVehicle(new FuelVehicle(id, seats, make, fuelType, capacity));
            cout << "Fuel Vehicle added successfully!" << endl;
            break;
        }
        case 4:
        {
            double weightCapacity;
            cout << "Enter Weight Capacity (kg): ";
            cin >> weightCapacity;
            addVehicle(new CargoVehicle(id, seats, make, weightCapacity));
            cout << "Cargo Vehicle added successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void addPersonnelInteractive()
    {
        string id, name;
        int type;

        cout << "\n=== ADD NEW PERSONNEL ===" << endl;
        cout << "Enter Personnel ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Select Personnel Type:" << endl;
        cout << "1. Driver" << endl;
        cout << "2. Conductor" << endl;
        cout << "3. Logistics Operator" << endl;
        cout << "Enter choice (1-3): ";
        cin >> type;

        switch (type)
        {
        case 1:
        {
            string license;
            char heavy;
            cout << "Enter License Class: ";
            cin >> license;
            cout << "Heavy Vehicle License (y/n): ";
            cin >> heavy;
            bool isHeavy = (heavy == 'y' || heavy == 'Y');
            addPersonnel(new Driver(id, name, license, isHeavy));
            cout << "Driver added successfully!" << endl;
            break;
        }
        case 2:
            addPersonnel(new Conductor(id, name));
            cout << "Conductor added successfully!" << endl;
            break;
        case 3:
            addPersonnel(new LogisticsOperator(id, name));
            cout << "Logistics Operator added successfully!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void addEmergencyUnitInteractive()
    {
        string id;
        int type;

        cout << "=== ADD NEW EMERGENCY UNIT ===" << endl;
        cout << "Enter Unit ID: ";
        cin >> id;

        cout << "Select Unit Type:" << endl;
        cout << "1. Fire Unit" << endl;
        cout << "2. Medical Unit" << endl;
        cout << "3. Police Unit" << endl;
        cout << "Enter choice (1-3): ";
        cin >> type;

        switch (type)
        {
        case 1:
        {
            double water, ladder;
            cout << "Enter Water Tank Level (L): ";
            cin >> water;
            cout << "Enter Ladder Length (m): ";
            cin >> ladder;
            addEmergencyUnit(new FireUnit(id, water, ladder));
            cout << "Fire Unit added successfully!" << endl;
            break;
        }
        case 2:
        {
            int capacity;
            cout << "Enter Patient Capacity: ";
            cin >> capacity;
            addEmergencyUnit(new MedicalUnit(id, capacity));
            cout << "Medical Unit added successfully!" << endl;
            break;
        }
        case 3:
        {
            string area;
            cout << "Enter Patrol Area: ";
            cin.ignore();
            getline(cin, area);
            addEmergencyUnit(new PoliceUnit(id, area));
            cout << "Police Unit added successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void addIncidentInteractive()
    {
        string id, location;
        int type;

        cout << "=== REPORT NEW INCIDENT ===" << endl;
        cout << "Enter Incident ID: ";
        cin >> id;
        cout << "Enter Location: ";
        cin.ignore();
        getline(cin, location);

        cout << "Select Incident Type:" << endl;
        cout << "1. Medical Incident" << endl;
        cout << "2. Fire Incident" << endl;
        cout << "3. Traffic Incident" << endl;
        cout << "Enter choice (1-3): ";
        cin >> type;

        switch (type)
        {
        case 1:
        {
            string condition;
            int patients;
            cout << "Enter Patient Condition: ";
            cin.ignore();
            getline(cin, condition);
            cout << "Enter Number of Patients: ";
            cin >> patients;
            addIncident(new MedicalIncident(id, location, condition, patients));
            cout << "Medical Incident reported successfully!" << endl;
            break;
        }
        case 2:
        {
            string intensity, building;
            cout << "Enter Fire Intensity: ";
            cin.ignore();
            getline(cin, intensity);
            cout << "Enter Building Type: ";
            getline(cin, building);
            addIncident(new FireIncident(id, location, intensity, building));
            cout << "Fire Incident reported successfully!" << endl;
            break;
        }
        case 3:
        {
            int vehicles;
            string condition;
            cout << "Enter Number of Vehicles Involved: ";
            cin >> vehicles;
            cout << "Enter Road Condition: ";
            cin.ignore();
            getline(cin, condition);
            addIncident(new TrafficIncident(id, location, vehicles, condition));
            cout << "Traffic Incident reported successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void addMonitoringDeviceInteractive()
    {
        string id;
        double lat, lon;
        int type;

        cout << "=== ADD NEW MONITORING DEVICE ===" << endl;
        cout << "Enter Device ID: ";
        cin >> id;
        cout << "Enter Latitude: ";
        cin >> lat;
        cout << "Enter Longitude: ";
        cin >> lon;

        cout << "Select Device Type:" << endl;
        cout << "1. Environmental Sensor" << endl;
        cout << "2. Traffic Sensor" << endl;
        cout << "3. Structural Health Monitor" << endl;
        cout << "Enter choice (1-3): ";
        cin >> type;

        switch (type)
        {
        case 1:
            addMonitoringDevice(new EnvironmentalSensor(id, lat, lon));
            cout << "Environmental Sensor added successfully!" << endl;
            break;
        case 2:
            addMonitoringDevice(new TrafficSensor(id, lat, lon));
            cout << "Traffic Sensor added successfully!" << endl;
            break;
        case 3:
        {
            string structure;
            cout << "Enter Structure Type: ";
            cin.ignore();
            getline(cin, structure);
            addMonitoringDevice(new StructuralHealthMonitor(id, lat, lon, structure));
            cout << "Structural Health Monitor added successfully!" << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    ~UOMS()
    {
        for (int i = 0; i < vehicleCount; i++)
            delete vehicles[i];
        for (int i = 0; i < personnelCount; i++)
            delete personnel[i];
        for (int i = 0; i < emergencyUnitCount; i++)
            delete emergencyUnits[i];
        for (int i = 0; i < incidentCount; i++)
            delete incidents[i];
        for (int i = 0; i < deviceCount; i++)
            delete monitoringDevices[i];
    }
};

// main menu
void displayMenu()
{
    cout << "=====================================================" << endl;
    cout << "  UNIFIED URBAN OPERATIONS MANAGEMENT SYSTEM" << endl;
    cout << "      ISLAMABAD MUNICIPAL ADMINISTRATION" << endl;
    cout << "=====================================================" << endl;
    cout << "1.  Add Vehicle" << endl;
    cout << "2.  Add Personnel" << endl;
    cout << "3.  Add Emergency Unit" << endl;
    cout << "4.  Report Incident" << endl;
    cout << "5.  Add Monitoring Device" << endl;
    cout << "6.  View All Vehicles" << endl;
    cout << "7.  View All Personnel" << endl;
    cout << "8.  View Emergency Units" << endl;
    cout << "9.  View Incidents" << endl;
    cout << "10. View Monitoring Devices" << endl;
    cout << "11. Collect Sensor Data" << endl;
    cout << "12. Generate System Report" << endl;
    cout << "0.  Exit System" << endl;
    cout << "=====================================================" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    UOMS system;
    int choice;

    cout << "=====================================================" << endl;
    cout << "       WELCOME TO ISLAMABAD UOMS" << endl;
    cout << " Unified Urban Operations Management System" << endl;
    cout << "=====================================================" << endl;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.addVehicleInteractive();
            break;
        case 2:
            system.addPersonnelInteractive();
            break;
        case 3:
            system.addEmergencyUnitInteractive();
            break;
        case 4:
            system.addIncidentInteractive();
            break;
        case 5:
            system.addMonitoringDeviceInteractive();
            break;
        case 6:
            system.displayAllVehicles();
            break;
        case 7:
            system.displayPersonnel();
            break;
        case 8:
            system.displayEmergencyUnits();
            break;
        case 9:
            system.displayIncidents();
            break;
        case 10:
            system.displayMonitoringDevices();
            break;
        case 11:
            system.collectAllSensorData();
            break;
        case 12:
            system.generateSystemReport();
            break;
        case 0:
            cout << "Thank you for using Islamabad UOMS!" << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 0-12." << endl;
        }

        if (choice != 0)
        {
            cout << "Press Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);

    return 0;
}