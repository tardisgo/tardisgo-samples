#include <hxcpp.h>

#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
namespace flash{
namespace geom{

Void Rectangle_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{
HX_STACK_PUSH("Rectangle::new","flash/geom/Rectangle.hx",20);
Float x = __o_x.Default(0);
Float y = __o_y.Default(0);
Float width = __o_width.Default(0);
Float height = __o_height.Default(0);
{
	HX_STACK_LINE(22)
	this->x = x;
	HX_STACK_LINE(23)
	this->y = y;
	HX_STACK_LINE(24)
	this->width = width;
	HX_STACK_LINE(25)
	this->height = height;
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hx::ObjectPtr< Rectangle_obj > Rectangle_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< Float >  __o_width,hx::Null< Float >  __o_height)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(__o_x,__o_y,__o_width,__o_height);
	return result;}

Dynamic Rectangle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

::flash::geom::Point Rectangle_obj::set_topLeft( ::flash::geom::Point value){
	HX_STACK_PUSH("Rectangle::set_topLeft","flash/geom/Rectangle.hx",277);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(277)
	this->x = value->x;
	HX_STACK_LINE(277)
	this->y = value->y;
	HX_STACK_LINE(277)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_topLeft,return )

::flash::geom::Point Rectangle_obj::get_topLeft( ){
	HX_STACK_PUSH("Rectangle::get_topLeft","flash/geom/Rectangle.hx",276);
	HX_STACK_THIS(this);
	HX_STACK_LINE(276)
	return ::flash::geom::Point_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_topLeft,return )

Float Rectangle_obj::set_top( Float value){
	HX_STACK_PUSH("Rectangle::set_top","flash/geom/Rectangle.hx",275);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(275)
	hx::SubEq(this->height,(value - this->y));
	HX_STACK_LINE(275)
	this->y = value;
	HX_STACK_LINE(275)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_top,return )

Float Rectangle_obj::get_top( ){
	HX_STACK_PUSH("Rectangle::get_top","flash/geom/Rectangle.hx",274);
	HX_STACK_THIS(this);
	HX_STACK_LINE(274)
	return this->y;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_top,return )

::flash::geom::Point Rectangle_obj::set_size( ::flash::geom::Point value){
	HX_STACK_PUSH("Rectangle::set_size","flash/geom/Rectangle.hx",273);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(273)
	this->width = value->x;
	HX_STACK_LINE(273)
	this->height = value->y;
	HX_STACK_LINE(273)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_size,return )

::flash::geom::Point Rectangle_obj::get_size( ){
	HX_STACK_PUSH("Rectangle::get_size","flash/geom/Rectangle.hx",272);
	HX_STACK_THIS(this);
	HX_STACK_LINE(272)
	return ::flash::geom::Point_obj::__new(this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_size,return )

Float Rectangle_obj::set_right( Float value){
	HX_STACK_PUSH("Rectangle::set_right","flash/geom/Rectangle.hx",271);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(271)
	this->width = (value - this->x);
	HX_STACK_LINE(271)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_right,return )

Float Rectangle_obj::get_right( ){
	HX_STACK_PUSH("Rectangle::get_right","flash/geom/Rectangle.hx",270);
	HX_STACK_THIS(this);
	HX_STACK_LINE(270)
	return (this->x + this->width);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_right,return )

Float Rectangle_obj::set_left( Float value){
	HX_STACK_PUSH("Rectangle::set_left","flash/geom/Rectangle.hx",269);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(269)
	hx::SubEq(this->width,(value - this->x));
	HX_STACK_LINE(269)
	this->x = value;
	HX_STACK_LINE(269)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_left,return )

Float Rectangle_obj::get_left( ){
	HX_STACK_PUSH("Rectangle::get_left","flash/geom/Rectangle.hx",268);
	HX_STACK_THIS(this);
	HX_STACK_LINE(268)
	return this->x;
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_left,return )

::flash::geom::Point Rectangle_obj::set_bottomRight( ::flash::geom::Point value){
	HX_STACK_PUSH("Rectangle::set_bottomRight","flash/geom/Rectangle.hx",267);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(267)
	this->width = (value->x - this->x);
	HX_STACK_LINE(267)
	this->height = (value->y - this->y);
	HX_STACK_LINE(267)
	return value->clone();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottomRight,return )

::flash::geom::Point Rectangle_obj::get_bottomRight( ){
	HX_STACK_PUSH("Rectangle::get_bottomRight","flash/geom/Rectangle.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_LINE(266)
	return ::flash::geom::Point_obj::__new((this->x + this->width),(this->y + this->height));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottomRight,return )

Float Rectangle_obj::set_bottom( Float value){
	HX_STACK_PUSH("Rectangle::set_bottom","flash/geom/Rectangle.hx",265);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(265)
	this->height = (value - this->y);
	HX_STACK_LINE(265)
	return value;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,set_bottom,return )

Float Rectangle_obj::get_bottom( ){
	HX_STACK_PUSH("Rectangle::get_bottom","flash/geom/Rectangle.hx",264);
	HX_STACK_THIS(this);
	HX_STACK_LINE(264)
	return (this->y + this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,get_bottom,return )

::flash::geom::Rectangle Rectangle_obj::_union( ::flash::geom::Rectangle toUnion){
	HX_STACK_PUSH("Rectangle::union","flash/geom/Rectangle.hx",246);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toUnion,"toUnion");
	HX_STACK_LINE(248)
	Float x0 = (  (((this->x > toUnion->x))) ? Float(toUnion->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(249)
	Float x1 = (  (((this->get_right() < toUnion->get_right()))) ? Float(toUnion->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(250)
	Float y0 = (  (((this->y > toUnion->y))) ? Float(toUnion->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(251)
	Float y1 = (  (((this->get_bottom() < toUnion->get_bottom()))) ? Float(toUnion->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(252)
	return ::flash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,_union,return )

::flash::geom::Rectangle Rectangle_obj::transform( ::flash::geom::Matrix m){
	HX_STACK_PUSH("Rectangle::transform","flash/geom/Rectangle.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(m,"m");
	HX_STACK_LINE(215)
	Float tx0 = ((m->a * this->x) + (m->c * this->y));		HX_STACK_VAR(tx0,"tx0");
	HX_STACK_LINE(216)
	Float tx1 = tx0;		HX_STACK_VAR(tx1,"tx1");
	HX_STACK_LINE(217)
	Float ty0 = ((m->b * this->x) + (m->d * this->y));		HX_STACK_VAR(ty0,"ty0");
	HX_STACK_LINE(218)
	Float ty1 = tx0;		HX_STACK_VAR(ty1,"ty1");
	HX_STACK_LINE(220)
	Float tx = ((m->a * ((this->x + this->width))) + (m->c * this->y));		HX_STACK_VAR(tx,"tx");
	HX_STACK_LINE(221)
	Float ty = ((m->b * ((this->x + this->width))) + (m->d * this->y));		HX_STACK_VAR(ty,"ty");
	HX_STACK_LINE(222)
	if (((tx < tx0))){
		HX_STACK_LINE(222)
		tx0 = tx;
	}
	HX_STACK_LINE(223)
	if (((ty < ty0))){
		HX_STACK_LINE(223)
		ty0 = ty;
	}
	HX_STACK_LINE(224)
	if (((tx > tx1))){
		HX_STACK_LINE(224)
		tx1 = tx;
	}
	HX_STACK_LINE(225)
	if (((ty > ty1))){
		HX_STACK_LINE(225)
		ty1 = ty;
	}
	HX_STACK_LINE(227)
	tx = ((m->a * ((this->x + this->width))) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(228)
	ty = ((m->b * ((this->x + this->width))) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(229)
	if (((tx < tx0))){
		HX_STACK_LINE(229)
		tx0 = tx;
	}
	HX_STACK_LINE(230)
	if (((ty < ty0))){
		HX_STACK_LINE(230)
		ty0 = ty;
	}
	HX_STACK_LINE(231)
	if (((tx > tx1))){
		HX_STACK_LINE(231)
		tx1 = tx;
	}
	HX_STACK_LINE(232)
	if (((ty > ty1))){
		HX_STACK_LINE(232)
		ty1 = ty;
	}
	HX_STACK_LINE(234)
	tx = ((m->a * this->x) + (m->c * ((this->y + this->height))));
	HX_STACK_LINE(235)
	ty = ((m->b * this->x) + (m->d * ((this->y + this->height))));
	HX_STACK_LINE(236)
	if (((tx < tx0))){
		HX_STACK_LINE(236)
		tx0 = tx;
	}
	HX_STACK_LINE(237)
	if (((ty < ty0))){
		HX_STACK_LINE(237)
		ty0 = ty;
	}
	HX_STACK_LINE(238)
	if (((tx > tx1))){
		HX_STACK_LINE(238)
		tx1 = tx;
	}
	HX_STACK_LINE(239)
	if (((ty > ty1))){
		HX_STACK_LINE(239)
		ty1 = ty;
	}
	HX_STACK_LINE(241)
	return ::flash::geom::Rectangle_obj::__new((tx0 + m->tx),(ty0 + m->ty),(tx1 - tx0),(ty1 - ty0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,transform,return )

::String Rectangle_obj::toString( ){
	HX_STACK_PUSH("Rectangle::toString","flash/geom/Rectangle.hx",206);
	HX_STACK_THIS(this);
	HX_STACK_LINE(206)
	return ((((((((HX_CSTRING("(x=") + this->x) + HX_CSTRING(", y=")) + this->y) + HX_CSTRING(", width=")) + this->width) + HX_CSTRING(", height=")) + this->height) + HX_CSTRING(")"));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,toString,return )

Void Rectangle_obj::setEmpty( ){
{
		HX_STACK_PUSH("Rectangle::setEmpty","flash/geom/Rectangle.hx",196);
		HX_STACK_THIS(this);
		HX_STACK_LINE(198)
		this->x = (int)0;
		HX_STACK_LINE(199)
		this->y = (int)0;
		HX_STACK_LINE(200)
		this->width = (int)0;
		HX_STACK_LINE(201)
		this->height = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,setEmpty,(void))

Void Rectangle_obj::offsetPoint( ::flash::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::offsetPoint","flash/geom/Rectangle.hx",188);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(190)
		hx::AddEq(this->x,point->x);
		HX_STACK_LINE(191)
		hx::AddEq(this->y,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,offsetPoint,(void))

Void Rectangle_obj::offset( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::offset","flash/geom/Rectangle.hx",180);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(182)
		hx::AddEq(this->x,dx);
		HX_STACK_LINE(183)
		hx::AddEq(this->y,dy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,offset,(void))

bool Rectangle_obj::isEmpty( ){
	HX_STACK_PUSH("Rectangle::isEmpty","flash/geom/Rectangle.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_LINE(173)
	return (bool((this->width <= (int)0)) || bool((this->height <= (int)0)));
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,isEmpty,return )

bool Rectangle_obj::intersects( ::flash::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersects","flash/geom/Rectangle.hx",156);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(158)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(159)
	Float x1 = (  (((this->get_right() > toIntersect->get_right()))) ? Float(toIntersect->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(160)
	if (((x1 <= x0))){
		HX_STACK_LINE(160)
		return false;
	}
	HX_STACK_LINE(166)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(167)
	Float y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? Float(toIntersect->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(168)
	return (y1 > y0);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersects,return )

::flash::geom::Rectangle Rectangle_obj::intersection( ::flash::geom::Rectangle toIntersect){
	HX_STACK_PUSH("Rectangle::intersection","flash/geom/Rectangle.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toIntersect,"toIntersect");
	HX_STACK_LINE(135)
	Float x0 = (  (((this->x < toIntersect->x))) ? Float(toIntersect->x) : Float(this->x) );		HX_STACK_VAR(x0,"x0");
	HX_STACK_LINE(136)
	Float x1 = (  (((this->get_right() > toIntersect->get_right()))) ? Float(toIntersect->get_right()) : Float(this->get_right()) );		HX_STACK_VAR(x1,"x1");
	HX_STACK_LINE(137)
	if (((x1 <= x0))){
		HX_STACK_LINE(137)
		return ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(143)
	Float y0 = (  (((this->y < toIntersect->y))) ? Float(toIntersect->y) : Float(this->y) );		HX_STACK_VAR(y0,"y0");
	HX_STACK_LINE(144)
	Float y1 = (  (((this->get_bottom() > toIntersect->get_bottom()))) ? Float(toIntersect->get_bottom()) : Float(this->get_bottom()) );		HX_STACK_VAR(y1,"y1");
	HX_STACK_LINE(145)
	if (((y1 <= y0))){
		HX_STACK_LINE(145)
		return ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(151)
	return ::flash::geom::Rectangle_obj::__new(x0,y0,(x1 - x0),(y1 - y0));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,intersection,return )

Void Rectangle_obj::inflatePoint( ::flash::geom::Point point){
{
		HX_STACK_PUSH("Rectangle::inflatePoint","flash/geom/Rectangle.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point,"point");
		HX_STACK_LINE(126)
		this->inflate(point->x,point->y);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,inflatePoint,(void))

Void Rectangle_obj::inflate( Float dx,Float dy){
{
		HX_STACK_PUSH("Rectangle::inflate","flash/geom/Rectangle.hx",116);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dx,"dx");
		HX_STACK_ARG(dy,"dy");
		HX_STACK_LINE(118)
		hx::SubEq(this->x,dx);
		HX_STACK_LINE(119)
		hx::SubEq(this->y,dy);
		HX_STACK_LINE(120)
		hx::AddEq(this->width,(dx * (int)2));
		HX_STACK_LINE(121)
		hx::AddEq(this->height,(dy * (int)2));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,inflate,(void))

Void Rectangle_obj::extendBounds( ::flash::geom::Rectangle r){
{
		HX_STACK_PUSH("Rectangle::extendBounds","flash/geom/Rectangle.hx",83);
		HX_STACK_THIS(this);
		HX_STACK_ARG(r,"r");
		HX_STACK_LINE(85)
		Float dx = (this->x - r->x);		HX_STACK_VAR(dx,"dx");
		HX_STACK_LINE(86)
		if (((dx > (int)0))){
			HX_STACK_LINE(88)
			hx::SubEq(this->x,dx);
			HX_STACK_LINE(89)
			hx::AddEq(this->width,dx);
		}
		HX_STACK_LINE(93)
		Float dy = (this->y - r->y);		HX_STACK_VAR(dy,"dy");
		HX_STACK_LINE(94)
		if (((dy > (int)0))){
			HX_STACK_LINE(96)
			hx::SubEq(this->y,dy);
			HX_STACK_LINE(97)
			hx::AddEq(this->height,dy);
		}
		HX_STACK_LINE(101)
		if (((r->get_right() > this->get_right()))){
			HX_STACK_LINE(101)
			this->set_right(r->get_right());
		}
		HX_STACK_LINE(107)
		if (((r->get_bottom() > this->get_bottom()))){
			HX_STACK_LINE(107)
			this->set_bottom(r->get_bottom());
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,extendBounds,(void))

bool Rectangle_obj::equals( ::flash::geom::Rectangle toCompare){
	HX_STACK_PUSH("Rectangle::equals","flash/geom/Rectangle.hx",76);
	HX_STACK_THIS(this);
	HX_STACK_ARG(toCompare,"toCompare");
	HX_STACK_LINE(76)
	return (bool((bool((bool((this->x == toCompare->x)) && bool((this->y == toCompare->y)))) && bool((this->width == toCompare->width)))) && bool((this->height == toCompare->height)));
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,equals,return )

Void Rectangle_obj::copyFrom( ::flash::geom::Rectangle sourceRect){
{
		HX_STACK_PUSH("Rectangle::copyFrom","flash/geom/Rectangle.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(sourceRect,"sourceRect");
		HX_STACK_LINE(68)
		this->x = sourceRect->x;
		HX_STACK_LINE(69)
		this->y = sourceRect->y;
		HX_STACK_LINE(70)
		this->width = sourceRect->width;
		HX_STACK_LINE(71)
		this->height = sourceRect->height;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,copyFrom,(void))

bool Rectangle_obj::containsRect( ::flash::geom::Rectangle rect){
	HX_STACK_PUSH("Rectangle::containsRect","flash/geom/Rectangle.hx",51);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rect,"rect");
	HX_STACK_LINE(51)
	if (((bool((rect->width <= (int)0)) || bool((rect->height <= (int)0))))){
		HX_STACK_LINE(53)
		return (bool((bool((bool((rect->x > this->x)) && bool((rect->y > this->y)))) && bool((rect->get_right() < this->get_right())))) && bool((rect->get_bottom() < this->get_bottom())));
	}
	else{
		HX_STACK_LINE(57)
		return (bool((bool((bool((rect->x >= this->x)) && bool((rect->y >= this->y)))) && bool((rect->get_right() <= this->get_right())))) && bool((rect->get_bottom() <= this->get_bottom())));
	}
	HX_STACK_LINE(51)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsRect,return )

bool Rectangle_obj::containsPoint( ::flash::geom::Point point){
	HX_STACK_PUSH("Rectangle::containsPoint","flash/geom/Rectangle.hx",44);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(44)
	return this->contains(point->x,point->y);
}


HX_DEFINE_DYNAMIC_FUNC1(Rectangle_obj,containsPoint,return )

bool Rectangle_obj::contains( Float x,Float y){
	HX_STACK_PUSH("Rectangle::contains","flash/geom/Rectangle.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(37)
	return (bool((bool((bool((x >= this->x)) && bool((y >= this->y)))) && bool((x < this->get_right())))) && bool((y < this->get_bottom())));
}


HX_DEFINE_DYNAMIC_FUNC2(Rectangle_obj,contains,return )

::flash::geom::Rectangle Rectangle_obj::clone( ){
	HX_STACK_PUSH("Rectangle::clone","flash/geom/Rectangle.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	return ::flash::geom::Rectangle_obj::__new(this->x,this->y,this->width,this->height);
}


HX_DEFINE_DYNAMIC_FUNC0(Rectangle_obj,clone,return )


Rectangle_obj::Rectangle_obj()
{
}

void Rectangle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Rectangle);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void Rectangle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(height,"height");
}

Dynamic Rectangle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return get_top(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return get_size(); }
		if (HX_FIELD_EQ(inName,"left") ) { return get_left(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"union") ) { return _union_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		if (HX_FIELD_EQ(inName,"right") ) { return get_right(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"offset") ) { return offset_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return get_bottom(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"set_top") ) { return set_top_dyn(); }
		if (HX_FIELD_EQ(inName,"get_top") ) { return get_top_dyn(); }
		if (HX_FIELD_EQ(inName,"isEmpty") ) { return isEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"inflate") ) { return inflate_dyn(); }
		if (HX_FIELD_EQ(inName,"topLeft") ) { return get_topLeft(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_size") ) { return set_size_dyn(); }
		if (HX_FIELD_EQ(inName,"get_size") ) { return get_size_dyn(); }
		if (HX_FIELD_EQ(inName,"set_left") ) { return set_left_dyn(); }
		if (HX_FIELD_EQ(inName,"get_left") ) { return get_left_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		if (HX_FIELD_EQ(inName,"setEmpty") ) { return setEmpty_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"contains") ) { return contains_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_right") ) { return set_right_dyn(); }
		if (HX_FIELD_EQ(inName,"get_right") ) { return get_right_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"set_bottom") ) { return set_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottom") ) { return get_bottom_dyn(); }
		if (HX_FIELD_EQ(inName,"intersects") ) { return intersects_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"set_topLeft") ) { return set_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"get_topLeft") ) { return get_topLeft_dyn(); }
		if (HX_FIELD_EQ(inName,"offsetPoint") ) { return offsetPoint_dyn(); }
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return get_bottomRight(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"intersection") ) { return intersection_dyn(); }
		if (HX_FIELD_EQ(inName,"inflatePoint") ) { return inflatePoint_dyn(); }
		if (HX_FIELD_EQ(inName,"extendBounds") ) { return extendBounds_dyn(); }
		if (HX_FIELD_EQ(inName,"containsRect") ) { return containsRect_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"containsPoint") ) { return containsPoint_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"set_bottomRight") ) { return set_bottomRight_dyn(); }
		if (HX_FIELD_EQ(inName,"get_bottomRight") ) { return get_bottomRight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Rectangle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"top") ) { return set_top(inValue); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"size") ) { return set_size(inValue); }
		if (HX_FIELD_EQ(inName,"left") ) { return set_left(inValue); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"right") ) { return set_right(inValue); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"bottom") ) { return set_bottom(inValue); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"topLeft") ) { return set_topLeft(inValue); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"bottomRight") ) { return set_bottomRight(inValue); }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Rectangle_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("topLeft"));
	outFields->push(HX_CSTRING("top"));
	outFields->push(HX_CSTRING("size"));
	outFields->push(HX_CSTRING("right"));
	outFields->push(HX_CSTRING("left"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("bottomRight"));
	outFields->push(HX_CSTRING("bottom"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_topLeft"),
	HX_CSTRING("get_topLeft"),
	HX_CSTRING("set_top"),
	HX_CSTRING("get_top"),
	HX_CSTRING("set_size"),
	HX_CSTRING("get_size"),
	HX_CSTRING("set_right"),
	HX_CSTRING("get_right"),
	HX_CSTRING("set_left"),
	HX_CSTRING("get_left"),
	HX_CSTRING("set_bottomRight"),
	HX_CSTRING("get_bottomRight"),
	HX_CSTRING("set_bottom"),
	HX_CSTRING("get_bottom"),
	HX_CSTRING("union"),
	HX_CSTRING("transform"),
	HX_CSTRING("toString"),
	HX_CSTRING("setEmpty"),
	HX_CSTRING("offsetPoint"),
	HX_CSTRING("offset"),
	HX_CSTRING("isEmpty"),
	HX_CSTRING("intersects"),
	HX_CSTRING("intersection"),
	HX_CSTRING("inflatePoint"),
	HX_CSTRING("inflate"),
	HX_CSTRING("extendBounds"),
	HX_CSTRING("equals"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("containsRect"),
	HX_CSTRING("containsPoint"),
	HX_CSTRING("contains"),
	HX_CSTRING("clone"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("width"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Rectangle_obj::__mClass,"__mClass");
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("flash.geom.Rectangle"), hx::TCanCast< Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace flash
} // end namespace geom
