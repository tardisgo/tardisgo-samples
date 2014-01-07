#ifndef INCLUDED_tardis_StackFrameBasis
#define INCLUDED_tardis_StackFrameBasis

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS1(tardis,StackFrame)
HX_DECLARE_CLASS1(tardis,StackFrameBasis)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  StackFrameBasis_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef StackFrameBasis_obj OBJ_;
		StackFrameBasis_obj();
		Void __construct(int gr,int ph,::String name);

	public:
		static hx::ObjectPtr< StackFrameBasis_obj > __new(int gr,int ph,::String name);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~StackFrameBasis_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("StackFrameBasis"); }

		virtual Void runDefers( );
		Dynamic runDefers_dyn();

		virtual Void defer( ::tardis::StackFrame fn);
		Dynamic defer_dyn();

		virtual Void setPH( int ph);
		Dynamic setPH_dyn();

		virtual Void setLatest( int ph,int blk);
		Dynamic setLatest_dyn();

		::List _deferStack;
		Dynamic _bds;
		int _goroutine;
		::String _functionName;
		int _functionPH;
		int _latestBlock;
		int _latestPH;
		bool _incomplete;
};

} // end namespace tardis

#endif /* INCLUDED_tardis_StackFrameBasis */ 
