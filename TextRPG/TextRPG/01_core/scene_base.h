#pragma once

enum ESceneType
{
	None,
	EST_START,
	EST_LOADING,
	EST_TOWN,
	EST_SELECT_STAGE,
	EST_DUNGEON
};

class SceneBase
{
	public:
		SceneBase() {};
		virtual ~SceneBase() {};

		virtual void Init() abstract;
};