#!/usr/bin/python

import random

possibilities = ['man', 'healthy_man', 'fat_man', 'old_man', 'young_man', 'child_man', 'baby_man', 
                 'homeless_man', 'business_man', 'doctor_man', 'criminal_man', 
                 'wom', 'healthy_wom', 'fat_wom', 'old_wom', 'young_wom', 'child_wom', 'baby_wom', 
                 'homeless_wom', 'business_wom', 'doctor_man', 'criminal_man', 
                 'cat', 'baby_cat', 'dog', 'dog_baby', 'horse', 'baby_horse', 
                 'racoon', 'baby_racoon', 'bunny', 'baby_bunny', 'deer', 'baby_deer']
car = []
walk1 = []
walk2 = []

def genScenario()
    x = random.randint(0, 9)
    if x = 0:  # one car, one barrier, one crossing
        topcross = 1
        botcross = 0
        
    elif x = 1:
        //

def genCar()
    carnum = random.randint(0, 8)
    carpeople = []
    x = 0
    while x < carnum:
        carpeople[x] = possibilities[random.randint(0,34)]
        x += 1
    return carpeople

def genWalk()
    walknum = random.randint(1, 8)
    walkpeople = []
    x = 0
    while x < walknum:
        walkpeople[x] = possibilities[random.randint(0,34)]
        x += 1
    return walkpeople

