#pragma once

enum ESceneType
{
	None,
	EST_START,
	EST_LOADING,
	EST_PLAYER_SETTING,
	EST_TOWN,
	EST_SHOP,
	EST_JOB_CENTER,
	EST_SELECT_STAGE,
	EST_DUNGEON,
	EST_BOSS,
	EST_END,
};

class SceneBase
{
	public:
		SceneBase() {};
		virtual ~SceneBase() {};

		virtual void Init() abstract;
};