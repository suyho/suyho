//�Q�[���̏��
enum GAMESTATE
{
	STATE_TITLE=1,//�^�C�g�����
	STATE_GAME,//�v���C���
	STATE_GAMEOVER,//�Q�[���I�[�o�[���
};

//���@�̏��
enum MOVESTATE
{
	JIKI_STATE_IDLE=0,//�ҋ@
	JIKI_STATE_FORWARD,//�O�i
	JIKI_STATE_BACKWARD,//���
	JIKI_STATE_JUMP,//����
	JIKI_STATE_FORJUMP,//�O����
	JIKI_STATE_BACKJUMP,//��뒵��
};

//�L�����̎��
enum KINDSTATE
{
	KIND_NONE=0,//��
	KIND_JIKI,//���@
	KIND_GROUND,//�n��
	KIND_WALL,//��
};

#define GROUND_Y 20	//�n��
#define GAMECHAR_NUM 100//�L�����̐�����


struct GAMECHAR
{
	int kind;	//���
	int x;	//X���W
	int y;	//Y���W
	int vy;	//Y���x
	int state;	//���
	int frame;	//�t���[��
};

extern int gFrame;//�v���C��ʂ̃t���[��
extern struct GAMECHAR gGamechars[GAMECHAR_NUM]; //���@���ϐ��錾