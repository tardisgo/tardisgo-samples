#ifndef INCLUDED_tardis_Channel
#define INCLUDED_tardis_Channel

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(tardis,Channel)
namespace tardis{


class HXCPP_CLASS_ATTRIBUTES  Channel_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Channel_obj OBJ_;
		Channel_obj();
		Void __construct(int how_many_entries);

	public:
		static hx::ObjectPtr< Channel_obj > __new(int how_many_entries);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Channel_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Channel"); }

		virtual Void close( );
		Dynamic close_dyn();

		virtual int cap( );
		Dynamic cap_dyn();

		virtual int len( );
		Dynamic len_dyn();

		virtual Dynamic receive( Dynamic zero);
		Dynamic receive_dyn();

		virtual bool hasContents( );
		Dynamic hasContents_dyn();

		virtual bool hasNoContents( );
		Dynamic hasNoContents_dyn();

		virtual bool send( Dynamic source);
		Dynamic send_dyn();

		virtual bool hasSpace( );
		Dynamic hasSpace_dyn();

		bool closed;
		int oldest_entry;
		int num_entries;
		int max_entries;
		Dynamic entries;
};

} // end namespace tardis

#endif /* INCLUDED_tardis_Channel */ 
