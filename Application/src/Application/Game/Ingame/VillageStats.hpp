#pragma once

#include "RobotFunctions.hpp"
#include "Application/Threads/Avenue.hpp"
#include <pthread.h>

#include "Application/Events/EventListener/EventListener.hpp"
#include "Application/Events/EventHandler/DefaultHandlers.hpp"
#include "Application/Game/GameConsts.hpp"

namespace Application
{
    class VillageStats
    {
    private:
        EventListener m_EventListener;
        GameConstsCache m_GameConstsCache;
        bool m_MarkedForDeletion = false;
        
        bool m_DecaymentPaused = false;

    public:
        const static int BASE_STATS_NO = FUNCTION_QTY;
        const static int POPULATION_INDEX = BASE_STATS_NO;
    private:
        int elapsedTimeTicks;
        bool onAttack;
        float statTax;
        int maxPop;

        int baseStats[BASE_STATS_NO];/*
            defenses;
            food;
            health;
            structures;
            resources;
        */

        Avenue *avenueVS[BASE_STATS_NO+1];
        pthread_t decayThread;

        void (VillageStats::*decayStatsFuncts[BASE_STATS_NO - 1])(int,int,float&) = {
            &VillageStats::decayFood,
            &VillageStats::decayHealth,
            &VillageStats::decayStructures,
            &VillageStats::decayDefenses,
        };


        int population; // if population reaches zero, the game is over -> pop calculated based on other village stats

        void initializeVSAvenues();
        bool updateGameConsts();

    public:
        VillageStats(GameConsts& gameConsts);
        VillageStats(const VillageStats&) = delete;
        VillageStats(VillageStats&&) = delete;
        ~VillageStats();

        float calcReduction(float,float);
        float calcRatio(int);
        float adjustStatsLimits(int,float,float,bool);

        void startStatsDecayment();
        void setStatsDecaymentPaused(bool paused);
        inline bool isStatusDecaymentPaused() { return m_DecaymentPaused; }

        void decayStat(int,int);
        void setOnStatusDecayed(EH_StatsDecayed *eventHandler) { m_EventListener.Register(eventHandler); }

        void decayDefenses(int,int,float&);
        void decayFood(int,int,float&);
        void decayHealth(int,int,float&);
        void decayStructures(int,int,float&);
        void decayResources(int,int,float&);

        void decayPopulation();

        Avenue *getAvenue(int type);

        int getStat(int) const;
        int getPopulation() const;
        int getResources() const;
        
        void setResources(int);

        void setStat(int,float);
        void changeStat(int type, int increase);
        void decayStats();

        void initializeStats();
        void addTaskResources(RobotFunction, time_t, int);

        int getElapsedTimeTicks();
    };

    void *runDecay (void *decayFuncObject);
} // namespace Application