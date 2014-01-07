#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_events_ErrorEvent
#include <flash/events/ErrorEvent.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_HTTPStatusEvent
#include <flash/events/HTTPStatusEvent.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IOErrorEvent
#include <flash/events/IOErrorEvent.h>
#endif
#ifndef INCLUDED_flash_events_ProgressEvent
#include <flash/events/ProgressEvent.h>
#endif
#ifndef INCLUDED_flash_events_TextEvent
#include <flash/events/TextEvent.h>
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
#ifndef INCLUDED_flash_net_URLVariables
#include <flash/net/URLVariables.h>
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
namespace net{

Void URLLoader_obj::__construct(::flash::net::URLRequest request)
{
HX_STACK_PUSH("URLLoader::new","flash/net/URLLoader.hx",35);
{
	HX_STACK_LINE(37)
	super::__construct(null());
	HX_STACK_LINE(39)
	this->__handle = (int)0;
	HX_STACK_LINE(40)
	this->bytesLoaded = (int)0;
	HX_STACK_LINE(41)
	this->bytesTotal = (int)-1;
	HX_STACK_LINE(42)
	this->state = (int)0;
	HX_STACK_LINE(43)
	this->dataFormat = ::flash::net::URLLoaderDataFormat_obj::TEXT;
	HX_STACK_LINE(45)
	if (((request != null()))){
		HX_STACK_LINE(45)
		this->load(request);
	}
}
;
	return null();
}

URLLoader_obj::~URLLoader_obj() { }

Dynamic URLLoader_obj::__CreateEmpty() { return  new URLLoader_obj; }
hx::ObjectPtr< URLLoader_obj > URLLoader_obj::__new(::flash::net::URLRequest request)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(request);
	return result;}

Dynamic URLLoader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< URLLoader_obj > result = new URLLoader_obj();
	result->__construct(inArgs[0]);
	return result;}

