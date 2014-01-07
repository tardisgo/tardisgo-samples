#ifndef INCLUDED_tardis_Go_utf16_IsSurrogate
#define INCLUDED_tardis_Go_utf16_IsSurrogate

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tardis/StackFrameBasis.h>
#include <tardis/StackFrame.h>
HX_DECLARE_CLASS1(tardis,Go_utf16_IsSurrogate)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Go_utf16_IsSurrogate_obj : public ::tardis::StackFrameBasis_obj{
	public:
		typedef ::tardis::StackFrameBasis_obj super;
		typedef Go_utf16_IsSurrogate_obj OBJ_;
		Go_utf16_IsSurrogate_obj();
		Void __construct(int gr,Dynamic _bds,int p_r);

	public:
		static hx::ObjectPtr< Go_utf16_IsSurrogate_obj > __new(int gr,Dynamic _bds,int p_r);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Go_utf16_IsSurrogate_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		inline operator ::tardis::StackFrame_obj *()
			{ return new ::tardis::StackFrame_delegate_< Go_utf16_IsSurrogate_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Go_utf16_IsSurrogate"); }

		virtual Void SubFn1( );
		Dynamic SubFn1_dyn();

		virtual Void SubFn0( );
		Dynamic SubFn0_dyn();

		virtual ::tardis::StackFrame run( );
		Dynamic run_dyn();

		int _Next;
		int _Phi;
		bool _t2;
		bool _t1;
		bool _t0;
		virtual Dynamic res( );
		Dynamic res_dyn();

		bool _res;
		int p_r;
		static bool callFromHaxe( int p_r);
		static Dynamic callFromHaxe_dyn();

		static bool callFromRT( int _gr,int p_r);
		static Dynamic callFromRT_dyn();

		static ::tardis::Go_utf16_IsSurrogate call( int gr,Dynamic _bds,int p_r);
		static Dynamic call_dyn();

};

} // end namespace tardis

#endif /* INCLUDED_tardis_Go_utf16_IsSurrogate */ 
