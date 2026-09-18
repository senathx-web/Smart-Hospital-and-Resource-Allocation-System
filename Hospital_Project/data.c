#include<stdio.h>

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20

// Doctor specialties
char *specialtyNames[] = {"General Practice (OPD)",
                           "Paediatrics",
                           "Cardiology",
                           "Neurology" };

float specialtyFees[] = {1500.00,2500.00,4500.00,5000.00};
int consultationTimes[] ={15,20,30,30};

int dailyPatientCap[] = {30,20,12,10};


// Hospital wards

char *wardNames[] = {"General ward",
                      "Paediatric ward",
                      "Surgical ward",
                      "ICU (Intensive Care Unit"};

float dailywardRates[] = {3000.00,6000.00,12000.00,25000.00};
int wardCapacity[] = {20,10,10,05};


int bedOccupancy[NUM_WARDS][MAX_BEDS] = {0};
