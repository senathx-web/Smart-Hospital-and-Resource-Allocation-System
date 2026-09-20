//Displaying menus/welcome massages/ outputs  goes here
#include <stdio.h>

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

extern char *wardNames[NUM_WARDS];
extern int wardCapacity[NUM_WARDS];
extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

extern char *specialtyNames[NUM_SPECIALTIES];
extern float specialtyFees[NUM_SPECIALTIES];
extern int consultationTimes[NUM_SPECIALTIES];
extern int dailyPatientCap[NUM_SPECIALTIES];

extern int wardCapacity[NUM_WARDS];
extern float dailywardRates[NUM_WARDS];


extern char patientNames[MAX_PATIENTS][50];
extern int patientAges [MAX_PATIENTS];
extern int emergencyLevels[MAX_PATIENTS];
extern int patientSpecialties[MAX_PATIENTS];
extern int patientWards[MAX_PATIENTS];
extern int admittedToWard[MAX_PATIENTS];
extern int admittedDays[MAX_PATIENTS];
extern int assignedBeds[MAX_PATIENTS];

extern float calculateSurCharge(float baseFee, int urgeLevel);
extern float calculateWardCost(int ward, int days);

extern float calculateGrossTotal(float basefee, float surcharge, float wordCost);
extern float calculateDiscount(float grossTotal, int age);
extern float calculateFinalAmount(float grossTotal, float discount);

extern int queueCount[NUM_SPECIALTIES];
extern float calculatewaitingTime(int specialty, int queCount);


void welcomeMenu(){
    printf("-----------------------------------------\n");
    printf("\t\t WELCOME \t\t\n");
    printf("-----------------------------------------\n");

    printf("1.Register patient\n");
    printf("2.Display Bed Availability\n");
    printf("3.Display specialities Details\n");
    printf("4.Display wards Details\n");
    printf("5.Display patient Bill\n");
    printf("6.Display All patients\n");
    printf("7.Generate summary Report\n");
    printf("8.Exit\n");

    printf("-----------------------------------------\n");
}

void displayBedMap(){
    for (int i = 0; i < NUM_WARDS; i++){
        printf("\n                                 %s               \n\n", wardNames[i]);
        for (int j = 0; j< wardCapacity[i]; j++){
            if (bedOccupancy[i][j] == 0){
                printf("  [Bed %02d:Available]  ",
                       j+1);
            }
            else{
                printf("  [Bed %02d: Occupied]  ",
                       j+1);
            }
            if ((j+1)%5 == 0){
                printf("\n");
            }
        }
        printf("\n");
    }
}

void displaySpecialties(){

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("Speciality ID    Speciality Name                Base Fee    Consultation Time    Daily Patient Cup\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    for(int i =0; i< NUM_SPECIALTIES;i++){
        printf("%-15d  %-25s      %.2f         %d mins  %10d\n",i+1,specialtyNames[i],specialtyFees[i], consultationTimes[i], dailyPatientCap[i]);
    }
}

void displayWards(){
    printf("-------------------------------------------------------------------\n");
    printf("Ward ID    Ward Name                   Bed Rate    Bed Capacity\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < NUM_WARDS; i++){
            printf("%-10d%-26s   %-10.2f   %d \n", i + 1,wardNames[i],dailywardRates[i],wardCapacity[i]);
        }
}

void displayPatientBill(int number){
    printf("\n");
    printf("-------------------------------------------------------------------\n");
    printf("              SMART HOSPITAL ADMISSION & BILL\n");
    printf("-------------------------------------------------------------------\n");

    printf("Patient ID               : PAT-%04d\n",1001 + number);
    printf("Patient Name             : %s\n",patientNames[number]);
    printf("Age                      : %d", patientAges[number]);

    if (patientAges[number]<5 || patientAges >65){
        printf(" (15% subsidy Eligible)");
    }
    printf("\n");

    printf("Speciality               : %s\n",patientSpecialties[number]);

    if(admittedToWard[number]== 1){
        printf("Assigned Ward  : %s (BED #%02d)\n",wardNames[patientWards[number]-1], assignedBeds[number] +1);
    }
    else{
        printf("Assigned Ward            : OPD\n");
    }

    printf("Urgency Level            : ");
    if(emergencyLevels[number]==1){
        printf("Level 1 (Normal)\n");
    }
    else if (emergencyLevels[number] == 2){
        printf("Level 2 (Urgent)\n");
    }
    else{
        printf("Level 3 (Critical)\n");
    }
    printf("-------------------------------------------------------------------\n");

    printf("Base Consultation Fee    : LKR %.2f\n", specialtyFees[number]);
    printf("Emergency Surcharge      : LKR %.2f\n", calculateSurCharge(specialtyFees[number],emergencyLevels[number]));
    printf("Ward stay cost (%d Days)  : LKR %.2f\n", admittedDays[number],calculateWardCost(patientWards[number],admittedDays[number]));

    printf("-------------------------------------------------------------------\n");

    printf("Gross Total Bill         : LKR %.2f\n",calculateGrossTotal(specialtyFees[number],
                                                                       calculateSurCharge(specialtyFees[number],emergencyLevels[number]),
                                                                       calculateWardCost(patientWards[number],admittedDays[number])));

    printf("Age subsidy Discount     : LKR -%.2f\n",calculateDiscount(calculateGrossTotal(specialtyFees[number],
                                                                       calculateSurCharge(specialtyFees[number],emergencyLevels[number]),
                                                                       calculateWardCost(patientWards[number],admittedDays[number])), patientAges[number]));

    printf("-------------------------------------------------------------------\n");

    printf("Final Payable Amount     : LKR %.2f\n",calculateFinalAmount(calculateGrossTotal(specialtyFees[number],
                                                                       calculateSurCharge(specialtyFees[number],emergencyLevels[number]),
                                                                       calculateWardCost(patientWards[number],admittedDays[number])), calculateDiscount(calculateGrossTotal(specialtyFees[number],
                                                                       calculateSurCharge(specialtyFees[number],emergencyLevels[number]),
                                                                       calculateWardCost(patientWards[number],admittedDays[number])), patientAges[number])));
    printf("Estimated waiting Time   : %.2f mins",calculatewaitingTime(patientSpecialties[number],queueCount[number]));

}



