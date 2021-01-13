#ifndef ROBOTS_MANAGEMENT
#define ROBOTS_MANAGEMENT

#include "RobotFunctions.hpp"
#include "Task.hpp"
#include "VillageStats.hpp"
#include "Avenue.hpp"
#include <vector>
#include "Application/ImGui/GameWindows/FunctionWindow.hpp"
#include "Application/Events/EventListener.hpp"
#include "Application/Events/Events.hpp"

#include <unordered_map>

namespace Application
{

    class RobotsManagement
    {
    public:
        enum Robots_Values_Index {TOT_ROBOTS, FREE_ROBOTS, PROD_COST};

        static constexpr int MAX_TASKS_PER_FUNCTION = 5;

    private:
        int totRobots;
        int freeRobots;
        int prodCost; 
        const float PROD_COST_INCREASE_TAX;
        const int TOT_ROBOTS_INI;
        const int FREE_ROBOTS_INI;
        const int PROD_COST_INI;

        VillageStats *villageStats;
        std::unordered_map<TaskID, Task*> tasks[FUNCTION_QTY];
        Avenue *robotsAvenues[3];
        pthread_t consumers[3];
        pthread_mutex_t tasksMutex;

        void initializeAvenues();
        void changeRobotsNum (int type, int increase);
        EventListener m_EventListener;

    public:
        
        RobotsManagement();
        void initializeStats();
        ~RobotsManagement();

        int getTotRobots() const;
        int getFreeRobots() const;
        int getProdCost() const;
        
        bool canRemoveRobots() const;
        bool canAddRobots() const;

        void setOnTaskCreated(EH_TaskCreated*);
        void setOnTaskEnded(EH_TaskEnded*);
        void setOnRobotsCreated(EH_RobotsCreated*);
        void setOnRobotsDestroyed(EH_RobotsDestroyed*);
        void setOnRobotsMoved(EH_RobotsMoved*);

        const std::unordered_map<TaskID, Task*> &getTasks(RobotFunction function) const;
        Task &findTask(TaskID taskID) const;

        void onTaskCompleted(TaskID completedTaskID);
        void setTotRobots(int newTotRobots);
        void setFreeRobots(int newFreeRobots);
        void setProdCost(int newProdCost);
        void setVillageStats(VillageStats *newVillageStats);
        
        bool createRobots(int);
        bool destroyRobots(int);
        bool createTask(RobotFunction);
        bool moveRobot(Task &, int);

        void tasksUp() const;
        void tasksDown() const;
        
        void endTask(Task &);
        void onTaskEnded(Task &);
    };
} // namespace Application
#endif