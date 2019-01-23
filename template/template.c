//
// Created by koncord on 08.01.19.
//

//#include <api.h>
#include <Functions/Chat.h>
#include <Functions/Stats.h>
#include <Functions/Miscellaneous.h>
#include <stdio.h>

void OnServerInit()
{
    printf("Server Initialized.\n");
}

void OnServerPostInit()
{

}

void OnServerExit(bool code)
{
    LogMessage(0, "Server closed.");
}

void OnPlayerConnect(PlayerId pid)
{
    char msg[256];
    snprintf(msg, 256, "Hello %s!", GetName(pid));
    bool sendToOtherPlayers = false;
    bool skipAttachedPlayer = false;
    SendMessage(pid, msg, sendToOtherPlayers, skipAttachedPlayer);
}

void OnPlayerDisconnect(PlayerId pid)
{
    char msg[256];
    snprintf(msg, 256, "Player %s disconnected.", GetName(pid));
    LogMessage(1, msg);
}

void OnPlayerDeath(PlayerId pid)
{

}

void OnPlayerResurrect(PlayerId pid)
{

}

void OnPlayerCellChange(PlayerId pid)
{

}

void OnPlayerAttribute(PlayerId pid)
{

}

void OnPlayerSkill(PlayerId pid)
{

}

void OnPlayerLevel(PlayerId pid)
{

}

void OnPlayerBounty(PlayerId pid)
{

}

void OnPlayerReputation(PlayerId pid)
{

}

void OnPlayerEquipment(PlayerId pid)
{

}

void OnPlayerInventory(PlayerId pid)
{

}

void OnPlayerJournal(PlayerId pid)
{

}

void OnPlayerFaction(PlayerId pid)
{

}

void OnPlayerShapeshift(PlayerId pid)
{

}

void OnPlayerQuickKeys(PlayerId pid)
{

}

void OnPlayerTopic(PlayerId pid)
{

}

void OnPlayerDisposition(PlayerId pid)
{

}

void OnPlayerBook(PlayerId pid)
{

}

void OnPlayerItemUse(PlayerId pid)
{

}

void OnPlayerMiscellaneous(PlayerId pid)
{

}

void OnPlayerInput(PlayerId pid)
{

}

void OnPlayerRest(PlayerId pid)
{

}

void OnRecordDynamic(PlayerId pid)
{

}

void OnCellLoad(PlayerId pid, const char *cellDescription)
{

}

void OnCellUnload(PlayerId pid, const char *cellDescription)
{

}

void OnCellDeletion(const char *cellDescription)
{

}

void OnContainer(PlayerId pid, const char *cellDescription)
{

}

void OnDoorState(PlayerId pid, const char *cellDescription)
{

}

void OnObjectActivate(PlayerId pid, const char *cellDescription)
{

}

void OnObjectPlace(PlayerId pid, const char *cellDescription)
{

}

void OnObjectState(PlayerId pid, const char *cellDescription)
{

}

void OnObjectSpawn(PlayerId pid, const char *cellDescription)
{

}

void OnObjectDelete(PlayerId pid, const char *cellDescription)
{

}

void OnObjectLock(PlayerId pid, const char *cellDescription)
{

}

void OnObjectScale(PlayerId pid, const char *cellDescription)
{

}

void OnObjectTrap(PlayerId pid, const char *cellDescription)
{

}

void OnVideoPlay(PlayerId pid, const char *cellDescription)
{

}

void OnActorList(PlayerId pid, const char *cellDescription)
{

}

void OnActorEquipment(PlayerId pid, const char *cellDescription)
{

}

void OnActorAI(PlayerId pid, const char *cellDescription)
{

}

void OnActorDeath(PlayerId pid, const char *cellDescription)
{

}

void OnActorCellChange(PlayerId pid, const char *cellDescription)
{

}

void OnActorTest(PlayerId pid, const char *cellDescription)
{

}

void OnPlayerSendMessage(PlayerId pid, const char *message)
{

}

void OnPlayerEndCharGen(PlayerId pid)
{

}

void OnGUIAction(PlayerId pid, const char *data)
{

}

void OnWorldKillCount(PlayerId pid)
{

}

void OnWorldMap(PlayerId pid)
{

}

void OnWorldWeather(PlayerId pid)
{

}

void OnMpNumIncrement(int mpNum)
{

}

void OnRequestPluginList()
{

}

int PluginInit()
{
    return 1;
}

void PluginFree()
{

}