Void URLLoader_obj::__dataComplete( ){
{
		HX_STACK_PUSH("URLLoader::__dataComplete","flash/net/URLLoader.hx",215);
		HX_STACK_THIS(this);
		HX_STACK_LINE(217)
		::flash::net::URLLoader_obj::activeLoaders->remove(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(219)
		if (((this->__onComplete_dyn() != null()))){
			HX_STACK_LINE(219)
			if ((this->__onComplete(this->data))){
				HX_STACK_LINE(221)
				this->dispatchEvent(::flash::events::Event_obj::__new(::flash::events::Event_obj::COMPLETE,null(),null()));
			}
			else{
				HX_STACK_LINE(225)
				this->__dispatchIOErrorEvent();
			}
		}
		else{
			HX_STACK_LINE(231)
			this->dispatchEvent(::flash::events::Event_obj::__new(::flash::events::Event_obj::COMPLETE,null(),null()));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,__dataComplete,(void))

Void URLLoader_obj::update( ){
{
		HX_STACK_PUSH("URLLoader::update","flash/net/URLLoader.hx",151);
		HX_STACK_THIS(this);
		HX_STACK_LINE(151)
		if (((this->__handle != null()))){
			HX_STACK_LINE(155)
			int old_loaded = this->bytesLoaded;		HX_STACK_VAR(old_loaded,"old_loaded");
			HX_STACK_LINE(156)
			int old_total = this->bytesTotal;		HX_STACK_VAR(old_total,"old_total");
			HX_STACK_LINE(157)
			::flash::net::URLLoader_obj::lime_curl_update_loader(this->__handle,hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(159)
			if (((bool((old_total < (int)0)) && bool((this->bytesTotal > (int)0))))){
				HX_STACK_LINE(159)
				this->dispatchEvent(::flash::events::Event_obj::__new(::flash::events::Event_obj::OPEN,null(),null()));
			}
			HX_STACK_LINE(165)
			if (((bool((this->bytesTotal > (int)0)) && bool((this->bytesLoaded != old_loaded))))){
				HX_STACK_LINE(165)
				this->dispatchEvent(::flash::events::ProgressEvent_obj::__new(HX_CSTRING("progress"),false,false,this->bytesLoaded,this->bytesTotal));
			}
			HX_STACK_LINE(171)
			int code = ::flash::net::URLLoader_obj::lime_curl_get_code(this->__handle);		HX_STACK_VAR(code,"code");
			HX_STACK_LINE(173)
			if (((this->state == (int)3))){
				HX_STACK_LINE(175)
				this->dispatchHTTPStatus(code);
				HX_STACK_LINE(177)
				if (((code < (int)400))){
					HX_STACK_LINE(179)
					::flash::utils::ByteArray bytes = ::flash::net::URLLoader_obj::lime_curl_get_data(this->__handle);		HX_STACK_VAR(bytes,"bytes");
					HX_STACK_LINE(181)
					{
						HX_STACK_LINE(181)
						::flash::net::URLLoader _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(181)
						{
							::flash::net::URLLoaderDataFormat _switch_1 = (_g->dataFormat);
							switch((_switch_1)->GetIndex()){
								case 1: case 2: {
									HX_STACK_LINE(183)
									this->data = (  (((bytes == null()))) ? Dynamic(HX_CSTRING("")) : Dynamic(bytes->asString()) );
								}
								;break;
								default: {
									HX_STACK_LINE(185)
									this->data = bytes;
								}
							}
						}
					}
					HX_STACK_LINE(190)
					this->__dataComplete();
				}
				else{
					HX_STACK_LINE(194)
					::flash::events::IOErrorEvent event = ::flash::events::IOErrorEvent_obj::__new(::flash::events::IOErrorEvent_obj::IO_ERROR,true,false,(HX_CSTRING("HTTP status code ") + ::Std_obj::string(code)),code);		HX_STACK_VAR(event,"event");
					HX_STACK_LINE(195)
					this->__handle = null();
					HX_STACK_LINE(196)
					this->dispatchEvent(event);
				}
			}
			else{
				HX_STACK_LINE(200)
				if (((this->state == (int)4))){
					HX_STACK_LINE(202)
					this->dispatchHTTPStatus(code);
					HX_STACK_LINE(204)
					::flash::events::IOErrorEvent event = ::flash::events::IOErrorEvent_obj::__new(::flash::events::IOErrorEvent_obj::IO_ERROR,true,false,::flash::net::URLLoader_obj::lime_curl_get_error_message(this->__handle),code);		HX_STACK_VAR(event,"event");
					HX_STACK_LINE(205)
					this->__handle = null();
					HX_STACK_LINE(206)
					this->dispatchEvent(event);
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,update,(void))

Void URLLoader_obj::dispatchHTTPStatus( int code){
{
		HX_STACK_PUSH("URLLoader::dispatchHTTPStatus","flash/net/URLLoader.hx",144);
		HX_STACK_THIS(this);
		HX_STACK_ARG(code,"code");
		HX_STACK_LINE(144)
		this->dispatchEvent(::flash::events::HTTPStatusEvent_obj::__new(::flash::events::HTTPStatusEvent_obj::HTTP_STATUS,false,false,code));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,dispatchHTTPStatus,(void))

Void URLLoader_obj::onError( ::String msg){
{
		HX_STACK_PUSH("URLLoader::onError","flash/net/URLLoader.hx",136);
		HX_STACK_THIS(this);
		HX_STACK_ARG(msg,"msg");
		HX_STACK_LINE(138)
		::flash::net::URLLoader_obj::activeLoaders->remove(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(139)
		this->dispatchEvent(::flash::events::IOErrorEvent_obj::__new(::flash::events::IOErrorEvent_obj::IO_ERROR,true,false,msg,null()));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,onError,(void))

Void URLLoader_obj::load( ::flash::net::URLRequest request){
{
		HX_STACK_PUSH("URLLoader::load","flash/net/URLLoader.hx",82);
		HX_STACK_THIS(this);
		HX_STACK_ARG(request,"request");
		HX_STACK_LINE(84)
		this->state = (int)1;
		HX_STACK_LINE(86)
		::String pref = request->url.substr((int)0,(int)7);		HX_STACK_VAR(pref,"pref");
		HX_STACK_LINE(87)
		if (((bool((pref != HX_CSTRING("http://"))) && bool((pref != HX_CSTRING("https:/")))))){
			HX_STACK_LINE(89)
			try{
				HX_STACK_LINE(91)
				::flash::utils::ByteArray bytes = ::flash::utils::ByteArray_obj::readFile(request->url);		HX_STACK_VAR(bytes,"bytes");
				HX_STACK_LINE(93)
				if (((bytes == null()))){
					HX_STACK_LINE(93)
					hx::Throw (((HX_CSTRING("Could not open file \"") + request->url) + HX_CSTRING("\"")));
				}
				HX_STACK_LINE(99)
				{
					HX_STACK_LINE(99)
					::flash::net::URLLoader _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(99)
					{
						::flash::net::URLLoaderDataFormat _switch_2 = (_g->dataFormat);
						switch((_switch_2)->GetIndex()){
							case 1: {
								HX_STACK_LINE(101)
								this->data = bytes->asString();
							}
							;break;
							case 2: {
								HX_STACK_LINE(102)
								this->data = ::flash::net::URLVariables_obj::__new(bytes->asString());
							}
							;break;
							default: {
								HX_STACK_LINE(103)
								this->data = bytes;
							}
						}
					}
				}
			}
			catch(Dynamic __e){
				{
					HX_STACK_BEGIN_CATCH
					Dynamic e = __e;{
						HX_STACK_LINE(109)
						this->onError(e);
						HX_STACK_LINE(110)
						return null();
					}
				}
			}
			HX_STACK_LINE(114)
			this->__dataComplete();
		}
		else{
			HX_STACK_LINE(118)
			request->__prepare();
			HX_STACK_LINE(119)
			this->__handle = ::flash::net::URLLoader_obj::lime_curl_create(request);
			HX_STACK_LINE(121)
			if (((this->__handle == null()))){
				HX_STACK_LINE(121)
				this->onError(HX_CSTRING("Could not open URL"));
			}
			else{
				HX_STACK_LINE(125)
				::flash::net::URLLoader_obj::activeLoaders->push(hx::ObjectPtr<OBJ_>(this));
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,load,(void))

Array< ::String > URLLoader_obj::getCookies( ){
	HX_STACK_PUSH("URLLoader::getCookies","flash/net/URLLoader.hx",61);
	HX_STACK_THIS(this);
	HX_STACK_LINE(61)
	return ::flash::net::URLLoader_obj::lime_curl_get_cookies(this->__handle);
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,getCookies,return )

Void URLLoader_obj::close( ){
{
		HX_STACK_PUSH("URLLoader::close","flash/net/URLLoader.hx",54);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,close,(void))

::List URLLoader_obj::activeLoaders;

int URLLoader_obj::urlInvalid;

int URLLoader_obj::urlInit;

int URLLoader_obj::urlLoading;

int URLLoader_obj::urlComplete;

int URLLoader_obj::urlError;

bool URLLoader_obj::hasActive( ){
	HX_STACK_PUSH("URLLoader::hasActive","flash/net/URLLoader.hx",68);
	HX_STACK_LINE(68)
	return !(::flash::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,hasActive,return )

Void URLLoader_obj::initialize( ::String caCertFilePath){
{
		HX_STACK_PUSH("URLLoader::initialize","flash/net/URLLoader.hx",75);
		HX_STACK_ARG(caCertFilePath,"caCertFilePath");
		HX_STACK_LINE(75)
		::flash::net::URLLoader_obj::lime_curl_initialize(caCertFilePath);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(URLLoader_obj,initialize,(void))

bool URLLoader_obj::__loadPending( ){
	HX_STACK_PUSH("URLLoader::__loadPending","flash/net/URLLoader.hx",240);
	HX_STACK_LINE(240)
	return !(::flash::net::URLLoader_obj::activeLoaders->isEmpty());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,__loadPending,return )

Void URLLoader_obj::__pollData( ){
{
		HX_STACK_PUSH("URLLoader::__pollData","flash/net/URLLoader.hx",247);
		HX_STACK_LINE(247)
		if ((!(::flash::net::URLLoader_obj::activeLoaders->isEmpty()))){
			HX_STACK_LINE(251)
			::flash::net::URLLoader_obj::lime_curl_process_loaders();
			HX_STACK_LINE(252)
			::List oldLoaders = ::flash::net::URLLoader_obj::activeLoaders;		HX_STACK_VAR(oldLoaders,"oldLoaders");
			HX_STACK_LINE(253)
			::flash::net::URLLoader_obj::activeLoaders = ::List_obj::__new();
			HX_STACK_LINE(255)
			for(::cpp::FastIterator_obj< ::flash::net::URLLoader > *__it = ::cpp::CreateFastIterator< ::flash::net::URLLoader >(oldLoaders->iterator());  __it->hasNext(); ){
				::flash::net::URLLoader loader = __it->next();
				{
					HX_STACK_LINE(257)
					loader->update();
					HX_STACK_LINE(258)
					if (((loader->state == (int)2))){
						HX_STACK_LINE(258)
						::flash::net::URLLoader_obj::activeLoaders->push(loader);
					}
				}
;
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(URLLoader_obj,__pollData,(void))

Dynamic URLLoader_obj::lime_curl_create;

Dynamic URLLoader_obj::lime_curl_process_loaders;

Dynamic URLLoader_obj::lime_curl_update_loader;

Dynamic URLLoader_obj::lime_curl_get_code;

Dynamic URLLoader_obj::lime_curl_get_error_message;

Dynamic URLLoader_obj::lime_curl_get_data;

Dynamic URLLoader_obj::lime_curl_get_cookies;

Dynamic URLLoader_obj::lime_curl_initialize;


URLLoader_obj::URLLoader_obj()
{
}

void URLLoader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(URLLoader);
	HX_MARK_MEMBER_NAME(__onComplete,"__onComplete");
	HX_MARK_MEMBER_NAME(__handle,"__handle");
	HX_MARK_MEMBER_NAME(state,"state");
	HX_MARK_MEMBER_NAME(dataFormat,"dataFormat");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_MARK_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void URLLoader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__onComplete,"__onComplete");
	HX_VISIT_MEMBER_NAME(__handle,"__handle");
	HX_VISIT_MEMBER_NAME(state,"state");
	HX_VISIT_MEMBER_NAME(dataFormat,"dataFormat");
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(bytesTotal,"bytesTotal");
	HX_VISIT_MEMBER_NAME(bytesLoaded,"bytesLoaded");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic URLLoader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"load") ) { return load_dyn(); }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		if (HX_FIELD_EQ(inName,"state") ) { return state; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"onError") ) { return onError_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { return __handle; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"hasActive") ) { return hasActive_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"initialize") ) { return initialize_dyn(); }
		if (HX_FIELD_EQ(inName,"__pollData") ) { return __pollData_dyn(); }
		if (HX_FIELD_EQ(inName,"getCookies") ) { return getCookies_dyn(); }
		if (HX_FIELD_EQ(inName,"dataFormat") ) { return dataFormat; }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { return bytesTotal; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { return bytesLoaded; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__onComplete") ) { return __onComplete; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { return activeLoaders; }
		if (HX_FIELD_EQ(inName,"__loadPending") ) { return __loadPending_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"__dataComplete") ) { return __dataComplete_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_curl_create") ) { return lime_curl_create; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_curl_get_code") ) { return lime_curl_get_code; }
		if (HX_FIELD_EQ(inName,"lime_curl_get_data") ) { return lime_curl_get_data; }
		if (HX_FIELD_EQ(inName,"dispatchHTTPStatus") ) { return dispatchHTTPStatus_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_curl_initialize") ) { return lime_curl_initialize; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_curl_get_cookies") ) { return lime_curl_get_cookies; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_curl_update_loader") ) { return lime_curl_update_loader; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_curl_process_loaders") ) { return lime_curl_process_loaders; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_curl_get_error_message") ) { return lime_curl_get_error_message; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic URLLoader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"state") ) { state=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"__handle") ) { __handle=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"dataFormat") ) { dataFormat=inValue.Cast< ::flash::net::URLLoaderDataFormat >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bytesTotal") ) { bytesTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bytesLoaded") ) { bytesLoaded=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"__onComplete") ) { __onComplete=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"activeLoaders") ) { activeLoaders=inValue.Cast< ::List >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"lime_curl_create") ) { lime_curl_create=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"lime_curl_get_code") ) { lime_curl_get_code=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lime_curl_get_data") ) { lime_curl_get_data=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"lime_curl_initialize") ) { lime_curl_initialize=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"lime_curl_get_cookies") ) { lime_curl_get_cookies=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"lime_curl_update_loader") ) { lime_curl_update_loader=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"lime_curl_process_loaders") ) { lime_curl_process_loaders=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 27:
		if (HX_FIELD_EQ(inName,"lime_curl_get_error_message") ) { lime_curl_get_error_message=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void URLLoader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__handle"));
	outFields->push(HX_CSTRING("state"));
	outFields->push(HX_CSTRING("dataFormat"));
	outFields->push(HX_CSTRING("data"));
	outFields->push(HX_CSTRING("bytesTotal"));
	outFields->push(HX_CSTRING("bytesLoaded"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("activeLoaders"),
	HX_CSTRING("urlInvalid"),
	HX_CSTRING("urlInit"),
	HX_CSTRING("urlLoading"),
	HX_CSTRING("urlComplete"),
	HX_CSTRING("urlError"),
	HX_CSTRING("hasActive"),
	HX_CSTRING("initialize"),
	HX_CSTRING("__loadPending"),
	HX_CSTRING("__pollData"),
	HX_CSTRING("lime_curl_create"),
	HX_CSTRING("lime_curl_process_loaders"),
	HX_CSTRING("lime_curl_update_loader"),
	HX_CSTRING("lime_curl_get_code"),
	HX_CSTRING("lime_curl_get_error_message"),
	HX_CSTRING("lime_curl_get_data"),
	HX_CSTRING("lime_curl_get_cookies"),
	HX_CSTRING("lime_curl_initialize"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("__dataComplete"),
	HX_CSTRING("update"),
	HX_CSTRING("dispatchHTTPStatus"),
	HX_CSTRING("onError"),
	HX_CSTRING("load"),
	HX_CSTRING("getCookies"),
	HX_CSTRING("close"),
	HX_CSTRING("__onComplete"),
	HX_CSTRING("__handle"),
	HX_CSTRING("state"),
	HX_CSTRING("dataFormat"),
	HX_CSTRING("data"),
	HX_CSTRING("bytesTotal"),
	HX_CSTRING("bytesLoaded"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(URLLoader_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(URLLoader_obj::activeLoaders,"activeLoaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInvalid,"urlInvalid");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlInit,"urlInit");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlLoading,"urlLoading");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlComplete,"urlComplete");
	HX_MARK_MEMBER_NAME(URLLoader_obj::urlError,"urlError");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_create,"lime_curl_create");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_process_loaders,"lime_curl_process_loaders");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_update_loader,"lime_curl_update_loader");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_get_code,"lime_curl_get_code");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_get_error_message,"lime_curl_get_error_message");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_get_data,"lime_curl_get_data");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_get_cookies,"lime_curl_get_cookies");
	HX_MARK_MEMBER_NAME(URLLoader_obj::lime_curl_initialize,"lime_curl_initialize");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(URLLoader_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::activeLoaders,"activeLoaders");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::urlInvalid,"urlInvalid");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::urlInit,"urlInit");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::urlLoading,"urlLoading");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::urlComplete,"urlComplete");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::urlError,"urlError");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_create,"lime_curl_create");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_process_loaders,"lime_curl_process_loaders");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_update_loader,"lime_curl_update_loader");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_get_code,"lime_curl_get_code");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_get_error_message,"lime_curl_get_error_message");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_get_data,"lime_curl_get_data");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_get_cookies,"lime_curl_get_cookies");
	HX_VISIT_MEMBER_NAME(URLLoader_obj::lime_curl_initialize,"lime_curl_initialize");
};

Class URLLoader_obj::__mClass;

void URLLoader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.net.URLLoader"), hx::TCanCast< URLLoader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void URLLoader_obj::__boot()
{
	activeLoaders= ::List_obj::__new();
	urlInvalid= (int)0;
	urlInit= (int)1;
	urlLoading= (int)2;
	urlComplete= (int)3;
	urlError= (int)4;
	lime_curl_create= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_create"),(int)1);
	lime_curl_process_loaders= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_process_loaders"),(int)0);
	lime_curl_update_loader= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_update_loader"),(int)2);
	lime_curl_get_code= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_get_code"),(int)1);
	lime_curl_get_error_message= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_get_error_message"),(int)1);
	lime_curl_get_data= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_get_data"),(int)1);
	lime_curl_get_cookies= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_get_cookies"),(int)1);
	lime_curl_initialize= ::flash::Lib_obj::load(HX_CSTRING("lime"),HX_CSTRING("lime_curl_initialize"),(int)1);
}

} // end namespace flash
} // end namespace net
