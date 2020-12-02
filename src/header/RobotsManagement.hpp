#ifndef ROBOTS_MANAGEMENT
#define ROBOTS_MANAGEMENT

#include "RobotFunctions.hpp"
#include "Task.hpp"
#include "VillageStats.hpp"
#include <vector>
#include <map> 
#include <ctime>


class RobotsManagement{

    private:
        int totRobots;
        int freeRobots;
        int efficiency;
        int prodCost;
        VillageStats *villageStats;
        std::vector<std::map<time_t,Task>> *tasks;

    public:
        RobotsManagement();
        void initializeStats();
        ~RobotsManagement();

        int getTotRobots() const;
        int getFreeRobots() const;
        int getEfficiency() const;
        int getProdCost() const;

        void setTotRobots(int newTotRobots);
        void setFreeRobots(int newFreeRobots);
        void setEfficiency(int newEfficiency);
        void setProdCost(int newProdCost);
        void setVillageStats(VillageStats *newVillageStats);
        void setTasks(std::vector<std::map<time_t, Task>> *newTasks);

        bool createRobot();
        bool destroyRobot();
        void createTask(RobotFunctions funct);
        bool moveRobot(RobotFunctions funct,time_t id,int robotNo);
};
#endif