#ifndef INCLUDED_flash_media_AudioThreadState
#define INCLUDED_flash_media_AudioThreadState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(cpp,vm,Mutex)
HX_DECLARE_CLASS2(cpp,vm,Thread)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,media,AudioThreadState)
HX_DECLARE_CLASS2(flash,media,SoundChannel)
HX_DECLARE_CLASS2(haxe,ds,ObjectMap)
namespace flash{
namespace media{


class HXCPP_CLASS_ATTRIBUTES  AudioThreadState_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef AudioThreadState_obj OBJ_;
		AudioThreadState_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< AudioThreadState_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~AudioThreadState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("AudioThreadState"); }

		virtual Void updateComplete( );
		Dynamic updateComplete_dyn();

		virtual Void remove( ::flash::media::SoundChannel channel);
		Dynamic remove_dyn();

		virtual Void checkComplete( );
		Dynamic checkComplete_dyn();

		virtual Void add( ::flash::media::SoundChannel channel);
		Dynamic add_dyn();

		::cpp::vm::Mutex mutex;
		::cpp::vm::Thread mainThread;
		::haxe::ds::ObjectMap channelList;
		::cpp::vm::Thread audioThread;
};

} // end namespace flash
} // end namespace media

#endif /* INCLUDED_flash_media_AudioThreadState */ 
