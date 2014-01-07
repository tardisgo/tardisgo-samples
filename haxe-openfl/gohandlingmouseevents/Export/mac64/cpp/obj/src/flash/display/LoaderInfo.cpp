#include <hxcpp.h>

#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Loader
#include <flash/display/Loader.h>
#endif
#ifndef INCLUDED_flash_display_LoaderInfo
#include <flash/display/LoaderInfo.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
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
#ifndef INCLUDED_flash_events_UncaughtErrorEvents
#include <flash/events/UncaughtErrorEvents.h>
#endif
#ifndef INCLUDED_flash_net_URLLoader
#include <flash/net/URLLoader.h>
#endif
#ifndef INCLUDED_flash_net_URLLoaderDataFormat
#include <flash/net/URLLoaderDataFormat.h>
#endif
#ifndef INCLUDED_flash_net_URLRequest
#include <flash/net/URLRequest.h>
#endif
#ifndef INCLUDED_flash_system_ApplicationDomain
#include <flash/system/ApplicationDomain.h>
#endif
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_flash_utils_IDataOutput
#include <flash/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace flash{
namespace display{

Void LoaderInfo_obj::__construct()
{
HX_STACK_PUSH("LoaderInfo::new","flash/display/LoaderInfo.hx",37);
{
	HX_STACK_LINE(39)
	super::__construct(null());
	HX_STACK_LINE(41)
	this->applicationDomain = ::flash::system::ApplicationDomain_obj::currentDomain;
	HX_STACK_LINE(42)
	this->childAllowsParent = true;
	HX_STACK_LINE(43)
	this->frameRate = (int)0;
	HX_STACK_LINE(44)
	this->dataFormat = ::flash::net::URLLoaderDataFormat_obj::BINARY;
	HX_STACK_LINE(45)
	this->loaderURL = null();
	HX_STACK_LINE(46)
	this->addEventListener(::flash::events::Event_obj::COMPLETE,this->this_onComplete_dyn(),null(),null(),null());
}
;
	return null();
}

LoaderInfo_obj::~LoaderInfo_obj() { }

Dynamic LoaderInfo_obj::__CreateEmpty() { return  new LoaderInfo_obj; }
hx::ObjectPtr< LoaderInfo_obj > LoaderInfo_obj::__new()
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

Dynamic LoaderInfo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< LoaderInfo_obj > result = new LoaderInfo_obj();
	result->__construct();
	return result;}

::flash::utils::ByteArray LoaderInfo_obj::get_bytes( ){
	HX_STACK_PUSH("LoaderInfo::get_bytes","flash/display/LoaderInfo.hx",113);
	HX_STACK_THIS(this);
	HX_STACK_LINE(113)
	return this->data;
}


HX_DEFINE_DYNAMIC_FUNC0(LoaderInfo_obj,get_bytes,return )

