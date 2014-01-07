#ifndef INCLUDED_flash_media_SoundChannel
#define INCLUDED_flash_media_SoundChannel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/events/EventDispatcher.h>
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,media,AudioThreadState)
HX_DECLARE_CLASS2(flash,media,Sound)
HX_DECLARE_CLASS2(flash,media,SoundChannel)
HX_DECLARE_CLASS2(flash,media,SoundTransform)
HX_DECLARE_CLASS2(flash,utils,ByteArray)
HX_DECLARE_CLASS2(flash,utils,IDataInput)
HX_DECLARE_CLASS2(flash,utils,IDataOutput)
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace flash{
namespace media{


class HXCPP_CLASS_ATTRIBUTES  SoundChannel_obj : public ::flash::events::EventDispatcher_obj{
	public:
		typedef ::flash::events::EventDispatcher_obj super;
		typedef SoundChannel_obj OBJ_;
		SoundChannel_obj();
		Void __construct(Dynamic handle,Float startTime,int loops,::flash::media::SoundTransform soundTransform);

	public:
		static hx::ObjectPtr< SoundChannel_obj > __new(Dynamic handle,Float startTime,int loops,::flash::media::SoundTransform soundTransform);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SoundChannel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SoundChannel"); }

		virtual ::flash::media::SoundTransform set_soundTransform( ::flash::media::SoundTransform value);
		Dynamic set_soundTransform_dyn();

		virtual ::flash::media::SoundTransform get_soundTransform( );
		Dynamic get_soundTransform_dyn();

		virtual Float set_position( Float value);
		Dynamic set_position_dyn();

		virtual Float get_position( );
		Dynamic get_position_dyn();

		virtual Float get_rightPeak( );
		Dynamic get_rightPeak_dyn();

		virtual Float get_leftPeak( );
		Dynamic get_leftPeak_dyn();

		virtual bool __runCheckComplete( );
		Dynamic __runCheckComplete_dyn();

		virtual bool __checkComplete( );
		Dynamic __checkComplete_dyn();

		virtual Void stop( );
		Dynamic stop_dyn();

		bool __addedToThread;
		::flash::media::SoundTransform __transform;
		::flash::media::Sound __soundInstance;
		Dynamic __handle;
		::flash::events::EventDispatcher __dataProvider;
		Float rightPeak;
		Float leftPeak;
		static int __dynamicSoundCount;
		static Array< ::Dynamic > __incompleteList;
		static int __audioMessageCheckComplete;
		static ::flash::media::AudioThreadState __audioState;
		static bool __audioThreadIsIdle;
		static bool __audioThreadRunning;
		static ::flash::media::SoundChannel createDynamic( Dynamic handle,::flash::media::SoundTransform soundTransform,::flash::events::EventDispatcher dataProvider);
		static Dynamic createDynamic_dyn();

		static Void __checkCompleteBackgroundThread( );
		static Dynamic __checkCompleteBackgroundThread_dyn();

		static bool __completePending( );
		static Dynamic __completePending_dyn();

		static Void __pollComplete( );
		static Dynamic __pollComplete_dyn();

		static Dynamic lime_sound_channel_is_complete;
		static Dynamic &lime_sound_channel_is_complete_dyn() { return lime_sound_channel_is_complete;}
		static Dynamic lime_sound_channel_get_left;
		static Dynamic &lime_sound_channel_get_left_dyn() { return lime_sound_channel_get_left;}
		static Dynamic lime_sound_channel_get_right;
		static Dynamic &lime_sound_channel_get_right_dyn() { return lime_sound_channel_get_right;}
		static Dynamic lime_sound_channel_get_position;
		static Dynamic &lime_sound_channel_get_position_dyn() { return lime_sound_channel_get_position;}
		static Dynamic lime_sound_channel_set_position;
		static Dynamic &lime_sound_channel_set_position_dyn() { return lime_sound_channel_set_position;}
		static Dynamic lime_sound_channel_get_data_position;
		static Dynamic &lime_sound_channel_get_data_position_dyn() { return lime_sound_channel_get_data_position;}
		static Dynamic lime_sound_channel_stop;
		static Dynamic &lime_sound_channel_stop_dyn() { return lime_sound_channel_stop;}
		static Dynamic lime_sound_channel_create;
		static Dynamic &lime_sound_channel_create_dyn() { return lime_sound_channel_create;}
		static Dynamic lime_sound_channel_set_transform;
		static Dynamic &lime_sound_channel_set_transform_dyn() { return lime_sound_channel_set_transform;}
		static Dynamic lime_sound_channel_needs_data;
		static Dynamic &lime_sound_channel_needs_data_dyn() { return lime_sound_channel_needs_data;}
		static Dynamic lime_sound_channel_add_data;
		static Dynamic &lime_sound_channel_add_data_dyn() { return lime_sound_channel_add_data;}
};

} // end namespace flash
} // end namespace media

#endif /* INCLUDED_flash_media_SoundChannel */ 
