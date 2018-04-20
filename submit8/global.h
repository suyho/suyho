//ゲームの状態
enum GAMESTATE
{
	STATE_TITLE=1,//タイトル画面
	STATE_GAME,//プレイ画面
	STATE_GAMEOVER,//ゲームオーバー画面
};

//自機の状態
enum MOVESTATE
{
	JIKI_STATE_IDLE=0,//待機
	JIKI_STATE_FORWARD,//前進
	JIKI_STATE_BACKWARD,//後退
	JIKI_STATE_JUMP,//跳躍
	JIKI_STATE_FORJUMP,//前跳躍
	JIKI_STATE_BACKJUMP,//後ろ跳躍
};

//キャラの種類
enum KINDSTATE
{
	KIND_NONE=0,//空
	KIND_JIKI,//自機
	KIND_GROUND,//地面
	KIND_WALL,//壁
};

#define GROUND_Y 20	//地面
#define GAMECHAR_NUM 100//キャラの数制限


struct GAMECHAR
{
	int kind;	//種類
	int x;	//X座標
	int y;	//Y座標
	int vy;	//Y速度
	int state;	//状態
	int frame;	//フレーム
};

extern int gFrame;//プレイ画面のフレーム
extern struct GAMECHAR gGamechars[GAMECHAR_NUM]; //仮　大域変数宣言