Void LoaderInfo_obj::this_onComplete( ::flash::events::Event event){
{
		HX_STACK_PUSH("LoaderInfo::this_onComplete","flash/display/LoaderInfo.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(99)
		this->url = this->__pendingURL;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,this_onComplete,(void))

Void LoaderInfo_obj::load( ::flash::net::URLRequest request){
{
		HX_STACK_PUSH("LoaderInfo::load","flash/display/LoaderInfo.hx",68);
		HX_STACK_THIS(this);
		HX_STACK_ARG(request,"request");
		HX_STACK_LINE(70)
		this->__pendingURL = request->url;
		HX_STACK_LINE(71)
		int dot = this->__pendingURL.lastIndexOf(HX_CSTRING("."),null());		HX_STACK_VAR(dot,"dot");
		HX_STACK_LINE(72)
		::String extension = (  (((dot > (int)0))) ? ::String(this->__pendingURL.substr((dot + (int)1),null()).toLowerCase()) : ::String(HX_CSTRING("")) );		HX_STACK_VAR(extension,"extension");
		struct _Function_1_1{
			inline static ::String Block( ::flash::display::LoaderInfo_obj *__this,::String &extension){
				HX_STACK_PUSH("*::closure","flash/display/LoaderInfo.hx",74);
				{
					HX_STACK_LINE(74)
					::String _switch_1 = (extension);
					if (  ( _switch_1==HX_CSTRING("swf"))){
						HX_STACK_LINE(76)
						return HX_CSTRING("application/x-shockwave-flash");
					}
					else if (  ( _switch_1==HX_CSTRING("jpg")) ||  ( _switch_1==HX_CSTRING("jpeg"))){
						HX_STACK_LINE(77)
						return HX_CSTRING("image/jpeg");
					}
					else if (  ( _switch_1==HX_CSTRING("png"))){
						HX_STACK_LINE(78)
						return HX_CSTRING("image/png");
					}
					else if (  ( _switch_1==HX_CSTRING("gif"))){
						HX_STACK_LINE(79)
						return HX_CSTRING("image/gif");
					}
					else  {
						HX_STACK_LINE(80)
						return hx::Throw ((HX_CSTRING("Unrecognized file ") + __this->__pendingURL));
					}
;
;
				}
				return null();
			}
		};
		HX_STACK_LINE(74)
		this->contentType = _Function_1_1::Block(this,extension);
		HX_STACK_LINE(85)
		this->url = null();
		HX_STACK_LINE(87)
		this->super::load(request);
	}
return null();
}


::flash::display::LoaderInfo LoaderInfo_obj::create( ::flash::display::Loader loader){
	HX_STACK_PUSH("LoaderInfo::create","flash/display/LoaderInfo.hx",51);
	HX_STACK_ARG(loader,"loader");
	HX_STACK_LINE(53)
	::flash::display::LoaderInfo loaderInfo = ::flash::display::LoaderInfo_obj::__new();		HX_STACK_VAR(loaderInfo,"loaderInfo");
	HX_STACK_LINE(54)
	loaderInfo->loader = loader;
	HX_STACK_LINE(55)
	loaderInfo->uncaughtErrorEvents = ::flash::events::UncaughtErrorEvents_obj::__new(null());
	HX_STACK_LINE(57)
	if (((loader == null()))){
		HX_STACK_LINE(57)
		loaderInfo->url = HX_CSTRING("");
	}
	HX_STACK_LINE(63)
	return loaderInfo;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(LoaderInfo_obj,create,return )


LoaderInfo_obj::LoaderInfo_obj()
{
}

void LoaderInfo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(LoaderInfo);
	HX_MARK_MEMBER_NAME(__pendingURL,"__pendingURL");
	HX_MARK_MEMBER_NAME(uncaughtErrorEvents,"uncaughtErrorEvents");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(url,"url");
	HX_MARK_MEMBER_NAME(sharedEvents,"sharedEvents");
	HX_MARK_MEMBER_NAME(sameDomain,"sameDomain");
	HX_MARK_MEMBER_NAME(parentAllowsChild,"parentAllowsChild");
	HX_MARK_MEMBER_NAME(parameters,"parameters");
	HX_MARK_MEMBER_NAME(loaderURL,"loaderURL");
	HX_MARK_MEMBER_NAME(loader,"loader");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(frameRate,"frameRate");
	HX_MARK_MEMBER_NAME(contentType,"contentType");
	HX_MARK_MEMBER_NAME(content,"content");
	HX_MARK_MEMBER_NAME(childAllowsParent,"childAllowsParent");
	HX_MARK_MEMBER_NAME(bytes,"bytes");
	HX_MARK_MEMBER_NAME(applicationDomain,"applicationDomain");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void LoaderInfo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__pendingURL,"__pendingURL");
	HX_VISIT_MEMBER_NAME(uncaughtErrorEvents,"uncaughtErrorEvents");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(url,"url");
	HX_VISIT_MEMBER_NAME(sharedEvents,"sharedEvents");
	HX_VISIT_MEMBER_NAME(sameDomain,"sameDomain");
	HX_VISIT_MEMBER_NAME(parentAllowsChild,"parentAllowsChild");
	HX_VISIT_MEMBER_NAME(parameters,"parameters");
	HX_VISIT_MEMBER_NAME(loaderURL,"loaderURL");
	HX_VISIT_MEMBER_NAME(loader,"loader");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(frameRate,"frameRate");
	HX_VISIT_MEMBER_NAME(contentType,"contentType");
	HX_VISIT_MEMBER_NAME(content,"content");
	HX_VISIT_MEMBER_NAME(childAllowsParent,"childAllowsParent");
	HX_VISIT_MEMBER_NAME(bytes,"bytes");
	HX_VISIT_MEMBER_NAME(applicationDomain,"applicationDomain");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic LoaderInfo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { return url; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"bytes") ) { return inCallProp ? get_bytes() : bytes; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"loader") ) { return loader; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { return content; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"get_bytes") ) { return get_bytes_dyn(); }
		if (HX_FIELD_EQ(inName,"loaderURL") ) { return loaderURL; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { return frameRate; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sameDomain") ) { return sameDomain; }
		if (HX_FIELD_EQ(inName,"parameters") ) { return parameters; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { return contentType; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__pendingURL") ) { return __pendingURL; }
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { return sharedEvents; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"this_onComplete") ) { return this_onComplete_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { return parentAllowsChild; }
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { return childAllowsParent; }
		if (HX_FIELD_EQ(inName,"applicationDomain") ) { return applicationDomain; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"uncaughtErrorEvents") ) { return uncaughtErrorEvents; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic LoaderInfo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"url") ) { url=inValue.Cast< ::String >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytes") ) { bytes=inValue.Cast< ::flash::utils::ByteArray >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"loader") ) { loader=inValue.Cast< ::flash::display::Loader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"content") ) { content=inValue.Cast< ::flash::display::DisplayObject >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"loaderURL") ) { loaderURL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"frameRate") ) { frameRate=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sameDomain") ) { sameDomain=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parameters") ) { parameters=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"contentType") ) { contentType=inValue.Cast< ::String >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__pendingURL") ) { __pendingURL=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sharedEvents") ) { sharedEvents=inValue.Cast< ::flash::events::EventDispatcher >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"parentAllowsChild") ) { parentAllowsChild=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"childAllowsParent") ) { childAllowsParent=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"applicationDomain") ) { applicationDomain=inValue.Cast< ::flash::system::ApplicationDomain >(); return inValue; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"uncaughtErrorEvents") ) { uncaughtErrorEvents=inValue.Cast< ::flash::events::UncaughtErrorEvents >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void LoaderInfo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__pendingURL"));
	outFields->push(HX_CSTRING("uncaughtErrorEvents"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("url"));
	outFields->push(HX_CSTRING("sharedEvents"));
	outFields->push(HX_CSTRING("sameDomain"));
	outFields->push(HX_CSTRING("parentAllowsChild"));
	outFields->push(HX_CSTRING("parameters"));
	outFields->push(HX_CSTRING("loaderURL"));
	outFields->push(HX_CSTRING("loader"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("frameRate"));
	outFields->push(HX_CSTRING("contentType"));
	outFields->push(HX_CSTRING("content"));
	outFields->push(HX_CSTRING("childAllowsParent"));
	outFields->push(HX_CSTRING("bytes"));
	outFields->push(HX_CSTRING("applicationDomain"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("create"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_bytes"),
	HX_CSTRING("this_onComplete"),
	HX_CSTRING("load"),
	HX_CSTRING("__pendingURL"),
	HX_CSTRING("uncaughtErrorEvents"),
	HX_CSTRING("width"),
	HX_CSTRING("url"),
	HX_CSTRING("sharedEvents"),
	HX_CSTRING("sameDomain"),
	HX_CSTRING("parentAllowsChild"),
	HX_CSTRING("parameters"),
	HX_CSTRING("loaderURL"),
	HX_CSTRING("loader"),
	HX_CSTRING("height"),
	HX_CSTRING("frameRate"),
	HX_CSTRING("contentType"),
	HX_CSTRING("content"),
	HX_CSTRING("childAllowsParent"),
	HX_CSTRING("bytes"),
	HX_CSTRING("applicationDomain"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(LoaderInfo_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(LoaderInfo_obj::__mClass,"__mClass");
};

Class LoaderInfo_obj::__mClass;

void LoaderInfo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.display.LoaderInfo"), hx::TCanCast< LoaderInfo_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void LoaderInfo_obj::__boot()
{
}

} // end namespace flash
} // end namespace display
