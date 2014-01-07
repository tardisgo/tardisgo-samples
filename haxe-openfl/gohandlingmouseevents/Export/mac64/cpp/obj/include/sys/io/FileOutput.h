#ifndef INCLUDED_sys_io_FileOutput
#define INCLUDED_sys_io_FileOutput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Output.h>
HX_DECLARE_CLASS2(haxe,io,Bytes)
HX_DECLARE_CLASS2(haxe,io,Output)
HX_DECLARE_CLASS2(sys,io,FileOutput)
namespace sys{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  FileOutput_obj : public ::haxe::io::Output_obj{
	public:
		typedef ::haxe::io::Output_obj super;
		typedef FileOutput_obj OBJ_;
		FileOutput_obj();
		Void __construct(Dynamic f);

	public:
		static hx::ObjectPtr< FileOutput_obj > __new(Dynamic f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileOutput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileOutput"); }

		virtual int writeBytes( ::haxe::io::Bytes s,int p,int l);

		virtual Void writeByte( int c);

		Dynamic __f;
		static Dynamic file_write;
		static Dynamic &file_write_dyn() { return file_write;}
		static Dynamic file_write_char;
		static Dynamic &file_write_char_dyn() { return file_write_char;}
};

} // end namespace sys
} // end namespace io

#endif /* INCLUDED_sys_io_FileOutput */ 
