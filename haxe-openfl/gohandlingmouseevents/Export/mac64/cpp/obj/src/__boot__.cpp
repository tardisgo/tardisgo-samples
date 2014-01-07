#include <hxcpp.h>

#include <tardis/TypeInfo.h>
#include <tardis/Go.h>
#include <tardis/_Go/Go_main_handleMouse.h>
#include <tardis/Go_haxegoruntime_M0.h>
#include <tardis/Go_haxegoruntime_SetFinalizer.h>
#include <tardis/Go_haxegoruntime_Rune2Raw.h>
#include <tardis/_Go/Go_hxutil_init.h>
#include <tardis/Go_utf8_DecodeRune.h>
#include <tardis/Go_hxutil_CPos.h>
#include <tardis/_Go/Go_haxegoruntime_cstringToGo.h>
#include <tardis/Go_haxegoruntime_M4.h>
#include <tardis/Go_haxegoruntime_CPos.h>
#include <tardis/Go_utf8_RuneLen.h>
#include <tardis/Go_utf16_EncodeRune.h>
#include <tardis/Go_hxutil_Host.h>
#include <tardis/Go_utf8_DecodeLastRune.h>
#include <tardis/_Go/Go_haxegoruntime_funcname_go.h>
#include <tardis/Go_haxegoruntime_M2.h>
#include <tardis/Go_haxegoruntime_Host.h>
#include <tardis/Go_utf16_IsSurrogate.h>
#include <tardis/Go_utf8_ValidRune.h>
#include <tardis/Go_utf8_FullRuneInString.h>
#include <tardis/Go_main_MouseGoroutine.h>
#include <tardis/Go_haxegoruntime_FuncForPC.h>
#include <tardis/Go_haxegoruntime_C6.h>
#include <tardis/_Go/Go_haxegoruntime_init.h>
#include <tardis/Go_haxegoruntime_Runes2Raw.h>
#include <tardis/Go_hxutil_NumGoroutine.h>
#include <tardis/Go_utf8_Valid.h>
#include <tardis/_Go/Go_utf8_decodeRuneInStringInternal.h>
#include <tardis/Go_main_MouseDown.h>
#include <tardis/Go_haxegoruntime_Goexit.h>
#include <tardis/Go_haxegoruntime_C4.h>
#include <tardis/Go_haxegoruntime_RunesToUTF16.h>
#include <tardis/Go_haxegoruntime_UTF16toRunes.h>
#include <tardis/Go_utf8_DecodeRuneInString.h>
#include <tardis/_Go/Go_haxegoruntime_funcline_go.h>
#include <tardis/Go_haxegoruntime_M1.h>
#include <tardis/Go_haxegoruntime_StringCompare.h>
#include <tardis/_Go/Go_utf16_init.h>
#include <tardis/Go_hxutil_HAXE.h>
#include <tardis/Go_hxutil_Gosched.h>
#include <tardis/Go_utf8_RuneStart.h>
#include <tardis/Go_main_MouseUp.h>
#include <tardis/Go_haxegoruntime_C3.h>
#include <tardis/_Go/Go_haxegoruntime_init_36_1.h>
#include <tardis/_Go/Go_haxegoruntime_runtime_NumGoroutine.h>
#include <tardis/_Go/Go_utf8_decodeRuneInternal.h>
#include <tardis/Go_haxegoruntime_Raw2Runes.h>
#include <tardis/Go_utf8_ValidString.h>
#include <tardis/Go_utf8_FullRune.h>
#include <tardis/Go_main_MouseMove.h>
#include <tardis/Go_haxegoruntime_C5.h>
#include <tardis/Go_haxegoruntime_Callers.h>
#include <tardis/Go_haxegoruntime_RunesToUTF8.h>
#include <tardis/Go_hxutil_StringsUTF16.h>
#include <tardis/Go_utf8_RuneCountInString.h>
#include <tardis/_Go/Go_main_main.h>
#include <tardis/Go_haxegoruntime_C2.h>
#include <tardis/_Go/Go_haxegoruntime_runtime_Gosched.h>
#include <tardis/_Go/Go_utf8_init.h>
#include <tardis/Go_haxegoruntime_UTF8toRunes.h>
#include <tardis/Go_hxutil_StringsUTF8.h>
#include <tardis/_Go/Go_main_init.h>
#include <tardis/Go_haxegoruntime_C1.h>
#include <tardis/Go_haxegoruntime_M6.h>
#include <tardis/Go_utf8_RuneCount.h>
#include <tardis/Go_utf16_Decode.h>
#include <tardis/Go_hxutil_Platform.h>
#include <tardis/Go_utf8_DecodeLastRuneInString.h>
#include <tardis/_Go/Go_haxegoruntime_funcentry_go.h>
#include <tardis/Go_haxegoruntime_M3.h>
#include <tardis/Go_haxegoruntime_Platform.h>
#include <tardis/Go_utf16_DecodeRune.h>
#include <tardis/Go_hxutil_Zilen.h>
#include <tardis/Go_haxegoruntime_C0.h>
#include <tardis/_Go/Go_haxegoruntime_getgoroot.h>
#include <tardis/Go_haxegoruntime_M5.h>
#include <tardis/Go_utf8_EncodeRune.h>
#include <tardis/Go_utf16_Encode.h>
#include <tardis/Scheduler.h>
#include <tardis/StackFrame.h>
#include <tardis/StackFrameBasis.h>
#include <tardis/Int64.h>
#include <tardis/_Go/HaxeInt64abs_Impl_.h>
#include <tardis/Complex.h>
#include <tardis/Channel.h>
#include <tardis/Interface.h>
#include <tardis/Closure.h>
#include <tardis/Slice.h>
#include <tardis/UnsafePointer.h>
#include <tardis/Pointer.h>
#include <tardis/Force.h>
#include <tardis/Deep.h>
#include <sys/io/FileOutput.h>
#include <openfl/utils/WeakRef.h>
#include <openfl/utils/Float32Array.h>
#include <openfl/utils/ArrayBufferView.h>
#include <openfl/gl/GLTexture.h>
#include <openfl/gl/GLShader.h>
#include <openfl/gl/GLRenderbuffer.h>
#include <openfl/gl/GLProgram.h>
#include <openfl/gl/GLFramebuffer.h>
#include <openfl/gl/GLBuffer.h>
#include <openfl/gl/GLObject.h>
#include <openfl/gl/GL.h>
#include <openfl/events/SystemEvent.h>
#include <openfl/events/JoystickEvent.h>
#include <openfl/display/Tilesheet.h>
#include <openfl/display/OpenGLView.h>
#include <openfl/display/ManagedStage.h>
#include <openfl/display/DirectRenderer.h>
#include <openfl/AssetType.h>
#include <openfl/AssetData.h>
#include <openfl/Assets.h>
#include <openfl/AssetCache.h>
#include <motion/easing/ExpoEaseInOut.h>
#include <motion/easing/ExpoEaseIn.h>
#include <motion/actuators/TransformActuator.h>
#include <motion/actuators/PropertyPathDetails.h>
#include <motion/actuators/PropertyDetails.h>
#include <motion/actuators/MotionPathActuator.h>
#include <motion/actuators/MethodActuator.h>
#include <motion/actuators/FilterActuator.h>
#include <motion/RotationPath.h>
#include <motion/LinearPath.h>
#include <motion/BezierPath.h>
#include <motion/ComponentPath.h>
#include <motion/IComponentPath.h>
#include <motion/MotionPath.h>
#include <motion/_Actuate/TweenTimer.h>
#include <motion/_Actuate/TransformOptions.h>
#include <motion/_Actuate/EffectsOptions.h>
#include <motion/Actuate.h>
#include <motion/easing/ExpoEaseOut.h>
#include <motion/easing/IEasing.h>
#include <motion/easing/Expo.h>
#include <motion/actuators/SimpleActuator.h>
#include <motion/actuators/GenericActuator.h>
#include <motion/actuators/IGenericActuator.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/BytesBuffer.h>
#include <haxe/ds/StringMap.h>
#include <haxe/ds/ObjectMap.h>
#include <haxe/ds/IntMap.h>
#include <haxe/Unserializer.h>
#include <haxe/Timer.h>
#include <haxe/Resource.h>
#include <haxe/Log.h>
#include <haxe/CallStack.h>
#include <haxe/StackItem.h>
#include <flash/utils/Timer.h>
#include <flash/utils/Endian.h>
#include <flash/utils/CompressionAlgorithm.h>
#include <flash/utils/ByteArray.h>
#include <flash/utils/IDataInput.h>
#include <openfl/utils/IMemoryRange.h>
#include <flash/utils/IDataOutput.h>
#include <flash/ui/Keyboard.h>
#include <flash/text/FontType.h>
#include <flash/text/FontStyle.h>
#include <flash/text/Font.h>
#include <flash/system/SecurityDomain.h>
#include <flash/system/LoaderContext.h>
#include <flash/system/ApplicationDomain.h>
#include <flash/net/URLVariables.h>
#include <flash/net/URLRequestMethod.h>
#include <flash/net/URLRequestHeader.h>
#include <flash/net/URLRequest.h>
#include <flash/net/URLLoaderDataFormat.h>
#include <flash/media/SoundTransform.h>
#include <flash/media/SoundLoaderContext.h>
#include <flash/media/AudioThreadState.h>
#include <flash/media/SoundChannel.h>
#include <flash/media/InternalAudioType.h>
#include <flash/media/Sound.h>
#include <flash/media/ID3Info.h>
#include <flash/geom/Vector3D.h>
#include <flash/geom/Transform.h>
#include <flash/geom/Rectangle.h>
#include <flash/geom/Point.h>
#include <flash/geom/Matrix3D.h>
#include <flash/geom/Matrix.h>
#include <flash/geom/ColorTransform.h>
#include <flash/filters/BitmapFilter.h>
#include <flash/events/UncaughtErrorEvents.h>
#include <flash/events/UncaughtErrorEvent.h>
#include <flash/events/TimerEvent.h>
#include <flash/events/SampleDataEvent.h>
#include <flash/events/ProgressEvent.h>
#include <flash/events/KeyboardEvent.h>
#include <flash/events/IOErrorEvent.h>
#include <flash/events/HTTPStatusEvent.h>
#include <flash/events/FocusEvent.h>
#include <flash/events/EventPhase.h>
#include <flash/events/Listener.h>
#include <flash/events/ErrorEvent.h>
#include <flash/events/TextEvent.h>
#include <flash/errors/RangeError.h>
#include <flash/errors/EOFError.h>
#include <flash/errors/ArgumentError.h>
#include <flash/errors/Error.h>
#include <flash/display/TriangleCulling.h>
#include <flash/display/StageScaleMode.h>
#include <flash/display/StageQuality.h>
#include <flash/display/StageDisplayState.h>
#include <flash/display/StageAlign.h>
#include <flash/display/TouchInfo.h>
#include <flash/display/Stage.h>
#include <flash/events/TouchEvent.h>
#include <flash/events/MouseEvent.h>
#include <flash/events/Event.h>
#include <flash/display/SpreadMethod.h>
#include <flash/display/Shape.h>
#include <flash/display/PixelSnapping.h>
#include <flash/display/MovieClip.h>
#include <flash/display/LoaderInfo.h>
#include <flash/net/URLLoader.h>
#include <flash/display/Loader.h>
#include <flash/display/LineScaleMode.h>
#include <flash/display/JointStyle.h>
#include <flash/display/InterpolationMethod.h>
#include <flash/display/IGraphicsData.h>
#include <flash/display/GraphicsPathWinding.h>
#include <flash/display/Graphics.h>
#include <flash/display/GradientType.h>
#include <flash/display/CapsStyle.h>
#include <flash/display/BlendMode.h>
#include <flash/display/OptimizedPerlin.h>
#include <flash/display/BitmapData.h>
#include <flash/display/Bitmap.h>
#include <flash/_Vector/Vector_Impl_.h>
#include <flash/Memory.h>
#include <cpp/zip/Uncompress.h>
#include <cpp/zip/Flush.h>
#include <cpp/zip/Compress.h>
#include <cpp/vm/Thread.h>
#include <cpp/vm/Mutex.h>
#include <cpp/rtti/FieldNumericIntegerLookup.h>
#include <Type.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Reflect.h>
#include <IMap.h>
#include <List.h>
#include <Lambda.h>
#include <DefaultAssetLibrary.h>
#include <openfl/AssetLibrary.h>
#include <Date.h>
#include <DocumentClass.h>
#include <Main.h>
#include <flash/display/Sprite.h>
#include <flash/display/DisplayObjectContainer.h>
#include <flash/display/InteractiveObject.h>
#include <flash/display/DisplayObject.h>
#include <flash/Lib.h>
#include <Std.h>
#include <sys/io/_Process/Stdout.h>
#include <haxe/io/Input.h>
#include <haxe/io/Bytes.h>
#include <sys/io/_Process/Stdin.h>
#include <haxe/io/Output.h>
#include <sys/io/Process.h>
#include <Sys.h>
#include <cpp/Lib.h>
#include <_Map/Map_Impl_.h>
#include <flash/display/IBitmapDrawable.h>
#include <flash/events/EventDispatcher.h>
#include <flash/events/IEventDispatcher.h>
#include <ApplicationMain.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::tardis::TypeInfo_obj::__register();
::tardis::Go_obj::__register();
::tardis::_Go::Go_main_handleMouse_obj::__register();
::tardis::Go_haxegoruntime_M0_obj::__register();
::tardis::Go_haxegoruntime_SetFinalizer_obj::__register();
::tardis::Go_haxegoruntime_Rune2Raw_obj::__register();
::tardis::_Go::Go_hxutil_init_obj::__register();
::tardis::Go_utf8_DecodeRune_obj::__register();
::tardis::Go_hxutil_CPos_obj::__register();
::tardis::_Go::Go_haxegoruntime_cstringToGo_obj::__register();
::tardis::Go_haxegoruntime_M4_obj::__register();
::tardis::Go_haxegoruntime_CPos_obj::__register();
::tardis::Go_utf8_RuneLen_obj::__register();
::tardis::Go_utf16_EncodeRune_obj::__register();
::tardis::Go_hxutil_Host_obj::__register();
::tardis::Go_utf8_DecodeLastRune_obj::__register();
::tardis::_Go::Go_haxegoruntime_funcname_go_obj::__register();
::tardis::Go_haxegoruntime_M2_obj::__register();
::tardis::Go_haxegoruntime_Host_obj::__register();
::tardis::Go_utf16_IsSurrogate_obj::__register();
::tardis::Go_utf8_ValidRune_obj::__register();
::tardis::Go_utf8_FullRuneInString_obj::__register();
::tardis::Go_main_MouseGoroutine_obj::__register();
::tardis::Go_haxegoruntime_FuncForPC_obj::__register();
::tardis::Go_haxegoruntime_C6_obj::__register();
::tardis::_Go::Go_haxegoruntime_init_obj::__register();
::tardis::Go_haxegoruntime_Runes2Raw_obj::__register();
::tardis::Go_hxutil_NumGoroutine_obj::__register();
::tardis::Go_utf8_Valid_obj::__register();
::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__register();
::tardis::Go_main_MouseDown_obj::__register();
::tardis::Go_haxegoruntime_Goexit_obj::__register();
::tardis::Go_haxegoruntime_C4_obj::__register();
::tardis::Go_haxegoruntime_RunesToUTF16_obj::__register();
::tardis::Go_haxegoruntime_UTF16toRunes_obj::__register();
::tardis::Go_utf8_DecodeRuneInString_obj::__register();
::tardis::_Go::Go_haxegoruntime_funcline_go_obj::__register();
::tardis::Go_haxegoruntime_M1_obj::__register();
::tardis::Go_haxegoruntime_StringCompare_obj::__register();
::tardis::_Go::Go_utf16_init_obj::__register();
::tardis::Go_hxutil_HAXE_obj::__register();
::tardis::Go_hxutil_Gosched_obj::__register();
::tardis::Go_utf8_RuneStart_obj::__register();
::tardis::Go_main_MouseUp_obj::__register();
::tardis::Go_haxegoruntime_C3_obj::__register();
::tardis::_Go::Go_haxegoruntime_init_36_1_obj::__register();
::tardis::_Go::Go_haxegoruntime_runtime_NumGoroutine_obj::__register();
::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__register();
::tardis::Go_haxegoruntime_Raw2Runes_obj::__register();
::tardis::Go_utf8_ValidString_obj::__register();
::tardis::Go_utf8_FullRune_obj::__register();
::tardis::Go_main_MouseMove_obj::__register();
::tardis::Go_haxegoruntime_C5_obj::__register();
::tardis::Go_haxegoruntime_Callers_obj::__register();
::tardis::Go_haxegoruntime_RunesToUTF8_obj::__register();
::tardis::Go_hxutil_StringsUTF16_obj::__register();
::tardis::Go_utf8_RuneCountInString_obj::__register();
::tardis::_Go::Go_main_main_obj::__register();
::tardis::Go_haxegoruntime_C2_obj::__register();
::tardis::_Go::Go_haxegoruntime_runtime_Gosched_obj::__register();
::tardis::_Go::Go_utf8_init_obj::__register();
::tardis::Go_haxegoruntime_UTF8toRunes_obj::__register();
::tardis::Go_hxutil_StringsUTF8_obj::__register();
::tardis::_Go::Go_main_init_obj::__register();
::tardis::Go_haxegoruntime_C1_obj::__register();
::tardis::Go_haxegoruntime_M6_obj::__register();
::tardis::Go_utf8_RuneCount_obj::__register();
::tardis::Go_utf16_Decode_obj::__register();
::tardis::Go_hxutil_Platform_obj::__register();
::tardis::Go_utf8_DecodeLastRuneInString_obj::__register();
::tardis::_Go::Go_haxegoruntime_funcentry_go_obj::__register();
::tardis::Go_haxegoruntime_M3_obj::__register();
::tardis::Go_haxegoruntime_Platform_obj::__register();
::tardis::Go_utf16_DecodeRune_obj::__register();
::tardis::Go_hxutil_Zilen_obj::__register();
::tardis::Go_haxegoruntime_C0_obj::__register();
::tardis::_Go::Go_haxegoruntime_getgoroot_obj::__register();
::tardis::Go_haxegoruntime_M5_obj::__register();
::tardis::Go_utf8_EncodeRune_obj::__register();
::tardis::Go_utf16_Encode_obj::__register();
::tardis::Scheduler_obj::__register();
::tardis::StackFrame_obj::__register();
::tardis::StackFrameBasis_obj::__register();
::tardis::Int64_obj::__register();
::tardis::_Go::HaxeInt64abs_Impl__obj::__register();
::tardis::Complex_obj::__register();
::tardis::Channel_obj::__register();
::tardis::Interface_obj::__register();
::tardis::Closure_obj::__register();
::tardis::Slice_obj::__register();
::tardis::UnsafePointer_obj::__register();
::tardis::Pointer_obj::__register();
::tardis::Force_obj::__register();
::tardis::Deep_obj::__register();
::sys::io::FileOutput_obj::__register();
::openfl::utils::WeakRef_obj::__register();
::openfl::utils::Float32Array_obj::__register();
::openfl::utils::ArrayBufferView_obj::__register();
::openfl::gl::GLTexture_obj::__register();
::openfl::gl::GLShader_obj::__register();
::openfl::gl::GLRenderbuffer_obj::__register();
::openfl::gl::GLProgram_obj::__register();
::openfl::gl::GLFramebuffer_obj::__register();
::openfl::gl::GLBuffer_obj::__register();
::openfl::gl::GLObject_obj::__register();
::openfl::gl::GL_obj::__register();
::openfl::events::SystemEvent_obj::__register();
::openfl::events::JoystickEvent_obj::__register();
::openfl::display::Tilesheet_obj::__register();
::openfl::display::OpenGLView_obj::__register();
::openfl::display::ManagedStage_obj::__register();
::openfl::display::DirectRenderer_obj::__register();
::openfl::AssetType_obj::__register();
::openfl::AssetData_obj::__register();
::openfl::Assets_obj::__register();
::openfl::AssetCache_obj::__register();
::motion::easing::ExpoEaseInOut_obj::__register();
::motion::easing::ExpoEaseIn_obj::__register();
::motion::actuators::TransformActuator_obj::__register();
::motion::actuators::PropertyPathDetails_obj::__register();
::motion::actuators::PropertyDetails_obj::__register();
::motion::actuators::MotionPathActuator_obj::__register();
::motion::actuators::MethodActuator_obj::__register();
::motion::actuators::FilterActuator_obj::__register();
::motion::RotationPath_obj::__register();
::motion::LinearPath_obj::__register();
::motion::BezierPath_obj::__register();
::motion::ComponentPath_obj::__register();
::motion::IComponentPath_obj::__register();
::motion::MotionPath_obj::__register();
::motion::_Actuate::TweenTimer_obj::__register();
::motion::_Actuate::TransformOptions_obj::__register();
::motion::_Actuate::EffectsOptions_obj::__register();
::motion::Actuate_obj::__register();
::motion::easing::ExpoEaseOut_obj::__register();
::motion::easing::IEasing_obj::__register();
::motion::easing::Expo_obj::__register();
::motion::actuators::SimpleActuator_obj::__register();
::motion::actuators::GenericActuator_obj::__register();
::motion::actuators::IGenericActuator_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::BytesBuffer_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::ds::ObjectMap_obj::__register();
::haxe::ds::IntMap_obj::__register();
::haxe::Unserializer_obj::__register();
::haxe::Timer_obj::__register();
::haxe::Resource_obj::__register();
::haxe::Log_obj::__register();
::haxe::CallStack_obj::__register();
::haxe::StackItem_obj::__register();
::flash::utils::Timer_obj::__register();
::flash::utils::Endian_obj::__register();
::flash::utils::CompressionAlgorithm_obj::__register();
::flash::utils::ByteArray_obj::__register();
::flash::utils::IDataInput_obj::__register();
::openfl::utils::IMemoryRange_obj::__register();
::flash::utils::IDataOutput_obj::__register();
::flash::ui::Keyboard_obj::__register();
::flash::text::FontType_obj::__register();
::flash::text::FontStyle_obj::__register();
::flash::text::Font_obj::__register();
::flash::system::SecurityDomain_obj::__register();
::flash::system::LoaderContext_obj::__register();
::flash::system::ApplicationDomain_obj::__register();
::flash::net::URLVariables_obj::__register();
::flash::net::URLRequestMethod_obj::__register();
::flash::net::URLRequestHeader_obj::__register();
::flash::net::URLRequest_obj::__register();
::flash::net::URLLoaderDataFormat_obj::__register();
::flash::media::SoundTransform_obj::__register();
::flash::media::SoundLoaderContext_obj::__register();
::flash::media::AudioThreadState_obj::__register();
::flash::media::SoundChannel_obj::__register();
::flash::media::InternalAudioType_obj::__register();
::flash::media::Sound_obj::__register();
::flash::media::ID3Info_obj::__register();
::flash::geom::Vector3D_obj::__register();
::flash::geom::Transform_obj::__register();
::flash::geom::Rectangle_obj::__register();
::flash::geom::Point_obj::__register();
::flash::geom::Matrix3D_obj::__register();
::flash::geom::Matrix_obj::__register();
::flash::geom::ColorTransform_obj::__register();
::flash::filters::BitmapFilter_obj::__register();
::flash::events::UncaughtErrorEvents_obj::__register();
::flash::events::UncaughtErrorEvent_obj::__register();
::flash::events::TimerEvent_obj::__register();
::flash::events::SampleDataEvent_obj::__register();
::flash::events::ProgressEvent_obj::__register();
::flash::events::KeyboardEvent_obj::__register();
::flash::events::IOErrorEvent_obj::__register();
::flash::events::HTTPStatusEvent_obj::__register();
::flash::events::FocusEvent_obj::__register();
::flash::events::EventPhase_obj::__register();
::flash::events::Listener_obj::__register();
::flash::events::ErrorEvent_obj::__register();
::flash::events::TextEvent_obj::__register();
::flash::errors::RangeError_obj::__register();
::flash::errors::EOFError_obj::__register();
::flash::errors::ArgumentError_obj::__register();
::flash::errors::Error_obj::__register();
::flash::display::TriangleCulling_obj::__register();
::flash::display::StageScaleMode_obj::__register();
::flash::display::StageQuality_obj::__register();
::flash::display::StageDisplayState_obj::__register();
::flash::display::StageAlign_obj::__register();
::flash::display::TouchInfo_obj::__register();
::flash::display::Stage_obj::__register();
::flash::events::TouchEvent_obj::__register();
::flash::events::MouseEvent_obj::__register();
::flash::events::Event_obj::__register();
::flash::display::SpreadMethod_obj::__register();
::flash::display::Shape_obj::__register();
::flash::display::PixelSnapping_obj::__register();
::flash::display::MovieClip_obj::__register();
::flash::display::LoaderInfo_obj::__register();
::flash::net::URLLoader_obj::__register();
::flash::display::Loader_obj::__register();
::flash::display::LineScaleMode_obj::__register();
::flash::display::JointStyle_obj::__register();
::flash::display::InterpolationMethod_obj::__register();
::flash::display::IGraphicsData_obj::__register();
::flash::display::GraphicsPathWinding_obj::__register();
::flash::display::Graphics_obj::__register();
::flash::display::GradientType_obj::__register();
::flash::display::CapsStyle_obj::__register();
::flash::display::BlendMode_obj::__register();
::flash::display::OptimizedPerlin_obj::__register();
::flash::display::BitmapData_obj::__register();
::flash::display::Bitmap_obj::__register();
::flash::_Vector::Vector_Impl__obj::__register();
::flash::Memory_obj::__register();
::cpp::zip::Uncompress_obj::__register();
::cpp::zip::Flush_obj::__register();
::cpp::zip::Compress_obj::__register();
::cpp::vm::Thread_obj::__register();
::cpp::vm::Mutex_obj::__register();
::cpp::rtti::FieldNumericIntegerLookup_obj::__register();
::Type_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Reflect_obj::__register();
::IMap_obj::__register();
::List_obj::__register();
::Lambda_obj::__register();
::DefaultAssetLibrary_obj::__register();
::openfl::AssetLibrary_obj::__register();
::Date_obj::__register();
::DocumentClass_obj::__register();
::Main_obj::__register();
::flash::display::Sprite_obj::__register();
::flash::display::DisplayObjectContainer_obj::__register();
::flash::display::InteractiveObject_obj::__register();
::flash::display::DisplayObject_obj::__register();
::flash::Lib_obj::__register();
::Std_obj::__register();
::sys::io::_Process::Stdout_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Bytes_obj::__register();
::sys::io::_Process::Stdin_obj::__register();
::haxe::io::Output_obj::__register();
::sys::io::Process_obj::__register();
::Sys_obj::__register();
::cpp::Lib_obj::__register();
::_Map::Map_Impl__obj::__register();
::flash::display::IBitmapDrawable_obj::__register();
::flash::events::EventDispatcher_obj::__register();
::flash::events::IEventDispatcher_obj::__register();
::ApplicationMain_obj::__register();
::flash::utils::ByteArray_obj::__init__();
::cpp::Lib_obj::__boot();
::cpp::rtti::FieldNumericIntegerLookup_obj::__boot();
::cpp::vm::Mutex_obj::__boot();
::cpp::vm::Thread_obj::__boot();
::cpp::zip::Compress_obj::__boot();
::cpp::zip::Flush_obj::__boot();
::cpp::zip::Uncompress_obj::__boot();
::haxe::Log_obj::__boot();
::ApplicationMain_obj::__boot();
::flash::events::IEventDispatcher_obj::__boot();
::flash::events::EventDispatcher_obj::__boot();
::flash::display::IBitmapDrawable_obj::__boot();
::_Map::Map_Impl__obj::__boot();
::Sys_obj::__boot();
::sys::io::Process_obj::__boot();
::haxe::io::Output_obj::__boot();
::sys::io::_Process::Stdin_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Input_obj::__boot();
::sys::io::_Process::Stdout_obj::__boot();
::Std_obj::__boot();
::flash::Lib_obj::__boot();
::flash::display::DisplayObject_obj::__boot();
::flash::display::InteractiveObject_obj::__boot();
::flash::display::DisplayObjectContainer_obj::__boot();
::flash::display::Sprite_obj::__boot();
::Main_obj::__boot();
::DocumentClass_obj::__boot();
::Date_obj::__boot();
::openfl::AssetLibrary_obj::__boot();
::DefaultAssetLibrary_obj::__boot();
::Lambda_obj::__boot();
::List_obj::__boot();
::IMap_obj::__boot();
::Reflect_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Type_obj::__boot();
::flash::Memory_obj::__boot();
::flash::_Vector::Vector_Impl__obj::__boot();
::flash::display::Bitmap_obj::__boot();
::flash::display::BitmapData_obj::__boot();
::flash::display::OptimizedPerlin_obj::__boot();
::flash::display::BlendMode_obj::__boot();
::flash::display::CapsStyle_obj::__boot();
::flash::display::GradientType_obj::__boot();
::flash::display::Graphics_obj::__boot();
::flash::display::GraphicsPathWinding_obj::__boot();
::flash::display::IGraphicsData_obj::__boot();
::flash::display::InterpolationMethod_obj::__boot();
::flash::display::JointStyle_obj::__boot();
::flash::display::LineScaleMode_obj::__boot();
::flash::display::Loader_obj::__boot();
::flash::net::URLLoader_obj::__boot();
::flash::display::LoaderInfo_obj::__boot();
::flash::display::MovieClip_obj::__boot();
::flash::display::PixelSnapping_obj::__boot();
::flash::display::Shape_obj::__boot();
::flash::display::SpreadMethod_obj::__boot();
::flash::events::Event_obj::__boot();
::flash::events::MouseEvent_obj::__boot();
::flash::events::TouchEvent_obj::__boot();
::flash::display::Stage_obj::__boot();
::flash::display::TouchInfo_obj::__boot();
::flash::display::StageAlign_obj::__boot();
::flash::display::StageDisplayState_obj::__boot();
::flash::display::StageQuality_obj::__boot();
::flash::display::StageScaleMode_obj::__boot();
::flash::display::TriangleCulling_obj::__boot();
::flash::errors::Error_obj::__boot();
::flash::errors::ArgumentError_obj::__boot();
::flash::errors::EOFError_obj::__boot();
::flash::errors::RangeError_obj::__boot();
::flash::events::TextEvent_obj::__boot();
::flash::events::ErrorEvent_obj::__boot();
::flash::events::Listener_obj::__boot();
::flash::events::EventPhase_obj::__boot();
::flash::events::FocusEvent_obj::__boot();
::flash::events::HTTPStatusEvent_obj::__boot();
::flash::events::IOErrorEvent_obj::__boot();
::flash::events::KeyboardEvent_obj::__boot();
::flash::events::ProgressEvent_obj::__boot();
::flash::events::SampleDataEvent_obj::__boot();
::flash::events::TimerEvent_obj::__boot();
::flash::events::UncaughtErrorEvent_obj::__boot();
::flash::events::UncaughtErrorEvents_obj::__boot();
::flash::filters::BitmapFilter_obj::__boot();
::flash::geom::ColorTransform_obj::__boot();
::flash::geom::Matrix_obj::__boot();
::flash::geom::Matrix3D_obj::__boot();
::flash::geom::Point_obj::__boot();
::flash::geom::Rectangle_obj::__boot();
::flash::geom::Transform_obj::__boot();
::flash::geom::Vector3D_obj::__boot();
::flash::media::ID3Info_obj::__boot();
::flash::media::Sound_obj::__boot();
::flash::media::InternalAudioType_obj::__boot();
::flash::media::SoundChannel_obj::__boot();
::flash::media::AudioThreadState_obj::__boot();
::flash::media::SoundLoaderContext_obj::__boot();
::flash::media::SoundTransform_obj::__boot();
::flash::net::URLLoaderDataFormat_obj::__boot();
::flash::net::URLRequest_obj::__boot();
::flash::net::URLRequestHeader_obj::__boot();
::flash::net::URLRequestMethod_obj::__boot();
::flash::net::URLVariables_obj::__boot();
::flash::system::ApplicationDomain_obj::__boot();
::flash::system::LoaderContext_obj::__boot();
::flash::system::SecurityDomain_obj::__boot();
::flash::text::Font_obj::__boot();
::flash::text::FontStyle_obj::__boot();
::flash::text::FontType_obj::__boot();
::flash::ui::Keyboard_obj::__boot();
::flash::utils::IDataOutput_obj::__boot();
::openfl::utils::IMemoryRange_obj::__boot();
::flash::utils::IDataInput_obj::__boot();
::flash::utils::ByteArray_obj::__boot();
::flash::utils::CompressionAlgorithm_obj::__boot();
::flash::utils::Endian_obj::__boot();
::flash::utils::Timer_obj::__boot();
::haxe::StackItem_obj::__boot();
::haxe::CallStack_obj::__boot();
::haxe::Resource_obj::__boot();
::haxe::Timer_obj::__boot();
::haxe::Unserializer_obj::__boot();
::haxe::ds::IntMap_obj::__boot();
::haxe::ds::ObjectMap_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::io::BytesBuffer_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::motion::actuators::IGenericActuator_obj::__boot();
::motion::actuators::GenericActuator_obj::__boot();
::motion::actuators::SimpleActuator_obj::__boot();
::motion::easing::Expo_obj::__boot();
::motion::easing::IEasing_obj::__boot();
::motion::easing::ExpoEaseOut_obj::__boot();
::motion::Actuate_obj::__boot();
::motion::_Actuate::EffectsOptions_obj::__boot();
::motion::_Actuate::TransformOptions_obj::__boot();
::motion::_Actuate::TweenTimer_obj::__boot();
::motion::MotionPath_obj::__boot();
::motion::IComponentPath_obj::__boot();
::motion::ComponentPath_obj::__boot();
::motion::BezierPath_obj::__boot();
::motion::LinearPath_obj::__boot();
::motion::RotationPath_obj::__boot();
::motion::actuators::FilterActuator_obj::__boot();
::motion::actuators::MethodActuator_obj::__boot();
::motion::actuators::MotionPathActuator_obj::__boot();
::motion::actuators::PropertyDetails_obj::__boot();
::motion::actuators::PropertyPathDetails_obj::__boot();
::motion::actuators::TransformActuator_obj::__boot();
::motion::easing::ExpoEaseIn_obj::__boot();
::motion::easing::ExpoEaseInOut_obj::__boot();
::openfl::AssetCache_obj::__boot();
::openfl::Assets_obj::__boot();
::openfl::AssetData_obj::__boot();
::openfl::AssetType_obj::__boot();
::openfl::display::DirectRenderer_obj::__boot();
::openfl::display::ManagedStage_obj::__boot();
::openfl::display::OpenGLView_obj::__boot();
::openfl::display::Tilesheet_obj::__boot();
::openfl::events::JoystickEvent_obj::__boot();
::openfl::events::SystemEvent_obj::__boot();
::openfl::gl::GL_obj::__boot();
::openfl::gl::GLObject_obj::__boot();
::openfl::gl::GLBuffer_obj::__boot();
::openfl::gl::GLFramebuffer_obj::__boot();
::openfl::gl::GLProgram_obj::__boot();
::openfl::gl::GLRenderbuffer_obj::__boot();
::openfl::gl::GLShader_obj::__boot();
::openfl::gl::GLTexture_obj::__boot();
::openfl::utils::ArrayBufferView_obj::__boot();
::openfl::utils::Float32Array_obj::__boot();
::openfl::utils::WeakRef_obj::__boot();
::sys::io::FileOutput_obj::__boot();
::tardis::Deep_obj::__boot();
::tardis::Force_obj::__boot();
::tardis::Pointer_obj::__boot();
::tardis::UnsafePointer_obj::__boot();
::tardis::Slice_obj::__boot();
::tardis::Closure_obj::__boot();
::tardis::Interface_obj::__boot();
::tardis::Channel_obj::__boot();
::tardis::Complex_obj::__boot();
::tardis::_Go::HaxeInt64abs_Impl__obj::__boot();
::tardis::Int64_obj::__boot();
::tardis::StackFrameBasis_obj::__boot();
::tardis::StackFrame_obj::__boot();
::tardis::Scheduler_obj::__boot();
::tardis::Go_utf16_Encode_obj::__boot();
::tardis::Go_utf8_EncodeRune_obj::__boot();
::tardis::Go_haxegoruntime_M5_obj::__boot();
::tardis::_Go::Go_haxegoruntime_getgoroot_obj::__boot();
::tardis::Go_haxegoruntime_C0_obj::__boot();
::tardis::Go_hxutil_Zilen_obj::__boot();
::tardis::Go_utf16_DecodeRune_obj::__boot();
::tardis::Go_haxegoruntime_Platform_obj::__boot();
::tardis::Go_haxegoruntime_M3_obj::__boot();
::tardis::_Go::Go_haxegoruntime_funcentry_go_obj::__boot();
::tardis::Go_utf8_DecodeLastRuneInString_obj::__boot();
::tardis::Go_hxutil_Platform_obj::__boot();
::tardis::Go_utf16_Decode_obj::__boot();
::tardis::Go_utf8_RuneCount_obj::__boot();
::tardis::Go_haxegoruntime_M6_obj::__boot();
::tardis::Go_haxegoruntime_C1_obj::__boot();
::tardis::_Go::Go_main_init_obj::__boot();
::tardis::Go_hxutil_StringsUTF8_obj::__boot();
::tardis::Go_haxegoruntime_UTF8toRunes_obj::__boot();
::tardis::_Go::Go_utf8_init_obj::__boot();
::tardis::_Go::Go_haxegoruntime_runtime_Gosched_obj::__boot();
::tardis::Go_haxegoruntime_C2_obj::__boot();
::tardis::_Go::Go_main_main_obj::__boot();
::tardis::Go_utf8_RuneCountInString_obj::__boot();
::tardis::Go_hxutil_StringsUTF16_obj::__boot();
::tardis::Go_haxegoruntime_RunesToUTF8_obj::__boot();
::tardis::Go_haxegoruntime_Callers_obj::__boot();
::tardis::Go_haxegoruntime_C5_obj::__boot();
::tardis::Go_main_MouseMove_obj::__boot();
::tardis::Go_utf8_FullRune_obj::__boot();
::tardis::Go_utf8_ValidString_obj::__boot();
::tardis::Go_haxegoruntime_Raw2Runes_obj::__boot();
::tardis::_Go::Go_utf8_decodeRuneInternal_obj::__boot();
::tardis::_Go::Go_haxegoruntime_runtime_NumGoroutine_obj::__boot();
::tardis::_Go::Go_haxegoruntime_init_36_1_obj::__boot();
::tardis::Go_haxegoruntime_C3_obj::__boot();
::tardis::Go_main_MouseUp_obj::__boot();
::tardis::Go_utf8_RuneStart_obj::__boot();
::tardis::Go_hxutil_Gosched_obj::__boot();
::tardis::Go_hxutil_HAXE_obj::__boot();
::tardis::_Go::Go_utf16_init_obj::__boot();
::tardis::Go_haxegoruntime_StringCompare_obj::__boot();
::tardis::Go_haxegoruntime_M1_obj::__boot();
::tardis::_Go::Go_haxegoruntime_funcline_go_obj::__boot();
::tardis::Go_utf8_DecodeRuneInString_obj::__boot();
::tardis::Go_haxegoruntime_UTF16toRunes_obj::__boot();
::tardis::Go_haxegoruntime_RunesToUTF16_obj::__boot();
::tardis::Go_haxegoruntime_C4_obj::__boot();
::tardis::Go_haxegoruntime_Goexit_obj::__boot();
::tardis::Go_main_MouseDown_obj::__boot();
::tardis::_Go::Go_utf8_decodeRuneInStringInternal_obj::__boot();
::tardis::Go_utf8_Valid_obj::__boot();
::tardis::Go_hxutil_NumGoroutine_obj::__boot();
::tardis::Go_haxegoruntime_Runes2Raw_obj::__boot();
::tardis::_Go::Go_haxegoruntime_init_obj::__boot();
::tardis::Go_haxegoruntime_C6_obj::__boot();
::tardis::Go_haxegoruntime_FuncForPC_obj::__boot();
::tardis::Go_main_MouseGoroutine_obj::__boot();
::tardis::Go_utf8_FullRuneInString_obj::__boot();
::tardis::Go_utf8_ValidRune_obj::__boot();
::tardis::Go_utf16_IsSurrogate_obj::__boot();
::tardis::Go_haxegoruntime_Host_obj::__boot();
::tardis::Go_haxegoruntime_M2_obj::__boot();
::tardis::_Go::Go_haxegoruntime_funcname_go_obj::__boot();
::tardis::Go_utf8_DecodeLastRune_obj::__boot();
::tardis::Go_hxutil_Host_obj::__boot();
::tardis::Go_utf16_EncodeRune_obj::__boot();
::tardis::Go_utf8_RuneLen_obj::__boot();
::tardis::Go_haxegoruntime_CPos_obj::__boot();
::tardis::Go_haxegoruntime_M4_obj::__boot();
::tardis::_Go::Go_haxegoruntime_cstringToGo_obj::__boot();
::tardis::Go_hxutil_CPos_obj::__boot();
::tardis::Go_utf8_DecodeRune_obj::__boot();
::tardis::_Go::Go_hxutil_init_obj::__boot();
::tardis::Go_haxegoruntime_Rune2Raw_obj::__boot();
::tardis::Go_haxegoruntime_SetFinalizer_obj::__boot();
::tardis::Go_haxegoruntime_M0_obj::__boot();
::tardis::_Go::Go_main_handleMouse_obj::__boot();
::tardis::Go_obj::__boot();
::tardis::TypeInfo_obj::__boot();
}

