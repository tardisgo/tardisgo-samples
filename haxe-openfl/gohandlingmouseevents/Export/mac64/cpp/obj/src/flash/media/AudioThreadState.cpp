#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_cpp_vm_Mutex
#include <cpp/vm/Mutex.h>
#endif
#ifndef INCLUDED_cpp_vm_Thread
#include <cpp/vm/Thread.h>
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
#ifndef INCLUDED_flash_media_AudioThreadState
#include <flash/media/AudioThreadState.h>
#endif
#ifndef INCLUDED_flash_media_SoundChannel
#include <flash/media/SoundChannel.h>
#endif
#ifndef INCLUDED_haxe_ds_IntMap
#include <haxe/ds/IntMap.h>
#endif
#ifndef INCLUDED_haxe_ds_ObjectMap
#include <haxe/ds/ObjectMap.h>
#endif
namespace flash{
namespace media{

Void AudioThreadState_obj::__construct()
{
HX_STACK_PUSH("AudioThreadState::new","flash/media/SoundChannel.hx",326);
{
	HX_STACK_LINE(328)
	this->mutex = ::cpp::vm::Mutex_obj::__new();
	HX_STACK_LINE(329)
	this->channelList = ::haxe::ds::ObjectMap_obj::__new();
}
;
	return null();
}

AudioThreadState_obj::~AudioThreadState_obj() { }

Dynamic AudioThreadState_obj::__CreateEmpty() { return  new AudioThreadState_obj; }
hx::ObjectPtr< AudioThreadState_obj > AudioThreadState_obj::__new()
{  hx::ObjectPtr< AudioThreadState_obj > result = new AudioThreadState_obj();
	result->__construct();
	return result;}

Dynamic AudioThreadState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< AudioThreadState_obj > result = new AudioThreadState_obj();
	result->__construct();
	return result;}

Void AudioThreadState_obj::updateComplete( ){
{
		HX_STACK_PUSH("AudioThreadState::updateComplete","flash/media/SoundChannel.hx",393);
		HX_STACK_THIS(this);
		HX_STACK_LINE(395)
		this->mutex->acquire();
		HX_STACK_LINE(397)
		for(::cpp::FastIterator_obj< ::flash::media::SoundChannel > *__it = ::cpp::CreateFastIterator< ::flash::media::SoundChannel >(this->channelList->keys());  __it->hasNext(); ){
			::flash::media::SoundChannel channel = __it->next();
			this->channelList->__Internal->set(::__hxcpp_obj_id(channel),channel->__runCheckComplete());
		}
		HX_STACK_LINE(403)
		this->mutex->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AudioThreadState_obj,updateComplete,(void))

Void AudioThreadState_obj::remove( ::flash::media::SoundChannel channel){
{
		HX_STACK_PUSH("AudioThreadState::remove","flash/media/SoundChannel.hx",372);
		HX_STACK_THIS(this);
		HX_STACK_ARG(channel,"channel");
		HX_STACK_LINE(374)
		this->mutex->acquire();
		HX_STACK_LINE(376)
		if ((this->channelList->__Internal->exists(::__hxcpp_obj_id(channel)))){
			HX_STACK_LINE(378)
			this->channelList->__Internal->remove(::__hxcpp_obj_id(channel));
			HX_STACK_LINE(380)
			if (((::Lambda_obj::count(this->channelList,null()) == (int)0))){
				HX_STACK_LINE(380)
				::flash::media::SoundChannel_obj::__audioThreadIsIdle = true;
			}
		}
		HX_STACK_LINE(388)
		this->mutex->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AudioThreadState_obj,remove,(void))

Void AudioThreadState_obj::checkComplete( ){
{
		HX_STACK_PUSH("AudioThreadState::checkComplete","flash/media/SoundChannel.hx",350);
		HX_STACK_THIS(this);
		HX_STACK_LINE(350)
		for(::cpp::FastIterator_obj< ::flash::media::SoundChannel > *__it = ::cpp::CreateFastIterator< ::flash::media::SoundChannel >(this->channelList->keys());  __it->hasNext(); ){
			::flash::media::SoundChannel channel = __it->next();
			{
				HX_STACK_LINE(354)
				Dynamic isComplete = this->channelList->get(channel);		HX_STACK_VAR(isComplete,"isComplete");
				HX_STACK_LINE(356)
				if ((isComplete)){
					HX_STACK_LINE(358)
					::flash::events::Event completeEvent = ::flash::events::Event_obj::__new(::flash::events::Event_obj::SOUND_COMPLETE,null(),null());		HX_STACK_VAR(completeEvent,"completeEvent");
					HX_STACK_LINE(359)
					channel->dispatchEvent(completeEvent);
					HX_STACK_LINE(361)
					this->mutex->acquire();
					HX_STACK_LINE(362)
					this->channelList->__Internal->remove(::__hxcpp_obj_id(channel));
					HX_STACK_LINE(363)
					this->mutex->release();
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(AudioThreadState_obj,checkComplete,(void))

Void AudioThreadState_obj::add( ::flash::media::SoundChannel channel){
{
		HX_STACK_PUSH("AudioThreadState::add","flash/media/SoundChannel.hx",334);
		HX_STACK_THIS(this);
		HX_STACK_ARG(channel,"channel");
		HX_STACK_LINE(336)
		this->mutex->acquire();
		HX_STACK_LINE(338)
		if ((!(this->channelList->__Internal->exists(::__hxcpp_obj_id(channel))))){
			HX_STACK_LINE(340)
			this->channelList->__Internal->set(::__hxcpp_obj_id(channel),false);
			HX_STACK_LINE(341)
			::flash::media::SoundChannel_obj::__audioThreadIsIdle = false;
		}
		HX_STACK_LINE(345)
		this->mutex->release();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(AudioThreadState_obj,add,(void))


AudioThreadState_obj::AudioThreadState_obj()
{
}

void AudioThreadState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(AudioThreadState);
	HX_MARK_MEMBER_NAME(mutex,"mutex");
	HX_MARK_MEMBER_NAME(mainThread,"mainThread");
	HX_MARK_MEMBER_NAME(channelList,"channelList");
	HX_MARK_MEMBER_NAME(audioThread,"audioThread");
	HX_MARK_END_CLASS();
}

void AudioThreadState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(mutex,"mutex");
	HX_VISIT_MEMBER_NAME(mainThread,"mainThread");
	HX_VISIT_MEMBER_NAME(channelList,"channelList");
	HX_VISIT_MEMBER_NAME(audioThread,"audioThread");
}

Dynamic AudioThreadState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { return mutex; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mainThread") ) { return mainThread; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"channelList") ) { return channelList; }
		if (HX_FIELD_EQ(inName,"audioThread") ) { return audioThread; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"checkComplete") ) { return checkComplete_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"updateComplete") ) { return updateComplete_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic AudioThreadState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"mutex") ) { mutex=inValue.Cast< ::cpp::vm::Mutex >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"mainThread") ) { mainThread=inValue.Cast< ::cpp::vm::Thread >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"channelList") ) { channelList=inValue.Cast< ::haxe::ds::ObjectMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"audioThread") ) { audioThread=inValue.Cast< ::cpp::vm::Thread >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void AudioThreadState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("mutex"));
	outFields->push(HX_CSTRING("mainThread"));
	outFields->push(HX_CSTRING("channelList"));
	outFields->push(HX_CSTRING("audioThread"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("updateComplete"),
	HX_CSTRING("remove"),
	HX_CSTRING("checkComplete"),
	HX_CSTRING("add"),
	HX_CSTRING("mutex"),
	HX_CSTRING("mainThread"),
	HX_CSTRING("channelList"),
	HX_CSTRING("audioThread"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(AudioThreadState_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(AudioThreadState_obj::__mClass,"__mClass");
};

Class AudioThreadState_obj::__mClass;

void AudioThreadState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.media.AudioThreadState"), hx::TCanCast< AudioThreadState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void AudioThreadState_obj::__boot()
{
}

} // end namespace flash
} // end namespace media
