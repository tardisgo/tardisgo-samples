#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_CapsStyle
#include <flash/display/CapsStyle.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_JointStyle
#include <flash/display/JointStyle.h>
#endif
#ifndef INCLUDED_flash_display_LineScaleMode
#include <flash/display/LineScaleMode.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_flash_utils_Timer
#include <flash/utils/Timer.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_tardis_Go
#include <tardis/Go.h>
#endif
#ifndef INCLUDED_tardis_Go_main_MouseDown
#include <tardis/Go_main_MouseDown.h>
#endif
#ifndef INCLUDED_tardis_Go_main_MouseGoroutine
#include <tardis/Go_main_MouseGoroutine.h>
#endif
#ifndef INCLUDED_tardis_Go_main_MouseMove
#include <tardis/Go_main_MouseMove.h>
#endif
#ifndef INCLUDED_tardis_Go_main_MouseUp
#include <tardis/Go_main_MouseUp.h>
#endif
#ifndef INCLUDED_tardis_Scheduler
#include <tardis/Scheduler.h>
#endif
#ifndef INCLUDED_tardis_StackFrame
#include <tardis/StackFrame.h>
#endif
#ifndef INCLUDED_tardis_StackFrameBasis
#include <tardis/StackFrameBasis.h>
#endif

Void Main_obj::__construct()
{
HX_STACK_PUSH("Main::new","Main.hx",24);
{
	HX_STACK_LINE(26)
	super::__construct();
	HX_STACK_LINE(28)
	this->Logo = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(29)
	this->Logo->addChild(::flash::display::Bitmap_obj::__new(::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/openfl.png"),null()),null(),null()));
	HX_STACK_LINE(30)
	this->Logo->set_x((int)100);
	HX_STACK_LINE(31)
	this->Logo->set_y((int)100);
	HX_STACK_LINE(32)
	this->Logo->buttonMode = true;
	HX_STACK_LINE(34)
	this->Destination = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(35)
	this->Destination->get_graphics()->beginFill((int)16119285,null());
	HX_STACK_LINE(36)
	this->Destination->get_graphics()->lineStyle((int)1,(int)13421772,null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(37)
	this->Destination->get_graphics()->drawRect((int)0,(int)0,(this->Logo->get_width() + (int)10),(this->Logo->get_height() + (int)10));
	HX_STACK_LINE(38)
	this->Destination->set_x((int)300);
	HX_STACK_LINE(39)
	this->Destination->set_y((int)95);
	HX_STACK_LINE(41)
	this->addChild(this->Destination);
	HX_STACK_LINE(42)
	this->addChild(this->Logo);
	HX_STACK_LINE(44)
	this->Logo->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->Logo_onMouseDown_dyn(),null(),null(),null());
	HX_STACK_LINE(46)
	{
		HX_STACK_LINE(46)
		if ((!(::tardis::Go_obj::doneInit))){
			HX_STACK_LINE(46)
			::tardis::Go_obj::init();
		}
		HX_STACK_LINE(46)
		::tardis::Go_main_MouseGoroutine _sf = hx::TCast< ::tardis::Go_main_MouseGoroutine >::cast(::tardis::Go_main_MouseGoroutine_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
		HX_STACK_LINE(46)
		while((_sf->_incomplete)){
			HX_STACK_LINE(46)
			::tardis::Scheduler_obj::runAll();
		}
	}
	HX_STACK_LINE(47)
	this->goTimer = ::flash::utils::Timer_obj::__new((int)100,null());
	HX_STACK_LINE(48)
	this->goTimer->addEventListener(HX_CSTRING("timer"),::tardis::Scheduler_obj::timerEventHandler_dyn(),null(),null(),null());
	HX_STACK_LINE(49)
	this->goTimer->start();
}
;
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::stage_onMouseUp( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Main::stage_onMouseUp","Main.hx",86);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(96)
		this->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->stage_onMouseMove_dyn(),null());
		HX_STACK_LINE(97)
		this->get_stage()->removeEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->stage_onMouseUp_dyn(),null());
		HX_STACK_LINE(99)
		{
			HX_STACK_LINE(99)
			if ((!(::tardis::Go_obj::doneInit))){
				HX_STACK_LINE(99)
				::tardis::Go_obj::init();
			}
			HX_STACK_LINE(99)
			::tardis::Go_main_MouseUp _sf = hx::TCast< ::tardis::Go_main_MouseUp >::cast(::tardis::Go_main_MouseUp_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
			HX_STACK_LINE(99)
			while((_sf->_incomplete)){
				HX_STACK_LINE(99)
				::tardis::Scheduler_obj::runAll();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onMouseUp,(void))

Void Main_obj::stage_onMouseMove( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Main::stage_onMouseMove","Main.hx",75);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(77)
		this->Logo->set_x((event->stageX + this->cacheOffsetX));
		HX_STACK_LINE(78)
		this->Logo->set_y((event->stageY + this->cacheOffsetY));
		HX_STACK_LINE(80)
		{
			HX_STACK_LINE(80)
			if ((!(::tardis::Go_obj::doneInit))){
				HX_STACK_LINE(80)
				::tardis::Go_obj::init();
			}
			HX_STACK_LINE(80)
			::tardis::Go_main_MouseMove _sf = hx::TCast< ::tardis::Go_main_MouseMove >::cast(::tardis::Go_main_MouseMove_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
			HX_STACK_LINE(80)
			while((_sf->_incomplete)){
				HX_STACK_LINE(80)
				::tardis::Scheduler_obj::runAll();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onMouseMove,(void))

Void Main_obj::Logo_onMouseDown( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Main::Logo_onMouseDown","Main.hx",61);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(63)
		this->cacheOffsetX = (this->Logo->get_x() - event->stageX);
		HX_STACK_LINE(64)
		this->cacheOffsetY = (this->Logo->get_y() - event->stageY);
		HX_STACK_LINE(66)
		this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->stage_onMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(67)
		this->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->stage_onMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(69)
		{
			HX_STACK_LINE(69)
			if ((!(::tardis::Go_obj::doneInit))){
				HX_STACK_LINE(69)
				::tardis::Go_obj::init();
			}
			HX_STACK_LINE(69)
			::tardis::Go_main_MouseDown _sf = hx::TCast< ::tardis::Go_main_MouseDown >::cast(::tardis::Go_main_MouseDown_obj::__new((int)0,Dynamic( Array_obj<Dynamic>::__new()))->run());		HX_STACK_VAR(_sf,"_sf");
			HX_STACK_LINE(69)
			while((_sf->_incomplete)){
				HX_STACK_LINE(69)
				::tardis::Scheduler_obj::runAll();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,Logo_onMouseDown,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(goTimer,"goTimer");
	HX_MARK_MEMBER_NAME(cacheOffsetY,"cacheOffsetY");
	HX_MARK_MEMBER_NAME(cacheOffsetX,"cacheOffsetX");
	HX_MARK_MEMBER_NAME(Destination,"Destination");
	HX_MARK_MEMBER_NAME(Logo,"Logo");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(goTimer,"goTimer");
	HX_VISIT_MEMBER_NAME(cacheOffsetY,"cacheOffsetY");
	HX_VISIT_MEMBER_NAME(cacheOffsetX,"cacheOffsetX");
	HX_VISIT_MEMBER_NAME(Destination,"Destination");
	HX_VISIT_MEMBER_NAME(Logo,"Logo");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Logo") ) { return Logo; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"goTimer") ) { return goTimer; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Destination") ) { return Destination; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cacheOffsetY") ) { return cacheOffsetY; }
		if (HX_FIELD_EQ(inName,"cacheOffsetX") ) { return cacheOffsetX; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stage_onMouseUp") ) { return stage_onMouseUp_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"Logo_onMouseDown") ) { return Logo_onMouseDown_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"stage_onMouseMove") ) { return stage_onMouseMove_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Logo") ) { Logo=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"goTimer") ) { goTimer=inValue.Cast< ::flash::utils::Timer >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Destination") ) { Destination=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"cacheOffsetY") ) { cacheOffsetY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"cacheOffsetX") ) { cacheOffsetX=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("goTimer"));
	outFields->push(HX_CSTRING("cacheOffsetY"));
	outFields->push(HX_CSTRING("cacheOffsetX"));
	outFields->push(HX_CSTRING("Destination"));
	outFields->push(HX_CSTRING("Logo"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("stage_onMouseUp"),
	HX_CSTRING("stage_onMouseMove"),
	HX_CSTRING("Logo_onMouseDown"),
	HX_CSTRING("goTimer"),
	HX_CSTRING("cacheOffsetY"),
	HX_CSTRING("cacheOffsetX"),
	HX_CSTRING("Destination"),
	HX_CSTRING("Logo"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Main_obj::__boot()
{
}

