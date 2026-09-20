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

extern int patientCount;
extern int finalAmounts[MAX_PATIENTS];
extern float discounts[MAX_PATIENTS];


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

void displayAllPatients(){
    if (patientCount == 0){
        printf("\nNo patients registered yet.\n");
        return;
    }

    printf("\n");
    printf("----------------------------------------------------\n");
    printf("                 PATIENT LIST\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < patientCount; i++){
        printf("\nPatient ID : PAT-%04d\n", 1001 + i);
        printf("Name       : %s\n", patientNames[i]);
        printf("Age        : %d\n", patientAges[i]);
        printf("Urgency    : Level %d\n", emergencyLevels[i]);
        printf("Final Bill : LKR %.2f\n",calculateFinalAmount(calculateGrossTotal(specialtyFees[i],
                                                                       calculateSurCharge(specialtyFees[i],emergencyLevels[i]),
                                                                       calculateWardCost(patientWards[i],admittedDays[i])), calculateDiscount(calculateGrossTotal(specialtyFees[i],
                                                                       calculateSurCharge(specialtyFees[i],emergencyLevels[i]),
                                                                       calculateWardCost(patientWards[i],admittedDays[i])), patientAges[i])));
    }
}

void displaySummaryReport(){
    int normal = 0;
    int urgent = 0;
    int critical = 0;

    float totalRevenue = 0.0;
    float totalDiscounts = 0.0;

    int highestPatient = -1;


    for (int i = 0; i < patientCount; i++){
        if (emergencyLevels[i] == 1){
            normal++;
        }else if (emergencyLevels[i] == 2){
            urgent++;
        }else if (emergencyLevels[i] == 3){
            critical++;
        }

        totalRevenue += finalAmounts[i];
        totalDiscounts += discounts[i];

        if (highestPatient == -1 || finalAmounts[i] > finalAmounts[highestPatient]){
            highestPatient = i;
        }
    }


    printf("\n");
    printf("--------------------------------------------\n");
    printf("          HOSPITAL SUMMARY REPORT \n");
    printf("--------------------------------------------\n");

    printf("\nTotal Patients: %d\n", patientCount);

    printf("\nUrgency Breakdown\n");
    printf("Normal   : %d\n", normal);
    printf("Urgent   : %d\n", urgent);
    printf("Critical : %d\n", critical);


    printf("\nFinancial Summary\n");
    printf("Total Revenue    : LKR %.2f\n",totalRevenue);
    printf("Total Discounts  : LKR %.2f\n",totalDiscounts);

    printf("\nBed Occupancy\n");

    for (int ward = 0; ward < NUM_WARDS; ward++){
        int occupied = 0;
        for (int bed = 0;bed < wardCapacity[ward];bed++){
            if (bedOccupancy[ward][bed] == 1){
                occupied++;
            }
        }
        float percentage =(float)occupied / wardCapacity[ward] *100;

        printf("%s : %.2f%%\n",wardNames[ward],percentage);
    }


    if (highestPatient != -1){
        printf("\nHighest-Paying Patient\n");
        printf("Name : %s\n",
               patientNames[highestPatient]);

        printf("Bill : LKR %.2f\n",
               finalAmounts[highestPatient]);
    }


}

