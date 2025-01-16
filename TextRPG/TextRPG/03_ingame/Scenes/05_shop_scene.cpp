#include "05_shop_scene.h"
#include "../../04_Util/gui.h"
#include "../../04_Util/util.h"
#include "../../02_manager/player_manager.h"
#include "../../02_manager/scene_manager.h"
#include "../../02_manager/shop_manager.h"
void ShopScene::Init()
{
	SceneManager::GetInstance()->SetStageProgress(2);

	DrawMainLayout();
	SelectCommand();
}

void ShopScene::DrawMainLayout()
{
	GUI::DrawInGameBox();

	string sceneTitle = ustring("🏪 상점");
	GUI::SettingTitle(sceneTitle);

	string playerName = PlayerManager::GetInstance()->GetPlayer().GetName();
	GUI::DrawNamingBox(playerName);

	// 골드표시

	string dungeon = ustring("1. 💣폭탄(데미지+)");
	string shop = ustring("2. 🍷HP포션(체력회복+)");
	string jobChangeCenter = ustring("3. 🧪DMG포션(데미지증가+)");
	vector<string> boxNames = { dungeon, shop, jobChangeCenter };
	GUI::DrawSelectBox(boxNames);

	string questionText1 = ustring("상점에 오신걸 환영합니다.");
	string questionText2 = ustring("원하는 행동을 입력하세요.");
	string questionText3 = ustring("1. 구매 2. 판매 3. 강화 4. 나가기");
	vector<string> questionTexts = { questionText1, questionText2, questionText3 };
	GUI::DrawQuestionText(questionTexts);

	GUI::GoToXY(8, 27);
}

void ShopScene::SelectCommand()
{
    int num;
    Inventory* inven = PlayerManager::GetInstance()->GetPlayer().GetInventory();
    while (true)
    {
        num = UTIL::IntegerVerify(num, 1, 4);

        switch (num)
        {
        case 1:
            ShopManager::GetInstance()->BuyItem(inven);
            break;
        case 2:
            ShopManager::GetInstance()->SellItem(inven);
            break;
        case 3:
            UTIL::UPrintEndl("아직 준비되지 않았습니다.");
            break;
        case 4:
            SceneManager::GetInstance()->LoadScene(EST_LOADING);
            return;
        default:
            UTIL::UPrintEndl("잘못된 입력입니다.");
            break;
        }
    }
}
