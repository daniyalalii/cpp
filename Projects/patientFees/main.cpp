#include <iostream>
#include <iomanip>
using namespace std;

class patientAccount
{
private:
    const int dailyRate = 1490.34;
    double charges;
    int daySpent;

public:
    patientAccount()
    {
        charges = 0;
        daySpent = 0;
    }
    void days()
    {
        daySpent = daySpent + 1;
    }
    int getCharges()
    {
        charges = daySpent * dailyRate;
        return charges;
    }

    int getDaySpent()
    {
        return daySpent;
    }
};

class surgery
{
private:
    double surgeryCharges;
    const double plasticSurgery = 49321.32;
    const double arthroscopy = 5000.23;
    const double neuroSurgery = 49789.93;
    const double endoscopy = 1989.93;
    const double vascularSurgery = 7983.43;

public:
    surgery()
    {
        surgeryCharges = 0;
    }
    void PlasticSurgery()
    {
        surgeryCharges += plasticSurgery;
    }
    void ArthoScopy()
    {
        surgeryCharges += arthroscopy;
    }
    void NeuroSurgery()
    {
        surgeryCharges += neuroSurgery;
    }
    void endoScopy()
    {
        surgeryCharges += endoscopy;
    }
    void VascularSurgery()
    {
        surgeryCharges += vascularSurgery;
    }

    void getPrices()
    {
        cout << fixed << showpoint << setprecision(2);
        cout << "-----------------------------" << endl;
        cout << "Plastic Surgery: " << plasticSurgery << endl;
        cout << "Surgery Prices are: " << endl;
        cout << "Vascular Surgery: " << vascularSurgery << endl;
        cout << "EndoScopy: " << endoscopy << endl;
        cout << "NeuroSurgery: " << neuroSurgery << endl;
        cout << "ArthoScopy: " << arthroscopy << endl;
        cout << "-----------------------------" << endl;
    }

    double getSurgeryCharges()
    {
        return surgeryCharges;
    }
};

class Pharmacy
{
private:
    double pharmacyCharges;
    const double Paracetamol = 210.23;
    const double Panadol = 175.32;
    const double VitaminD = 75.32;
    const double Amoxil = 299.21;
    const double Omeprazole = 789.21;

public:
    Pharmacy()
    {
        pharmacyCharges = 0;
    }
    void paracetamol()
    {
        pharmacyCharges += Paracetamol;
    }
    void panadol()
    {
        pharmacyCharges += Panadol;
    }
    void vitaminD()
    {
        pharmacyCharges += VitaminD;
    }
    void amoxil()
    {
        pharmacyCharges += Amoxil;
    }
    void omeprazole()
    {
        pharmacyCharges += Omeprazole;
    }
    void getPrices()
    {
        cout << "-----------------------------" << endl;
        cout << "Prices of medicines are: " << endl;
        cout << fixed << showpoint << setprecision(2);
        cout << "Panadol: " << Panadol << endl;
        cout << "Paracetamol: " << Paracetamol << endl;
        cout << "Amoxil: " << Amoxil << endl;
        cout << "Omeprazole: " << Omeprazole << endl;
        cout << "Vitamin D: " << VitaminD << endl;
        cout << "-----------------------------" << endl;
    }
    double getPharmacyCharges()
    {
        return pharmacyCharges;
    }
};
int main()
{
    int input;
    patientAccount p1;
    p1.days();
    p1.days();
    p1.days();
    surgery s1;
    s1.getPrices();
    s1.VascularSurgery();
    Pharmacy med1;
    med1.getPrices();
    med1.amoxil();
    med1.panadol();
    cout << "Total Charges for patient is: " << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << p1.getCharges() + s1.getSurgeryCharges() + med1.getPharmacyCharges() << endl;
    return 0;
}