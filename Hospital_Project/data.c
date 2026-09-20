#include<stdio.h>

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20
#define MAX_PATIENTS 500

int patientCount = 0;
// Doctor specialties
char *specialtyNames[NUM_SPECIALTIES] = {"General Practice (OPD)",
                           "Paediatrics",
                           "Cardiology",
                           "Neurology" };

float specialtyFees[NUM_SPECIALTIES] = {1500.00,2500.00,4500.00,5000.00};
int consultationTimes[NUM_SPECIALTIES] ={15,20,30,30};
int dailyPatientCap[NUM_SPECIALTIES] = {30,20,12,10};


// Hospital wards
char *wardNames[NUM_WARDS] = {"General ward",
                      "Paediatric ward",
                      "Surgical ward",
                      "ICU (Intensive Care Unit"};

float dailywardRates[NUM_WARDS] = {3000.00,6000.00,12000.00,25000.00};
int wardCapacity[NUM_WARDS] = {20,10,10,05};
int bedOccupancy[NUM_WARDS][MAX_BEDS] = {0};

// patient details
char patientNames[MAX_PATIENTS][50];
int patientAges [MAX_PATIENTS];
int emergencyLevels[MAX_PATIENTS];
int patientSpecialties[MAX_PATIENTS];
int patientWards[MAX_PATIENTS];
int admittedToWard[MAX_PATIENTS];
int admittedDays[MAX_PATIENTS];
int assignedBeds[MAX_PATIENTS];


int queueCount[NUM_SPECIALTIES] = {0};
