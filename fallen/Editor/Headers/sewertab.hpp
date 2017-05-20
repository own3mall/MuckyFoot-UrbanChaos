// TexTab.hpp
// Guy Simmons, 20th February 1997

#ifndef	_SewerTab_HPP_
#define	_SewerTab_HPP_

#include	"ModeTab.hpp"
#include	"Stealth.h"
#include	"EditMod.hpp"
#include	"undo.hpp"


#define	FLAG_WINDOW_USED		(1<<0)
#define	FLAG_WINDOW_LEDGE		(1<<1)
#define	FLAG_WINDOW_FAT_LEDGE	(1<<2)
#define	FLAG_WINDOW_WIDE_LEDGE	(1<<3)
#define	FLAG_WINDOW_SUNK_IN		(1<<4)
#define	FLAG_WINDOW_FLAT		(1<<5)
#define	FLAG_WINDOW_EDGED		(1<<6)
#define	FLAG_WINDOW_EDGED_DEEP	(1<<7)
#define	FLAG_WINDOW_EDGED_FAT	(1<<8)


/*
#define	FLAG_WINDOW_	(1<<)
*/

/*
#define	FLAG_WALL_			(1<<)
*/

/*
#define	FLAG_STOREY_		(1<<)
*/

#define	FLAG_BUILDING_
/*
#define	FLAG_BUILDING_
*/




#define	PASTE_TEXTURE	(1<<0)
#define	PASTE_ALTITUDE	(1<<1)


extern	SWORD	get_new_storey(void);
extern	void	free_wall(SWORD wall);
extern	SWORD	get_new_building(void);
extern	SWORD	get_new_wall(void);







class	SewerTab	:	public	ModeTab
{
	private:
		SLONG				Axis;
		SLONG				GridFlag;
		UBYTE				AxisMode;
		EdRect				View1;
		EdRect				View2;
		EdRect				View3;
		UBYTE				RedrawTabContent;
		SLONG				X1,Y1,Z1,X2,Y2,Z2;
		SLONG				FloorHead;
		SLONG				EditWindow;
		SLONG				EditY;
		SLONG				CurrentY;
		SLONG				ViewX,ViewY,ViewZ;
		SLONG				ViewSize;
		SLONG				RoomID;

	public:
							SewerTab(EditorModule *parent);
							~SewerTab();
		void				DrawTabContent(void);
		void				HandleTab(MFPoint *current_point);
		UWORD				HandleTabClick(UBYTE flags,MFPoint *clicked_point);
		void				HandleControl(UWORD control_id);
		void				DrawModuleContent(SLONG x,SLONG y,SLONG w,SLONG h);
		SLONG				HandleModuleContentClick(MFPoint	*clicked_point,UBYTE flags,SLONG x,SLONG y,SLONG w,SLONG h);
		SLONG				SetWorldMouse(ULONG flag);
		SLONG				KeyboardInterface(void);
		SLONG				DragEngine(UBYTE flags,MFPoint *clicked_point);
		SLONG				CalcMapCoord(SLONG	*mapx,SLONG	*mapy,SLONG	*mapz,SLONG	x,SLONG	y,SLONG	w,SLONG	h,MFPoint	*clicked_point);
		SLONG				DragPaint(UBYTE flags);
		SLONG				DragMark(UBYTE flags);
		SLONG				DragVertex(UBYTE flags);
		SLONG				DragBuilding(UBYTE flags,UBYTE type);
		SLONG				DragStairs(UWORD stairs,UBYTE flags);

		SLONG				MouseInContent(void);
		SLONG				DoKeys(void);
		SLONG  				DoZoom(void);
		void				HighlightVertexes(SLONG x,SLONG y,SLONG w,SLONG h);
		SLONG				ClickInVertexStoreyList(SLONG building,SLONG storey_index,SLONG w,SLONG h,MFPoint	*mouse_point);
		SLONG				ClickInVertex(SLONG x,SLONG y,SLONG w,SLONG h,MFPoint	*mouse_point);
		SLONG				ClickNearWall(SLONG x,SLONG y,SLONG w,SLONG h,MFPoint	*mouse_point);
		SLONG				WallOptions(void);
		SLONG				RoofOptions(void);
		SLONG				FenceOptions(void);
		void				DeleteVertex(void);
		void				AddHeightOffset(SLONG *x,SLONG *y);
		SLONG				GetHeightColour(SLONG storey);
		void				DrawContentLine(SLONG x1,SLONG y1,SLONG x2,SLONG y2,SLONG col);
		void				DrawContentLineY(SLONG x1,SLONG y1,SLONG z1,SLONG x2,SLONG y2,SLONG z2,SLONG col);

		SLONG				DrawWall(SLONG px,SLONG pz,SLONG x1,SLONG z1,SLONG index,SLONG storey);
		SLONG				DrawWindow(SLONG px,SLONG pz,SLONG x1,SLONG z1,SLONG dx,SLONG dz);
		void				DrawRoofFaces(SLONG roof,SLONG storey);
		void				DrawFloorFaces(SLONG wall);
		void				CheckStoreyIntegrity(UWORD storey);
		void				ResetSewerTab(void);
		void				DrawFloorTextures(SLONG x,SLONG y,SLONG w,SLONG h);
		void				DrawFloorLabels(SLONG x,SLONG y,SLONG w,SLONG h);
		inline	void		SetViewToEngine(void)	{ViewX=(engine.X>>8)&ELE_AND;ViewY=(engine.Y>>8)&ELE_AND;ViewZ=(engine.Z>>8)&ELE_AND;}
		inline	void		SetEngineToView(void)	{engine.X=ViewX<<8;engine.Y=ViewY<<8;engine.Z=ViewZ<<8;}
		inline	void		SetView(SLONG x,SLONG z)	{ViewX=x;ViewZ=z;}
		void				DrawContentRect(SLONG x1,SLONG z1,SLONG x2,SLONG z2,SLONG col);
		void				DoStairPopUp(SLONG stair,MFPoint *clicked_point);
//		Undo				MyUndo;
		UBYTE				RedrawModuleContent;
		void				Clear(void);
		UWORD				Mode;
		SLONG				EditBuilding;
		SLONG				EditStorey;
		SLONG				EditWall;
		SLONG				OutsideEditStorey;
		SLONG				OutsideEditWall;
		UWORD				Texture;
		UWORD				RoofTop;
		UWORD				CurrentFloorType;
		EditorModule		*Parent;
};



#endif

