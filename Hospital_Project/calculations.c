#include <stdio.h>
#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20

extern float dailywardRates[NUM_WARDS];
extern int wardCapacity[NUM_WARDS];
extern  int bedOccupancy[NUM_WARDS][MAX_BEDS];
extern int consultationTimes[NUM_SPECIALTIES];

extern int numbers[];

//Calculating waiting time
float calculatewaitingTime(int specialty, int queCount){
    return queCount * consultationTimes[specialty];
}

//Calculating surcgarge
float calculateSurCharge(float baseFee, int urgeLevel){
    if(urgeLevel == 1){
        return 0.0;
    }
    else if(urgeLevel == 2){
        return baseFee *0.2;
    }
    else if(urgeLevel == 3){
        return baseFee * 0.5;
    }
    return 0.0;
}

//calculating ward costs
float calculateWardCost(int ward, int days){
    if (days<= 0){
        return 0.0;
    }
    return days * dailywardRates[ward];
}

//Calculating gross total
float calculateGrossTotal(float basefee, float surcharge, float wordCost){
    return basefee + surcharge + wordCost ;
}

// calculating discounts

float calculateDiscount(float grossTotal, int age){
    if (age<5 || age>65){
        return grossTotal* 0.15;
    }

    return 0.0;
}

float calculateFinalAmount(float grossTotal, float discount){
    return grossTotal - discount;
}


