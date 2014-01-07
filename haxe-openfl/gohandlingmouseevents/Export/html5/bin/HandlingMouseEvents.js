(function () { "use strict";
var $hxClasses = {},$estr = function() { return js.Boot.__string_rec(this,''); };
function $extend(from, fields) {
	function inherit() {}; inherit.prototype = from; var proto = new inherit();
	for (var name in fields) proto[name] = fields[name];
	if( fields.toString !== Object.prototype.toString ) proto.toString = fields.toString;
	return proto;
}
var ApplicationMain = function() { }
$hxClasses["ApplicationMain"] = ApplicationMain;
ApplicationMain.__name__ = ["ApplicationMain"];
ApplicationMain.main = function() {
	ApplicationMain.completed = 0;
	ApplicationMain.loaders = new haxe.ds.StringMap();
	ApplicationMain.urlLoaders = new haxe.ds.StringMap();
	ApplicationMain.total = 0;
	flash.Lib.get_current().loaderInfo = flash.display.LoaderInfo.create(null);
	try {
		if(Reflect.hasField(js.Browser.window,"winParameters")) flash.Lib.get_current().loaderInfo.parameters = (Reflect.field(js.Browser.window,"winParameters"))();
		flash.Lib.get_current().get_stage().loaderInfo = flash.Lib.get_current().loaderInfo;
	} catch( e ) {
	}
	ApplicationMain.preloader = new NMEPreloader();
	flash.Lib.get_current().addChild(ApplicationMain.preloader);
	ApplicationMain.preloader.onInit();
	var loader = new flash.display.Loader();
	ApplicationMain.loaders.set("assets/code.png",loader);
	ApplicationMain.total++;
	var loader1 = new flash.display.Loader();
	ApplicationMain.loaders.set("assets/gopher.png",loader1);
	ApplicationMain.total++;
	var loader2 = new flash.display.Loader();
	ApplicationMain.loaders.set("assets/openfl.png",loader2);
	ApplicationMain.total++;
	var resourcePrefix = "__ASSET__:bitmap_";
	var _g = 0, _g1 = haxe.Resource.listNames();
	while(_g < _g1.length) {
		var resourceName = _g1[_g];
		++_g;
		if(StringTools.startsWith(resourceName,resourcePrefix)) {
			var type = Type.resolveClass(StringTools.replace(resourceName.substring(resourcePrefix.length),"_","."));
			if(type != null) {
				ApplicationMain.total++;
				var instance = Type.createInstance(type,[0,0,true,16777215,ApplicationMain.bitmapClass_onComplete]);
			}
		}
	}
	if(ApplicationMain.total == 0) ApplicationMain.begin(); else {
		var $it0 = ApplicationMain.loaders.keys();
		while( $it0.hasNext() ) {
			var path = $it0.next();
			var loader3 = ApplicationMain.loaders.get(path);
			loader3.contentLoaderInfo.addEventListener("complete",ApplicationMain.loader_onComplete);
			loader3.load(new flash.net.URLRequest(path));
		}
		var $it1 = ApplicationMain.urlLoaders.keys();
		while( $it1.hasNext() ) {
			var path = $it1.next();
			var urlLoader = ApplicationMain.urlLoaders.get(path);
			urlLoader.addEventListener("complete",ApplicationMain.loader_onComplete);
			urlLoader.load(new flash.net.URLRequest(path));
		}
	}
}
ApplicationMain.begin = function() {
	ApplicationMain.preloader.addEventListener(flash.events.Event.COMPLETE,ApplicationMain.preloader_onComplete);
	ApplicationMain.preloader.onLoaded();
}
ApplicationMain.bitmapClass_onComplete = function(instance) {
	ApplicationMain.completed++;
	var classType = Type.getClass(instance);
	classType.preload = instance;
	if(ApplicationMain.completed == ApplicationMain.total) ApplicationMain.begin();
}
ApplicationMain.loader_onComplete = function(event) {
	ApplicationMain.completed++;
	ApplicationMain.preloader.onUpdate(ApplicationMain.completed,ApplicationMain.total);
	if(ApplicationMain.completed == ApplicationMain.total) ApplicationMain.begin();
}
ApplicationMain.preloader_onComplete = function(event) {
	ApplicationMain.preloader.removeEventListener(flash.events.Event.COMPLETE,ApplicationMain.preloader_onComplete);
	flash.Lib.get_current().removeChild(ApplicationMain.preloader);
	ApplicationMain.preloader = null;
	if(Reflect.field(Main,"main") == null) {
		var mainDisplayObj = Type.createInstance(DocumentClass,[]);
		if(js.Boot.__instanceof(mainDisplayObj,flash.display.DisplayObject)) flash.Lib.get_current().addChild(mainDisplayObj);
	} else Reflect.field(Main,"main").apply(Main,[]);
}
var flash = {}
flash.events = {}
flash.events.IEventDispatcher = function() { }
$hxClasses["flash.events.IEventDispatcher"] = flash.events.IEventDispatcher;
flash.events.IEventDispatcher.__name__ = ["flash","events","IEventDispatcher"];
flash.events.IEventDispatcher.prototype = {
	__class__: flash.events.IEventDispatcher
}
flash.events.EventDispatcher = function(target) {
	if(target != null) this.__target = target; else this.__target = this;
	this.__eventMap = [];
};
$hxClasses["flash.events.EventDispatcher"] = flash.events.EventDispatcher;
flash.events.EventDispatcher.__name__ = ["flash","events","EventDispatcher"];
flash.events.EventDispatcher.__interfaces__ = [flash.events.IEventDispatcher];
flash.events.EventDispatcher.compareListeners = function(l1,l2) {
	return l1.mPriority == l2.mPriority?0:l1.mPriority > l2.mPriority?-1:1;
}
flash.events.EventDispatcher.prototype = {
	willTrigger: function(type) {
		return this.hasEventListener(type);
	}
	,toString: function() {
		return "[ " + this.__name__ + " ]";
	}
	,setList: function(type,list) {
		this.__eventMap[type] = list;
	}
	,removeEventListener: function(type,listener,inCapture) {
		if(inCapture == null) inCapture = false;
		if(!this.existList(type)) return;
		var list = this.getList(type);
		var capture = inCapture == null?false:inCapture;
		var _g1 = 0, _g = list.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(list[i].Is(listener,capture)) {
				list.splice(i,1);
				return;
			}
		}
	}
	,hasEventListener: function(type) {
		return this.existList(type);
	}
	,getList: function(type) {
		return this.__eventMap[type];
	}
	,existList: function(type) {
		return this.__eventMap != null && this.__eventMap[type] != undefined;
	}
	,dispatchEvent: function(event) {
		if(event.target == null) event.target = this.__target;
		var capture = event.eventPhase == flash.events.EventPhase.CAPTURING_PHASE;
		if(this.existList(event.type)) {
			var list = this.getList(event.type);
			var idx = 0;
			while(idx < list.length) {
				var listener = list[idx];
				if(listener.mUseCapture == capture) {
					listener.dispatchEvent(event);
					if(event.__getIsCancelledNow()) return true;
				}
				if(idx < list.length && listener != list[idx]) {
				} else idx++;
			}
			return true;
		}
		return false;
	}
	,addEventListener: function(type,inListener,useCapture,inPriority,useWeakReference) {
		if(useWeakReference == null) useWeakReference = false;
		if(inPriority == null) inPriority = 0;
		if(useCapture == null) useCapture = false;
		var capture = useCapture == null?false:useCapture;
		var priority = inPriority == null?0:inPriority;
		var list = this.getList(type);
		if(!this.existList(type)) {
			list = [];
			this.setList(type,list);
		}
		list.push(new flash.events.Listener(inListener,capture,priority));
		list.sort(flash.events.EventDispatcher.compareListeners);
	}
	,__class__: flash.events.EventDispatcher
}
flash.display = {}
flash.display.IBitmapDrawable = function() { }
$hxClasses["flash.display.IBitmapDrawable"] = flash.display.IBitmapDrawable;
flash.display.IBitmapDrawable.__name__ = ["flash","display","IBitmapDrawable"];
flash.display.IBitmapDrawable.prototype = {
	__class__: flash.display.IBitmapDrawable
}
flash.display.DisplayObject = function() {
	flash.events.EventDispatcher.call(this,null);
	this.___id = flash.utils.Uuid.uuid();
	this.set_parent(null);
	this.set_transform(new flash.geom.Transform(this));
	this.__x = 0.0;
	this.__y = 0.0;
	this.__scaleX = 1.0;
	this.__scaleY = 1.0;
	this.__rotation = 0.0;
	this.__width = 0.0;
	this.__height = 0.0;
	this.set_visible(true);
	this.alpha = 1.0;
	this.__filters = new Array();
	this.__boundsRect = new flash.geom.Rectangle();
	this.__scrollRect = null;
	this.__mask = null;
	this.__maskingObj = null;
	this.set___combinedVisible(this.get_visible());
};
$hxClasses["flash.display.DisplayObject"] = flash.display.DisplayObject;
flash.display.DisplayObject.__name__ = ["flash","display","DisplayObject"];
flash.display.DisplayObject.__interfaces__ = [flash.display.IBitmapDrawable];
flash.display.DisplayObject.__super__ = flash.events.EventDispatcher;
flash.display.DisplayObject.prototype = $extend(flash.events.EventDispatcher.prototype,{
	__srUpdateDivs: function() {
		var gfx = this.__getGraphics();
		if(gfx == null || this.parent == null) return;
		if(this.__scrollRect == null) {
			if(this._srAxes != null && gfx.__surface.parentNode == this._srAxes && this._srWindow.parentNode != null) this._srWindow.parentNode.replaceChild(gfx.__surface,this._srWindow);
			return;
		}
		if(this._srWindow == null) {
			this._srWindow = js.Browser.document.createElement("div");
			this._srAxes = js.Browser.document.createElement("div");
			this._srWindow.style.setProperty("position","absolute","");
			this._srWindow.style.setProperty("left","0px","");
			this._srWindow.style.setProperty("top","0px","");
			this._srWindow.style.setProperty("width","0px","");
			this._srWindow.style.setProperty("height","0px","");
			this._srWindow.style.setProperty("overflow","hidden","");
			this._srAxes.style.setProperty("position","absolute","");
			this._srAxes.style.setProperty("left","0px","");
			this._srAxes.style.setProperty("top","0px","");
			this._srWindow.appendChild(this._srAxes);
		}
		var pnt = this.parent.localToGlobal(new flash.geom.Point(this.get_x(),this.get_y()));
		this._srWindow.style.left = pnt.x + "px";
		this._srWindow.style.top = pnt.y + "px";
		this._srWindow.style.width = this.__scrollRect.width + "px";
		this._srWindow.style.height = this.__scrollRect.height + "px";
		this._srAxes.style.left = -pnt.x - this.__scrollRect.x + "px";
		this._srAxes.style.top = -pnt.y - this.__scrollRect.y + "px";
		if(gfx.__surface.parentNode != this._srAxes && gfx.__surface.parentNode != null) {
			gfx.__surface.parentNode.insertBefore(this._srWindow,gfx.__surface);
			flash.Lib.__removeSurface(gfx.__surface);
			this._srAxes.appendChild(gfx.__surface);
		}
	}
	,__getSrWindow: function() {
		return this._srWindow;
	}
	,set_width: function(inValue) {
		if(this.get__boundsInvalid()) this.validateBounds();
		var w = this.__boundsRect.width;
		if(this.__scaleX * w != inValue) {
			if(w == 0) {
				this.__scaleX = 1;
				this.__invalidateMatrix(true);
				this.___renderFlags |= 64;
				if(this.parent != null) this.parent.___renderFlags |= 64;
				w = this.__boundsRect.width;
			}
			if(w <= 0) return 0;
			this.__scaleX = inValue / w;
			this.__invalidateMatrix(true);
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
		}
		return inValue;
	}
	,get_width: function() {
		if(this.get__boundsInvalid()) this.validateBounds();
		return this.__width;
	}
	,set_y: function(inValue) {
		if(this.__y != inValue) {
			this.__y = inValue;
			this.__invalidateMatrix(true);
			if(this.parent != null) this.parent.__invalidateBounds();
		}
		return inValue;
	}
	,get_y: function() {
		return this.__y;
	}
	,set_x: function(inValue) {
		if(this.__x != inValue) {
			this.__x = inValue;
			this.__invalidateMatrix(true);
			if(this.parent != null) this.parent.__invalidateBounds();
		}
		return inValue;
	}
	,get_x: function() {
		return this.__x;
	}
	,set_visible: function(inValue) {
		if(this.__visible != inValue) {
			this.__visible = inValue;
			this.setSurfaceVisible(inValue);
		}
		return this.__visible;
	}
	,get_visible: function() {
		return this.__visible;
	}
	,set_transform: function(inValue) {
		this.transform = inValue;
		this.__x = this.transform.get_matrix().tx;
		this.__y = this.transform.get_matrix().ty;
		this.__invalidateMatrix(true);
		return inValue;
	}
	,get__topmostSurface: function() {
		var gfx = this.__getGraphics();
		if(gfx != null) return gfx.__surface;
		return null;
	}
	,get_stage: function() {
		var gfx = this.__getGraphics();
		if(gfx != null) return flash.Lib.__getStage();
		return null;
	}
	,set_scrollRect: function(inValue) {
		this.__scrollRect = inValue;
		this.__srUpdateDivs();
		return inValue;
	}
	,get_scrollRect: function() {
		if(this.__scrollRect == null) return null;
		return this.__scrollRect.clone();
	}
	,set_scaleY: function(inValue) {
		if(this.__scaleY != inValue) {
			this.__scaleY = inValue;
			this.__invalidateMatrix(true);
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
		}
		return inValue;
	}
	,get_scaleY: function() {
		return this.__scaleY;
	}
	,set_scaleX: function(inValue) {
		if(this.__scaleX != inValue) {
			this.__scaleX = inValue;
			this.__invalidateMatrix(true);
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
		}
		return inValue;
	}
	,get_scaleX: function() {
		return this.__scaleX;
	}
	,set_rotation: function(inValue) {
		if(this.__rotation != inValue) {
			this.__rotation = inValue;
			this.__invalidateMatrix(true);
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
		}
		return inValue;
	}
	,get_rotation: function() {
		return this.__rotation;
	}
	,set_parent: function(inValue) {
		if(inValue == this.parent) return inValue;
		this.__invalidateMatrix();
		if(this.parent != null) {
			HxOverrides.remove(this.parent.__children,this);
			this.parent.__invalidateBounds();
		}
		if(inValue != null) {
			inValue.___renderFlags |= 64;
			if(inValue.parent != null) inValue.parent.___renderFlags |= 64;
		}
		if(this.parent == null && inValue != null) {
			this.parent = inValue;
			var evt = new flash.events.Event(flash.events.Event.ADDED,true,false);
			this.dispatchEvent(evt);
		} else if(this.parent != null && inValue == null) {
			this.parent = inValue;
			var evt = new flash.events.Event(flash.events.Event.REMOVED,true,false);
			this.dispatchEvent(evt);
		} else this.parent = inValue;
		return inValue;
	}
	,set___combinedVisible: function(inValue) {
		if(this.__combinedVisible != inValue) {
			this.__combinedVisible = inValue;
			this.setSurfaceVisible(inValue);
		}
		return this.__combinedVisible;
	}
	,get_mouseY: function() {
		return this.globalToLocal(new flash.geom.Point(0,this.get_stage().get_mouseY())).y;
	}
	,get_mouseX: function() {
		return this.globalToLocal(new flash.geom.Point(this.get_stage().get_mouseX(),0)).x;
	}
	,get__matrixInvalid: function() {
		return (this.___renderFlags & 4) != 0;
	}
	,get__matrixChainInvalid: function() {
		return (this.___renderFlags & 8) != 0;
	}
	,set_mask: function(inValue) {
		if(this.__mask != null) this.__mask.__maskingObj = null;
		this.__mask = inValue;
		if(this.__mask != null) this.__mask.__maskingObj = this;
		return this.__mask;
	}
	,get_mask: function() {
		return this.__mask;
	}
	,set_height: function(inValue) {
		if(this.get__boundsInvalid()) this.validateBounds();
		var h = this.__boundsRect.height;
		if(this.__scaleY * h != inValue) {
			if(h == 0) {
				this.__scaleY = 1;
				this.__invalidateMatrix(true);
				this.___renderFlags |= 64;
				if(this.parent != null) this.parent.___renderFlags |= 64;
				h = this.__boundsRect.height;
			}
			if(h <= 0) return 0;
			this.__scaleY = inValue / h;
			this.__invalidateMatrix(true);
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
		}
		return inValue;
	}
	,get_height: function() {
		if(this.get__boundsInvalid()) this.validateBounds();
		return this.__height;
	}
	,set_filters: function(filters) {
		var oldFilterCount = this.__filters == null?0:this.__filters.length;
		if(filters == null) {
			this.__filters = null;
			if(oldFilterCount > 0) this.invalidateGraphics();
		} else {
			this.__filters = new Array();
			var _g = 0;
			while(_g < filters.length) {
				var filter = filters[_g];
				++_g;
				this.__filters.push(filter.clone());
			}
			this.invalidateGraphics();
		}
		return filters;
	}
	,get__boundsInvalid: function() {
		var gfx = this.__getGraphics();
		if(gfx == null) return (this.___renderFlags & 64) != 0; else return (this.___renderFlags & 64) != 0 || gfx.boundsDirty;
	}
	,get_filters: function() {
		if(this.__filters == null) return [];
		var result = new Array();
		var _g = 0, _g1 = this.__filters;
		while(_g < _g1.length) {
			var filter = _g1[_g];
			++_g;
			result.push(filter.clone());
		}
		return result;
	}
	,get__bottommostSurface: function() {
		var gfx = this.__getGraphics();
		if(gfx != null) return gfx.__surface;
		return null;
	}
	,__validateMatrix: function() {
		var parentMatrixInvalid = (this.___renderFlags & 8) != 0 && this.parent != null;
		if((this.___renderFlags & 4) != 0 || parentMatrixInvalid) {
			if(parentMatrixInvalid) this.parent.__validateMatrix();
			var m = this.transform.get_matrix();
			if((this.___renderFlags & 16) != 0) this.___renderFlags &= -5;
			if((this.___renderFlags & 4) != 0) {
				m.identity();
				m.scale(this.__scaleX,this.__scaleY);
				var rad = this.__rotation * flash.geom.Transform.DEG_TO_RAD;
				if(rad != 0.0) m.rotate(rad);
				m.translate(this.__x,this.__y);
				this.transform._matrix.copy(m);
				m;
			}
			var cm = this.transform.__getFullMatrix(null);
			var fm = this.parent == null?m:this.parent.transform.__getFullMatrix(m);
			this._fullScaleX = fm._sx;
			this._fullScaleY = fm._sy;
			if(cm.a != fm.a || cm.b != fm.b || cm.c != fm.c || cm.d != fm.d || cm.tx != fm.tx || cm.ty != fm.ty) {
				this.transform.__setFullMatrix(fm);
				this.___renderFlags |= 32;
			}
			this.___renderFlags &= -29;
		}
	}
	,__unifyChildrenWithDOM: function(lastMoveObj) {
		var gfx = this.__getGraphics();
		if(gfx != null && lastMoveObj != null && this != lastMoveObj) {
			var ogfx = lastMoveObj.__getGraphics();
			if(ogfx != null) flash.Lib.__setSurfaceZIndexAfter(this.__scrollRect == null?gfx.__surface:this._srWindow,lastMoveObj.__scrollRect == null?ogfx.__surface:lastMoveObj == this.parent?ogfx.__surface:lastMoveObj._srWindow);
		}
		if(gfx == null) return lastMoveObj; else return this;
	}
	,__testFlag: function(mask) {
		return (this.___renderFlags & mask) != 0;
	}
	,__setMatrix: function(inValue) {
		this.transform._matrix.copy(inValue);
		return inValue;
	}
	,__setFullMatrix: function(inValue) {
		return this.transform.__setFullMatrix(inValue);
	}
	,__setFlagToValue: function(mask,value) {
		if(value) this.___renderFlags |= mask; else this.___renderFlags &= ~mask;
	}
	,__setFlag: function(mask) {
		this.___renderFlags |= mask;
	}
	,__setDimensions: function() {
		if(this.scale9Grid != null) {
			this.__boundsRect.width *= this.__scaleX;
			this.__boundsRect.height *= this.__scaleY;
			this.__width = this.__boundsRect.width;
			this.__height = this.__boundsRect.height;
		} else {
			this.__width = this.__boundsRect.width * this.__scaleX;
			this.__height = this.__boundsRect.height * this.__scaleY;
		}
	}
	,__render: function(inMask,clipRect) {
		if(!this.__combinedVisible) return;
		var gfx = this.__getGraphics();
		if(gfx == null) return;
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		if(gfx.__render(inMask,this.__filters,1,1)) {
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
			this.__applyFilters(gfx.__surface);
			this.___renderFlags |= 32;
		}
		var fullAlpha = (this.parent != null?this.parent.__combinedAlpha:1) * this.alpha;
		if(inMask != null) {
			var m = this.getSurfaceTransform(gfx);
			flash.Lib.__drawToSurface(gfx.__surface,inMask,m,fullAlpha,clipRect);
		} else {
			if((this.___renderFlags & 32) != 0) {
				var m = this.getSurfaceTransform(gfx);
				flash.Lib.__setSurfaceTransform(gfx.__surface,m);
				this.___renderFlags &= -33;
				this.__srUpdateDivs();
			}
			flash.Lib.__setSurfaceOpacity(gfx.__surface,fullAlpha);
		}
	}
	,__removeFromStage: function() {
		var gfx = this.__getGraphics();
		if(gfx != null && flash.Lib.__isOnStage(gfx.__surface)) {
			flash.Lib.__removeSurface(gfx.__surface);
			var evt = new flash.events.Event(flash.events.Event.REMOVED_FROM_STAGE,false,false);
			this.dispatchEvent(evt);
		}
	}
	,__matrixOverridden: function() {
		this.__x = this.transform.get_matrix().tx;
		this.__y = this.transform.get_matrix().ty;
		this.___renderFlags |= 16;
		this.___renderFlags |= 4;
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
	}
	,__isOnStage: function() {
		var gfx = this.__getGraphics();
		if(gfx != null && flash.Lib.__isOnStage(gfx.__surface)) return true;
		return false;
	}
	,__invalidateMatrix: function(local) {
		if(local == null) local = false;
		if(local) this.___renderFlags |= 4; else this.___renderFlags |= 8;
	}
	,__invalidateBounds: function() {
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
	}
	,__getSurface: function() {
		var gfx = this.__getGraphics();
		var surface = null;
		if(gfx != null) surface = gfx.__surface;
		return surface;
	}
	,__getObjectUnderPoint: function(point) {
		if(!this.get_visible()) return null;
		var gfx = this.__getGraphics();
		if(gfx != null) {
			gfx.__render();
			var extX = gfx.__extent.x;
			var extY = gfx.__extent.y;
			var local = this.globalToLocal(point);
			if(local.x - extX <= 0 || local.y - extY <= 0 || (local.x - extX) * this.get_scaleX() > this.get_width() || (local.y - extY) * this.get_scaleY() > this.get_height()) return null;
			if(gfx.__hitTest(local.x,local.y)) return this;
		}
		return null;
	}
	,__getMatrix: function() {
		return this.transform.get_matrix();
	}
	,__getInteractiveObjectStack: function(outStack) {
		var io = this;
		if(io != null) outStack.push(io);
		if(this.parent != null) this.parent.__getInteractiveObjectStack(outStack);
	}
	,__getGraphics: function() {
		return null;
	}
	,__getFullMatrix: function(localMatrix) {
		return this.transform.__getFullMatrix(localMatrix);
	}
	,__fireEvent: function(event) {
		var stack = [];
		if(this.parent != null) this.parent.__getInteractiveObjectStack(stack);
		var l = stack.length;
		if(l > 0) {
			event.__setPhase(flash.events.EventPhase.CAPTURING_PHASE);
			stack.reverse();
			var _g = 0;
			while(_g < stack.length) {
				var obj = stack[_g];
				++_g;
				event.currentTarget = obj;
				obj.__dispatchEvent(event);
				if(event.__getIsCancelled()) return;
			}
		}
		event.__setPhase(flash.events.EventPhase.AT_TARGET);
		event.currentTarget = this;
		this.__dispatchEvent(event);
		if(event.__getIsCancelled()) return;
		if(event.bubbles) {
			event.__setPhase(flash.events.EventPhase.BUBBLING_PHASE);
			stack.reverse();
			var _g = 0;
			while(_g < stack.length) {
				var obj = stack[_g];
				++_g;
				event.currentTarget = obj;
				obj.__dispatchEvent(event);
				if(event.__getIsCancelled()) return;
			}
		}
	}
	,__dispatchEvent: function(event) {
		if(event.target == null) event.target = this;
		event.currentTarget = this;
		return flash.events.EventDispatcher.prototype.dispatchEvent.call(this,event);
	}
	,__contains: function(child) {
		return false;
	}
	,__clearFlag: function(mask) {
		this.___renderFlags &= ~mask;
	}
	,__broadcast: function(event) {
		this.__dispatchEvent(event);
	}
	,__applyFilters: function(surface) {
		if(this.__filters != null) {
			var _g = 0, _g1 = this.__filters;
			while(_g < _g1.length) {
				var filter = _g1[_g];
				++_g;
				filter.__applyFilter(surface);
			}
		}
	}
	,__addToStage: function(newParent,beforeSibling) {
		var gfx = this.__getGraphics();
		if(gfx == null) return;
		if(newParent.__getGraphics() != null) {
			flash.Lib.__setSurfaceId(gfx.__surface,this.___id);
			if(beforeSibling != null && beforeSibling.__getGraphics() != null) flash.Lib.__appendSurface(gfx.__surface,beforeSibling.get__bottommostSurface()); else {
				var stageChildren = [];
				var _g = 0, _g1 = newParent.__children;
				while(_g < _g1.length) {
					var child = _g1[_g];
					++_g;
					if(child.get_stage() != null) stageChildren.push(child);
				}
				if(stageChildren.length < 1) flash.Lib.__appendSurface(gfx.__surface,null,newParent.get__topmostSurface()); else {
					var nextSibling = stageChildren[stageChildren.length - 1];
					var container;
					while(js.Boot.__instanceof(nextSibling,flash.display.DisplayObjectContainer)) {
						container = js.Boot.__cast(nextSibling , flash.display.DisplayObjectContainer);
						if(container.__children.length > 0) nextSibling = container.__children[container.__children.length - 1]; else break;
					}
					if(nextSibling.__getGraphics() != gfx) flash.Lib.__appendSurface(gfx.__surface,null,nextSibling.get__topmostSurface()); else flash.Lib.__appendSurface(gfx.__surface);
				}
			}
			flash.Lib.__setSurfaceTransform(gfx.__surface,this.getSurfaceTransform(gfx));
		} else if(newParent.name == "Stage") flash.Lib.__appendSurface(gfx.__surface);
		if(this.__isOnStage()) {
			this.__srUpdateDivs();
			var evt = new flash.events.Event(flash.events.Event.ADDED_TO_STAGE,false,false);
			this.dispatchEvent(evt);
		}
	}
	,validateBounds: function() {
		if(this.get__boundsInvalid()) {
			var gfx = this.__getGraphics();
			if(gfx == null) {
				this.__boundsRect.x = this.get_x();
				this.__boundsRect.y = this.get_y();
				this.__boundsRect.width = 0;
				this.__boundsRect.height = 0;
			} else {
				this.__boundsRect = gfx.__extent.clone();
				if(this.scale9Grid != null) {
					this.__boundsRect.width *= this.__scaleX;
					this.__boundsRect.height *= this.__scaleY;
					this.__width = this.__boundsRect.width;
					this.__height = this.__boundsRect.height;
				} else {
					this.__width = this.__boundsRect.width * this.__scaleX;
					this.__height = this.__boundsRect.height * this.__scaleY;
				}
				gfx.boundsDirty = false;
			}
			this.___renderFlags &= -65;
		}
	}
	,toString: function() {
		return "[DisplayObject name=" + this.name + " id=" + this.___id + "]";
	}
	,setSurfaceVisible: function(inValue) {
		var gfx = this.__getGraphics();
		if(gfx != null && gfx.__surface != null) flash.Lib.__setSurfaceVisible(gfx.__surface,inValue);
	}
	,localToGlobal: function(point) {
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		return this.transform.__getFullMatrix(null).transformPoint(point);
	}
	,invalidateGraphics: function() {
		var gfx = this.__getGraphics();
		if(gfx != null) {
			gfx.__changed = true;
			gfx.__clearNextCycle = true;
		}
	}
	,hitTestPoint: function(x,y,shapeFlag) {
		if(shapeFlag == null) shapeFlag = false;
		var boundingBox = shapeFlag == null?true:!shapeFlag;
		if(!boundingBox) return this.__getObjectUnderPoint(new flash.geom.Point(x,y)) != null; else {
			var gfx = this.__getGraphics();
			if(gfx != null) {
				var extX = gfx.__extent.x;
				var extY = gfx.__extent.y;
				var local = this.globalToLocal(new flash.geom.Point(x,y));
				if(local.x - extX < 0 || local.y - extY < 0 || (local.x - extX) * this.get_scaleX() > this.get_width() || (local.y - extY) * this.get_scaleY() > this.get_height()) return false; else return true;
			}
			return false;
		}
	}
	,hitTestObject: function(obj) {
		if(obj != null && obj.parent != null && this.parent != null) {
			var currentBounds = this.getBounds(this);
			var targetBounds = obj.getBounds(this);
			return currentBounds.intersects(targetBounds);
		}
		return false;
	}
	,handleGraphicsUpdated: function(gfx) {
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
		this.__applyFilters(gfx.__surface);
		this.___renderFlags |= 32;
	}
	,globalToLocal: function(inPos) {
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		return this.transform.__getFullMatrix(null).invert().transformPoint(inPos);
	}
	,getSurfaceTransform: function(gfx) {
		var extent = gfx.__extentWithFilters;
		var fm = this.transform.__getFullMatrix(null);
		fm.__translateTransformed(extent.get_topLeft());
		return fm;
	}
	,getScreenBounds: function() {
		if(this.get__boundsInvalid()) this.validateBounds();
		return this.__boundsRect.clone();
	}
	,getRect: function(targetCoordinateSpace) {
		return this.getBounds(targetCoordinateSpace);
	}
	,getBounds: function(targetCoordinateSpace) {
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		if(this.get__boundsInvalid()) this.validateBounds();
		var m = this.transform.__getFullMatrix(null);
		if(targetCoordinateSpace != null) m.concat(targetCoordinateSpace.transform.__getFullMatrix(null).invert());
		var rect = this.__boundsRect.transform(m);
		return rect;
	}
	,drawToSurface: function(inSurface,matrix,inColorTransform,blendMode,clipRect,smoothing) {
		var oldAlpha = this.alpha;
		this.alpha = 1;
		this.__render(inSurface,clipRect);
		this.alpha = oldAlpha;
	}
	,dispatchEvent: function(event) {
		var result = this.__dispatchEvent(event);
		if(event.__getIsCancelled()) return true;
		if(event.bubbles && this.parent != null) this.parent.dispatchEvent(event);
		return result;
	}
	,__class__: flash.display.DisplayObject
	,__properties__: {set_filters:"set_filters",get_filters:"get_filters",set_height:"set_height",get_height:"get_height",set_mask:"set_mask",get_mask:"get_mask",get_mouseX:"get_mouseX",get_mouseY:"get_mouseY",set_parent:"set_parent",set_rotation:"set_rotation",get_rotation:"get_rotation",set_scaleX:"set_scaleX",get_scaleX:"get_scaleX",set_scaleY:"set_scaleY",get_scaleY:"get_scaleY",set_scrollRect:"set_scrollRect",get_scrollRect:"get_scrollRect",get_stage:"get_stage",set_transform:"set_transform",set_visible:"set_visible",get_visible:"get_visible",set_width:"set_width",get_width:"get_width",set_x:"set_x",get_x:"get_x",set_y:"set_y",get_y:"get_y",set___combinedVisible:"set___combinedVisible",get__bottommostSurface:"get__bottommostSurface",get__boundsInvalid:"get__boundsInvalid",get__matrixChainInvalid:"get__matrixChainInvalid",get__matrixInvalid:"get__matrixInvalid",get__topmostSurface:"get__topmostSurface"}
});
flash.display.InteractiveObject = function() {
	flash.display.DisplayObject.call(this);
	this.tabEnabled = false;
	this.mouseEnabled = true;
	this.doubleClickEnabled = true;
	this.set_tabIndex(0);
};
$hxClasses["flash.display.InteractiveObject"] = flash.display.InteractiveObject;
flash.display.InteractiveObject.__name__ = ["flash","display","InteractiveObject"];
flash.display.InteractiveObject.__super__ = flash.display.DisplayObject;
flash.display.InteractiveObject.prototype = $extend(flash.display.DisplayObject.prototype,{
	set_tabIndex: function(inIndex) {
		return this.__tabIndex = inIndex;
	}
	,get_tabIndex: function() {
		return this.__tabIndex;
	}
	,__getObjectUnderPoint: function(point) {
		if(!this.mouseEnabled) return null; else return flash.display.DisplayObject.prototype.__getObjectUnderPoint.call(this,point);
	}
	,toString: function() {
		return "[InteractiveObject name=" + this.name + " id=" + this.___id + "]";
	}
	,__class__: flash.display.InteractiveObject
	,__properties__: $extend(flash.display.DisplayObject.prototype.__properties__,{set_tabIndex:"set_tabIndex",get_tabIndex:"get_tabIndex"})
});
flash.display.DisplayObjectContainer = function() {
	this.__children = new Array();
	this.mouseChildren = true;
	this.tabChildren = true;
	flash.display.InteractiveObject.call(this);
	this.__combinedAlpha = this.alpha;
};
$hxClasses["flash.display.DisplayObjectContainer"] = flash.display.DisplayObjectContainer;
flash.display.DisplayObjectContainer.__name__ = ["flash","display","DisplayObjectContainer"];
flash.display.DisplayObjectContainer.__super__ = flash.display.InteractiveObject;
flash.display.DisplayObjectContainer.prototype = $extend(flash.display.InteractiveObject.prototype,{
	set_scrollRect: function(inValue) {
		inValue = flash.display.InteractiveObject.prototype.set_scrollRect.call(this,inValue);
		this.__unifyChildrenWithDOM();
		return inValue;
	}
	,set_visible: function(inVal) {
		this.set___combinedVisible(this.parent != null?this.parent.__combinedVisible && inVal:inVal);
		return flash.display.InteractiveObject.prototype.set_visible.call(this,inVal);
	}
	,get_numChildren: function() {
		return this.__children.length;
	}
	,set___combinedVisible: function(inVal) {
		if(inVal != this.__combinedVisible) {
			var _g = 0, _g1 = this.__children;
			while(_g < _g1.length) {
				var child = _g1[_g];
				++_g;
				child.set___combinedVisible(child.get_visible() && inVal);
			}
		}
		return flash.display.InteractiveObject.prototype.set___combinedVisible.call(this,inVal);
	}
	,set_filters: function(filters) {
		flash.display.InteractiveObject.prototype.set_filters.call(this,filters);
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			child.set_filters(filters);
		}
		return filters;
	}
	,__unifyChildrenWithDOM: function(lastMoveObj) {
		var obj = flash.display.InteractiveObject.prototype.__unifyChildrenWithDOM.call(this,lastMoveObj);
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			obj = child.__unifyChildrenWithDOM(obj);
			if(child.get_scrollRect() != null) obj = child;
		}
		return obj;
	}
	,__swapSurface: function(c1,c2) {
		if(this.__children[c1] == null) throw "Null element at index " + c1 + " length " + this.__children.length;
		if(this.__children[c2] == null) throw "Null element at index " + c2 + " length " + this.__children.length;
		var gfx1 = this.__children[c1].__getGraphics();
		var gfx2 = this.__children[c2].__getGraphics();
		if(gfx1 != null && gfx2 != null) {
			var surface1 = this.__children[c1].__scrollRect == null?gfx1.__surface:this.__children[c1].__getSrWindow();
			var surface2 = this.__children[c2].__scrollRect == null?gfx2.__surface:this.__children[c2].__getSrWindow();
			if(surface1 != null && surface2 != null) flash.Lib.__swapSurface(surface1,surface2);
		}
	}
	,__render: function(inMask,clipRect) {
		if(!this.__visible) return;
		if(clipRect == null && this.__scrollRect != null) clipRect = this.__scrollRect;
		flash.display.InteractiveObject.prototype.__render.call(this,inMask,clipRect);
		this.__combinedAlpha = this.parent != null?this.parent.__combinedAlpha * this.alpha:this.alpha;
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(child.__visible) {
				if(clipRect != null) {
					if((child.___renderFlags & 4) != 0 || (child.___renderFlags & 8) != 0) child.__validateMatrix();
				}
				child.__render(inMask,clipRect);
			}
		}
		if(this.__addedChildren) {
			this.__unifyChildrenWithDOM();
			this.__addedChildren = false;
		}
	}
	,__removeFromStage: function() {
		flash.display.InteractiveObject.prototype.__removeFromStage.call(this);
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			child.__removeFromStage();
		}
	}
	,__removeChild: function(child) {
		HxOverrides.remove(this.__children,child);
		child.__removeFromStage();
		child.set_parent(null);
		return child;
	}
	,__invalidateMatrix: function(local) {
		if(local == null) local = false;
		if(!((this.___renderFlags & 8) != 0) && !((this.___renderFlags & 4) != 0)) {
			var _g = 0, _g1 = this.__children;
			while(_g < _g1.length) {
				var child = _g1[_g];
				++_g;
				child.__invalidateMatrix();
			}
		}
		flash.display.InteractiveObject.prototype.__invalidateMatrix.call(this,local);
	}
	,__getObjectsUnderPoint: function(point,stack) {
		var l = this.__children.length - 1;
		var _g1 = 0, _g = this.__children.length;
		while(_g1 < _g) {
			var i = _g1++;
			var result = this.__children[l - i].__getObjectUnderPoint(point);
			if(result != null) stack.push(result);
		}
	}
	,__getObjectUnderPoint: function(point) {
		if(!this.get_visible()) return null;
		var l = this.__children.length - 1;
		var _g1 = 0, _g = this.__children.length;
		while(_g1 < _g) {
			var i = _g1++;
			var result = null;
			if(this.mouseEnabled) result = this.__children[l - i].__getObjectUnderPoint(point);
			if(result != null) return this.mouseChildren?result:this;
		}
		return flash.display.InteractiveObject.prototype.__getObjectUnderPoint.call(this,point);
	}
	,__contains: function(child) {
		if(child == null) return false;
		if(this == child) return true;
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var c = _g1[_g];
			++_g;
			if(c == child || c.__contains(child)) return true;
		}
		return false;
	}
	,__broadcast: function(event) {
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			child.__broadcast(event);
		}
		this.dispatchEvent(event);
	}
	,__addToStage: function(newParent,beforeSibling) {
		flash.display.InteractiveObject.prototype.__addToStage.call(this,newParent,beforeSibling);
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(child.__getGraphics() == null || !child.__isOnStage()) child.__addToStage(this);
		}
	}
	,validateBounds: function() {
		if(this.get__boundsInvalid()) {
			flash.display.InteractiveObject.prototype.validateBounds.call(this);
			var _g = 0, _g1 = this.__children;
			while(_g < _g1.length) {
				var obj = _g1[_g];
				++_g;
				if(obj.get_visible()) {
					var r = obj.getBounds(this);
					if(r.width != 0 || r.height != 0) {
						if(this.__boundsRect.width == 0 && this.__boundsRect.height == 0) this.__boundsRect = r.clone(); else this.__boundsRect.extendBounds(r);
					}
				}
			}
			if(this.scale9Grid != null) {
				this.__boundsRect.width *= this.__scaleX;
				this.__boundsRect.height *= this.__scaleY;
				this.__width = this.__boundsRect.width;
				this.__height = this.__boundsRect.height;
			} else {
				this.__width = this.__boundsRect.width * this.__scaleX;
				this.__height = this.__boundsRect.height * this.__scaleY;
			}
		}
	}
	,toString: function() {
		return "[DisplayObjectContainer name=" + this.name + " id=" + this.___id + "]";
	}
	,swapChildrenAt: function(child1,child2) {
		var swap = this.__children[child1];
		this.__children[child1] = this.__children[child2];
		this.__children[child2] = swap;
		swap = null;
	}
	,swapChildren: function(child1,child2) {
		var c1 = -1;
		var c2 = -1;
		var swap;
		var _g1 = 0, _g = this.__children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.__children[i] == child1) c1 = i; else if(this.__children[i] == child2) c2 = i;
		}
		if(c1 != -1 && c2 != -1) {
			swap = this.__children[c1];
			this.__children[c1] = this.__children[c2];
			this.__children[c2] = swap;
			swap = null;
			this.__swapSurface(c1,c2);
			child1.__unifyChildrenWithDOM();
			child2.__unifyChildrenWithDOM();
		}
	}
	,setChildIndex: function(child,index) {
		if(index > this.__children.length) throw "Invalid index position " + index;
		var oldIndex = this.getChildIndex(child);
		if(oldIndex < 0) {
			var msg = "setChildIndex : object " + child.name + " not found.";
			if(child.parent == this) {
				var realindex = -1;
				var _g1 = 0, _g = this.__children.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(this.__children[i] == child) {
						realindex = i;
						break;
					}
				}
				if(realindex != -1) msg += "Internal error: Real child index was " + Std.string(realindex); else msg += "Internal error: Child was not in __children array!";
			}
			throw msg;
		}
		if(index < oldIndex) {
			var i = oldIndex;
			while(i > index) {
				this.swapChildren(this.__children[i],this.__children[i - 1]);
				i--;
			}
		} else if(oldIndex < index) {
			var i = oldIndex;
			while(i < index) {
				this.swapChildren(this.__children[i],this.__children[i + 1]);
				i++;
			}
		}
	}
	,removeChildAt: function(index) {
		if(index >= 0 && index < this.__children.length) return this.__removeChild(this.__children[index]);
		throw "removeChildAt(" + index + ") : none found?";
	}
	,removeChild: function(inChild) {
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(child == inChild) return (function($this) {
				var $r;
				HxOverrides.remove($this.__children,child);
				child.__removeFromStage();
				child.set_parent(null);
				$r = child;
				return $r;
			}(this));
		}
		throw "removeChild : none found?";
	}
	,getObjectsUnderPoint: function(point) {
		var result = new Array();
		this.__getObjectsUnderPoint(point,result);
		return result;
	}
	,getChildIndex: function(inChild) {
		var _g1 = 0, _g = this.__children.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.__children[i] == inChild) return i;
		}
		return -1;
	}
	,getChildByName: function(inName) {
		var _g = 0, _g1 = this.__children;
		while(_g < _g1.length) {
			var child = _g1[_g];
			++_g;
			if(child.name == inName) return child;
		}
		return null;
	}
	,getChildAt: function(index) {
		if(index >= 0 && index < this.__children.length) return this.__children[index];
		throw "getChildAt : index out of bounds " + index + "/" + this.__children.length;
		return null;
	}
	,contains: function(child) {
		return this.__contains(child);
	}
	,addChildAt: function(object,index) {
		if(index > this.__children.length || index < 0) throw "Invalid index position " + index;
		this.__addedChildren = true;
		if(object.parent == this) {
			this.setChildIndex(object,index);
			return object;
		}
		if(index == this.__children.length) return this.addChild(object); else {
			if(this.__isOnStage()) object.__addToStage(this,this.__children[index]);
			this.__children.splice(index,0,object);
			object.set_parent(this);
		}
		return object;
	}
	,addChild: function(object) {
		if(object == null) throw "DisplayObjectContainer asked to add null child object";
		if(object == this) throw "Adding to self";
		this.__addedChildren = true;
		if(object.parent == this) {
			this.setChildIndex(object,this.__children.length - 1);
			return object;
		}
		object.set_parent(this);
		if(this.__isOnStage()) object.__addToStage(this);
		if(this.__children == null) this.__children = new Array();
		this.__children.push(object);
		return object;
	}
	,__class__: flash.display.DisplayObjectContainer
	,__properties__: $extend(flash.display.InteractiveObject.prototype.__properties__,{get_numChildren:"get_numChildren"})
});
flash.display.Sprite = function() {
	flash.display.DisplayObjectContainer.call(this);
	this.__graphics = new flash.display.Graphics();
	this.buttonMode = false;
};
$hxClasses["flash.display.Sprite"] = flash.display.Sprite;
flash.display.Sprite.__name__ = ["flash","display","Sprite"];
flash.display.Sprite.__super__ = flash.display.DisplayObjectContainer;
flash.display.Sprite.prototype = $extend(flash.display.DisplayObjectContainer.prototype,{
	set_useHandCursor: function(cursor) {
		if(cursor == this.useHandCursor) return cursor;
		if(this.__cursorCallbackOver != null) this.removeEventListener(flash.events.MouseEvent.ROLL_OVER,this.__cursorCallbackOver);
		if(this.__cursorCallbackOut != null) this.removeEventListener(flash.events.MouseEvent.ROLL_OUT,this.__cursorCallbackOut);
		if(!cursor) flash.Lib.__setCursor(flash._Lib.CursorType.Default); else {
			this.__cursorCallbackOver = function(_) {
				flash.Lib.__setCursor(flash._Lib.CursorType.Pointer);
			};
			this.__cursorCallbackOut = function(_) {
				flash.Lib.__setCursor(flash._Lib.CursorType.Default);
			};
			this.addEventListener(flash.events.MouseEvent.ROLL_OVER,this.__cursorCallbackOver);
			this.addEventListener(flash.events.MouseEvent.ROLL_OUT,this.__cursorCallbackOut);
		}
		this.useHandCursor = cursor;
		return cursor;
	}
	,get_graphics: function() {
		return this.__graphics;
	}
	,get_dropTarget: function() {
		return this.__dropTarget;
	}
	,__getGraphics: function() {
		return this.__graphics;
	}
	,toString: function() {
		return "[Sprite name=" + this.name + " id=" + this.___id + "]";
	}
	,stopDrag: function() {
		if(this.__isOnStage()) {
			this.get_stage().__stopDrag(this);
			var l = this.parent.__children.length - 1;
			var obj = this.get_stage();
			var _g1 = 0, _g = this.parent.__children.length;
			while(_g1 < _g) {
				var i = _g1++;
				var result = this.parent.__children[l - i].__getObjectUnderPoint(new flash.geom.Point(this.get_stage().get_mouseX(),this.get_stage().get_mouseY()));
				if(result != null) obj = result;
			}
			if(obj != this) this.__dropTarget = obj; else this.__dropTarget = this.get_stage();
		}
	}
	,startDrag: function(lockCenter,bounds) {
		if(lockCenter == null) lockCenter = false;
		if(this.__isOnStage()) this.get_stage().__startDrag(this,lockCenter,bounds);
	}
	,__class__: flash.display.Sprite
	,__properties__: $extend(flash.display.DisplayObjectContainer.prototype.__properties__,{get_dropTarget:"get_dropTarget",get_graphics:"get_graphics",set_useHandCursor:"set_useHandCursor"})
});
var Main = function() {
	this.lastStatus = "";
	this.UseGopher = true;
	flash.display.Sprite.call(this);
	this.whatToDo = new flash.text.TextField();
	this.whatToDo.selectable = false;
	this.whatToDo.set_x(50);
	this.whatToDo.set_y(90);
	this.whatToDo.set_width(350);
	this.whatToDo.set_text("USE YOUR MOUSE TO PUT THE GOPHER IN THE BOX");
	this.whatToDo.set_textColor(16711680);
	this.addChild(this.whatToDo);
	this.Code = new flash.display.Sprite();
	this.Code.addChild(new flash.display.Bitmap(openfl.Assets.getBitmapData("assets/code.png")));
	this.Code.set_x(400);
	this.Code.set_y(10);
	this.Logo = new flash.display.Sprite();
	this.Logo.addChild(new flash.display.Bitmap(openfl.Assets.getBitmapData("assets/gopher.png")));
	this.Logo.set_x(100);
	this.Logo.set_y(150);
	this.Logo.buttonMode = true;
	this.Destination = new flash.display.Sprite();
	this.Destination.get_graphics().beginFill(16119285);
	this.Destination.get_graphics().lineStyle(1,13421772);
	this.Destination.get_graphics().drawRect(0,0,this.Logo.get_width() + 10,this.Logo.get_height() + 10);
	this.Destination.set_x(300);
	this.Destination.set_y(145);
	this.addChild(this.Code);
	this.addChild(this.Destination);
	this.addChild(this.Logo);
	this.Logo.addEventListener(flash.events.MouseEvent.MOUSE_DOWN,$bind(this,this.Logo_onMouseDown));
	this.get_stage().addEventListener(flash.events.MouseEvent.MOUSE_MOVE,$bind(this,this.stage_onMouseMove));
	this.get_stage().addEventListener(flash.events.MouseEvent.MOUSE_UP,$bind(this,this.stage_onMouseUp));
	this.textField = new flash.text.TextField();
	this.textField.selectable = false;
	this.textField.set_x(305);
	this.textField.set_y(260);
	this.textField.set_width(200);
	this.textField.set_textColor(32768);
	this.textField.set_text("(initialising)");
	this.addChild(this.textField);
	tardis.Go.init();
	tardis.Go_main_MouseGoroutine.callFromHaxe();
	this.goTimer = new flash.utils.Timer(200);
	this.goTimer.addEventListener("timer",$bind(this,this.goTimerEvent));
	this.goTimer.start();
};
$hxClasses["Main"] = Main;
Main.__name__ = ["Main"];
Main.__super__ = flash.display.Sprite;
Main.prototype = $extend(flash.display.Sprite.prototype,{
	stage_onMouseUp: function(event) {
		tardis.Go_main_MouseUp.callFromHaxe(event.stageX,event.stageY);
	}
	,stage_onMouseMove: function(event) {
		tardis.Go_main_MouseMove.callFromHaxe(event.stageX,event.stageY);
	}
	,Logo_onMouseDown: function(event) {
		tardis.Go_main_MouseDown.callFromHaxe(event.stageX,event.stageY);
	}
	,goTimerEvent: function(e) {
		tardis.Scheduler.timerEventHandler(e);
		this.Logo.set_x(tardis.Go.main_SpriteX.ref());
		this.Logo.set_y(tardis.Go.main_SpriteY.ref());
		if(this.lastStatus != tardis.Go.main_Status.ref()) {
			this.lastStatus = tardis.Go.main_Status.ref();
			this.textField.set_text(this.lastStatus);
		}
		if(this.Destination.hitTestPoint(this.Logo.get_x(),this.Logo.get_y())) {
			if(this.UseGopher) {
				this.Logo.addChild(new flash.display.Bitmap(openfl.Assets.getBitmapData("assets/openfl.png")));
				this.UseGopher = false;
			}
		} else if(!this.UseGopher) {
			this.Logo.addChild(new flash.display.Bitmap(openfl.Assets.getBitmapData("assets/gopher.png")));
			this.UseGopher = true;
		}
	}
	,__class__: Main
});
var DocumentClass = function() {
	Main.call(this);
};
$hxClasses["DocumentClass"] = DocumentClass;
DocumentClass.__name__ = ["DocumentClass"];
DocumentClass.__super__ = Main;
DocumentClass.prototype = $extend(Main.prototype,{
	get_stage: function() {
		return flash.Lib.get_current().get_stage();
	}
	,__class__: DocumentClass
});
var openfl = {}
openfl.AssetLibrary = function() {
};
$hxClasses["openfl.AssetLibrary"] = openfl.AssetLibrary;
openfl.AssetLibrary.__name__ = ["openfl","AssetLibrary"];
openfl.AssetLibrary.prototype = {
	loadSound: function(id,handler) {
		handler(this.getSound(id));
	}
	,loadMusic: function(id,handler) {
		handler(this.getMusic(id));
	}
	,loadMovieClip: function(id,handler) {
		handler(this.getMovieClip(id));
	}
	,loadFont: function(id,handler) {
		handler(this.getFont(id));
	}
	,loadBytes: function(id,handler) {
		handler(this.getBytes(id));
	}
	,loadBitmapData: function(id,handler) {
		handler(this.getBitmapData(id));
	}
	,load: function(handler) {
		handler(this);
	}
	,isLocal: function(id,type) {
		return true;
	}
	,getSound: function(id) {
		return null;
	}
	,getPath: function(id) {
		return null;
	}
	,getMusic: function(id) {
		return this.getSound(id);
	}
	,getMovieClip: function(id) {
		return null;
	}
	,getFont: function(id) {
		return null;
	}
	,getBytes: function(id) {
		return null;
	}
	,getBitmapData: function(id) {
		return null;
	}
	,exists: function(id,type) {
		return false;
	}
	,__class__: openfl.AssetLibrary
}
var _Map = {}
_Map.Map_Impl_ = function() { }
$hxClasses["_Map.Map_Impl_"] = _Map.Map_Impl_;
_Map.Map_Impl_.__name__ = ["_Map","Map_Impl_"];
var DefaultAssetLibrary = function() {
	openfl.AssetLibrary.call(this);
	DefaultAssetLibrary.path.set("assets/code.png","assets/code.png");
	var value = Reflect.field(openfl.AssetType,"image".toUpperCase());
	DefaultAssetLibrary.type.set("assets/code.png",value);
	DefaultAssetLibrary.path.set("assets/gopher.png","assets/gopher.png");
	var value = Reflect.field(openfl.AssetType,"image".toUpperCase());
	DefaultAssetLibrary.type.set("assets/gopher.png",value);
	DefaultAssetLibrary.path.set("assets/openfl.png","assets/openfl.png");
	var value = Reflect.field(openfl.AssetType,"image".toUpperCase());
	DefaultAssetLibrary.type.set("assets/openfl.png",value);
};
$hxClasses["DefaultAssetLibrary"] = DefaultAssetLibrary;
DefaultAssetLibrary.__name__ = ["DefaultAssetLibrary"];
DefaultAssetLibrary.__super__ = openfl.AssetLibrary;
DefaultAssetLibrary.prototype = $extend(openfl.AssetLibrary.prototype,{
	loadSound: function(id,handler) {
		handler(this.getSound(id));
	}
	,loadMusic: function(id,handler) {
		handler(this.getMusic(id));
	}
	,loadFont: function(id,handler) {
		handler(this.getFont(id));
	}
	,loadBytes: function(id,handler) {
		if(DefaultAssetLibrary.path.exists(id)) {
			var loader = new flash.net.URLLoader();
			loader.addEventListener(flash.events.Event.COMPLETE,function(event) {
				var bytes = new flash.utils.ByteArray();
				bytes.writeUTFBytes(event.currentTarget.data);
				bytes.position = 0;
				handler(bytes);
			});
			loader.load(new flash.net.URLRequest(DefaultAssetLibrary.path.get(id)));
		} else handler(this.getBytes(id));
	}
	,loadBitmapData: function(id,handler) {
		if(DefaultAssetLibrary.path.exists(id)) {
			var loader = new flash.display.Loader();
			loader.contentLoaderInfo.addEventListener(flash.events.Event.COMPLETE,function(event) {
				handler((js.Boot.__cast(event.currentTarget.content , flash.display.Bitmap)).bitmapData);
			});
			loader.load(new flash.net.URLRequest(DefaultAssetLibrary.path.get(id)));
		} else handler(this.getBitmapData(id));
	}
	,isLocal: function(id,type) {
		return true;
	}
	,getSound: function(id) {
		return new flash.media.Sound(new flash.net.URLRequest(DefaultAssetLibrary.path.get(id)));
	}
	,getPath: function(id) {
		return DefaultAssetLibrary.path.get(id);
	}
	,getMusic: function(id) {
		return new flash.media.Sound(new flash.net.URLRequest(DefaultAssetLibrary.path.get(id)));
	}
	,getFont: function(id) {
		return js.Boot.__cast(Type.createInstance(DefaultAssetLibrary.className.get(id),[]) , flash.text.Font);
	}
	,getBytes: function(id) {
		var bytes = null;
		var data = ApplicationMain.urlLoaders.get(DefaultAssetLibrary.path.get(id)).data;
		if(js.Boot.__instanceof(data,String)) {
			bytes = new flash.utils.ByteArray();
			bytes.writeUTFBytes(data);
		} else if(js.Boot.__instanceof(data,flash.utils.ByteArray)) bytes = data; else bytes = null;
		if(bytes != null) {
			bytes.position = 0;
			return bytes;
		} else return null;
	}
	,getBitmapData: function(id) {
		return (js.Boot.__cast(ApplicationMain.loaders.get(DefaultAssetLibrary.path.get(id)).contentLoaderInfo.content , flash.display.Bitmap)).bitmapData;
	}
	,exists: function(id,type) {
		var assetType = DefaultAssetLibrary.type.get(id);
		if(assetType != null) {
			if(assetType == type || (type == openfl.AssetType.SOUND || type == openfl.AssetType.MUSIC) && (assetType == openfl.AssetType.MUSIC || assetType == openfl.AssetType.SOUND)) return true;
			if(type == openfl.AssetType.BINARY || type == null) return true;
		}
		return false;
	}
	,__class__: DefaultAssetLibrary
});
var EReg = function(r,opt) {
	opt = opt.split("u").join("");
	this.r = new RegExp(r,opt);
};
$hxClasses["EReg"] = EReg;
EReg.__name__ = ["EReg"];
EReg.prototype = {
	replace: function(s,by) {
		return s.replace(this.r,by);
	}
	,matchedPos: function() {
		if(this.r.m == null) throw "No string matched";
		return { pos : this.r.m.index, len : this.r.m[0].length};
	}
	,matchedRight: function() {
		if(this.r.m == null) throw "No string matched";
		var sz = this.r.m.index + this.r.m[0].length;
		return this.r.s.substr(sz,this.r.s.length - sz);
	}
	,matched: function(n) {
		return this.r.m != null && n >= 0 && n < this.r.m.length?this.r.m[n]:(function($this) {
			var $r;
			throw "EReg::matched";
			return $r;
		}(this));
	}
	,match: function(s) {
		if(this.r.global) this.r.lastIndex = 0;
		this.r.m = this.r.exec(s);
		this.r.s = s;
		return this.r.m != null;
	}
	,__class__: EReg
}
var HxOverrides = function() { }
$hxClasses["HxOverrides"] = HxOverrides;
HxOverrides.__name__ = ["HxOverrides"];
HxOverrides.strDate = function(s) {
	switch(s.length) {
	case 8:
		var k = s.split(":");
		var d = new Date();
		d.setTime(0);
		d.setUTCHours(k[0]);
		d.setUTCMinutes(k[1]);
		d.setUTCSeconds(k[2]);
		return d;
	case 10:
		var k = s.split("-");
		return new Date(k[0],k[1] - 1,k[2],0,0,0);
	case 19:
		var k = s.split(" ");
		var y = k[0].split("-");
		var t = k[1].split(":");
		return new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
	default:
		throw "Invalid date format : " + s;
	}
}
HxOverrides.cca = function(s,index) {
	var x = s.charCodeAt(index);
	if(x != x) return undefined;
	return x;
}
HxOverrides.substr = function(s,pos,len) {
	if(pos != null && pos != 0 && len != null && len < 0) return "";
	if(len == null) len = s.length;
	if(pos < 0) {
		pos = s.length + pos;
		if(pos < 0) pos = 0;
	} else if(len < 0) len = s.length + len - pos;
	return s.substr(pos,len);
}
HxOverrides.remove = function(a,obj) {
	var i = 0;
	var l = a.length;
	while(i < l) {
		if(a[i] == obj) {
			a.splice(i,1);
			return true;
		}
		i++;
	}
	return false;
}
HxOverrides.iter = function(a) {
	return { cur : 0, arr : a, hasNext : function() {
		return this.cur < this.arr.length;
	}, next : function() {
		return this.arr[this.cur++];
	}};
}
var List = function() {
	this.length = 0;
};
$hxClasses["List"] = List;
List.__name__ = ["List"];
List.prototype = {
	iterator: function() {
		return { h : this.h, hasNext : function() {
			return this.h != null;
		}, next : function() {
			if(this.h == null) return null;
			var x = this.h[0];
			this.h = this.h[1];
			return x;
		}};
	}
	,isEmpty: function() {
		return this.h == null;
	}
	,pop: function() {
		if(this.h == null) return null;
		var x = this.h[0];
		this.h = this.h[1];
		if(this.h == null) this.q = null;
		this.length--;
		return x;
	}
	,first: function() {
		return this.h == null?null:this.h[0];
	}
	,push: function(item) {
		var x = [item,this.h];
		this.h = x;
		if(this.q == null) this.q = x;
		this.length++;
	}
	,add: function(item) {
		var x = [item];
		if(this.h == null) this.h = x; else this.q[1] = x;
		this.q = x;
		this.length++;
	}
	,__class__: List
}
var IMap = function() { }
$hxClasses["IMap"] = IMap;
IMap.__name__ = ["IMap"];
var NMEPreloader = function() {
	flash.display.Sprite.call(this);
	var backgroundColor = this.getBackgroundColor();
	var r = backgroundColor >> 16 & 255;
	var g = backgroundColor >> 8 & 255;
	var b = backgroundColor & 255;
	var perceivedLuminosity = 0.299 * r + 0.587 * g + 0.114 * b;
	var color = 0;
	if(perceivedLuminosity < 70) color = 16777215;
	var x = 30;
	var height = 9;
	var y = this.getHeight() / 2 - height / 2;
	var width = this.getWidth() - x * 2;
	var padding = 3;
	this.outline = new flash.display.Sprite();
	this.outline.get_graphics().lineStyle(1,color,0.15,true);
	this.outline.get_graphics().drawRoundRect(0,0,width,height,padding * 2,padding * 2);
	this.outline.set_x(x);
	this.outline.set_y(y);
	this.addChild(this.outline);
	this.progress = new flash.display.Sprite();
	this.progress.get_graphics().beginFill(color,0.35);
	this.progress.get_graphics().drawRect(0,0,width - padding * 2,height - padding * 2);
	this.progress.set_x(x + padding);
	this.progress.set_y(y + padding);
	this.progress.set_scaleX(0);
	this.addChild(this.progress);
};
$hxClasses["NMEPreloader"] = NMEPreloader;
NMEPreloader.__name__ = ["NMEPreloader"];
NMEPreloader.__super__ = flash.display.Sprite;
NMEPreloader.prototype = $extend(flash.display.Sprite.prototype,{
	onUpdate: function(bytesLoaded,bytesTotal) {
		var percentLoaded = bytesLoaded / bytesTotal;
		if(percentLoaded > 1) percentLoaded == 1;
		this.progress.set_scaleX(percentLoaded);
	}
	,onLoaded: function() {
		this.dispatchEvent(new flash.events.Event(flash.events.Event.COMPLETE));
	}
	,onInit: function() {
	}
	,getWidth: function() {
		var width = 800;
		if(width > 0) return width; else return flash.Lib.get_current().get_stage().get_stageWidth();
	}
	,getHeight: function() {
		var height = 600;
		if(height > 0) return height; else return flash.Lib.get_current().get_stage().get_stageHeight();
	}
	,getBackgroundColor: function() {
		return 16777215;
	}
	,__class__: NMEPreloader
});
var Reflect = function() { }
$hxClasses["Reflect"] = Reflect;
Reflect.__name__ = ["Reflect"];
Reflect.hasField = function(o,field) {
	return Object.prototype.hasOwnProperty.call(o,field);
}
Reflect.field = function(o,field) {
	var v = null;
	try {
		v = o[field];
	} catch( e ) {
	}
	return v;
}
Reflect.getProperty = function(o,field) {
	var tmp;
	return o == null?null:o.__properties__ && (tmp = o.__properties__["get_" + field])?o[tmp]():o[field];
}
Reflect.fields = function(o) {
	var a = [];
	if(o != null) {
		var hasOwnProperty = Object.prototype.hasOwnProperty;
		for( var f in o ) {
		if(f != "__id__" && f != "hx__closures__" && hasOwnProperty.call(o,f)) a.push(f);
		}
	}
	return a;
}
Reflect.isFunction = function(f) {
	return typeof(f) == "function" && !(f.__name__ || f.__ename__);
}
Reflect.compareMethods = function(f1,f2) {
	if(f1 == f2) return true;
	if(!Reflect.isFunction(f1) || !Reflect.isFunction(f2)) return false;
	return f1.scope == f2.scope && f1.method == f2.method && f1.method != null;
}
Reflect.isObject = function(v) {
	if(v == null) return false;
	var t = typeof(v);
	return t == "string" || t == "object" && v.__enum__ == null || t == "function" && (v.__name__ || v.__ename__) != null;
}
Reflect.deleteField = function(o,field) {
	if(!Reflect.hasField(o,field)) return false;
	delete(o[field]);
	return true;
}
var Std = function() { }
$hxClasses["Std"] = Std;
Std.__name__ = ["Std"];
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std.parseInt = function(x) {
	var v = parseInt(x,10);
	if(v == 0 && (HxOverrides.cca(x,1) == 120 || HxOverrides.cca(x,1) == 88)) v = parseInt(x);
	if(isNaN(v)) return null;
	return v;
}
Std.parseFloat = function(x) {
	return parseFloat(x);
}
var StringBuf = function() {
	this.b = "";
};
$hxClasses["StringBuf"] = StringBuf;
StringBuf.__name__ = ["StringBuf"];
StringBuf.prototype = {
	__class__: StringBuf
}
var StringTools = function() { }
$hxClasses["StringTools"] = StringTools;
StringTools.__name__ = ["StringTools"];
StringTools.urlEncode = function(s) {
	return encodeURIComponent(s);
}
StringTools.urlDecode = function(s) {
	return decodeURIComponent(s.split("+").join(" "));
}
StringTools.startsWith = function(s,start) {
	return s.length >= start.length && HxOverrides.substr(s,0,start.length) == start;
}
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
}
StringTools.hex = function(n,digits) {
	var s = "";
	var hexChars = "0123456789ABCDEF";
	do {
		s = hexChars.charAt(n & 15) + s;
		n >>>= 4;
	} while(n > 0);
	if(digits != null) while(s.length < digits) s = "0" + s;
	return s;
}
var Type = function() { }
$hxClasses["Type"] = Type;
Type.__name__ = ["Type"];
Type.getClass = function(o) {
	if(o == null) return null;
	return o.__class__;
}
Type.getClassName = function(c) {
	var a = c.__name__;
	return a.join(".");
}
Type.resolveClass = function(name) {
	var cl = $hxClasses[name];
	if(cl == null || !cl.__name__) return null;
	return cl;
}
Type.resolveEnum = function(name) {
	var e = $hxClasses[name];
	if(e == null || !e.__ename__) return null;
	return e;
}
Type.createInstance = function(cl,args) {
	switch(args.length) {
	case 0:
		return new cl();
	case 1:
		return new cl(args[0]);
	case 2:
		return new cl(args[0],args[1]);
	case 3:
		return new cl(args[0],args[1],args[2]);
	case 4:
		return new cl(args[0],args[1],args[2],args[3]);
	case 5:
		return new cl(args[0],args[1],args[2],args[3],args[4]);
	case 6:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5]);
	case 7:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6]);
	case 8:
		return new cl(args[0],args[1],args[2],args[3],args[4],args[5],args[6],args[7]);
	default:
		throw "Too many arguments";
	}
	return null;
}
Type.createEmptyInstance = function(cl) {
	function empty() {}; empty.prototype = cl.prototype;
	return new empty();
}
Type.createEnum = function(e,constr,params) {
	var f = Reflect.field(e,constr);
	if(f == null) throw "No such constructor " + constr;
	if(Reflect.isFunction(f)) {
		if(params == null) throw "Constructor " + constr + " need parameters";
		return f.apply(e,params);
	}
	if(params != null && params.length != 0) throw "Constructor " + constr + " does not need parameters";
	return f;
}
Type.getEnumConstructs = function(e) {
	var a = e.__constructs__;
	return a.slice();
}
var haxe = {}
haxe.Timer = function() { }
$hxClasses["haxe.Timer"] = haxe.Timer;
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.stamp = function() {
	return new Date().getTime() / 1000;
}
flash.Lib = function(rootElement,width,height) {
	this.mKilled = false;
	this.__scr = rootElement;
	if(this.__scr == null) throw "Root element not found";
	this.__scr.style.setProperty("overflow","hidden","");
	this.__scr.style.setProperty("position","absolute","");
	if(this.__scr.style.getPropertyValue("width") != "100%") this.__scr.style.width = width + "px";
	if(this.__scr.style.getPropertyValue("height") != "100%") this.__scr.style.height = height + "px";
};
$hxClasses["flash.Lib"] = flash.Lib;
flash.Lib.__name__ = ["flash","Lib"];
flash.Lib.__properties__ = {get_current:"get_current"}
flash.Lib.addCallback = function(functionName,closure) {
	flash.Lib.mMe.__scr[functionName] = closure;
}
flash.Lib["as"] = function(v,c) {
	return js.Boot.__instanceof(v,c)?v:null;
}
flash.Lib.attach = function(name) {
	return new flash.display.MovieClip();
}
flash.Lib.getTimer = function() {
	return (haxe.Timer.stamp() - flash.Lib.starttime) * 1000 | 0;
}
flash.Lib.getURL = function(request,target) {
	if(target == null) target = "_blank";
	window.open(request.url,target);
}
flash.Lib.preventDefaultTouchMove = function() {
	js.Browser.document.addEventListener("touchmove",function(evt) {
		evt.preventDefault();
	},false);
}
flash.Lib.Run = function(tgt,width,height) {
	flash.Lib.mMe = new flash.Lib(tgt,width,height);
	var _g1 = 0, _g = tgt.attributes.length;
	while(_g1 < _g) {
		var i = _g1++;
		var attr = tgt.attributes.item(i);
		if(StringTools.startsWith(attr.name,"data-")) {
			if(attr.name == "data-" + "framerate") flash.Lib.__getStage().set_frameRate(Std.parseFloat(attr.value));
		}
	}
	var _g = 0, _g1 = flash.Lib.HTML_TOUCH_EVENT_TYPES;
	while(_g < _g1.length) {
		var type = _g1[_g];
		++_g;
		tgt.addEventListener(type,($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),true);
	}
	var _g = 0, _g1 = flash.Lib.HTML_TOUCH_ALT_EVENT_TYPES;
	while(_g < _g1.length) {
		var type = _g1[_g];
		++_g;
		tgt.addEventListener(type,($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),true);
	}
	var _g = 0, _g1 = flash.Lib.HTML_DIV_EVENT_TYPES;
	while(_g < _g1.length) {
		var type = _g1[_g];
		++_g;
		tgt.addEventListener(type,($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),true);
	}
	if(Reflect.hasField(js.Browser.window,"on" + "devicemotion")) js.Browser.window.addEventListener("devicemotion",($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),true);
	if(Reflect.hasField(js.Browser.window,"on" + "orientationchange")) js.Browser.window.addEventListener("orientationchange",($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),true);
	var _g = 0, _g1 = flash.Lib.HTML_WINDOW_EVENT_TYPES;
	while(_g < _g1.length) {
		var type = _g1[_g];
		++_g;
		js.Browser.window.addEventListener(type,($_=flash.Lib.__getStage(),$bind($_,$_.__queueStageEvent)),false);
	}
	if(tgt.style.backgroundColor != null && tgt.style.backgroundColor != "") flash.Lib.__getStage().set_backgroundColor(flash.Lib.__parseColor(tgt.style.backgroundColor,function(res,pos,cur) {
		return pos == 0?res | cur << 16:pos == 1?res | cur << 8:pos == 2?res | cur:(function($this) {
			var $r;
			throw "pos should be 0-2";
			return $r;
		}(this));
	})); else flash.Lib.__getStage().set_backgroundColor(16777215);
	flash.Lib.get_current().get_graphics().beginFill(flash.Lib.__getStage().get_backgroundColor());
	flash.Lib.get_current().get_graphics().drawRect(0,0,width,height);
	flash.Lib.__setSurfaceId(flash.Lib.get_current().get_graphics().__surface,"Root MovieClip");
	flash.Lib.__getStage().__updateNextWake();
	return flash.Lib.mMe;
}
flash.Lib.setUserScalable = function(isScalable) {
	if(isScalable == null) isScalable = true;
	var meta = js.Browser.document.createElement("meta");
	meta.name = "viewport";
	meta.content = "user-scalable=" + (isScalable?"yes":"no");
}
flash.Lib.trace = function(arg) {
	if(window.console != null) window.console.log(arg);
}
flash.Lib.__appendSurface = function(surface,before,after) {
	if(flash.Lib.mMe.__scr != null) {
		surface.style.setProperty("position","absolute","");
		surface.style.setProperty("left","0px","");
		surface.style.setProperty("top","0px","");
		surface.style.setProperty("transform-origin","0 0","");
		surface.style.setProperty("-moz-transform-origin","0 0","");
		surface.style.setProperty("-webkit-transform-origin","0 0","");
		surface.style.setProperty("-o-transform-origin","0 0","");
		surface.style.setProperty("-ms-transform-origin","0 0","");
		try {
			if(surface.localName == "canvas") surface.onmouseover = surface.onselectstart = function() {
				return false;
			};
		} catch( e ) {
		}
		if(before != null) before.parentNode.insertBefore(surface,before); else if(after != null && after.nextSibling != null) after.parentNode.insertBefore(surface,after.nextSibling); else flash.Lib.mMe.__scr.appendChild(surface);
	}
}
flash.Lib.__appendText = function(surface,container,text,wrap,isHtml) {
	var _g1 = 0, _g = surface.childNodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		surface.removeChild(surface.childNodes[i]);
	}
	if(isHtml) container.innerHTML = text; else container.appendChild(js.Browser.document.createTextNode(text));
	container.style.setProperty("position","relative","");
	container.style.setProperty("cursor","default","");
	if(!wrap) container.style.setProperty("white-space","nowrap","");
	surface.appendChild(container);
}
flash.Lib.__bootstrap = function() {
	if(flash.Lib.mMe == null) {
		var target = js.Browser.document.getElementById("haxe:openfl");
		if(target == null) target = js.Browser.document.createElement("div");
		var agent = navigator.userAgent;
		if(agent.indexOf("BlackBerry") > -1 && target.style.height == "100%") target.style.height = screen.height + "px";
		if(agent.indexOf("Android") > -1) {
			var version = Std.parseFloat(HxOverrides.substr(agent,agent.indexOf("Android") + 8,3));
			if(version <= 2.3) flash.Lib.mForce2DTransform = true;
		}
		flash.Lib.Run(target,flash.Lib.__getWidth(),flash.Lib.__getHeight());
	}
}
flash.Lib.__copyStyle = function(src,tgt) {
	tgt.id = src.id;
	var _g = 0, _g1 = ["left","top","transform","transform-origin","-moz-transform","-moz-transform-origin","-webkit-transform","-webkit-transform-origin","-o-transform","-o-transform-origin","opacity","display"];
	while(_g < _g1.length) {
		var prop = _g1[_g];
		++_g;
		tgt.style.setProperty(prop,src.style.getPropertyValue(prop),"");
	}
}
flash.Lib.__createSurfaceAnimationCSS = function(surface,data,template,templateFunc,fps,discrete,infinite) {
	if(infinite == null) infinite = false;
	if(discrete == null) discrete = false;
	if(fps == null) fps = 25;
	if(surface.id == null || surface.id == "") {
		flash.Lib.trace("Failed to create a CSS Style tag for a surface without an id attribute");
		return null;
	}
	var style = null;
	if(surface.getAttribute("data-openfl-anim") != null) style = js.Browser.document.getElementById(surface.getAttribute("data-openfl-anim")); else {
		style = flash.Lib.mMe.__scr.appendChild(js.Browser.document.createElement("style"));
		style.sheet.id = "__openfl_anim_" + surface.id + "__";
		surface.setAttribute("data-openfl-anim",style.sheet.id);
	}
	var keyframeStylesheetRule = "";
	var _g1 = 0, _g = data.length;
	while(_g1 < _g) {
		var i = _g1++;
		var perc = i / (data.length - 1) * 100;
		var frame = data[i];
		keyframeStylesheetRule += perc + "% { " + template.execute(templateFunc(frame)) + " } ";
	}
	var animationDiscreteRule = discrete?"steps(::steps::, end)":"";
	var animationInfiniteRule = infinite?"infinite":"";
	var animationTpl = "";
	var _g = 0, _g1 = ["animation","-moz-animation","-webkit-animation","-o-animation","-ms-animation"];
	while(_g < _g1.length) {
		var prefix = _g1[_g];
		++_g;
		animationTpl += prefix + ": ::id:: ::duration::s " + animationDiscreteRule + " " + animationInfiniteRule + "; ";
	}
	var animationStylesheetRule = new haxe.Template(animationTpl).execute({ id : surface.id, duration : data.length / fps, steps : 1});
	var rules = style.sheet.rules != null?style.sheet.rules:style.sheet.cssRules;
	var _g = 0, _g1 = ["","-moz-","-webkit-","-o-","-ms-"];
	while(_g < _g1.length) {
		var variant = _g1[_g];
		++_g;
		try {
			style.sheet.insertRule("@" + variant + "keyframes " + surface.id + " {" + keyframeStylesheetRule + "}",rules.length);
		} catch( e ) {
		}
	}
	style.sheet.insertRule("#" + surface.id + " { " + animationStylesheetRule + " } ",rules.length);
	return style;
}
flash.Lib.__designMode = function(mode) {
	js.Browser.document.designMode = mode?"on":"off";
}
flash.Lib.__disableFullScreen = function() {
}
flash.Lib.__disableRightClick = function() {
	if(flash.Lib.mMe != null) try {
		flash.Lib.mMe.__scr.oncontextmenu = function() {
			return false;
		};
	} catch( e ) {
		flash.Lib.trace("Disable right click not supported in this browser.");
	}
}
flash.Lib.__drawClippedImage = function(surface,tgtCtx,clipRect) {
	if(clipRect != null) {
		if(clipRect.x < 0) {
			clipRect.width += clipRect.x;
			clipRect.x = 0;
		}
		if(clipRect.y < 0) {
			clipRect.height += clipRect.y;
			clipRect.y = 0;
		}
		if(clipRect.width > surface.width - clipRect.x) clipRect.width = surface.width - clipRect.x;
		if(clipRect.height > surface.height - clipRect.y) clipRect.height = surface.height - clipRect.y;
		tgtCtx.drawImage(surface,clipRect.x,clipRect.y,clipRect.width,clipRect.height,clipRect.x,clipRect.y,clipRect.width,clipRect.height);
	} else tgtCtx.drawImage(surface,0,0);
}
flash.Lib.__drawSurfaceRect = function(surface,tgt,x,y,rect) {
	var tgtCtx = tgt.getContext("2d");
	tgt.width = rect.width;
	tgt.height = rect.height;
	tgtCtx.drawImage(surface,rect.x,rect.y,rect.width,rect.height,0,0,rect.width,rect.height);
	tgt.style.left = x + "px";
	tgt.style.top = y + "px";
}
flash.Lib.__drawToSurface = function(surface,tgt,matrix,alpha,clipRect,smoothing) {
	if(smoothing == null) smoothing = true;
	if(alpha == null) alpha = 1.0;
	var srcCtx = surface.getContext("2d");
	var tgtCtx = tgt.getContext("2d");
	tgtCtx.globalAlpha = alpha;
	flash.Lib.__setImageSmoothing(tgtCtx,smoothing);
	if(surface.width > 0 && surface.height > 0) {
		if(matrix != null) {
			tgtCtx.save();
			if(matrix.a == 1 && matrix.b == 0 && matrix.c == 0 && matrix.d == 1) tgtCtx.translate(matrix.tx,matrix.ty); else tgtCtx.setTransform(matrix.a,matrix.b,matrix.c,matrix.d,matrix.tx,matrix.ty);
			flash.Lib.__drawClippedImage(surface,tgtCtx,clipRect);
			tgtCtx.restore();
		} else flash.Lib.__drawClippedImage(surface,tgtCtx,clipRect);
	}
}
flash.Lib.__enableFullScreen = function() {
	if(flash.Lib.mMe != null) {
		var origWidth = flash.Lib.mMe.__scr.style.getPropertyValue("width");
		var origHeight = flash.Lib.mMe.__scr.style.getPropertyValue("height");
		flash.Lib.mMe.__scr.style.setProperty("width","100%","");
		flash.Lib.mMe.__scr.style.setProperty("height","100%","");
		flash.Lib.__disableFullScreen = function() {
			flash.Lib.mMe.__scr.style.setProperty("width",origWidth,"");
			flash.Lib.mMe.__scr.style.setProperty("height",origHeight,"");
		};
	}
}
flash.Lib.__enableRightClick = function() {
	if(flash.Lib.mMe != null) try {
		flash.Lib.mMe.__scr.oncontextmenu = null;
	} catch( e ) {
		flash.Lib.trace("Enable right click not supported in this browser.");
	}
}
flash.Lib.__fullScreenHeight = function() {
	return js.Browser.window.innerHeight;
}
flash.Lib.__fullScreenWidth = function() {
	return js.Browser.window.innerWidth;
}
flash.Lib.__getHeight = function() {
	var tgt = flash.Lib.mMe != null?flash.Lib.mMe.__scr:js.Browser.document.getElementById("haxe:openfl");
	return tgt != null && tgt.clientHeight > 0?tgt.clientHeight:500;
}
flash.Lib.__getStage = function() {
	if(flash.Lib.mStage == null) {
		var width = flash.Lib.__getWidth();
		var height = flash.Lib.__getHeight();
		flash.Lib.mStage = new flash.display.Stage(width,height);
	}
	return flash.Lib.mStage;
}
flash.Lib.__getWidth = function() {
	var tgt = flash.Lib.mMe != null?flash.Lib.mMe.__scr:js.Browser.document.getElementById("haxe:openfl");
	return tgt != null && tgt.clientWidth > 0?tgt.clientWidth:500;
}
flash.Lib.__isOnStage = function(surface) {
	var p = surface;
	while(p != null && p != flash.Lib.mMe.__scr) p = p.parentNode;
	return p == flash.Lib.mMe.__scr;
}
flash.Lib.__parseColor = function(str,cb) {
	var re = new EReg("rgb\\(([0-9]*), ?([0-9]*), ?([0-9]*)\\)","");
	var hex = new EReg("#([0-9a-zA-Z][0-9a-zA-Z])([0-9a-zA-Z][0-9a-zA-Z])([0-9a-zA-Z][0-9a-zA-Z])","");
	if(re.match(str)) {
		var col = 0;
		var _g = 1;
		while(_g < 4) {
			var pos = _g++;
			var v = Std.parseInt(re.matched(pos));
			col = cb(col,pos - 1,v);
		}
		return col;
	} else if(hex.match(str)) {
		var col = 0;
		var _g = 1;
		while(_g < 4) {
			var pos = _g++;
			var v = "0x" + hex.matched(pos) & 255;
			v = cb(col,pos - 1,v);
		}
		return col;
	} else throw "Cannot parse color '" + str + "'.";
}
flash.Lib.__removeSurface = function(surface) {
	if(flash.Lib.mMe.__scr != null) {
		var anim = surface.getAttribute("data-openfl-anim");
		if(anim != null) {
			var style = js.Browser.document.getElementById(anim);
			if(style != null) flash.Lib.mMe.__scr.removeChild(style);
		}
		if(surface.parentNode != null) surface.parentNode.removeChild(surface);
	}
	return surface;
}
flash.Lib.__setSurfaceBorder = function(surface,color,size) {
	surface.style.setProperty("border-color","#" + StringTools.hex(color),"");
	surface.style.setProperty("border-style","solid","");
	surface.style.setProperty("border-width",size + "px","");
	surface.style.setProperty("border-collapse","collapse","");
}
flash.Lib.__setSurfaceClipping = function(surface,rect) {
}
flash.Lib.__setSurfaceFont = function(surface,font,bold,size,color,align,lineHeight) {
	surface.style.setProperty("font-family",font,"");
	surface.style.setProperty("font-weight",Std.string(bold),"");
	surface.style.setProperty("color","#" + StringTools.hex(color),"");
	surface.style.setProperty("font-size",size + "px","");
	surface.style.setProperty("text-align",align,"");
	surface.style.setProperty("line-height",lineHeight + "px","");
}
flash.Lib.__setSurfaceOpacity = function(surface,alpha) {
	surface.style.setProperty("opacity",Std.string(alpha),"");
}
flash.Lib.__setSurfacePadding = function(surface,padding,margin,display) {
	surface.style.setProperty("padding",padding + "px","");
	surface.style.setProperty("margin",margin + "px","");
	surface.style.setProperty("top",padding + 2 + "px","");
	surface.style.setProperty("right",padding + 1 + "px","");
	surface.style.setProperty("left",padding + 1 + "px","");
	surface.style.setProperty("bottom",padding + 1 + "px","");
	surface.style.setProperty("display",display?"inline":"block","");
}
flash.Lib.__setSurfaceTransform = function(surface,matrix) {
	if(matrix.a == 1 && matrix.b == 0 && matrix.c == 0 && matrix.d == 1 && surface.getAttribute("data-openfl-anim") == null) {
		surface.style.left = matrix.tx + "px";
		surface.style.top = matrix.ty + "px";
		surface.style.setProperty("transform","","");
		surface.style.setProperty("-moz-transform","","");
		surface.style.setProperty("-webkit-transform","","");
		surface.style.setProperty("-o-transform","","");
		surface.style.setProperty("-ms-transform","","");
	} else {
		surface.style.left = "0px";
		surface.style.top = "0px";
		surface.style.setProperty("transform","matrix(" + matrix.a + ", " + matrix.b + ", " + matrix.c + ", " + matrix.d + ", " + matrix.tx + ", " + matrix.ty + ")","");
		surface.style.setProperty("-moz-transform","matrix(" + matrix.a + ", " + matrix.b + ", " + matrix.c + ", " + matrix.d + ", " + matrix.tx + "px, " + matrix.ty + "px)","");
		if(!flash.Lib.mForce2DTransform) surface.style.setProperty("-webkit-transform","matrix3d(" + matrix.a + ", " + matrix.b + ", " + "0, 0, " + matrix.c + ", " + matrix.d + ", " + "0, 0, 0, 0, 1, 0, " + matrix.tx + ", " + matrix.ty + ", " + "0, 1" + ")",""); else surface.style.setProperty("-webkit-transform","matrix(" + matrix.a + ", " + matrix.b + ", " + matrix.c + ", " + matrix.d + ", " + matrix.tx + ", " + matrix.ty + ")","");
		surface.style.setProperty("-o-transform","matrix(" + matrix.a + ", " + matrix.b + ", " + matrix.c + ", " + matrix.d + ", " + matrix.tx + ", " + matrix.ty + ")","");
		surface.style.setProperty("-ms-transform","matrix(" + matrix.a + ", " + matrix.b + ", " + matrix.c + ", " + matrix.d + ", " + matrix.tx + ", " + matrix.ty + ")","");
	}
}
flash.Lib.__setSurfaceZIndexAfter = function(surface1,surface2) {
	if(surface1 != null && surface2 != null) {
		if(surface1.parentNode != surface2.parentNode && surface2.parentNode != null) surface2.parentNode.appendChild(surface1);
		if(surface2.parentNode != null) {
			var nextSibling = surface2.nextSibling;
			if(surface1.previousSibling != surface2) {
				var swap = flash.Lib.__removeSurface(surface1);
				if(nextSibling == null) surface2.parentNode.appendChild(swap); else surface2.parentNode.insertBefore(swap,nextSibling);
			}
		}
	}
}
flash.Lib.__swapSurface = function(surface1,surface2) {
	var parent1 = surface1.parentNode;
	var parent2 = surface2.parentNode;
	if(parent1 != null && parent2 != null) {
		if(parent1 == parent2) {
			var next1 = surface1.nextSibling;
			var next2 = surface2.nextSibling;
			if(next1 == surface2) parent1.insertBefore(surface2,surface1); else if(next2 == surface1) parent1.insertBefore(surface1,surface2); else {
				parent1.replaceChild(surface2,surface1);
				if(next2 != null) parent1.insertBefore(surface1,next2); else parent1.appendChild(surface1);
			}
		} else {
			var next2 = surface2.nextSibling;
			parent1.replaceChild(surface2,surface1);
			if(next2 != null) parent2.insertBefore(surface1,next2); else parent2.appendChild(surface1);
		}
	}
}
flash.Lib.__setContentEditable = function(surface,contentEditable) {
	if(contentEditable == null) contentEditable = true;
	surface.setAttribute("contentEditable",contentEditable?"true":"false");
}
flash.Lib.__setCursor = function(type) {
	if(flash.Lib.mMe != null) flash.Lib.mMe.__scr.style.cursor = (function($this) {
		var $r;
		switch( (type)[1] ) {
		case 0:
			$r = "pointer";
			break;
		case 1:
			$r = "text";
			break;
		default:
			$r = "default";
		}
		return $r;
	}(this));
}
flash.Lib.__setImageSmoothing = function(context,enabled) {
	var _g = 0, _g1 = ["imageSmoothingEnabled","mozImageSmoothingEnabled","webkitImageSmoothingEnabled"];
	while(_g < _g1.length) {
		var variant = _g1[_g];
		++_g;
		context[variant] = enabled;
	}
}
flash.Lib.__setSurfaceAlign = function(surface,align) {
	surface.style.setProperty("text-align",align,"");
}
flash.Lib.__setSurfaceId = function(surface,name) {
	var regex = new EReg("[^a-zA-Z0-9\\-]","g");
	surface.id = regex.replace(name,"_");
}
flash.Lib.__setSurfaceRotation = function(surface,rotate) {
	surface.style.setProperty("transform","rotate(" + rotate + "deg)","");
	surface.style.setProperty("-moz-transform","rotate(" + rotate + "deg)","");
	surface.style.setProperty("-webkit-transform","rotate(" + rotate + "deg)","");
	surface.style.setProperty("-o-transform","rotate(" + rotate + "deg)","");
	surface.style.setProperty("-ms-transform","rotate(" + rotate + "deg)","");
}
flash.Lib.__setSurfaceScale = function(surface,scale) {
	surface.style.setProperty("transform","scale(" + scale + ")","");
	surface.style.setProperty("-moz-transform","scale(" + scale + ")","");
	surface.style.setProperty("-webkit-transform","scale(" + scale + ")","");
	surface.style.setProperty("-o-transform","scale(" + scale + ")","");
	surface.style.setProperty("-ms-transform","scale(" + scale + ")","");
}
flash.Lib.__setSurfaceSpritesheetAnimation = function(surface,spec,fps) {
	if(spec.length == 0) return surface;
	var div = js.Browser.document.createElement("div");
	div.style.backgroundImage = "url(" + surface.toDataURL("image/png") + ")";
	div.id = surface.id;
	var keyframeTpl = new haxe.Template("background-position: ::left::px ::top::px; width: ::width::px; height: ::height::px; ");
	var templateFunc = function(frame) {
		return { left : -frame.x, top : -frame.y, width : frame.width, height : frame.height};
	};
	flash.Lib.__createSurfaceAnimationCSS(div,spec,keyframeTpl,templateFunc,fps,true,true);
	if(flash.Lib.__isOnStage(surface)) {
		flash.Lib.__appendSurface(div);
		flash.Lib.__copyStyle(surface,div);
		flash.Lib.__swapSurface(surface,div);
		flash.Lib.__removeSurface(surface);
	} else flash.Lib.__copyStyle(surface,div);
	return div;
}
flash.Lib.__setSurfaceVisible = function(surface,visible) {
	if(visible) surface.style.setProperty("display","block",""); else surface.style.setProperty("display","none","");
}
flash.Lib.__setTextDimensions = function(surface,width,height,align) {
	surface.style.setProperty("width",width + "px","");
	surface.style.setProperty("height",height + "px","");
	surface.style.setProperty("overflow","hidden","");
	surface.style.setProperty("text-align",align,"");
}
flash.Lib.__surfaceHitTest = function(surface,x,y) {
	var _g1 = 0, _g = surface.childNodes.length;
	while(_g1 < _g) {
		var i = _g1++;
		var node = surface.childNodes[i];
		if(x >= node.offsetLeft && x <= node.offsetLeft + node.offsetWidth && y >= node.offsetTop && y <= node.offsetTop + node.offsetHeight) return true;
	}
	return false;
}
flash.Lib.get_current = function() {
	if(flash.Lib.mMainClassRoot == null) {
		flash.Lib.mMainClassRoot = new flash.display.MovieClip();
		flash.Lib.mCurrent = flash.Lib.mMainClassRoot;
		flash.Lib.__getStage().addChild(flash.Lib.mCurrent);
	}
	return flash.Lib.mMainClassRoot;
}
flash.Lib.prototype = {
	__class__: flash.Lib
}
flash._Lib = {}
flash._Lib.CursorType = $hxClasses["flash._Lib.CursorType"] = { __ename__ : true, __constructs__ : ["Pointer","Text","Default"] }
flash._Lib.CursorType.Pointer = ["Pointer",0];
flash._Lib.CursorType.Pointer.toString = $estr;
flash._Lib.CursorType.Pointer.__enum__ = flash._Lib.CursorType;
flash._Lib.CursorType.Text = ["Text",1];
flash._Lib.CursorType.Text.toString = $estr;
flash._Lib.CursorType.Text.__enum__ = flash._Lib.CursorType;
flash._Lib.CursorType.Default = ["Default",2];
flash._Lib.CursorType.Default.toString = $estr;
flash._Lib.CursorType.Default.__enum__ = flash._Lib.CursorType;
flash._Vector = {}
flash._Vector.Vector_Impl_ = function() { }
$hxClasses["flash._Vector.Vector_Impl_"] = flash._Vector.Vector_Impl_;
flash._Vector.Vector_Impl_.__name__ = ["flash","_Vector","Vector_Impl_"];
flash._Vector.Vector_Impl_.__properties__ = {set_fixed:"set_fixed",get_fixed:"get_fixed",set_length:"set_length",get_length:"get_length"}
flash._Vector.Vector_Impl_._new = function(length,fixed) {
	return new Array();
}
flash._Vector.Vector_Impl_.concat = function(this1,a) {
	return this1.concat(a);
}
flash._Vector.Vector_Impl_.copy = function(this1) {
	return this1.slice();
}
flash._Vector.Vector_Impl_.iterator = function(this1) {
	return HxOverrides.iter(this1);
}
flash._Vector.Vector_Impl_.join = function(this1,sep) {
	return this1.join(sep);
}
flash._Vector.Vector_Impl_.pop = function(this1) {
	return this1.pop();
}
flash._Vector.Vector_Impl_.push = function(this1,x) {
	return this1.push(x);
}
flash._Vector.Vector_Impl_.reverse = function(this1) {
	this1.reverse();
}
flash._Vector.Vector_Impl_.shift = function(this1) {
	return this1.shift();
}
flash._Vector.Vector_Impl_.unshift = function(this1,x) {
	this1.unshift(x);
}
flash._Vector.Vector_Impl_.slice = function(this1,pos,end) {
	return this1.slice(pos,end);
}
flash._Vector.Vector_Impl_.sort = function(this1,f) {
	this1.sort(f);
}
flash._Vector.Vector_Impl_.splice = function(this1,pos,len) {
	return this1.splice(pos,len);
}
flash._Vector.Vector_Impl_.toString = function(this1) {
	return this1.toString();
}
flash._Vector.Vector_Impl_.indexOf = function(this1,x,from) {
	if(from == null) from = 0;
	var _g1 = from, _g = this1.length;
	while(_g1 < _g) {
		var i = _g1++;
		if(this1[i] == x) return i;
	}
	return -1;
}
flash._Vector.Vector_Impl_.lastIndexOf = function(this1,x,from) {
	if(from == null) from = 0;
	var i = this1.length - 1;
	while(i >= from) {
		if(this1[i] == x) return i;
		i--;
	}
	return -1;
}
flash._Vector.Vector_Impl_.ofArray = function(a) {
	return flash._Vector.Vector_Impl_.concat(flash._Vector.Vector_Impl_._new(),a);
}
flash._Vector.Vector_Impl_.convert = function(v) {
	return v;
}
flash._Vector.Vector_Impl_.fromArray = function(a) {
	return a;
}
flash._Vector.Vector_Impl_.toArray = function(this1) {
	return this1;
}
flash._Vector.Vector_Impl_.get_length = function(this1) {
	return this1.length;
}
flash._Vector.Vector_Impl_.set_length = function(this1,value) {
	if(value < this1.length) this1 = this1.slice(0,value);
	while(value > this1.length) this1.push(null);
	return value;
}
flash._Vector.Vector_Impl_.get_fixed = function(this1) {
	return false;
}
flash._Vector.Vector_Impl_.set_fixed = function(this1,value) {
	return value;
}
flash.accessibility = {}
flash.accessibility.AccessibilityProperties = function() {
	this.description = "";
	this.forceSimple = false;
	this.name = "";
	this.noAutoLabeling = false;
	this.shortcut = "";
	this.silent = false;
};
$hxClasses["flash.accessibility.AccessibilityProperties"] = flash.accessibility.AccessibilityProperties;
flash.accessibility.AccessibilityProperties.__name__ = ["flash","accessibility","AccessibilityProperties"];
flash.accessibility.AccessibilityProperties.prototype = {
	__class__: flash.accessibility.AccessibilityProperties
}
flash.display.Bitmap = function(inBitmapData,inPixelSnapping,inSmoothing) {
	if(inSmoothing == null) inSmoothing = false;
	flash.display.DisplayObject.call(this);
	this.pixelSnapping = inPixelSnapping;
	this.smoothing = inSmoothing;
	if(inBitmapData != null) {
		this.set_bitmapData(inBitmapData);
		if(this.bitmapData.__referenceCount == 1) this.__graphics = new flash.display.Graphics(this.bitmapData.___textureBuffer);
	}
	if(this.pixelSnapping == null) this.pixelSnapping = flash.display.PixelSnapping.AUTO;
	if(this.__graphics == null) this.__graphics = new flash.display.Graphics();
	if(this.bitmapData != null) this.__render();
};
$hxClasses["flash.display.Bitmap"] = flash.display.Bitmap;
flash.display.Bitmap.__name__ = ["flash","display","Bitmap"];
flash.display.Bitmap.__super__ = flash.display.DisplayObject;
flash.display.Bitmap.prototype = $extend(flash.display.DisplayObject.prototype,{
	set_bitmapData: function(inBitmapData) {
		if(inBitmapData != this.bitmapData) {
			if(this.bitmapData != null) {
				this.bitmapData.__referenceCount--;
				if(this.__graphics.__surface == this.bitmapData.___textureBuffer) flash.Lib.__setSurfaceOpacity(this.bitmapData.___textureBuffer,0);
			}
			if(inBitmapData != null) inBitmapData.__referenceCount++;
		}
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
		this.bitmapData = inBitmapData;
		return inBitmapData;
	}
	,__render: function(inMask,clipRect) {
		if(!this.__combinedVisible) return;
		if(this.bitmapData == null) return;
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		if(this.bitmapData.___textureBuffer != this.__graphics.__surface) {
			var imageDataLease = this.bitmapData.__lease;
			if(imageDataLease != null && (this.__currentLease == null || imageDataLease.seed != this.__currentLease.seed || imageDataLease.time != this.__currentLease.time)) {
				var srcCanvas = this.bitmapData.___textureBuffer;
				this.__graphics.__surface.width = srcCanvas.width;
				this.__graphics.__surface.height = srcCanvas.height;
				this.__graphics.clear();
				flash.Lib.__drawToSurface(srcCanvas,this.__graphics.__surface);
				this.__currentLease = imageDataLease.clone();
				this.___renderFlags |= 64;
				if(this.parent != null) this.parent.___renderFlags |= 64;
				this.__applyFilters(this.__graphics.__surface);
				this.___renderFlags |= 32;
			}
		}
		if(inMask != null) {
			this.__applyFilters(this.__graphics.__surface);
			var m = this.getBitmapSurfaceTransform(this.__graphics);
			flash.Lib.__drawToSurface(this.__graphics.__surface,inMask,m,(this.parent != null?this.parent.__combinedAlpha:1) * this.alpha,clipRect,this.smoothing);
		} else {
			if((this.___renderFlags & 32) != 0) {
				var m = this.getBitmapSurfaceTransform(this.__graphics);
				flash.Lib.__setSurfaceTransform(this.__graphics.__surface,m);
				this.___renderFlags &= -33;
			}
			if(!this.__init) {
				flash.Lib.__setSurfaceOpacity(this.__graphics.__surface,0);
				this.__init = true;
			} else flash.Lib.__setSurfaceOpacity(this.__graphics.__surface,(this.parent != null?this.parent.__combinedAlpha:1) * this.alpha);
		}
	}
	,__getObjectUnderPoint: function(point) {
		if(!this.get_visible()) return null; else if(this.bitmapData != null) {
			var local = this.globalToLocal(point);
			if(local.x < 0 || local.y < 0 || local.x > this.get_width() / this.get_scaleX() || local.y > this.get_height() / this.get_scaleY()) return null; else return this;
		} else return flash.display.DisplayObject.prototype.__getObjectUnderPoint.call(this,point);
	}
	,__getGraphics: function() {
		return this.__graphics;
	}
	,validateBounds: function() {
		if(this.get__boundsInvalid()) {
			flash.display.DisplayObject.prototype.validateBounds.call(this);
			if(this.bitmapData != null) {
				var r = new flash.geom.Rectangle(0,0,this.bitmapData.get_width(),this.bitmapData.get_height());
				if(r.width != 0 || r.height != 0) {
					if(this.__boundsRect.width == 0 && this.__boundsRect.height == 0) this.__boundsRect = r.clone(); else this.__boundsRect.extendBounds(r);
				}
			}
			if(this.scale9Grid != null) {
				this.__boundsRect.width *= this.__scaleX;
				this.__boundsRect.height *= this.__scaleY;
				this.__width = this.__boundsRect.width;
				this.__height = this.__boundsRect.height;
			} else {
				this.__width = this.__boundsRect.width * this.__scaleX;
				this.__height = this.__boundsRect.height * this.__scaleY;
			}
		}
	}
	,toString: function() {
		return "[Bitmap name=" + this.name + " id=" + this.___id + "]";
	}
	,getBitmapSurfaceTransform: function(gfx) {
		var extent = gfx.__extentWithFilters;
		var fm = this.transform.__getFullMatrix(null);
		fm.__translateTransformed(extent.get_topLeft());
		return fm;
	}
	,__class__: flash.display.Bitmap
	,__properties__: $extend(flash.display.DisplayObject.prototype.__properties__,{set_bitmapData:"set_bitmapData"})
});
flash.display.BitmapData = function(width,height,transparent,inFillColor) {
	if(inFillColor == null) inFillColor = -1;
	if(transparent == null) transparent = true;
	this.__locked = false;
	this.__referenceCount = 0;
	this.__leaseNum = 0;
	this.__lease = new flash.display.ImageDataLease();
	this.__lease.set(this.__leaseNum++,new Date().getTime());
	this.___textureBuffer = js.Browser.document.createElement("canvas");
	this.___textureBuffer.width = width;
	this.___textureBuffer.height = height;
	this.___id = flash.utils.Uuid.uuid();
	flash.Lib.__setSurfaceId(this.___textureBuffer,this.___id);
	this.__transparent = transparent;
	this.rect = new flash.geom.Rectangle(0,0,width,height);
	if(this.__transparent) {
		this.__transparentFiller = js.Browser.document.createElement("canvas");
		this.__transparentFiller.width = width;
		this.__transparentFiller.height = height;
		var ctx = this.__transparentFiller.getContext("2d");
		ctx.fillStyle = "rgba(0,0,0,0);";
		ctx.fill();
	}
	if(inFillColor != null && width > 0 && height > 0) {
		if(!this.__transparent) inFillColor |= -16777216;
		this.__initColor = inFillColor;
		this.__fillRect(this.rect,inFillColor);
	}
};
$hxClasses["flash.display.BitmapData"] = flash.display.BitmapData;
flash.display.BitmapData.__name__ = ["flash","display","BitmapData"];
flash.display.BitmapData.__interfaces__ = [flash.display.IBitmapDrawable];
flash.display.BitmapData.getRGBAPixels = function(bitmapData) {
	var p = bitmapData.getPixels(new flash.geom.Rectangle(0,0,bitmapData.___textureBuffer != null?bitmapData.___textureBuffer.width:0,bitmapData.___textureBuffer != null?bitmapData.___textureBuffer.height:0));
	var num = (bitmapData.___textureBuffer != null?bitmapData.___textureBuffer.width:0) * (bitmapData.___textureBuffer != null?bitmapData.___textureBuffer.height:0);
	p.position = 0;
	var _g = 0;
	while(_g < num) {
		var i = _g++;
		var pos = p.position;
		var alpha = p.readByte();
		var red = p.readByte();
		var green = p.readByte();
		var blue = p.readByte();
		p.position = pos;
		p.writeByte(red);
		p.writeByte(green);
		p.writeByte(blue);
		p.writeByte(alpha);
	}
	return p;
}
flash.display.BitmapData.loadFromBase64 = function(base64,type,onload) {
	var bitmapData = new flash.display.BitmapData(0,0);
	bitmapData.__loadFromBase64(base64,type,onload);
	return bitmapData;
}
flash.display.BitmapData.loadFromBytes = function(bytes,inRawAlpha,onload) {
	var bitmapData = new flash.display.BitmapData(0,0);
	bitmapData.__loadFromBytes(bytes,inRawAlpha,onload);
	return bitmapData;
}
flash.display.BitmapData.__base64Encode = function(bytes) {
	var blob = "";
	var codex = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	bytes.position = 0;
	while(bytes.position < bytes.length) {
		var by1 = 0, by2 = 0, by3 = 0;
		by1 = bytes.readByte();
		if(bytes.position < bytes.length) by2 = bytes.readByte();
		if(bytes.position < bytes.length) by3 = bytes.readByte();
		var by4 = 0, by5 = 0, by6 = 0, by7 = 0;
		by4 = by1 >> 2;
		by5 = (by1 & 3) << 4 | by2 >> 4;
		by6 = (by2 & 15) << 2 | by3 >> 6;
		by7 = by3 & 63;
		blob += codex.charAt(by4);
		blob += codex.charAt(by5);
		if(bytes.position < bytes.length) blob += codex.charAt(by6); else blob += "=";
		if(bytes.position < bytes.length) blob += codex.charAt(by7); else blob += "=";
	}
	return blob;
}
flash.display.BitmapData.__createFromHandle = function(inHandle) {
	var result = new flash.display.BitmapData(0,0);
	result.___textureBuffer = inHandle;
	return result;
}
flash.display.BitmapData.__isJPG = function(bytes) {
	bytes.position = 0;
	return bytes.readByte() == 255 && bytes.readByte() == 216;
}
flash.display.BitmapData.__isPNG = function(bytes) {
	bytes.position = 0;
	return bytes.readByte() == 137 && bytes.readByte() == 80 && bytes.readByte() == 78 && bytes.readByte() == 71 && bytes.readByte() == 13 && bytes.readByte() == 10 && bytes.readByte() == 26 && bytes.readByte() == 10;
}
flash.display.BitmapData.prototype = {
	get_width: function() {
		if(this.___textureBuffer != null) return this.___textureBuffer.width; else return 0;
	}
	,get_transparent: function() {
		return this.__transparent;
	}
	,get_height: function() {
		if(this.___textureBuffer != null) return this.___textureBuffer.height; else return 0;
	}
	,__onLoad: function(data,e) {
		var canvas = data.texture;
		var width = data.image.width;
		var height = data.image.height;
		canvas.width = width;
		canvas.height = height;
		var ctx = canvas.getContext("2d");
		ctx.drawImage(data.image,0,0,width,height);
		data.bitmapData.width = width;
		data.bitmapData.height = height;
		data.bitmapData.rect = new flash.geom.Rectangle(0,0,width,height);
		data.bitmapData.__buildLease();
		if(data.inLoader != null) {
			var e1 = new flash.events.Event(flash.events.Event.COMPLETE);
			e1.target = data.inLoader;
			data.inLoader.dispatchEvent(e1);
		}
	}
	,__loadFromFile: function(inFilename,inLoader) {
		var _g = this;
		var image = js.Browser.document.createElement("img");
		if(inLoader != null) {
			var data = { image : image, texture : this.___textureBuffer, inLoader : inLoader, bitmapData : this};
			image.addEventListener("load",(function(f,a1) {
				return function(e) {
					return f(a1,e);
				};
			})($bind(this,this.__onLoad),data),false);
			image.addEventListener("error",function(e) {
				if(!image.complete) _g.__onLoad(data,e);
			},false);
		}
		image.src = inFilename;
		if(image.complete) {
		}
	}
	,__incrNumRefBitmaps: function() {
		this.__assignedBitmaps++;
	}
	,__getNumRefBitmaps: function() {
		return this.__assignedBitmaps;
	}
	,__loadFromBytes: function(bytes,inRawAlpha,onload) {
		var _g = this;
		var type = "";
		if(flash.display.BitmapData.__isPNG(bytes)) type = "image/png"; else if(flash.display.BitmapData.__isJPG(bytes)) type = "image/jpeg"; else throw new flash.errors.IOError("BitmapData tried to read a PNG/JPG ByteArray, but found an invalid header.");
		if(inRawAlpha != null) this.__loadFromBase64(flash.display.BitmapData.__base64Encode(bytes),type,function(_) {
			var ctx = _g.___textureBuffer.getContext("2d");
			var pixels = ctx.getImageData(0,0,_g.___textureBuffer.width,_g.___textureBuffer.height);
			var _g2 = 0, _g1 = inRawAlpha.length;
			while(_g2 < _g1) {
				var i = _g2++;
				pixels.data[i * 4 + 3] = inRawAlpha.readUnsignedByte();
			}
			ctx.putImageData(pixels,0,0);
			if(onload != null) onload(_g);
		}); else this.__loadFromBase64(flash.display.BitmapData.__base64Encode(bytes),type,onload);
	}
	,__loadFromBase64: function(base64,type,onload) {
		var _g = this;
		var img = js.Browser.document.createElement("img");
		var canvas = this.___textureBuffer;
		var drawImage = function(_) {
			canvas.width = img.width;
			canvas.height = img.height;
			var ctx = canvas.getContext("2d");
			ctx.drawImage(img,0,0);
			_g.rect = new flash.geom.Rectangle(0,0,canvas.width,canvas.height);
			if(onload != null) onload(_g);
		};
		img.addEventListener("load",drawImage,false);
		img.src = "data:" + type + ";base64," + base64;
	}
	,__getLease: function() {
		return this.__lease;
	}
	,__fillRect: function(rect,color) {
		this.__lease.set(this.__leaseNum++,new Date().getTime());
		var ctx = this.___textureBuffer.getContext("2d");
		var r = (color & 16711680) >>> 16;
		var g = (color & 65280) >>> 8;
		var b = color & 255;
		var a = this.__transparent?color >>> 24:255;
		if(!this.__locked) {
			var style = "rgba(" + r + ", " + g + ", " + b + ", " + a / 255 + ")";
			ctx.fillStyle = style;
			ctx.fillRect(rect.x,rect.y,rect.width,rect.height);
		} else {
			var s = 4 * (Math.round(rect.x) + Math.round(rect.y) * this.__imageData.width);
			var offsetY;
			var offsetX;
			var _g1 = 0, _g = Math.round(rect.height);
			while(_g1 < _g) {
				var i = _g1++;
				offsetY = i * this.__imageData.width;
				var _g3 = 0, _g2 = Math.round(rect.width);
				while(_g3 < _g2) {
					var j = _g3++;
					offsetX = 4 * (j + offsetY);
					this.__imageData.data[s + offsetX] = r;
					this.__imageData.data[s + offsetX + 1] = g;
					this.__imageData.data[s + offsetX + 2] = b;
					this.__imageData.data[s + offsetX + 3] = a;
				}
			}
			this.__imageDataChanged = true;
		}
	}
	,__decrNumRefBitmaps: function() {
		this.__assignedBitmaps--;
	}
	,__clearCanvas: function() {
		var ctx = this.___textureBuffer.getContext("2d");
		ctx.clearRect(0,0,this.___textureBuffer.width,this.___textureBuffer.height);
	}
	,__buildLease: function() {
		this.__lease.set(this.__leaseNum++,new Date().getTime());
	}
	,unlock: function(changeRect) {
		this.__locked = false;
		var ctx = this.___textureBuffer.getContext("2d");
		if(this.__imageDataChanged) {
			if(changeRect != null) ctx.putImageData(this.__imageData,0,0,changeRect.x,changeRect.y,changeRect.width,changeRect.height); else ctx.putImageData(this.__imageData,0,0);
		}
		var _g = 0, _g1 = this.__copyPixelList;
		while(_g < _g1.length) {
			var copyCache = _g1[_g];
			++_g;
			if(this.__transparent && copyCache.transparentFiller != null) {
				var trpCtx = copyCache.transparentFiller.getContext("2d");
				var trpData = trpCtx.getImageData(copyCache.sourceX,copyCache.sourceY,copyCache.sourceWidth,copyCache.sourceHeight);
				ctx.putImageData(trpData,copyCache.destX,copyCache.destY);
			}
			ctx.drawImage(copyCache.handle,copyCache.sourceX,copyCache.sourceY,copyCache.sourceWidth,copyCache.sourceHeight,copyCache.destX,copyCache.destY,copyCache.sourceWidth,copyCache.sourceHeight);
		}
		this.__lease.set(this.__leaseNum++,new Date().getTime());
	}
	,threshold: function(sourceBitmapData,sourceRect,destPoint,operation,threshold,color,mask,copySource) {
		if(copySource == null) copySource = false;
		if(mask == null) mask = -1;
		if(color == null) color = 0;
		console.log("BitmapData.threshold not implemented");
		return 0;
	}
	,setPixels: function(rect,byteArray) {
		rect = this.clipRect(rect);
		if(rect == null) return;
		var len = Math.round(4 * rect.width * rect.height);
		if(!this.__locked) {
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.createImageData(rect.width,rect.height);
			var _g = 0;
			while(_g < len) {
				var i = _g++;
				imageData.data[i] = byteArray.readByte();
			}
			ctx.putImageData(imageData,rect.x,rect.y);
		} else {
			var offset = Math.round(4 * this.__imageData.width * rect.y + rect.x * 4);
			var pos = offset;
			var boundR = Math.round(4 * (rect.x + rect.width));
			var _g = 0;
			while(_g < len) {
				var i = _g++;
				if(pos % (this.__imageData.width * 4) > boundR - 1) pos += this.__imageData.width * 4 - boundR;
				this.__imageData.data[pos] = byteArray.readByte();
				pos++;
			}
			this.__imageDataChanged = true;
		}
	}
	,setPixel32: function(x,y,color) {
		if(x < 0 || y < 0 || x >= (this.___textureBuffer != null?this.___textureBuffer.width:0) || y >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) return;
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.createImageData(1,1);
			imageData.data[0] = (color & 16711680) >>> 16;
			imageData.data[1] = (color & 65280) >>> 8;
			imageData.data[2] = color & 255;
			if(this.__transparent) imageData.data[3] = (color & -16777216) >>> 24; else imageData.data[3] = 255;
			ctx.putImageData(imageData,x,y);
		} else {
			var offset = 4 * y * this.__imageData.width + x * 4;
			this.__imageData.data[offset] = (color & 16711680) >>> 16;
			this.__imageData.data[offset + 1] = (color & 65280) >>> 8;
			this.__imageData.data[offset + 2] = color & 255;
			if(this.__transparent) this.__imageData.data[offset + 3] = (color & -16777216) >>> 24; else this.__imageData.data[offset + 3] = 255;
			this.__imageDataChanged = true;
		}
	}
	,setPixel: function(x,y,color) {
		if(x < 0 || y < 0 || x >= (this.___textureBuffer != null?this.___textureBuffer.width:0) || y >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) return;
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.createImageData(1,1);
			imageData.data[0] = (color & 16711680) >>> 16;
			imageData.data[1] = (color & 65280) >>> 8;
			imageData.data[2] = color & 255;
			if(this.__transparent) imageData.data[3] = 255;
			ctx.putImageData(imageData,x,y);
		} else {
			var offset = 4 * y * this.__imageData.width + x * 4;
			this.__imageData.data[offset] = (color & 16711680) >>> 16;
			this.__imageData.data[offset + 1] = (color & 65280) >>> 8;
			this.__imageData.data[offset + 2] = color & 255;
			if(this.__transparent) this.__imageData.data[offset + 3] = 255;
			this.__imageDataChanged = true;
		}
	}
	,scroll: function(x,y) {
		throw "bitmapData.scroll is currently not supported for HTML5";
	}
	,noise: function(randomSeed,low,high,channelOptions,grayScale) {
		if(grayScale == null) grayScale = false;
		if(channelOptions == null) channelOptions = 7;
		if(high == null) high = 255;
		if(low == null) low = 0;
		var generator = new flash.display._BitmapData.MinstdGenerator(randomSeed);
		var ctx = this.___textureBuffer.getContext("2d");
		var imageData = null;
		if(this.__locked) imageData = this.__imageData; else imageData = ctx.createImageData(this.___textureBuffer.width,this.___textureBuffer.height);
		var _g1 = 0, _g = this.___textureBuffer.width * this.___textureBuffer.height;
		while(_g1 < _g) {
			var i = _g1++;
			if(grayScale) imageData.data[i * 4] = imageData.data[i * 4 + 1] = imageData.data[i * 4 + 2] = low + generator.nextValue() % (high - low + 1); else {
				imageData.data[i * 4] = (channelOptions & 1) == 0?0:low + generator.nextValue() % (high - low + 1);
				imageData.data[i * 4 + 1] = (channelOptions & 2) == 0?0:low + generator.nextValue() % (high - low + 1);
				imageData.data[i * 4 + 2] = (channelOptions & 4) == 0?0:low + generator.nextValue() % (high - low + 1);
			}
			imageData.data[i * 4 + 3] = (channelOptions & 8) == 0?255:low + generator.nextValue() % (high - low + 1);
		}
		if(this.__locked) this.__imageDataChanged = true; else ctx.putImageData(imageData,0,0);
	}
	,lock: function() {
		this.__locked = true;
		var ctx = this.___textureBuffer.getContext("2d");
		this.__imageData = ctx.getImageData(0,0,this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0);
		this.__imageDataChanged = false;
		this.__copyPixelList = [];
	}
	,hitTest: function(firstPoint,firstAlphaThreshold,secondObject,secondBitmapDataPoint,secondAlphaThreshold) {
		if(secondAlphaThreshold == null) secondAlphaThreshold = 1;
		var type = Type.getClassName(Type.getClass(secondObject));
		firstAlphaThreshold = firstAlphaThreshold & -1;
		var me = this;
		var doHitTest = function(imageData) {
			if(secondObject.__proto__ == null || secondObject.__proto__.__class__ == null || secondObject.__proto__.__class__.__name__ == null) return false;
			var _g = secondObject.__proto__.__class__.__name__[2];
			switch(_g) {
			case "Rectangle":
				var rect = secondObject;
				rect.x -= firstPoint.x;
				rect.y -= firstPoint.y;
				rect = me.clipRect(me.rect);
				if(me.rect == null) return false;
				var boundingBox = new flash.geom.Rectangle(0,0,me.___textureBuffer != null?me.___textureBuffer.width:0,me.___textureBuffer != null?me.___textureBuffer.height:0);
				if(!rect.intersects(boundingBox)) return false;
				var diff = rect.intersection(boundingBox);
				var offset = 4 * (Math.round(diff.x) + Math.round(diff.y) * imageData.width) + 3;
				var pos = offset;
				var boundR = Math.round(4 * (diff.x + diff.width));
				while(pos < offset + Math.round(4 * (diff.width + imageData.width * diff.height))) {
					if(pos % (imageData.width * 4) > boundR - 1) pos += imageData.width * 4 - boundR;
					if(imageData.data[pos] - firstAlphaThreshold >= 0) return true;
					pos += 4;
				}
				return false;
			case "Point":
				var point = secondObject;
				var x = point.x - firstPoint.x;
				var y = point.y - firstPoint.y;
				if(x < 0 || y < 0 || x >= (me.___textureBuffer != null?me.___textureBuffer.width:0) || y >= (me.___textureBuffer != null?me.___textureBuffer.height:0)) return false;
				if(imageData.data[Math.round(4 * (y * (me.___textureBuffer != null?me.___textureBuffer.width:0) + x)) + 3] - firstAlphaThreshold > 0) return true;
				return false;
			case "Bitmap":
				throw "bitmapData.hitTest with a second object of type Bitmap is currently not supported for HTML5";
				return false;
			case "BitmapData":
				throw "bitmapData.hitTest with a second object of type BitmapData is currently not supported for HTML5";
				return false;
			default:
				throw "BitmapData::hitTest secondObject argument must be either a Rectangle, a Point, a Bitmap or a BitmapData object.";
				return false;
			}
		};
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.getImageData(0,0,this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0);
			return doHitTest(imageData);
		} else return doHitTest(this.__imageData);
	}
	,handle: function() {
		return this.___textureBuffer;
	}
	,getPixels: function(rect) {
		var len = Math.round(4 * rect.width * rect.height);
		var byteArray = new flash.utils.ByteArray();
		if(byteArray.allocated < len) byteArray.___resizeBuffer(byteArray.allocated = Math.max(len,byteArray.allocated * 2) | 0); else if(byteArray.allocated > len) byteArray.___resizeBuffer(byteArray.allocated = len);
		byteArray.length = len;
		len;
		rect = this.clipRect(rect);
		if(rect == null) return byteArray;
		if(!this.__locked) {
			var ctx = this.___textureBuffer.getContext("2d");
			var imagedata = ctx.getImageData(rect.x,rect.y,rect.width,rect.height);
			var _g = 0;
			while(_g < len) {
				var i = _g++;
				byteArray.writeByte(imagedata.data[i]);
			}
		} else {
			var offset = Math.round(4 * this.__imageData.width * rect.y + rect.x * 4);
			var pos = offset;
			var boundR = Math.round(4 * (rect.x + rect.width));
			var _g = 0;
			while(_g < len) {
				var i = _g++;
				if(pos % (this.__imageData.width * 4) > boundR - 1) pos += this.__imageData.width * 4 - boundR;
				byteArray.writeByte(this.__imageData.data[pos]);
				pos++;
			}
		}
		byteArray.position = 0;
		return byteArray;
	}
	,getPixel32: function(x,y) {
		if(x < 0 || y < 0 || x >= (this.___textureBuffer != null?this.___textureBuffer.width:0) || y >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) return 0;
		if(!this.__locked) {
			var ctx = this.___textureBuffer.getContext("2d");
			return this.getInt32(0,ctx.getImageData(x,y,1,1).data);
		} else return this.getInt32(4 * y * this.___textureBuffer.width + x * 4,this.__imageData.data);
	}
	,getPixel: function(x,y) {
		if(x < 0 || y < 0 || x >= (this.___textureBuffer != null?this.___textureBuffer.width:0) || y >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) return 0;
		if(!this.__locked) {
			var ctx = this.___textureBuffer.getContext("2d");
			var imagedata = ctx.getImageData(x,y,1,1);
			return imagedata.data[0] << 16 | imagedata.data[1] << 8 | imagedata.data[2];
		} else {
			var offset = 4 * y * (this.___textureBuffer != null?this.___textureBuffer.width:0) + x * 4;
			return this.__imageData.data[offset] << 16 | this.__imageData.data[offset + 1] << 8 | this.__imageData.data[offset + 2];
		}
	}
	,getInt32: function(offset,data) {
		return (this.__transparent?data[offset + 3]:255) << 24 | data[offset] << 16 | data[offset + 1] << 8 | data[offset + 2];
	}
	,getColorBoundsRect: function(mask,color,findColor) {
		if(findColor == null) findColor = true;
		var me = this;
		var doGetColorBoundsRect = function(data) {
			var minX = me.___textureBuffer != null?me.___textureBuffer.width:0, maxX = 0, minY = me.___textureBuffer != null?me.___textureBuffer.height:0, maxY = 0, i = 0;
			while(i < data.length) {
				var value = me.getInt32(i,data);
				if(findColor) {
					if((value & mask) == color) {
						var x = Math.round(i % ((me.___textureBuffer != null?me.___textureBuffer.width:0) * 4) / 4);
						var y = Math.round(i / ((me.___textureBuffer != null?me.___textureBuffer.width:0) * 4));
						if(x < minX) minX = x;
						if(x > maxX) maxX = x;
						if(y < minY) minY = y;
						if(y > maxY) maxY = y;
					}
				} else if((value & mask) != color) {
					var x = Math.round(i % ((me.___textureBuffer != null?me.___textureBuffer.width:0) * 4) / 4);
					var y = Math.round(i / ((me.___textureBuffer != null?me.___textureBuffer.width:0) * 4));
					if(x < minX) minX = x;
					if(x > maxX) maxX = x;
					if(y < minY) minY = y;
					if(y > maxY) maxY = y;
				}
				i += 4;
			}
			if(minX < maxX && minY < maxY) return new flash.geom.Rectangle(minX,minY,maxX - minX + 1,maxY - minY); else return new flash.geom.Rectangle(0,0,me.___textureBuffer != null?me.___textureBuffer.width:0,me.___textureBuffer != null?me.___textureBuffer.height:0);
		};
		if(!this.__locked) {
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.getImageData(0,0,this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0);
			return doGetColorBoundsRect(imageData.data);
		} else return doGetColorBoundsRect(this.__imageData.data);
	}
	,floodFill: function(x,y,color) {
		var wasLocked = this.__locked;
		if(!this.__locked) this.lock();
		var queue = new Array();
		queue.push(new flash.geom.Point(x,y));
		var old = this.getPixel32(x,y);
		var iterations = 0;
		var search = new Array();
		var _g1 = 0, _g = (this.___textureBuffer != null?this.___textureBuffer.width:0) + 1;
		while(_g1 < _g) {
			var i = _g1++;
			var column = new Array();
			var _g3 = 0, _g2 = (this.___textureBuffer != null?this.___textureBuffer.height:0) + 1;
			while(_g3 < _g2) {
				var i1 = _g3++;
				column.push(false);
			}
			search.push(column);
		}
		var currPoint, newPoint;
		while(queue.length > 0) {
			currPoint = queue.shift();
			++iterations;
			var x1 = currPoint.x | 0;
			var y1 = currPoint.y | 0;
			if(x1 < 0 || x1 >= (this.___textureBuffer != null?this.___textureBuffer.width:0)) continue;
			if(y1 < 0 || y1 >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) continue;
			search[x1][y1] = true;
			if(this.getPixel32(x1,y1) == old) {
				this.setPixel32(x1,y1,color);
				if(!search[x1 + 1][y1]) queue.push(new flash.geom.Point(x1 + 1,y1));
				if(!search[x1][y1 + 1]) queue.push(new flash.geom.Point(x1,y1 + 1));
				if(x1 > 0 && !search[x1 - 1][y1]) queue.push(new flash.geom.Point(x1 - 1,y1));
				if(y1 > 0 && !search[x1][y1 - 1]) queue.push(new flash.geom.Point(x1,y1 - 1));
			}
		}
		if(!wasLocked) this.unlock();
	}
	,fillRect: function(rect,color) {
		if(rect == null) return;
		if(rect.width <= 0 || rect.height <= 0) return;
		if(rect.x == 0 && rect.y == 0 && rect.width == this.___textureBuffer.width && rect.height == this.___textureBuffer.height) {
			if(this.__transparent) {
				if(color >>> 24 == 0 || color == this.__initColor) return this.__clearCanvas();
			} else if((color | -16777216) == (this.__initColor | -16777216)) return this.__clearCanvas();
		}
		return this.__fillRect(rect,color);
	}
	,drawToSurface: function(inSurface,matrix,inColorTransform,blendMode,clipRect,smoothing) {
		this.__lease.set(this.__leaseNum++,new Date().getTime());
		var ctx = inSurface.getContext("2d");
		if(matrix != null) {
			ctx.save();
			if(matrix.a == 1 && matrix.b == 0 && matrix.c == 0 && matrix.d == 1) ctx.translate(matrix.tx,matrix.ty); else {
				flash.Lib.__setImageSmoothing(ctx,smoothing);
				ctx.setTransform(matrix.a,matrix.b,matrix.c,matrix.d,matrix.tx,matrix.ty);
			}
			ctx.drawImage(this.___textureBuffer,0,0);
			ctx.restore();
		} else ctx.drawImage(this.___textureBuffer,0,0);
		if(inColorTransform != null) this.colorTransform(new flash.geom.Rectangle(0,0,this.___textureBuffer.width,this.___textureBuffer.height),inColorTransform);
	}
	,draw: function(source,matrix,inColorTransform,blendMode,clipRect,smoothing) {
		if(smoothing == null) smoothing = false;
		this.__lease.set(this.__leaseNum++,new Date().getTime());
		source.drawToSurface(this.___textureBuffer,matrix,inColorTransform,blendMode,clipRect,smoothing);
		if(inColorTransform != null) {
			var rect = new flash.geom.Rectangle();
			var object = source;
			rect.x = matrix != null?matrix.tx:0;
			rect.y = matrix != null?matrix.ty:0;
			try {
				rect.width = Reflect.getProperty(source,"width");
				rect.height = Reflect.getProperty(source,"height");
			} catch( e ) {
				rect.width = this.___textureBuffer.width;
				rect.height = this.___textureBuffer.height;
			}
			this.colorTransform(rect,inColorTransform);
		}
	}
	,dispose: function() {
		this.__clearCanvas();
		this.___textureBuffer = null;
		this.__leaseNum = 0;
		this.__lease = null;
		this.__imageData = null;
	}
	,destroy: function() {
		this.___textureBuffer = null;
	}
	,copyPixels: function(sourceBitmapData,sourceRect,destPoint,alphaBitmapData,alphaPoint,mergeAlpha) {
		if(mergeAlpha == null) mergeAlpha = false;
		if(sourceBitmapData.___textureBuffer == null || this.___textureBuffer == null || sourceBitmapData.___textureBuffer.width == 0 || sourceBitmapData.___textureBuffer.height == 0 || sourceRect.width <= 0 || sourceRect.height <= 0) return;
		if(sourceRect.x + sourceRect.width > sourceBitmapData.___textureBuffer.width) sourceRect.width = sourceBitmapData.___textureBuffer.width - sourceRect.x;
		if(sourceRect.y + sourceRect.height > sourceBitmapData.___textureBuffer.height) sourceRect.height = sourceBitmapData.___textureBuffer.height - sourceRect.y;
		if(alphaBitmapData != null && alphaBitmapData.__transparent) {
			if(alphaPoint == null) alphaPoint = new flash.geom.Point();
			var bitmapData = new flash.display.BitmapData(sourceBitmapData.___textureBuffer != null?sourceBitmapData.___textureBuffer.width:0,sourceBitmapData.___textureBuffer != null?sourceBitmapData.___textureBuffer.height:0,true);
			bitmapData.copyPixels(sourceBitmapData,sourceRect,new flash.geom.Point(sourceRect.x,sourceRect.y));
			bitmapData.copyChannel(alphaBitmapData,new flash.geom.Rectangle(alphaPoint.x,alphaPoint.y,sourceRect.width,sourceRect.height),new flash.geom.Point(sourceRect.x,sourceRect.y),8,8);
			sourceBitmapData = bitmapData;
		}
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			if(!mergeAlpha) {
				if(this.__transparent && sourceBitmapData.__transparent) {
					var trpCtx = sourceBitmapData.__transparentFiller.getContext("2d");
					var trpData = trpCtx.getImageData(sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height);
					ctx.putImageData(trpData,destPoint.x,destPoint.y);
				}
			}
			ctx.drawImage(sourceBitmapData.___textureBuffer,sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height,destPoint.x,destPoint.y,sourceRect.width,sourceRect.height);
		} else this.__copyPixelList[this.__copyPixelList.length] = { handle : sourceBitmapData.___textureBuffer, transparentFiller : mergeAlpha?null:sourceBitmapData.__transparentFiller, sourceX : sourceRect.x, sourceY : sourceRect.y, sourceWidth : sourceRect.width, sourceHeight : sourceRect.height, destX : destPoint.x, destY : destPoint.y};
	}
	,copyChannel: function(sourceBitmapData,sourceRect,destPoint,sourceChannel,destChannel) {
		this.rect = this.clipRect(this.rect);
		if(this.rect == null) return;
		if(destChannel == 8 && !this.__transparent) return;
		if(sourceBitmapData.___textureBuffer == null || this.___textureBuffer == null || sourceRect.width <= 0 || sourceRect.height <= 0) return;
		if(sourceRect.x + sourceRect.width > sourceBitmapData.___textureBuffer.width) sourceRect.width = sourceBitmapData.___textureBuffer.width - sourceRect.x;
		if(sourceRect.y + sourceRect.height > sourceBitmapData.___textureBuffer.height) sourceRect.height = sourceBitmapData.___textureBuffer.height - sourceRect.y;
		var doChannelCopy = function(imageData) {
			var srcCtx = sourceBitmapData.___textureBuffer.getContext("2d");
			var srcImageData = srcCtx.getImageData(sourceRect.x,sourceRect.y,sourceRect.width,sourceRect.height);
			var destIdx = -1;
			if(destChannel == 8) destIdx = 3; else if(destChannel == 4) destIdx = 2; else if(destChannel == 2) destIdx = 1; else if(destChannel == 1) destIdx = 0; else throw "Invalid destination BitmapDataChannel passed to BitmapData::copyChannel.";
			var pos = 4 * (Math.round(destPoint.x) + Math.round(destPoint.y) * imageData.width) + destIdx;
			var boundR = Math.round(4 * (destPoint.x + sourceRect.width));
			var setPos = function(val) {
				if(pos % (imageData.width * 4) > boundR - 1) pos += imageData.width * 4 - boundR;
				imageData.data[pos] = val;
				pos += 4;
			};
			var srcIdx = -1;
			if(sourceChannel == 8) srcIdx = 3; else if(sourceChannel == 4) srcIdx = 2; else if(sourceChannel == 2) srcIdx = 1; else if(sourceChannel == 1) srcIdx = 0; else throw "Invalid source BitmapDataChannel passed to BitmapData::copyChannel.";
			while(srcIdx < srcImageData.data.length) {
				setPos(srcImageData.data[srcIdx]);
				srcIdx += 4;
			}
		};
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			var imageData = ctx.getImageData(0,0,this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0);
			doChannelCopy(imageData);
			ctx.putImageData(imageData,0,0);
		} else {
			doChannelCopy(this.__imageData);
			this.__imageDataChanged = true;
		}
	}
	,compare: function(inBitmapTexture) {
		throw "bitmapData.compare is currently not supported for HTML5";
		return 0;
	}
	,colorTransform: function(rect,colorTransform) {
		if(rect == null) return;
		rect = this.clipRect(rect);
		if(!this.__locked) {
			this.__lease.set(this.__leaseNum++,new Date().getTime());
			var ctx = this.___textureBuffer.getContext("2d");
			var imagedata = ctx.getImageData(rect.x,rect.y,rect.width,rect.height);
			var offsetX;
			var _g1 = 0, _g = imagedata.data.length >> 2;
			while(_g1 < _g) {
				var i = _g1++;
				offsetX = i * 4;
				imagedata.data[offsetX] = imagedata.data[offsetX] * colorTransform.redMultiplier + colorTransform.redOffset | 0;
				imagedata.data[offsetX + 1] = imagedata.data[offsetX + 1] * colorTransform.greenMultiplier + colorTransform.greenOffset | 0;
				imagedata.data[offsetX + 2] = imagedata.data[offsetX + 2] * colorTransform.blueMultiplier + colorTransform.blueOffset | 0;
				imagedata.data[offsetX + 3] = imagedata.data[offsetX + 3] * colorTransform.alphaMultiplier + colorTransform.alphaOffset | 0;
			}
			ctx.putImageData(imagedata,rect.x,rect.y);
		} else {
			var s = 4 * (Math.round(rect.x) + Math.round(rect.y) * this.__imageData.width);
			var offsetY;
			var offsetX;
			var _g1 = 0, _g = Math.round(rect.height);
			while(_g1 < _g) {
				var i = _g1++;
				offsetY = i * this.__imageData.width;
				var _g3 = 0, _g2 = Math.round(rect.width);
				while(_g3 < _g2) {
					var j = _g3++;
					offsetX = 4 * (j + offsetY);
					this.__imageData.data[s + offsetX] = this.__imageData.data[s + offsetX] * colorTransform.redMultiplier + colorTransform.redOffset | 0;
					this.__imageData.data[s + offsetX + 1] = this.__imageData.data[s + offsetX + 1] * colorTransform.greenMultiplier + colorTransform.greenOffset | 0;
					this.__imageData.data[s + offsetX + 2] = this.__imageData.data[s + offsetX + 2] * colorTransform.blueMultiplier + colorTransform.blueOffset | 0;
					this.__imageData.data[s + offsetX + 3] = this.__imageData.data[s + offsetX + 3] * colorTransform.alphaMultiplier + colorTransform.alphaOffset | 0;
				}
			}
			this.__imageDataChanged = true;
		}
	}
	,clone: function() {
		var bitmapData = new flash.display.BitmapData(this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0,this.__transparent);
		var rect = new flash.geom.Rectangle(0,0,this.___textureBuffer != null?this.___textureBuffer.width:0,this.___textureBuffer != null?this.___textureBuffer.height:0);
		bitmapData.setPixels(rect,this.getPixels(rect));
		bitmapData.__lease.set(bitmapData.__leaseNum++,new Date().getTime());
		return bitmapData;
	}
	,clipRect: function(r) {
		if(r.x < 0) {
			r.width -= -r.x;
			r.x = 0;
			if(r.x + r.width <= 0) return null;
		}
		if(r.y < 0) {
			r.height -= -r.y;
			r.y = 0;
			if(r.y + r.height <= 0) return null;
		}
		if(r.x + r.width >= (this.___textureBuffer != null?this.___textureBuffer.width:0)) {
			r.width -= r.x + r.width - (this.___textureBuffer != null?this.___textureBuffer.width:0);
			if(r.width <= 0) return null;
		}
		if(r.y + r.height >= (this.___textureBuffer != null?this.___textureBuffer.height:0)) {
			r.height -= r.y + r.height - (this.___textureBuffer != null?this.___textureBuffer.height:0);
			if(r.height <= 0) return null;
		}
		return r;
	}
	,clear: function(color) {
		this.fillRect(this.rect,color);
	}
	,applyFilter: function(sourceBitmapData,sourceRect,destPoint,filter) {
		if(sourceBitmapData == this && sourceRect.x == destPoint.x && sourceRect.y == destPoint.y) filter.__applyFilter(this.___textureBuffer,sourceRect); else {
			var bitmapData = new flash.display.BitmapData(sourceRect.width | 0,sourceRect.height | 0);
			bitmapData.copyPixels(sourceBitmapData,sourceRect,new flash.geom.Point());
			filter.__applyFilter(bitmapData.___textureBuffer);
			this.copyPixels(bitmapData,bitmapData.rect,destPoint);
		}
	}
	,__class__: flash.display.BitmapData
	,__properties__: {get_height:"get_height",get_transparent:"get_transparent",get_width:"get_width"}
}
flash.display.ImageDataLease = function() {
};
$hxClasses["flash.display.ImageDataLease"] = flash.display.ImageDataLease;
flash.display.ImageDataLease.__name__ = ["flash","display","ImageDataLease"];
flash.display.ImageDataLease.prototype = {
	set: function(s,t) {
		this.seed = s;
		this.time = t;
	}
	,clone: function() {
		var leaseClone = new flash.display.ImageDataLease();
		leaseClone.seed = this.seed;
		leaseClone.time = this.time;
		return leaseClone;
	}
	,__class__: flash.display.ImageDataLease
}
flash.display._BitmapData = {}
flash.display._BitmapData.MinstdGenerator = function(seed) {
	if(seed == 0) this.value = 1; else this.value = seed;
};
$hxClasses["flash.display._BitmapData.MinstdGenerator"] = flash.display._BitmapData.MinstdGenerator;
flash.display._BitmapData.MinstdGenerator.__name__ = ["flash","display","_BitmapData","MinstdGenerator"];
flash.display._BitmapData.MinstdGenerator.prototype = {
	nextValue: function() {
		var lo = 16807 * (this.value & 65535);
		var hi = 16807 * (this.value >>> 16);
		lo += (hi & 32767) << 16;
		if(lo < 0 || lo > -2147483648 - 1) {
			lo &= -2147483648 - 1;
			++lo;
		}
		lo += hi >>> 15;
		if(lo < 0 || lo > -2147483648 - 1) {
			lo &= -2147483648 - 1;
			++lo;
		}
		return this.value = lo;
	}
	,__class__: flash.display._BitmapData.MinstdGenerator
}
flash.display.BitmapDataChannel = function() { }
$hxClasses["flash.display.BitmapDataChannel"] = flash.display.BitmapDataChannel;
flash.display.BitmapDataChannel.__name__ = ["flash","display","BitmapDataChannel"];
flash.display.BlendMode = $hxClasses["flash.display.BlendMode"] = { __ename__ : true, __constructs__ : ["ADD","ALPHA","DARKEN","DIFFERENCE","ERASE","HARDLIGHT","INVERT","LAYER","LIGHTEN","MULTIPLY","NORMAL","OVERLAY","SCREEN","SUBTRACT"] }
flash.display.BlendMode.ADD = ["ADD",0];
flash.display.BlendMode.ADD.toString = $estr;
flash.display.BlendMode.ADD.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.ALPHA = ["ALPHA",1];
flash.display.BlendMode.ALPHA.toString = $estr;
flash.display.BlendMode.ALPHA.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.DARKEN = ["DARKEN",2];
flash.display.BlendMode.DARKEN.toString = $estr;
flash.display.BlendMode.DARKEN.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.DIFFERENCE = ["DIFFERENCE",3];
flash.display.BlendMode.DIFFERENCE.toString = $estr;
flash.display.BlendMode.DIFFERENCE.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.ERASE = ["ERASE",4];
flash.display.BlendMode.ERASE.toString = $estr;
flash.display.BlendMode.ERASE.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.HARDLIGHT = ["HARDLIGHT",5];
flash.display.BlendMode.HARDLIGHT.toString = $estr;
flash.display.BlendMode.HARDLIGHT.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.INVERT = ["INVERT",6];
flash.display.BlendMode.INVERT.toString = $estr;
flash.display.BlendMode.INVERT.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.LAYER = ["LAYER",7];
flash.display.BlendMode.LAYER.toString = $estr;
flash.display.BlendMode.LAYER.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.LIGHTEN = ["LIGHTEN",8];
flash.display.BlendMode.LIGHTEN.toString = $estr;
flash.display.BlendMode.LIGHTEN.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.MULTIPLY = ["MULTIPLY",9];
flash.display.BlendMode.MULTIPLY.toString = $estr;
flash.display.BlendMode.MULTIPLY.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.NORMAL = ["NORMAL",10];
flash.display.BlendMode.NORMAL.toString = $estr;
flash.display.BlendMode.NORMAL.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.OVERLAY = ["OVERLAY",11];
flash.display.BlendMode.OVERLAY.toString = $estr;
flash.display.BlendMode.OVERLAY.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.SCREEN = ["SCREEN",12];
flash.display.BlendMode.SCREEN.toString = $estr;
flash.display.BlendMode.SCREEN.__enum__ = flash.display.BlendMode;
flash.display.BlendMode.SUBTRACT = ["SUBTRACT",13];
flash.display.BlendMode.SUBTRACT.toString = $estr;
flash.display.BlendMode.SUBTRACT.__enum__ = flash.display.BlendMode;
flash.display.CapsStyle = $hxClasses["flash.display.CapsStyle"] = { __ename__ : true, __constructs__ : ["NONE","ROUND","SQUARE"] }
flash.display.CapsStyle.NONE = ["NONE",0];
flash.display.CapsStyle.NONE.toString = $estr;
flash.display.CapsStyle.NONE.__enum__ = flash.display.CapsStyle;
flash.display.CapsStyle.ROUND = ["ROUND",1];
flash.display.CapsStyle.ROUND.toString = $estr;
flash.display.CapsStyle.ROUND.__enum__ = flash.display.CapsStyle;
flash.display.CapsStyle.SQUARE = ["SQUARE",2];
flash.display.CapsStyle.SQUARE.toString = $estr;
flash.display.CapsStyle.SQUARE.__enum__ = flash.display.CapsStyle;
flash.display.GradientType = $hxClasses["flash.display.GradientType"] = { __ename__ : true, __constructs__ : ["RADIAL","LINEAR"] }
flash.display.GradientType.RADIAL = ["RADIAL",0];
flash.display.GradientType.RADIAL.toString = $estr;
flash.display.GradientType.RADIAL.__enum__ = flash.display.GradientType;
flash.display.GradientType.LINEAR = ["LINEAR",1];
flash.display.GradientType.LINEAR.toString = $estr;
flash.display.GradientType.LINEAR.__enum__ = flash.display.GradientType;
flash.display.Graphics = function(inSurface) {
	flash.Lib.__bootstrap();
	if(inSurface == null) {
		this.__surface = js.Browser.document.createElement("canvas");
		this.__surface.width = 0;
		this.__surface.height = 0;
	} else this.__surface = inSurface;
	this.mLastMoveID = 0;
	this.mPenX = 0.0;
	this.mPenY = 0.0;
	this.mDrawList = new Array();
	this.mPoints = [];
	this.mSolidGradient = null;
	this.mBitmap = null;
	this.mFilling = false;
	this.mFillColour = 0;
	this.mFillAlpha = 0.0;
	this.mLastMoveID = 0;
	this.boundsDirty = true;
	this.__clearLine();
	this.mLineJobs = [];
	this.__changed = true;
	this.nextDrawIndex = 0;
	this.__extent = new flash.geom.Rectangle();
	this.__extentWithFilters = new flash.geom.Rectangle();
	this._padding = 0.0;
	this.__clearNextCycle = true;
};
$hxClasses["flash.display.Graphics"] = flash.display.Graphics;
flash.display.Graphics.__name__ = ["flash","display","Graphics"];
flash.display.Graphics.__detectIsPointInPathMode = function() {
	var canvas = js.Browser.document.createElement("canvas");
	var ctx = canvas.getContext("2d");
	if(ctx.isPointInPath == null) return flash.display.PointInPathMode.USER_SPACE;
	ctx.save();
	ctx.translate(1,0);
	ctx.beginPath();
	ctx.rect(0,0,1,1);
	var rv = ctx.isPointInPath(0.3,0.3)?flash.display.PointInPathMode.USER_SPACE:flash.display.PointInPathMode.DEVICE_SPACE;
	ctx.restore();
	return rv;
}
flash.display.Graphics.prototype = {
	__render: function(maskHandle,filters,sx,sy,clip0,clip1,clip2,clip3) {
		if(sy == null) sy = 1.0;
		if(sx == null) sx = 1.0;
		if(!this.__changed) return false;
		this.closePolygon(true);
		var padding = this._padding;
		if(filters != null) {
			var _g = 0;
			while(_g < filters.length) {
				var filter = filters[_g];
				++_g;
				if(Reflect.hasField(filter,"blurX")) padding += Math.max(Reflect.field(filter,"blurX"),Reflect.field(filter,"blurY")) * 4;
			}
		}
		this.__expandFilteredExtent(-(padding * sx) / 2,-(padding * sy) / 2);
		if(this.__clearNextCycle) {
			this.nextDrawIndex = 0;
			this.__clearCanvas();
			this.__clearNextCycle = false;
		}
		if(this.__extentWithFilters.width - this.__extentWithFilters.x > this.__surface.width || this.__extentWithFilters.height - this.__extentWithFilters.y > this.__surface.height) this.__adjustSurface(sx,sy);
		var ctx = (function($this) {
			var $r;
			try {
				$r = $this.__surface.getContext("2d");
			} catch( e ) {
				$r = null;
			}
			return $r;
		}(this));
		if(ctx == null) return false;
		if(clip0 != null) {
			ctx.beginPath();
			ctx.moveTo(clip0.x * sx,clip0.y * sy);
			ctx.lineTo(clip1.x * sx,clip1.y * sy);
			ctx.lineTo(clip2.x * sx,clip2.y * sy);
			ctx.lineTo(clip3.x * sx,clip3.y * sy);
			ctx.closePath();
			ctx.clip();
		}
		if(filters != null) {
			var _g = 0;
			while(_g < filters.length) {
				var filter = filters[_g];
				++_g;
				if(js.Boot.__instanceof(filter,flash.filters.DropShadowFilter)) filter.__applyFilter(this.__surface,null,true);
			}
		}
		var len = this.mDrawList.length;
		ctx.save();
		if(this.__extentWithFilters.x != 0 || this.__extentWithFilters.y != 0) ctx.translate(-this.__extentWithFilters.x * sx,-this.__extentWithFilters.y * sy);
		if(sx != 1 || sy != 0) ctx.scale(sx,sy);
		var doStroke = false;
		var _g = this.nextDrawIndex;
		while(_g < len) {
			var i = _g++;
			var d = this.mDrawList[len - 1 - i];
			if(d.tileJob != null) this.__drawTiles(d.tileJob.sheet,d.tileJob.drawList,d.tileJob.flags); else {
				if(d.lineJobs.length > 0) {
					var _g1 = 0, _g2 = d.lineJobs;
					while(_g1 < _g2.length) {
						var lj = _g2[_g1];
						++_g1;
						ctx.lineWidth = lj.thickness;
						switch(lj.joints) {
						case 0:
							ctx.lineJoin = "round";
							break;
						case 4096:
							ctx.lineJoin = "miter";
							break;
						case 8192:
							ctx.lineJoin = "bevel";
							break;
						}
						switch(lj.caps) {
						case 256:
							ctx.lineCap = "round";
							break;
						case 512:
							ctx.lineCap = "square";
							break;
						case 0:
							ctx.lineCap = "butt";
							break;
						}
						ctx.miterLimit = lj.miter_limit;
						if(lj.grad != null) ctx.strokeStyle = this.createCanvasGradient(ctx,lj.grad); else ctx.strokeStyle = this.createCanvasColor(lj.colour,lj.alpha);
						ctx.beginPath();
						var _g4 = lj.point_idx0, _g3 = lj.point_idx1 + 1;
						while(_g4 < _g3) {
							var i1 = _g4++;
							var p = d.points[i1];
							switch(p.type) {
							case 0:
								ctx.moveTo(p.x,p.y);
								break;
							case 2:
								ctx.quadraticCurveTo(p.cx,p.cy,p.x,p.y);
								break;
							default:
								ctx.lineTo(p.x,p.y);
							}
						}
						ctx.closePath();
						doStroke = true;
					}
				} else {
					ctx.beginPath();
					var _g1 = 0, _g2 = d.points;
					while(_g1 < _g2.length) {
						var p = _g2[_g1];
						++_g1;
						switch(p.type) {
						case 0:
							ctx.moveTo(p.x,p.y);
							break;
						case 2:
							ctx.quadraticCurveTo(p.cx,p.cy,p.x,p.y);
							break;
						default:
							ctx.lineTo(p.x,p.y);
						}
					}
					ctx.closePath();
				}
				var fillColour = d.fillColour;
				var fillAlpha = d.fillAlpha;
				var g = d.solidGradient;
				var bitmap = d.bitmap;
				if(g != null) ctx.fillStyle = this.createCanvasGradient(ctx,g); else if(bitmap != null && (bitmap.flags & 16) > 0) {
					var m = bitmap.matrix;
					if(m != null) ctx.transform(m.a,m.b,m.c,m.d,m.tx,m.ty);
					if((bitmap.flags & 65536) == 0) {
						ctx.mozImageSmoothingEnabled = false;
						ctx.webkitImageSmoothingEnabled = false;
					}
					ctx.fillStyle = ctx.createPattern(bitmap.texture_buffer,"repeat");
				} else ctx.fillStyle = this.createCanvasColor(fillColour,Math.min(1.0,Math.max(0.0,fillAlpha)));
				ctx.fill();
				if(doStroke) ctx.stroke();
				ctx.save();
				if(bitmap != null && (bitmap.flags & 16) == 0) {
					ctx.clip();
					var img = bitmap.texture_buffer;
					var m = bitmap.matrix;
					if(m != null) ctx.transform(m.a,m.b,m.c,m.d,m.tx,m.ty);
					ctx.drawImage(img,0,0);
				}
				ctx.restore();
			}
		}
		ctx.restore();
		this.__changed = false;
		this.nextDrawIndex = len > 0?len - 1:0;
		this.mDrawList = [];
		return true;
	}
	,__mediaSurface: function(surface) {
		this.__surface = surface;
	}
	,__invalidate: function() {
		this.__changed = true;
		this.__clearNextCycle = true;
	}
	,__hitTest: function(inX,inY) {
		var ctx = (function($this) {
			var $r;
			try {
				$r = $this.__surface.getContext("2d");
			} catch( e ) {
				$r = null;
			}
			return $r;
		}(this));
		if(ctx == null) return false;
		if(ctx.isPointInPath(inX,inY)) return true; else if(this.mDrawList.length == 0 && this.__extent.width > 0 && this.__extent.height > 0) return true;
		return false;
	}
	,__expandStandardExtent: function(x,y,thickness) {
		if(thickness == null) thickness = 0;
		if(this._padding > 0) {
			this.__extent.width -= this._padding;
			this.__extent.height -= this._padding;
		}
		if(thickness != null && thickness > this._padding) this._padding = thickness;
		var maxX, minX, maxY, minY;
		minX = this.__extent.x;
		minY = this.__extent.y;
		maxX = this.__extent.width + minX;
		maxY = this.__extent.height + minY;
		maxX = x > maxX?x:maxX;
		minX = x < minX?x:minX;
		maxY = y > maxY?y:maxY;
		minY = y < minY?y:minY;
		this.__extent.x = minX;
		this.__extent.y = minY;
		this.__extent.width = maxX - minX + this._padding;
		this.__extent.height = maxY - minY + this._padding;
		this.boundsDirty = true;
	}
	,__expandFilteredExtent: function(x,y) {
		var maxX, minX, maxY, minY;
		minX = this.__extent.x;
		minY = this.__extent.y;
		maxX = this.__extent.width + minX;
		maxY = this.__extent.height + minY;
		maxX = x > maxX?x:maxX;
		minX = x < minX?x:minX;
		maxY = y > maxY?y:maxY;
		minY = y < minY?y:minY;
		this.__extentWithFilters.x = minX;
		this.__extentWithFilters.y = minY;
		this.__extentWithFilters.width = maxX - minX;
		this.__extentWithFilters.height = maxY - minY;
	}
	,__drawTiles: function(sheet,tileData,flags) {
		if(flags == null) flags = 0;
		var useScale = (flags & 1) > 0;
		var useRotation = (flags & 2) > 0;
		var useTransform = (flags & 16) > 0;
		var useRGB = (flags & 4) > 0;
		var useAlpha = (flags & 8) > 0;
		if(useTransform) {
			useScale = false;
			useRotation = false;
		}
		var scaleIndex = 0;
		var rotationIndex = 0;
		var rgbIndex = 0;
		var alphaIndex = 0;
		var transformIndex = 0;
		var numValues = 3;
		if(useScale) {
			scaleIndex = numValues;
			numValues++;
		}
		if(useRotation) {
			rotationIndex = numValues;
			numValues++;
		}
		if(useTransform) {
			transformIndex = numValues;
			numValues += 4;
		}
		if(useRGB) {
			rgbIndex = numValues;
			numValues += 3;
		}
		if(useAlpha) {
			alphaIndex = numValues;
			numValues++;
		}
		var totalCount = tileData.length;
		var itemCount = totalCount / numValues | 0;
		var index = 0;
		var rect = null;
		var center = null;
		var previousTileID = -1;
		var surface = sheet.__bitmap.___textureBuffer;
		var ctx = (function($this) {
			var $r;
			try {
				$r = $this.__surface.getContext("2d");
			} catch( e ) {
				$r = null;
			}
			return $r;
		}(this));
		if(ctx != null) while(index < totalCount) {
			var tileID = tileData[index + 2] | 0;
			if(tileID != previousTileID) {
				rect = sheet.__tileRects[tileID];
				center = sheet.__centerPoints[tileID];
				previousTileID = tileID;
			}
			if(rect != null && center != null) {
				ctx.save();
				ctx.translate(tileData[index],tileData[index + 1]);
				if(useRotation) ctx.rotate(tileData[index + rotationIndex]);
				var scale = 1.0;
				if(useScale) scale = tileData[index + scaleIndex];
				if(useTransform) ctx.transform(tileData[index + transformIndex],tileData[index + transformIndex + 1],tileData[index + transformIndex + 2],tileData[index + transformIndex + 3],0,0);
				if(useAlpha) ctx.globalAlpha = tileData[index + alphaIndex];
				ctx.drawImage(surface,rect.x,rect.y,rect.width,rect.height,-center.x * scale,-center.y * scale,rect.width * scale,rect.height * scale);
				ctx.restore();
			}
			index += numValues;
		}
	}
	,__drawEllipse: function(x,y,rx,ry) {
		this.moveTo(x + rx,y);
		this.curveTo(rx + x,-0.4142 * ry + y,0.7071 * rx + x,-0.7071 * ry + y);
		this.curveTo(0.4142 * rx + x,-ry + y,x,-ry + y);
		this.curveTo(-0.4142 * rx + x,-ry + y,-0.7071 * rx + x,-0.7071 * ry + y);
		this.curveTo(-rx + x,-0.4142 * ry + y,-rx + x,y);
		this.curveTo(-rx + x,0.4142 * ry + y,-0.7071 * rx + x,0.7071 * ry + y);
		this.curveTo(-0.4142 * rx + x,ry + y,x,ry + y);
		this.curveTo(0.4142 * rx + x,ry + y,0.7071 * rx + x,0.7071 * ry + y);
		this.curveTo(rx + x,0.4142 * ry + y,rx + x,y);
	}
	,__clearLine: function() {
		this.mCurrentLine = new flash.display.LineJob(null,-1,-1,0.0,0.0,0,1,0,256,3,3.0);
	}
	,__clearCanvas: function() {
		if(this.__surface != null) {
			var ctx = (function($this) {
				var $r;
				try {
					$r = $this.__surface.getContext("2d");
				} catch( e ) {
					$r = null;
				}
				return $r;
			}(this));
			if(ctx != null) ctx.clearRect(0,0,this.__surface.width,this.__surface.height);
		}
	}
	,__adjustSurface: function(sx,sy) {
		if(sy == null) sy = 1.0;
		if(sx == null) sx = 1.0;
		if(Reflect.field(this.__surface,"getContext") != null) {
			var width = Math.ceil((this.__extentWithFilters.width - this.__extentWithFilters.x) * sx);
			var height = Math.ceil((this.__extentWithFilters.height - this.__extentWithFilters.y) * sy);
			if(width <= 5000 && height <= 5000) {
				var dstCanvas = js.Browser.document.createElement("canvas");
				dstCanvas.width = width;
				dstCanvas.height = height;
				flash.Lib.__drawToSurface(this.__surface,dstCanvas);
				if(flash.Lib.__isOnStage(this.__surface)) {
					flash.Lib.__appendSurface(dstCanvas);
					flash.Lib.__copyStyle(this.__surface,dstCanvas);
					flash.Lib.__swapSurface(this.__surface,dstCanvas);
					flash.Lib.__removeSurface(this.__surface);
					if(this.__surface.id != null) flash.Lib.__setSurfaceId(dstCanvas,this.__surface.id);
				}
				this.__surface = dstCanvas;
			}
		}
	}
	,moveTo: function(inX,inY) {
		this.mPenX = inX;
		this.mPenY = inY;
		this.__expandStandardExtent(inX,inY);
		if(!this.mFilling) this.closePolygon(false); else {
			this.addLineSegment();
			this.mLastMoveID = this.mPoints.length;
			this.mPoints.push(new flash.display.GfxPoint(this.mPenX,this.mPenY,0.0,0.0,0));
		}
	}
	,lineTo: function(inX,inY) {
		var pid = this.mPoints.length;
		if(pid == 0) {
			this.mPoints.push(new flash.display.GfxPoint(this.mPenX,this.mPenY,0.0,0.0,0));
			pid++;
		}
		this.mPenX = inX;
		this.mPenY = inY;
		this.__expandStandardExtent(inX,inY,this.mCurrentLine.thickness);
		this.mPoints.push(new flash.display.GfxPoint(this.mPenX,this.mPenY,0.0,0.0,1));
		if(this.mCurrentLine.grad != null || this.mCurrentLine.alpha > 0) {
			if(this.mCurrentLine.point_idx0 < 0) this.mCurrentLine.point_idx0 = pid - 1;
			this.mCurrentLine.point_idx1 = pid;
		}
		if(!this.mFilling) this.closePolygon(false);
	}
	,lineStyle: function(thickness,color,alpha,pixelHinting,scaleMode,caps,joints,miterLimit) {
		this.addLineSegment();
		if(thickness == null) {
			this.__clearLine();
			return;
		} else {
			this.mCurrentLine.grad = null;
			this.mCurrentLine.thickness = thickness;
			this.mCurrentLine.colour = color == null?0:color;
			this.mCurrentLine.alpha = alpha == null?1.0:alpha;
			this.mCurrentLine.miter_limit = miterLimit == null?3.0:miterLimit;
			this.mCurrentLine.pixel_hinting = pixelHinting == null || !pixelHinting?0:16384;
		}
		if(caps != null) {
			switch( (caps)[1] ) {
			case 1:
				this.mCurrentLine.caps = 256;
				break;
			case 2:
				this.mCurrentLine.caps = 512;
				break;
			case 0:
				this.mCurrentLine.caps = 0;
				break;
			}
		}
		this.mCurrentLine.scale_mode = 3;
		if(scaleMode != null) {
			switch( (scaleMode)[1] ) {
			case 2:
				this.mCurrentLine.scale_mode = 3;
				break;
			case 3:
				this.mCurrentLine.scale_mode = 1;
				break;
			case 0:
				this.mCurrentLine.scale_mode = 2;
				break;
			case 1:
				this.mCurrentLine.scale_mode = 0;
				break;
			}
		}
		this.mCurrentLine.joints = 0;
		if(joints != null) {
			switch( (joints)[1] ) {
			case 1:
				this.mCurrentLine.joints = 0;
				break;
			case 0:
				this.mCurrentLine.joints = 4096;
				break;
			case 2:
				this.mCurrentLine.joints = 8192;
				break;
			}
		}
	}
	,lineGradientStyle: function(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio) {
		this.mCurrentLine.grad = this.createGradient(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio);
	}
	,getContext: function() {
		try {
			return this.__surface.getContext("2d");
		} catch( e ) {
			return null;
		}
	}
	,flush: function() {
		this.closePolygon(true);
	}
	,endFill: function() {
		this.closePolygon(true);
	}
	,drawTiles: function(sheet,tileData,smooth,flags) {
		if(flags == null) flags = 0;
		if(smooth == null) smooth = false;
		this.__expandStandardExtent(flash.Lib.get_current().get_stage().get_stageWidth(),flash.Lib.get_current().get_stage().get_stageHeight());
		this.addDrawable(new flash.display.Drawable(null,null,null,null,null,null,new flash.display.TileJob(sheet,tileData,flags)));
		this.__changed = true;
	}
	,drawRoundRect: function(x,y,width,height,rx,ry) {
		if(ry == null) ry = -1;
		if(ry == -1) ry = rx;
		rx *= 0.5;
		ry *= 0.5;
		var w = width * 0.5;
		x += w;
		if(rx > w) rx = w;
		var lw = w - rx;
		var w_ = lw + rx * Math.sin(Math.PI / 4);
		var cw_ = lw + rx * Math.tan(Math.PI / 8);
		var h = height * 0.5;
		y += h;
		if(ry > h) ry = h;
		var lh = h - ry;
		var h_ = lh + ry * Math.sin(Math.PI / 4);
		var ch_ = lh + ry * Math.tan(Math.PI / 8);
		this.closePolygon(false);
		this.moveTo(x + w,y + lh);
		this.curveTo(x + w,y + ch_,x + w_,y + h_);
		this.curveTo(x + cw_,y + h,x + lw,y + h);
		this.lineTo(x - lw,y + h);
		this.curveTo(x - cw_,y + h,x - w_,y + h_);
		this.curveTo(x - w,y + ch_,x - w,y + lh);
		this.lineTo(x - w,y - lh);
		this.curveTo(x - w,y - ch_,x - w_,y - h_);
		this.curveTo(x - cw_,y - h,x - lw,y - h);
		this.lineTo(x + lw,y - h);
		this.curveTo(x + cw_,y - h,x + w_,y - h_);
		this.curveTo(x + w,y - ch_,x + w,y - lh);
		this.lineTo(x + w,y + lh);
		this.closePolygon(false);
	}
	,drawRect: function(x,y,width,height) {
		this.closePolygon(false);
		this.moveTo(x,y);
		this.lineTo(x + width,y);
		this.lineTo(x + width,y + height);
		this.lineTo(x,y + height);
		this.lineTo(x,y);
		this.closePolygon(false);
	}
	,drawGraphicsData: function(points) {
		var $it0 = ((function(_e) {
			return function() {
				return $iterator(flash._Vector.Vector_Impl_)(_e);
			};
		})(points))();
		while( $it0.hasNext() ) {
			var data = $it0.next();
			if(data == null) this.mFilling = true; else switch(data.__graphicsDataType) {
			case flash.display.GraphicsDataType.STROKE:
				var stroke = data;
				if(stroke.fill == null) this.lineStyle(stroke.thickness,0,1.,stroke.pixelHinting,stroke.scaleMode,stroke.caps,stroke.joints,stroke.miterLimit); else switch(stroke.fill.__graphicsFillType) {
				case flash.display.GraphicsFillType.SOLID_FILL:
					var fill = stroke.fill;
					this.lineStyle(stroke.thickness,fill.color,fill.alpha,stroke.pixelHinting,stroke.scaleMode,stroke.caps,stroke.joints,stroke.miterLimit);
					break;
				case flash.display.GraphicsFillType.GRADIENT_FILL:
					var fill = stroke.fill;
					this.lineGradientStyle(fill.type,fill.colors,fill.alphas,fill.ratios,fill.matrix,fill.spreadMethod,fill.interpolationMethod,fill.focalPointRatio);
					break;
				}
				break;
			case flash.display.GraphicsDataType.PATH:
				var path = data;
				var j = 0;
				var _g1 = 0, _g = flash._Vector.Vector_Impl_.get_length(path.commands);
				while(_g1 < _g) {
					var i = _g1++;
					var command = path.commands[i];
					switch(command) {
					case 1:
						this.moveTo(path.data[j],path.data[j + 1]);
						j = j + 2;
						break;
					case 2:
						this.lineTo(path.data[j],path.data[j + 1]);
						j = j + 2;
						break;
					case 3:
						this.curveTo(path.data[j],path.data[j + 1],path.data[j + 2],path.data[j + 3]);
						j = j + 4;
						break;
					}
				}
				break;
			case flash.display.GraphicsDataType.SOLID:
				var fill = data;
				this.beginFill(fill.color,fill.alpha);
				break;
			case flash.display.GraphicsDataType.GRADIENT:
				var fill = data;
				this.beginGradientFill(fill.type,fill.colors,fill.alphas,fill.ratios,fill.matrix,fill.spreadMethod,fill.interpolationMethod,fill.focalPointRatio);
				break;
			}
		}
	}
	,drawEllipse: function(x,y,rx,ry) {
		this.closePolygon(false);
		rx /= 2;
		ry /= 2;
		this.__drawEllipse(x + rx,y + ry,rx,ry);
		this.closePolygon(false);
	}
	,drawCircle: function(x,y,rad) {
		this.closePolygon(false);
		this.__drawEllipse(x,y,rad,rad);
		this.closePolygon(false);
	}
	,curveTo: function(inCX,inCY,inX,inY) {
		var pid = this.mPoints.length;
		if(pid == 0) {
			this.mPoints.push(new flash.display.GfxPoint(this.mPenX,this.mPenY,0.0,0.0,0));
			pid++;
		}
		this.mPenX = inX;
		this.mPenY = inY;
		this.__expandStandardExtent(inX,inY,this.mCurrentLine.thickness);
		this.mPoints.push(new flash.display.GfxPoint(inX,inY,inCX,inCY,2));
		if(this.mCurrentLine.grad != null || this.mCurrentLine.alpha > 0) {
			if(this.mCurrentLine.point_idx0 < 0) this.mCurrentLine.point_idx0 = pid - 1;
			this.mCurrentLine.point_idx1 = pid;
		}
	}
	,createGradient: function(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio) {
		var points = new Array();
		var _g1 = 0, _g = colors.length;
		while(_g1 < _g) {
			var i = _g1++;
			points.push(new flash.display.GradPoint(colors[i],alphas[i],ratios[i]));
		}
		var flags = 0;
		if(type == flash.display.GradientType.RADIAL) flags |= 1;
		if(spreadMethod == flash.display.SpreadMethod.REPEAT) flags |= 2; else if(spreadMethod == flash.display.SpreadMethod.REFLECT) flags |= 4;
		if(matrix == null) {
			matrix = new flash.geom.Matrix();
			matrix.createGradientBox(25,25);
		} else matrix = matrix.clone();
		var focal = focalPointRatio == null?0:focalPointRatio;
		return new flash.display.Grad(points,matrix,flags,focal);
	}
	,createCanvasGradient: function(ctx,g) {
		var gradient;
		var matrix = g.matrix;
		if((g.flags & 1) == 0) {
			var p1 = matrix.transformPoint(new flash.geom.Point(-819.2,0));
			var p2 = matrix.transformPoint(new flash.geom.Point(819.2,0));
			gradient = ctx.createLinearGradient(p1.x,p1.y,p2.x,p2.y);
		} else {
			var p1 = matrix.transformPoint(new flash.geom.Point(g.focal * 819.2,0));
			var p2 = matrix.transformPoint(new flash.geom.Point(0,819.2));
			gradient = ctx.createRadialGradient(p1.x,p1.y,0,p2.x,p1.y,p2.y);
		}
		var _g = 0, _g1 = g.points;
		while(_g < _g1.length) {
			var point = _g1[_g];
			++_g;
			var color = this.createCanvasColor(point.col,point.alpha);
			var pos = point.ratio / 255;
			gradient.addColorStop(pos,color);
		}
		return gradient;
	}
	,createCanvasColor: function(color,alpha) {
		var r = (16711680 & color) >> 16;
		var g = (65280 & color) >> 8;
		var b = 255 & color;
		return "rgba" + "(" + r + "," + g + "," + b + "," + alpha + ")";
	}
	,closePolygon: function(inCancelFill) {
		var l = this.mPoints.length;
		if(l > 0) {
			if(l > 1) {
				if(this.mFilling && l > 2) {
					if(this.mPoints[this.mLastMoveID].x != this.mPoints[l - 1].x || this.mPoints[this.mLastMoveID].y != this.mPoints[l - 1].y) this.lineTo(this.mPoints[this.mLastMoveID].x,this.mPoints[this.mLastMoveID].y);
				}
				this.addLineSegment();
				var drawable = new flash.display.Drawable(this.mPoints,this.mFillColour,this.mFillAlpha,this.mSolidGradient,this.mBitmap,this.mLineJobs,null);
				this.addDrawable(drawable);
			}
			this.mLineJobs = [];
			this.mPoints = [];
		}
		if(inCancelFill) {
			this.mFillAlpha = 0;
			this.mSolidGradient = null;
			this.mBitmap = null;
			this.mFilling = false;
		}
		this.__changed = true;
	}
	,clear: function() {
		this.__clearLine();
		this.mPenX = 0.0;
		this.mPenY = 0.0;
		this.mDrawList = new Array();
		this.nextDrawIndex = 0;
		this.mPoints = [];
		this.mSolidGradient = null;
		this.mFilling = false;
		this.mFillColour = 0;
		this.mFillAlpha = 0.0;
		this.mLastMoveID = 0;
		this.__clearNextCycle = true;
		this.boundsDirty = true;
		this.__extent.x = 0.0;
		this.__extent.y = 0.0;
		this.__extent.width = 0.0;
		this.__extent.height = 0.0;
		this._padding = 0.0;
		this.mLineJobs = [];
	}
	,blit: function(inTexture) {
		this.closePolygon(true);
		var ctx = (function($this) {
			var $r;
			try {
				$r = $this.__surface.getContext("2d");
			} catch( e ) {
				$r = null;
			}
			return $r;
		}(this));
		if(ctx != null) ctx.drawImage(inTexture.___textureBuffer,this.mPenX,this.mPenY);
	}
	,beginGradientFill: function(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio) {
		this.closePolygon(true);
		this.mFilling = true;
		this.mBitmap = null;
		this.mSolidGradient = this.createGradient(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio);
	}
	,beginFill: function(color,alpha) {
		this.closePolygon(true);
		this.mFillColour = color;
		this.mFillAlpha = alpha == null?1.0:alpha;
		this.mFilling = true;
		this.mSolidGradient = null;
		this.mBitmap = null;
	}
	,beginBitmapFill: function(bitmap,matrix,in_repeat,in_smooth) {
		if(in_smooth == null) in_smooth = false;
		if(in_repeat == null) in_repeat = true;
		this.closePolygon(true);
		var repeat = in_repeat == null?true:in_repeat;
		var smooth = in_smooth == null?false:in_smooth;
		this.mFilling = true;
		this.mSolidGradient = null;
		this.__expandStandardExtent(bitmap.___textureBuffer != null?bitmap.___textureBuffer.width:0,bitmap.___textureBuffer != null?bitmap.___textureBuffer.height:0);
		this.mBitmap = { texture_buffer : bitmap.___textureBuffer, matrix : matrix == null?matrix:matrix.clone(), flags : (repeat?16:0) | (smooth?65536:0)};
	}
	,addLineSegment: function() {
		if(this.mCurrentLine.point_idx1 > 0) this.mLineJobs.push(new flash.display.LineJob(this.mCurrentLine.grad,this.mCurrentLine.point_idx0,this.mCurrentLine.point_idx1,this.mCurrentLine.thickness,this.mCurrentLine.alpha,this.mCurrentLine.colour,this.mCurrentLine.pixel_hinting,this.mCurrentLine.joints,this.mCurrentLine.caps,this.mCurrentLine.scale_mode,this.mCurrentLine.miter_limit));
		this.mCurrentLine.point_idx0 = this.mCurrentLine.point_idx1 = -1;
	}
	,addDrawable: function(inDrawable) {
		if(inDrawable == null) return;
		this.mDrawList.unshift(inDrawable);
	}
	,__class__: flash.display.Graphics
}
flash.display.Drawable = function(inPoints,inFillColour,inFillAlpha,inSolidGradient,inBitmap,inLineJobs,inTileJob) {
	this.points = inPoints;
	this.fillColour = inFillColour;
	this.fillAlpha = inFillAlpha;
	this.solidGradient = inSolidGradient;
	this.bitmap = inBitmap;
	this.lineJobs = inLineJobs;
	this.tileJob = inTileJob;
};
$hxClasses["flash.display.Drawable"] = flash.display.Drawable;
flash.display.Drawable.__name__ = ["flash","display","Drawable"];
flash.display.Drawable.prototype = {
	__class__: flash.display.Drawable
}
flash.display.GfxPoint = function(inX,inY,inCX,inCY,inType) {
	this.x = inX;
	this.y = inY;
	this.cx = inCX;
	this.cy = inCY;
	this.type = inType;
};
$hxClasses["flash.display.GfxPoint"] = flash.display.GfxPoint;
flash.display.GfxPoint.__name__ = ["flash","display","GfxPoint"];
flash.display.GfxPoint.prototype = {
	__class__: flash.display.GfxPoint
}
flash.display.Grad = function(inPoints,inMatrix,inFlags,inFocal) {
	this.points = inPoints;
	this.matrix = inMatrix;
	this.flags = inFlags;
	this.focal = inFocal;
};
$hxClasses["flash.display.Grad"] = flash.display.Grad;
flash.display.Grad.__name__ = ["flash","display","Grad"];
flash.display.Grad.prototype = {
	__class__: flash.display.Grad
}
flash.display.GradPoint = function(inCol,inAlpha,inRatio) {
	this.col = inCol;
	this.alpha = inAlpha;
	this.ratio = inRatio;
};
$hxClasses["flash.display.GradPoint"] = flash.display.GradPoint;
flash.display.GradPoint.__name__ = ["flash","display","GradPoint"];
flash.display.GradPoint.prototype = {
	__class__: flash.display.GradPoint
}
flash.display.LineJob = function(inGrad,inPoint_idx0,inPoint_idx1,inThickness,inAlpha,inColour,inPixel_hinting,inJoints,inCaps,inScale_mode,inMiter_limit) {
	this.grad = inGrad;
	this.point_idx0 = inPoint_idx0;
	this.point_idx1 = inPoint_idx1;
	this.thickness = inThickness;
	this.alpha = inAlpha;
	this.colour = inColour;
	this.pixel_hinting = inPixel_hinting;
	this.joints = inJoints;
	this.caps = inCaps;
	this.scale_mode = inScale_mode;
	this.miter_limit = inMiter_limit;
};
$hxClasses["flash.display.LineJob"] = flash.display.LineJob;
flash.display.LineJob.__name__ = ["flash","display","LineJob"];
flash.display.LineJob.prototype = {
	__class__: flash.display.LineJob
}
flash.display.PointInPathMode = $hxClasses["flash.display.PointInPathMode"] = { __ename__ : true, __constructs__ : ["USER_SPACE","DEVICE_SPACE"] }
flash.display.PointInPathMode.USER_SPACE = ["USER_SPACE",0];
flash.display.PointInPathMode.USER_SPACE.toString = $estr;
flash.display.PointInPathMode.USER_SPACE.__enum__ = flash.display.PointInPathMode;
flash.display.PointInPathMode.DEVICE_SPACE = ["DEVICE_SPACE",1];
flash.display.PointInPathMode.DEVICE_SPACE.toString = $estr;
flash.display.PointInPathMode.DEVICE_SPACE.__enum__ = flash.display.PointInPathMode;
flash.display.TileJob = function(sheet,drawList,flags) {
	this.sheet = sheet;
	this.drawList = drawList;
	this.flags = flags;
};
$hxClasses["flash.display.TileJob"] = flash.display.TileJob;
flash.display.TileJob.__name__ = ["flash","display","TileJob"];
flash.display.TileJob.prototype = {
	__class__: flash.display.TileJob
}
flash.display.IGraphicsFill = function() { }
$hxClasses["flash.display.IGraphicsFill"] = flash.display.IGraphicsFill;
flash.display.IGraphicsFill.__name__ = ["flash","display","IGraphicsFill"];
flash.display.IGraphicsFill.prototype = {
	__class__: flash.display.IGraphicsFill
}
flash.display.IGraphicsData = function() { }
$hxClasses["flash.display.IGraphicsData"] = flash.display.IGraphicsData;
flash.display.IGraphicsData.__name__ = ["flash","display","IGraphicsData"];
flash.display.IGraphicsData.prototype = {
	__class__: flash.display.IGraphicsData
}
flash.display.GraphicsGradientFill = function(type,colors,alphas,ratios,matrix,spreadMethod,interpolationMethod,focalPointRatio) {
	if(focalPointRatio == null) focalPointRatio = 0;
	this.type = type;
	this.colors = colors;
	this.alphas = alphas;
	this.ratios = ratios;
	this.matrix = matrix;
	this.spreadMethod = spreadMethod;
	this.interpolationMethod = interpolationMethod;
	this.focalPointRatio = focalPointRatio;
	this.__graphicsDataType = flash.display.GraphicsDataType.GRADIENT;
	this.__graphicsFillType = flash.display.GraphicsFillType.GRADIENT_FILL;
};
$hxClasses["flash.display.GraphicsGradientFill"] = flash.display.GraphicsGradientFill;
flash.display.GraphicsGradientFill.__name__ = ["flash","display","GraphicsGradientFill"];
flash.display.GraphicsGradientFill.__interfaces__ = [flash.display.IGraphicsFill,flash.display.IGraphicsData];
flash.display.GraphicsGradientFill.prototype = {
	__class__: flash.display.GraphicsGradientFill
}
flash.display.IGraphicsPath = function() { }
$hxClasses["flash.display.IGraphicsPath"] = flash.display.IGraphicsPath;
flash.display.IGraphicsPath.__name__ = ["flash","display","IGraphicsPath"];
flash.display.GraphicsPath = function(commands,data,winding) {
	this.commands = commands;
	this.data = data;
	this.winding = winding;
	this.__graphicsDataType = flash.display.GraphicsDataType.PATH;
};
$hxClasses["flash.display.GraphicsPath"] = flash.display.GraphicsPath;
flash.display.GraphicsPath.__name__ = ["flash","display","GraphicsPath"];
flash.display.GraphicsPath.__interfaces__ = [flash.display.IGraphicsPath,flash.display.IGraphicsData];
flash.display.GraphicsPath.prototype = {
	moveTo: function(x,y) {
		if(this.commands != null && this.data != null) {
			flash._Vector.Vector_Impl_.push(this.commands,1);
			flash._Vector.Vector_Impl_.push(this.data,x);
			flash._Vector.Vector_Impl_.push(this.data,y);
		}
	}
	,lineTo: function(x,y) {
		if(this.commands != null && this.data != null) {
			flash._Vector.Vector_Impl_.push(this.commands,2);
			flash._Vector.Vector_Impl_.push(this.data,x);
			flash._Vector.Vector_Impl_.push(this.data,y);
		}
	}
	,curveTo: function(controlX,controlY,anchorX,anchorY) {
		if(this.commands != null && this.data != null) {
			flash._Vector.Vector_Impl_.push(this.commands,3);
			flash._Vector.Vector_Impl_.push(this.data,anchorX);
			flash._Vector.Vector_Impl_.push(this.data,anchorY);
			flash._Vector.Vector_Impl_.push(this.data,controlX);
			flash._Vector.Vector_Impl_.push(this.data,controlY);
		}
	}
	,__class__: flash.display.GraphicsPath
}
flash.display.GraphicsPathCommand = function() { }
$hxClasses["flash.display.GraphicsPathCommand"] = flash.display.GraphicsPathCommand;
flash.display.GraphicsPathCommand.__name__ = ["flash","display","GraphicsPathCommand"];
flash.display.GraphicsPathWinding = $hxClasses["flash.display.GraphicsPathWinding"] = { __ename__ : true, __constructs__ : ["EVEN_ODD","NON_ZERO"] }
flash.display.GraphicsPathWinding.EVEN_ODD = ["EVEN_ODD",0];
flash.display.GraphicsPathWinding.EVEN_ODD.toString = $estr;
flash.display.GraphicsPathWinding.EVEN_ODD.__enum__ = flash.display.GraphicsPathWinding;
flash.display.GraphicsPathWinding.NON_ZERO = ["NON_ZERO",1];
flash.display.GraphicsPathWinding.NON_ZERO.toString = $estr;
flash.display.GraphicsPathWinding.NON_ZERO.__enum__ = flash.display.GraphicsPathWinding;
flash.display.GraphicsSolidFill = function(color,alpha) {
	if(alpha == null) alpha = 1;
	if(color == null) color = 0;
	this.alpha = alpha;
	this.color = color;
	this.__graphicsDataType = flash.display.GraphicsDataType.SOLID;
	this.__graphicsFillType = flash.display.GraphicsFillType.SOLID_FILL;
};
$hxClasses["flash.display.GraphicsSolidFill"] = flash.display.GraphicsSolidFill;
flash.display.GraphicsSolidFill.__name__ = ["flash","display","GraphicsSolidFill"];
flash.display.GraphicsSolidFill.__interfaces__ = [flash.display.IGraphicsFill,flash.display.IGraphicsData];
flash.display.GraphicsSolidFill.prototype = {
	__class__: flash.display.GraphicsSolidFill
}
flash.display.IGraphicsStroke = function() { }
$hxClasses["flash.display.IGraphicsStroke"] = flash.display.IGraphicsStroke;
flash.display.IGraphicsStroke.__name__ = ["flash","display","IGraphicsStroke"];
flash.display.GraphicsStroke = function(thickness,pixelHinting,scaleMode,caps,joints,miterLimit,fill) {
	if(miterLimit == null) miterLimit = 3;
	if(pixelHinting == null) pixelHinting = false;
	if(thickness == null) thickness = 0.0;
	this.caps = caps != null?caps:null;
	this.fill = fill;
	this.joints = joints != null?joints:null;
	this.miterLimit = miterLimit;
	this.pixelHinting = pixelHinting;
	this.scaleMode = scaleMode != null?scaleMode:null;
	this.thickness = thickness;
	this.__graphicsDataType = flash.display.GraphicsDataType.STROKE;
};
$hxClasses["flash.display.GraphicsStroke"] = flash.display.GraphicsStroke;
flash.display.GraphicsStroke.__name__ = ["flash","display","GraphicsStroke"];
flash.display.GraphicsStroke.__interfaces__ = [flash.display.IGraphicsStroke,flash.display.IGraphicsData];
flash.display.GraphicsStroke.prototype = {
	__class__: flash.display.GraphicsStroke
}
flash.display.GraphicsDataType = $hxClasses["flash.display.GraphicsDataType"] = { __ename__ : true, __constructs__ : ["STROKE","SOLID","GRADIENT","PATH"] }
flash.display.GraphicsDataType.STROKE = ["STROKE",0];
flash.display.GraphicsDataType.STROKE.toString = $estr;
flash.display.GraphicsDataType.STROKE.__enum__ = flash.display.GraphicsDataType;
flash.display.GraphicsDataType.SOLID = ["SOLID",1];
flash.display.GraphicsDataType.SOLID.toString = $estr;
flash.display.GraphicsDataType.SOLID.__enum__ = flash.display.GraphicsDataType;
flash.display.GraphicsDataType.GRADIENT = ["GRADIENT",2];
flash.display.GraphicsDataType.GRADIENT.toString = $estr;
flash.display.GraphicsDataType.GRADIENT.__enum__ = flash.display.GraphicsDataType;
flash.display.GraphicsDataType.PATH = ["PATH",3];
flash.display.GraphicsDataType.PATH.toString = $estr;
flash.display.GraphicsDataType.PATH.__enum__ = flash.display.GraphicsDataType;
flash.display.GraphicsFillType = $hxClasses["flash.display.GraphicsFillType"] = { __ename__ : true, __constructs__ : ["SOLID_FILL","GRADIENT_FILL"] }
flash.display.GraphicsFillType.SOLID_FILL = ["SOLID_FILL",0];
flash.display.GraphicsFillType.SOLID_FILL.toString = $estr;
flash.display.GraphicsFillType.SOLID_FILL.__enum__ = flash.display.GraphicsFillType;
flash.display.GraphicsFillType.GRADIENT_FILL = ["GRADIENT_FILL",1];
flash.display.GraphicsFillType.GRADIENT_FILL.toString = $estr;
flash.display.GraphicsFillType.GRADIENT_FILL.__enum__ = flash.display.GraphicsFillType;
flash.display.InterpolationMethod = $hxClasses["flash.display.InterpolationMethod"] = { __ename__ : true, __constructs__ : ["RGB","LINEAR_RGB"] }
flash.display.InterpolationMethod.RGB = ["RGB",0];
flash.display.InterpolationMethod.RGB.toString = $estr;
flash.display.InterpolationMethod.RGB.__enum__ = flash.display.InterpolationMethod;
flash.display.InterpolationMethod.LINEAR_RGB = ["LINEAR_RGB",1];
flash.display.InterpolationMethod.LINEAR_RGB.toString = $estr;
flash.display.InterpolationMethod.LINEAR_RGB.__enum__ = flash.display.InterpolationMethod;
flash.display.JointStyle = $hxClasses["flash.display.JointStyle"] = { __ename__ : true, __constructs__ : ["MITER","ROUND","BEVEL"] }
flash.display.JointStyle.MITER = ["MITER",0];
flash.display.JointStyle.MITER.toString = $estr;
flash.display.JointStyle.MITER.__enum__ = flash.display.JointStyle;
flash.display.JointStyle.ROUND = ["ROUND",1];
flash.display.JointStyle.ROUND.toString = $estr;
flash.display.JointStyle.ROUND.__enum__ = flash.display.JointStyle;
flash.display.JointStyle.BEVEL = ["BEVEL",2];
flash.display.JointStyle.BEVEL.toString = $estr;
flash.display.JointStyle.BEVEL.__enum__ = flash.display.JointStyle;
flash.display.LineScaleMode = $hxClasses["flash.display.LineScaleMode"] = { __ename__ : true, __constructs__ : ["HORIZONTAL","NONE","NORMAL","VERTICAL"] }
flash.display.LineScaleMode.HORIZONTAL = ["HORIZONTAL",0];
flash.display.LineScaleMode.HORIZONTAL.toString = $estr;
flash.display.LineScaleMode.HORIZONTAL.__enum__ = flash.display.LineScaleMode;
flash.display.LineScaleMode.NONE = ["NONE",1];
flash.display.LineScaleMode.NONE.toString = $estr;
flash.display.LineScaleMode.NONE.__enum__ = flash.display.LineScaleMode;
flash.display.LineScaleMode.NORMAL = ["NORMAL",2];
flash.display.LineScaleMode.NORMAL.toString = $estr;
flash.display.LineScaleMode.NORMAL.__enum__ = flash.display.LineScaleMode;
flash.display.LineScaleMode.VERTICAL = ["VERTICAL",3];
flash.display.LineScaleMode.VERTICAL.toString = $estr;
flash.display.LineScaleMode.VERTICAL.__enum__ = flash.display.LineScaleMode;
flash.display.Loader = function() {
	flash.display.Sprite.call(this);
	this.contentLoaderInfo = flash.display.LoaderInfo.create(this);
};
$hxClasses["flash.display.Loader"] = flash.display.Loader;
flash.display.Loader.__name__ = ["flash","display","Loader"];
flash.display.Loader.__super__ = flash.display.Sprite;
flash.display.Loader.prototype = $extend(flash.display.Sprite.prototype,{
	handleLoad: function(e) {
		e.currentTarget = this;
		this.content.__invalidateBounds();
		this.content.__render(null,null);
		this.contentLoaderInfo.removeEventListener(flash.events.Event.COMPLETE,$bind(this,this.handleLoad));
	}
	,validateBounds: function() {
		if(this.get__boundsInvalid()) {
			flash.display.Sprite.prototype.validateBounds.call(this);
			if(this.mImage != null) {
				var r = new flash.geom.Rectangle(0,0,this.mImage.get_width(),this.mImage.get_height());
				if(r.width != 0 || r.height != 0) {
					if(this.__boundsRect.width == 0 && this.__boundsRect.height == 0) this.__boundsRect = r.clone(); else this.__boundsRect.extendBounds(r);
				}
			}
			if(this.scale9Grid != null) {
				this.__boundsRect.width *= this.__scaleX;
				this.__boundsRect.height *= this.__scaleY;
				this.__width = this.__boundsRect.width;
				this.__height = this.__boundsRect.height;
			} else {
				this.__width = this.__boundsRect.width * this.__scaleX;
				this.__height = this.__boundsRect.height * this.__scaleY;
			}
		}
	}
	,toString: function() {
		return "[Loader name=" + this.name + " id=" + this.___id + "]";
	}
	,loadBytes: function(buffer) {
		var _g = this;
		try {
			this.contentLoaderInfo.addEventListener(flash.events.Event.COMPLETE,$bind(this,this.handleLoad),false,2147483647);
			flash.display.BitmapData.loadFromBytes(buffer,null,function(bmd) {
				_g.content = new flash.display.Bitmap(bmd);
				_g.contentLoaderInfo.content = _g.content;
				_g.addChild(_g.content);
				var evt = new flash.events.Event(flash.events.Event.COMPLETE);
				evt.currentTarget = _g;
				_g.contentLoaderInfo.dispatchEvent(evt);
			});
		} catch( e ) {
			console.log("Error " + Std.string(e));
			var evt = new flash.events.IOErrorEvent(flash.events.IOErrorEvent.IO_ERROR);
			evt.currentTarget = this;
			this.contentLoaderInfo.dispatchEvent(evt);
		}
	}
	,load: function(request,context) {
		var extension = "";
		var parts = request.url.split(".");
		if(parts.length > 0) extension = parts[parts.length - 1].toLowerCase();
		var transparent = true;
		this.contentLoaderInfo.url = request.url;
		if(request.contentType == null && request.contentType != "") this.contentLoaderInfo.contentType = (function($this) {
			var $r;
			switch(extension) {
			case "swf":
				$r = "application/x-shockwave-flash";
				break;
			case "jpg":case "jpeg":
				$r = (function($this) {
					var $r;
					transparent = false;
					$r = "image/jpeg";
					return $r;
				}($this));
				break;
			case "png":
				$r = "image/png";
				break;
			case "gif":
				$r = "image/gif";
				break;
			default:
				$r = "application/x-www-form-urlencoded";
			}
			return $r;
		}(this)); else this.contentLoaderInfo.contentType = request.contentType;
		this.mImage = new flash.display.BitmapData(0,0,transparent);
		try {
			this.contentLoaderInfo.addEventListener(flash.events.Event.COMPLETE,$bind(this,this.handleLoad),false,2147483647);
			this.mImage.__loadFromFile(request.url,this.contentLoaderInfo);
			this.content = new flash.display.Bitmap(this.mImage);
			this.contentLoaderInfo.content = this.content;
			this.addChild(this.content);
		} catch( e ) {
			console.log("Error " + Std.string(e));
			var evt = new flash.events.IOErrorEvent(flash.events.IOErrorEvent.IO_ERROR);
			evt.currentTarget = this;
			this.contentLoaderInfo.dispatchEvent(evt);
			return;
		}
		if(this.mShape == null) {
			this.mShape = new flash.display.Shape();
			this.addChild(this.mShape);
		}
	}
	,__class__: flash.display.Loader
});
flash.display.LoaderInfo = function() {
	flash.events.EventDispatcher.call(this);
	this.applicationDomain = flash.system.ApplicationDomain.currentDomain;
	this.bytesLoaded = 0;
	this.bytesTotal = 0;
	this.childAllowsParent = true;
	this.parameters = { };
};
$hxClasses["flash.display.LoaderInfo"] = flash.display.LoaderInfo;
flash.display.LoaderInfo.__name__ = ["flash","display","LoaderInfo"];
flash.display.LoaderInfo.create = function(ldr) {
	var li = new flash.display.LoaderInfo();
	if(ldr != null) li.loader = ldr; else li.url = "";
	return li;
}
flash.display.LoaderInfo.__super__ = flash.events.EventDispatcher;
flash.display.LoaderInfo.prototype = $extend(flash.events.EventDispatcher.prototype,{
	__class__: flash.display.LoaderInfo
});
flash.display.MovieClip = function() {
	flash.display.Sprite.call(this);
	this.enabled = true;
	this.__currentFrame = 0;
	this.__totalFrames = 0;
	this.loaderInfo = flash.display.LoaderInfo.create(null);
};
$hxClasses["flash.display.MovieClip"] = flash.display.MovieClip;
flash.display.MovieClip.__name__ = ["flash","display","MovieClip"];
flash.display.MovieClip.__super__ = flash.display.Sprite;
flash.display.MovieClip.prototype = $extend(flash.display.Sprite.prototype,{
	get_totalFrames: function() {
		return this.__totalFrames;
	}
	,get_framesLoaded: function() {
		return this.__totalFrames;
	}
	,get_currentFrame: function() {
		return this.__currentFrame;
	}
	,toString: function() {
		return "[MovieClip name=" + this.name + " id=" + this.___id + "]";
	}
	,stop: function() {
	}
	,prevFrame: function() {
	}
	,play: function() {
	}
	,nextFrame: function() {
	}
	,gotoAndStop: function(frame,scene) {
		if(scene == null) scene = "";
	}
	,gotoAndPlay: function(frame,scene) {
		if(scene == null) scene = "";
	}
	,__class__: flash.display.MovieClip
	,__properties__: $extend(flash.display.Sprite.prototype.__properties__,{get_currentFrame:"get_currentFrame",get_framesLoaded:"get_framesLoaded",get_totalFrames:"get_totalFrames"})
});
flash.display.PixelSnapping = $hxClasses["flash.display.PixelSnapping"] = { __ename__ : true, __constructs__ : ["NEVER","AUTO","ALWAYS"] }
flash.display.PixelSnapping.NEVER = ["NEVER",0];
flash.display.PixelSnapping.NEVER.toString = $estr;
flash.display.PixelSnapping.NEVER.__enum__ = flash.display.PixelSnapping;
flash.display.PixelSnapping.AUTO = ["AUTO",1];
flash.display.PixelSnapping.AUTO.toString = $estr;
flash.display.PixelSnapping.AUTO.__enum__ = flash.display.PixelSnapping;
flash.display.PixelSnapping.ALWAYS = ["ALWAYS",2];
flash.display.PixelSnapping.ALWAYS.toString = $estr;
flash.display.PixelSnapping.ALWAYS.__enum__ = flash.display.PixelSnapping;
flash.display.Shape = function() {
	flash.display.DisplayObject.call(this);
	this.__graphics = new flash.display.Graphics();
};
$hxClasses["flash.display.Shape"] = flash.display.Shape;
flash.display.Shape.__name__ = ["flash","display","Shape"];
flash.display.Shape.__super__ = flash.display.DisplayObject;
flash.display.Shape.prototype = $extend(flash.display.DisplayObject.prototype,{
	get_graphics: function() {
		return this.__graphics;
	}
	,__getObjectUnderPoint: function(point) {
		if(this.parent == null) return null;
		if(this.parent.mouseEnabled && flash.display.DisplayObject.prototype.__getObjectUnderPoint.call(this,point) == this) return this.parent; else return null;
	}
	,__getGraphics: function() {
		return this.__graphics;
	}
	,toString: function() {
		return "[Shape name=" + this.name + " id=" + this.___id + "]";
	}
	,__class__: flash.display.Shape
	,__properties__: $extend(flash.display.DisplayObject.prototype.__properties__,{get_graphics:"get_graphics"})
});
flash.display.SpreadMethod = $hxClasses["flash.display.SpreadMethod"] = { __ename__ : true, __constructs__ : ["REPEAT","REFLECT","PAD"] }
flash.display.SpreadMethod.REPEAT = ["REPEAT",0];
flash.display.SpreadMethod.REPEAT.toString = $estr;
flash.display.SpreadMethod.REPEAT.__enum__ = flash.display.SpreadMethod;
flash.display.SpreadMethod.REFLECT = ["REFLECT",1];
flash.display.SpreadMethod.REFLECT.toString = $estr;
flash.display.SpreadMethod.REFLECT.__enum__ = flash.display.SpreadMethod;
flash.display.SpreadMethod.PAD = ["PAD",2];
flash.display.SpreadMethod.PAD.toString = $estr;
flash.display.SpreadMethod.PAD.__enum__ = flash.display.SpreadMethod;
flash.events.Event = function(inType,inBubbles,inCancelable) {
	if(inCancelable == null) inCancelable = false;
	if(inBubbles == null) inBubbles = false;
	this.type = inType;
	this.bubbles = inBubbles;
	this.cancelable = inCancelable;
	this.__isCancelled = false;
	this.__isCancelledNow = false;
	this.target = null;
	this.currentTarget = null;
	this.eventPhase = flash.events.EventPhase.AT_TARGET;
};
$hxClasses["flash.events.Event"] = flash.events.Event;
flash.events.Event.__name__ = ["flash","events","Event"];
flash.events.Event.prototype = {
	__setPhase: function(phase) {
		this.eventPhase = phase;
	}
	,__getIsCancelledNow: function() {
		return this.__isCancelledNow;
	}
	,__getIsCancelled: function() {
		return this.__isCancelled;
	}
	,__createSimilar: function(type,related,targ) {
		var result = new flash.events.Event(type,this.bubbles,this.cancelable);
		if(targ != null) result.target = targ;
		return result;
	}
	,toString: function() {
		return "[Event type=" + this.type + " bubbles=" + Std.string(this.bubbles) + " cancelable=" + Std.string(this.cancelable) + "]";
	}
	,stopPropagation: function() {
		this.__isCancelled = true;
	}
	,stopImmediatePropagation: function() {
		this.__isCancelled = true;
		this.__isCancelledNow = true;
	}
	,clone: function() {
		return new flash.events.Event(this.type,this.bubbles,this.cancelable);
	}
	,__class__: flash.events.Event
}
flash.events.MouseEvent = function(type,bubbles,cancelable,localX,localY,relatedObject,ctrlKey,altKey,shiftKey,buttonDown,delta,commandKey,clickCount) {
	if(clickCount == null) clickCount = 0;
	if(commandKey == null) commandKey = false;
	if(delta == null) delta = 0;
	if(buttonDown == null) buttonDown = false;
	if(shiftKey == null) shiftKey = false;
	if(altKey == null) altKey = false;
	if(ctrlKey == null) ctrlKey = false;
	if(localY == null) localY = 0;
	if(localX == null) localX = 0;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = true;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.shiftKey = shiftKey;
	this.altKey = altKey;
	this.ctrlKey = ctrlKey;
	this.bubbles = bubbles;
	this.relatedObject = relatedObject;
	this.delta = delta;
	this.localX = localX;
	this.localY = localY;
	this.buttonDown = buttonDown;
	this.commandKey = commandKey;
	this.clickCount = clickCount;
};
$hxClasses["flash.events.MouseEvent"] = flash.events.MouseEvent;
flash.events.MouseEvent.__name__ = ["flash","events","MouseEvent"];
flash.events.MouseEvent.__create = function(type,event,local,target) {
	var __mouseDown = false;
	var delta = 2;
	if(type == flash.events.MouseEvent.MOUSE_WHEEL) {
		var mouseEvent = event;
		if(mouseEvent.wheelDelta) delta = mouseEvent.wheelDelta / 120 | 0; else if(mouseEvent.detail) -mouseEvent.detail | 0;
	}
	if(type == flash.events.MouseEvent.MOUSE_DOWN) __mouseDown = event.which != null?event.which == 1:event.button != null?event.button == 0:false; else if(type == flash.events.MouseEvent.MOUSE_UP) {
		if(event.which != null) {
			if(event.which == 1) __mouseDown = false; else if(event.button != null) {
				if(event.button == 0) __mouseDown = false; else __mouseDown = false;
			}
		}
	}
	var pseudoEvent = new flash.events.MouseEvent(type,true,false,local.x,local.y,null,event.ctrlKey,event.altKey,event.shiftKey,__mouseDown,delta);
	pseudoEvent.stageX = flash.Lib.get_current().get_stage().get_mouseX();
	pseudoEvent.stageY = flash.Lib.get_current().get_stage().get_mouseY();
	pseudoEvent.target = target;
	return pseudoEvent;
}
flash.events.MouseEvent.__super__ = flash.events.Event;
flash.events.MouseEvent.prototype = $extend(flash.events.Event.prototype,{
	updateAfterEvent: function() {
	}
	,__createSimilar: function(type,related,targ) {
		var result = new flash.events.MouseEvent(type,this.bubbles,this.cancelable,this.localX,this.localY,related == null?this.relatedObject:related,this.ctrlKey,this.altKey,this.shiftKey,this.buttonDown,this.delta,this.commandKey,this.clickCount);
		if(targ != null) result.target = targ;
		return result;
	}
	,__class__: flash.events.MouseEvent
});
flash.display.Stage = function(width,height) {
	flash.display.DisplayObjectContainer.call(this);
	this.__focusObject = null;
	this.__focusObjectActivated = false;
	this.__windowWidth = width;
	this.__windowHeight = height;
	this.stageFocusRect = false;
	this.scaleMode = flash.display.StageScaleMode.SHOW_ALL;
	this.__stageMatrix = new flash.geom.Matrix();
	this.tabEnabled = true;
	this.set_frameRate(0.0);
	this.set_backgroundColor(16777215);
	this.name = "Stage";
	this.loaderInfo = flash.display.LoaderInfo.create(null);
	this.loaderInfo.parameters.width = Std.string(this.__windowWidth);
	this.loaderInfo.parameters.height = Std.string(this.__windowHeight);
	this.__pointInPathMode = flash.display.Graphics.__detectIsPointInPathMode();
	this.__mouseOverObjects = [];
	this.set_showDefaultContextMenu(true);
	this.__touchInfo = [];
	this.__uIEventsQueue = new Array(1000);
	this.__uIEventsQueueIndex = 0;
};
$hxClasses["flash.display.Stage"] = flash.display.Stage;
flash.display.Stage.__name__ = ["flash","display","Stage"];
flash.display.Stage.getOrientation = function() {
	var rotation = window.orientation;
	var orientation = flash.display.Stage.OrientationPortrait;
	switch(rotation) {
	case -90:
		orientation = flash.display.Stage.OrientationLandscapeLeft;
		break;
	case 180:
		orientation = flash.display.Stage.OrientationPortraitUpsideDown;
		break;
	case 90:
		orientation = flash.display.Stage.OrientationLandscapeRight;
		break;
	default:
		orientation = flash.display.Stage.OrientationPortrait;
	}
	return orientation;
}
flash.display.Stage.__super__ = flash.display.DisplayObjectContainer;
flash.display.Stage.prototype = $extend(flash.display.DisplayObjectContainer.prototype,{
	get_stageWidth: function() {
		return this.__windowWidth;
	}
	,get_stageHeight: function() {
		return this.__windowHeight;
	}
	,get_stage: function() {
		return flash.Lib.__getStage();
	}
	,set_showDefaultContextMenu: function(showDefaultContextMenu) {
		if(showDefaultContextMenu != this.__showDefaultContextMenu && this.__showDefaultContextMenu != null) {
			if(!showDefaultContextMenu) flash.Lib.__disableRightClick(); else flash.Lib.__enableRightClick();
		}
		this.__showDefaultContextMenu = showDefaultContextMenu;
		return showDefaultContextMenu;
	}
	,get_showDefaultContextMenu: function() {
		return this.__showDefaultContextMenu;
	}
	,set_quality: function(inQuality) {
		return this.quality = inQuality;
	}
	,get_quality: function() {
		return this.quality != null?this.quality:flash.display.StageQuality.BEST;
	}
	,get_mouseY: function() {
		return this._mouseY;
	}
	,get_mouseX: function() {
		return this._mouseX;
	}
	,get_fullScreenHeight: function() {
		return js.Browser.window.innerHeight;
	}
	,get_fullScreenWidth: function() {
		return js.Browser.window.innerWidth;
	}
	,set_frameRate: function(speed) {
		if(speed == 0) {
			var window = js.Browser.window;
			var __requestAnimationFrame = window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame || window.oRequestAnimationFrame || window.msRequestAnimationFrame;
			if(__requestAnimationFrame == null) speed = 60;
		}
		if(speed != 0) this.__interval = 1000.0 / speed | 0;
		this.__frameRate = speed;
		this.__updateNextWake();
		return speed;
	}
	,get_frameRate: function() {
		return this.__frameRate;
	}
	,set_focus: function(inObj) {
		this.__onFocus(inObj);
		return this.__focusObject;
	}
	,get_focus: function() {
		return this.__focusObject;
	}
	,set_displayState: function(displayState) {
		if(displayState != this.displayState && this.displayState != null) {
			switch( (displayState)[1] ) {
			case 0:
				flash.Lib.__disableFullScreen();
				break;
			case 1:
			case 2:
				flash.Lib.__enableFullScreen();
				break;
			}
		}
		this.displayState = displayState;
		return displayState;
	}
	,get_displayState: function() {
		return this.displayState;
	}
	,set_color: function(col) {
		return this.__backgroundColour = col;
	}
	,get_color: function() {
		return this.__backgroundColour;
	}
	,set_backgroundColor: function(col) {
		return this.__backgroundColour = col;
	}
	,get_backgroundColor: function() {
		return this.__backgroundColour;
	}
	,__onTouch: function(event,touch,type,touchInfo,isPrimaryTouchPoint) {
		var rect = flash.Lib.mMe.__scr.getBoundingClientRect();
		var point = new flash.geom.Point(touch.pageX - rect.left,touch.pageY - rect.top);
		var obj = this.__getObjectUnderPoint(point);
		this._mouseX = point.x;
		this._mouseY = point.y;
		var stack = new Array();
		if(obj != null) obj.__getInteractiveObjectStack(stack);
		if(stack.length > 0) {
			stack.reverse();
			var local = obj.globalToLocal(point);
			var evt = flash.events.TouchEvent.__create(type,event,touch,local,obj);
			evt.touchPointID = touch.identifier;
			evt.isPrimaryTouchPoint = isPrimaryTouchPoint;
			this.__checkInOuts(evt,stack,touchInfo);
			obj.__fireEvent(evt);
			var mouseType = (function($this) {
				var $r;
				switch(type) {
				case "touchBegin":
					$r = flash.events.MouseEvent.MOUSE_DOWN;
					break;
				case "touchEnd":
					$r = flash.events.MouseEvent.MOUSE_UP;
					break;
				default:
					$r = (function($this) {
						var $r;
						if($this.__dragObject != null) $this.__drag(point);
						$r = flash.events.MouseEvent.MOUSE_MOVE;
						return $r;
					}($this));
				}
				return $r;
			}(this));
			obj.__fireEvent(flash.events.MouseEvent.__create(mouseType,evt,local,obj));
		} else {
			var evt = flash.events.TouchEvent.__create(type,event,touch,point,null);
			evt.touchPointID = touch.identifier;
			evt.isPrimaryTouchPoint = isPrimaryTouchPoint;
			this.__checkInOuts(evt,stack,touchInfo);
		}
	}
	,__onResize: function(inW,inH) {
		this.__windowWidth = inW;
		this.__windowHeight = inH;
		var event = new flash.events.Event(flash.events.Event.RESIZE);
		event.target = this;
		this.__broadcast(event);
	}
	,__onMouse: function(event,type) {
		var rect = flash.Lib.mMe.__scr.getBoundingClientRect();
		var point = new flash.geom.Point(event.clientX - rect.left,event.clientY - rect.top);
		if(this.__dragObject != null) this.__drag(point);
		var obj = this.__getObjectUnderPoint(point);
		this._mouseX = point.x;
		this._mouseY = point.y;
		var stack = new Array();
		if(obj != null) obj.__getInteractiveObjectStack(stack);
		if(stack.length > 0) {
			stack.reverse();
			var local = obj.globalToLocal(point);
			var evt = flash.events.MouseEvent.__create(type,event,local,obj);
			this.__checkInOuts(evt,stack);
			if(type == flash.events.MouseEvent.MOUSE_DOWN) this.__onFocus(stack[stack.length - 1]);
			obj.__fireEvent(evt);
		} else {
			var evt = flash.events.MouseEvent.__create(type,event,point,null);
			this.__checkInOuts(evt,stack);
		}
	}
	,__onFocus: function(target) {
		if(target != this.__focusObject) {
			if(this.__focusObject != null) this.__focusObject.__fireEvent(new flash.events.FocusEvent(flash.events.FocusEvent.FOCUS_OUT,true,false,this.__focusObject,false,0));
			target.__fireEvent(new flash.events.FocusEvent(flash.events.FocusEvent.FOCUS_IN,true,false,target,false,0));
			this.__focusObject = target;
		}
	}
	,__onKey: function(code,pressed,inChar,ctrl,alt,shift,keyLocation) {
		var stack = new Array();
		if(this.__focusObject == null) this.__getInteractiveObjectStack(stack); else this.__focusObject.__getInteractiveObjectStack(stack);
		if(stack.length > 0) {
			var obj = stack[0];
			var evt = new flash.events.KeyboardEvent(pressed?flash.events.KeyboardEvent.KEY_DOWN:flash.events.KeyboardEvent.KEY_UP,true,false,inChar,code,keyLocation,ctrl,alt,shift);
			obj.__fireEvent(evt);
		}
	}
	,__handleOrientationChange: function() {
	}
	,__handleAccelerometer: function(evt) {
		flash.display.Stage.__acceleration.x = evt.accelerationIncludingGravity.x;
		flash.display.Stage.__acceleration.y = evt.accelerationIncludingGravity.y;
		flash.display.Stage.__acceleration.z = evt.accelerationIncludingGravity.z;
	}
	,__updateNextWake: function() {
		if(this.__frameRate == 0) {
			var __requestAnimationFrame = window.requestAnimationFrame || window.webkitRequestAnimationFrame || window.mozRequestAnimationFrame || window.oRequestAnimationFrame || window.msRequestAnimationFrame;
			__requestAnimationFrame($bind(this,this.__updateNextWake));
			this.__stageRender();
		} else {
			js.Browser.window.clearInterval(this.__timer);
			this.__timer = js.Browser.window.setInterval($bind(this,this.__stageRender),this.__interval);
		}
	}
	,__stopDrag: function(sprite) {
		this.__dragBounds = null;
		this.__dragObject = null;
	}
	,__startDrag: function(sprite,lockCenter,bounds) {
		if(lockCenter == null) lockCenter = false;
		this.__dragBounds = bounds == null?null:bounds.clone();
		this.__dragObject = sprite;
		if(this.__dragObject != null) {
			var mouse = new flash.geom.Point(this._mouseX,this._mouseY);
			var p = this.__dragObject.parent;
			if(p != null) mouse = p.globalToLocal(mouse);
			if(lockCenter) {
				var bounds1 = sprite.getBounds(this);
				this.__dragOffsetX = this.__dragObject.get_x() - (bounds1.width / 2 + bounds1.x);
				this.__dragOffsetY = this.__dragObject.get_y() - (bounds1.height / 2 + bounds1.y);
			} else {
				this.__dragOffsetX = this.__dragObject.get_x() - mouse.x;
				this.__dragOffsetY = this.__dragObject.get_y() - mouse.y;
			}
		}
	}
	,__stageRender: function(_) {
		if(!this.__stageActive) {
			this.__onResize(this.__windowWidth,this.__windowHeight);
			var event = new flash.events.Event(flash.events.Event.ACTIVATE);
			event.target = this;
			this.__broadcast(event);
			this.__stageActive = true;
		}
		var _g1 = 0, _g = this.__uIEventsQueueIndex;
		while(_g1 < _g) {
			var i = _g1++;
			if(this.__uIEventsQueue[i] != null) this.__processStageEvent(this.__uIEventsQueue[i]);
		}
		this.__uIEventsQueueIndex = 0;
		var event = new flash.events.Event(flash.events.Event.ENTER_FRAME);
		this.__broadcast(event);
		if(this.__invalid) {
			var event1 = new flash.events.Event(flash.events.Event.RENDER);
			this.__broadcast(event1);
		}
		this.__renderAll();
	}
	,__renderToCanvas: function(canvas) {
		canvas.width = canvas.width;
		this.__render(canvas);
	}
	,__renderAll: function() {
		this.__render(null,null);
	}
	,__queueStageEvent: function(evt) {
		this.__uIEventsQueue[this.__uIEventsQueueIndex++] = evt;
	}
	,__processStageEvent: function(evt) {
		evt.stopPropagation();
		switch(evt.type) {
		case "resize":
			this.__onResize(flash.Lib.__getWidth(),flash.Lib.__getHeight());
			break;
		case "focus":
			this.__onFocus(this);
			if(!this.__focusObjectActivated) {
				this.__focusObjectActivated = true;
				this.dispatchEvent(new flash.events.Event(flash.events.Event.ACTIVATE));
			}
			break;
		case "blur":
			if(this.__focusObjectActivated) {
				this.__focusObjectActivated = false;
				this.dispatchEvent(new flash.events.Event(flash.events.Event.DEACTIVATE));
			}
			break;
		case "mousemove":
			this.__onMouse(evt,flash.events.MouseEvent.MOUSE_MOVE);
			break;
		case "mousedown":
			this.__onMouse(evt,flash.events.MouseEvent.MOUSE_DOWN);
			break;
		case "mouseup":
			this.__onMouse(evt,flash.events.MouseEvent.MOUSE_UP);
			break;
		case "click":
			this.__onMouse(evt,flash.events.MouseEvent.CLICK);
			break;
		case "mousewheel":
			this.__onMouse(evt,flash.events.MouseEvent.MOUSE_WHEEL);
			break;
		case "dblclick":
			this.__onMouse(evt,flash.events.MouseEvent.DOUBLE_CLICK);
			break;
		case "keydown":
			var evt1 = evt;
			var keyCode = evt1.keyCode != null?evt1.keyCode:evt1.which;
			keyCode = flash.ui.Keyboard.__convertMozillaCode(keyCode);
			this.__onKey(keyCode,true,evt1.charCode,evt1.ctrlKey,evt1.altKey,evt1.shiftKey,evt1.keyLocation);
			break;
		case "keyup":
			var evt1 = evt;
			var keyCode = evt1.keyCode != null?evt1.keyCode:evt1.which;
			keyCode = flash.ui.Keyboard.__convertMozillaCode(keyCode);
			this.__onKey(keyCode,false,evt1.charCode,evt1.ctrlKey,evt1.altKey,evt1.shiftKey,evt1.keyLocation);
			break;
		case "touchstart":
			var evt1 = evt;
			evt1.preventDefault();
			var touchInfo = new flash.display._Stage.TouchInfo();
			this.__touchInfo[evt1.changedTouches[0].identifier] = touchInfo;
			this.__onTouch(evt1,evt1.changedTouches[0],"touchBegin",touchInfo,false);
			break;
		case "touchmove":
			var evt1 = evt;
			evt1.preventDefault();
			var touchInfo = this.__touchInfo[evt1.changedTouches[0].identifier];
			this.__onTouch(evt1,evt1.changedTouches[0],"touchMove",touchInfo,true);
			break;
		case "touchend":
			var evt1 = evt;
			evt1.preventDefault();
			var touchInfo = this.__touchInfo[evt1.changedTouches[0].identifier];
			this.__onTouch(evt1,evt1.changedTouches[0],"touchEnd",touchInfo,true);
			this.__touchInfo[evt1.changedTouches[0].identifier] = null;
			break;
		case "devicemotion":
			var evt1 = evt;
			this.__handleAccelerometer(evt1);
			break;
		case "orientationchange":
			this.__handleOrientationChange();
			break;
		default:
		}
	}
	,__isOnStage: function() {
		return true;
	}
	,__drag: function(point) {
		var p = this.__dragObject.parent;
		if(p != null) point = p.globalToLocal(point);
		var x = point.x + this.__dragOffsetX;
		var y = point.y + this.__dragOffsetY;
		if(this.__dragBounds != null) {
			if(x < this.__dragBounds.x) x = this.__dragBounds.x; else if(x > this.__dragBounds.get_right()) x = this.__dragBounds.get_right();
			if(y < this.__dragBounds.y) y = this.__dragBounds.y; else if(y > this.__dragBounds.get_bottom()) y = this.__dragBounds.get_bottom();
		}
		this.__dragObject.set_x(x);
		this.__dragObject.set_y(y);
	}
	,__checkInOuts: function(event,stack,touchInfo) {
		var prev = touchInfo == null?this.__mouseOverObjects:touchInfo.touchOverObjects;
		var changeEvents = touchInfo == null?flash.display.Stage.__mouseChanges:flash.display.Stage.__touchChanges;
		var new_n = stack.length;
		var new_obj = new_n > 0?stack[new_n - 1]:null;
		var old_n = prev.length;
		var old_obj = old_n > 0?prev[old_n - 1]:null;
		if(new_obj != old_obj) {
			if(old_obj != null) old_obj.__fireEvent(event.__createSimilar(changeEvents[0],new_obj,old_obj));
			if(new_obj != null) new_obj.__fireEvent(event.__createSimilar(changeEvents[1],old_obj,new_obj));
			var common = 0;
			while(common < new_n && common < old_n && stack[common] == prev[common]) common++;
			var rollOut = event.__createSimilar(changeEvents[2],new_obj,old_obj);
			var i = old_n - 1;
			while(i >= common) {
				prev[i].dispatchEvent(rollOut);
				i--;
			}
			var rollOver = event.__createSimilar(changeEvents[3],old_obj);
			var i1 = new_n - 1;
			while(i1 >= common) {
				stack[i1].dispatchEvent(rollOver);
				i1--;
			}
			if(touchInfo == null) this.__mouseOverObjects = stack; else touchInfo.touchOverObjects = stack;
		}
	}
	,toString: function() {
		return "[Stage id=" + this.___id + "]";
	}
	,invalidate: function() {
		this.__invalid = true;
	}
	,__class__: flash.display.Stage
	,__properties__: $extend(flash.display.DisplayObjectContainer.prototype.__properties__,{set_backgroundColor:"set_backgroundColor",get_backgroundColor:"get_backgroundColor",set_color:"set_color",get_color:"get_color",set_displayState:"set_displayState",get_displayState:"get_displayState",set_focus:"set_focus",get_focus:"get_focus",set_frameRate:"set_frameRate",get_frameRate:"get_frameRate",get_fullScreenHeight:"get_fullScreenHeight",get_fullScreenWidth:"get_fullScreenWidth",set_quality:"set_quality",get_quality:"get_quality",set_showDefaultContextMenu:"set_showDefaultContextMenu",get_showDefaultContextMenu:"get_showDefaultContextMenu",get_stageHeight:"get_stageHeight",get_stageWidth:"get_stageWidth"})
});
flash.display._Stage = {}
flash.display._Stage.TouchInfo = function() {
	this.touchOverObjects = [];
};
$hxClasses["flash.display._Stage.TouchInfo"] = flash.display._Stage.TouchInfo;
flash.display._Stage.TouchInfo.__name__ = ["flash","display","_Stage","TouchInfo"];
flash.display._Stage.TouchInfo.prototype = {
	__class__: flash.display._Stage.TouchInfo
}
flash.display.StageAlign = $hxClasses["flash.display.StageAlign"] = { __ename__ : true, __constructs__ : ["TOP_RIGHT","TOP_LEFT","TOP","RIGHT","LEFT","BOTTOM_RIGHT","BOTTOM_LEFT","BOTTOM"] }
flash.display.StageAlign.TOP_RIGHT = ["TOP_RIGHT",0];
flash.display.StageAlign.TOP_RIGHT.toString = $estr;
flash.display.StageAlign.TOP_RIGHT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.TOP_LEFT = ["TOP_LEFT",1];
flash.display.StageAlign.TOP_LEFT.toString = $estr;
flash.display.StageAlign.TOP_LEFT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.TOP = ["TOP",2];
flash.display.StageAlign.TOP.toString = $estr;
flash.display.StageAlign.TOP.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.RIGHT = ["RIGHT",3];
flash.display.StageAlign.RIGHT.toString = $estr;
flash.display.StageAlign.RIGHT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.LEFT = ["LEFT",4];
flash.display.StageAlign.LEFT.toString = $estr;
flash.display.StageAlign.LEFT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.BOTTOM_RIGHT = ["BOTTOM_RIGHT",5];
flash.display.StageAlign.BOTTOM_RIGHT.toString = $estr;
flash.display.StageAlign.BOTTOM_RIGHT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.BOTTOM_LEFT = ["BOTTOM_LEFT",6];
flash.display.StageAlign.BOTTOM_LEFT.toString = $estr;
flash.display.StageAlign.BOTTOM_LEFT.__enum__ = flash.display.StageAlign;
flash.display.StageAlign.BOTTOM = ["BOTTOM",7];
flash.display.StageAlign.BOTTOM.toString = $estr;
flash.display.StageAlign.BOTTOM.__enum__ = flash.display.StageAlign;
flash.display.StageDisplayState = $hxClasses["flash.display.StageDisplayState"] = { __ename__ : true, __constructs__ : ["NORMAL","FULL_SCREEN","FULL_SCREEN_INTERACTIVE"] }
flash.display.StageDisplayState.NORMAL = ["NORMAL",0];
flash.display.StageDisplayState.NORMAL.toString = $estr;
flash.display.StageDisplayState.NORMAL.__enum__ = flash.display.StageDisplayState;
flash.display.StageDisplayState.FULL_SCREEN = ["FULL_SCREEN",1];
flash.display.StageDisplayState.FULL_SCREEN.toString = $estr;
flash.display.StageDisplayState.FULL_SCREEN.__enum__ = flash.display.StageDisplayState;
flash.display.StageDisplayState.FULL_SCREEN_INTERACTIVE = ["FULL_SCREEN_INTERACTIVE",2];
flash.display.StageDisplayState.FULL_SCREEN_INTERACTIVE.toString = $estr;
flash.display.StageDisplayState.FULL_SCREEN_INTERACTIVE.__enum__ = flash.display.StageDisplayState;
flash.display.StageQuality = function() { }
$hxClasses["flash.display.StageQuality"] = flash.display.StageQuality;
flash.display.StageQuality.__name__ = ["flash","display","StageQuality"];
flash.display.StageScaleMode = $hxClasses["flash.display.StageScaleMode"] = { __ename__ : true, __constructs__ : ["SHOW_ALL","NO_SCALE","NO_BORDER","EXACT_FIT"] }
flash.display.StageScaleMode.SHOW_ALL = ["SHOW_ALL",0];
flash.display.StageScaleMode.SHOW_ALL.toString = $estr;
flash.display.StageScaleMode.SHOW_ALL.__enum__ = flash.display.StageScaleMode;
flash.display.StageScaleMode.NO_SCALE = ["NO_SCALE",1];
flash.display.StageScaleMode.NO_SCALE.toString = $estr;
flash.display.StageScaleMode.NO_SCALE.__enum__ = flash.display.StageScaleMode;
flash.display.StageScaleMode.NO_BORDER = ["NO_BORDER",2];
flash.display.StageScaleMode.NO_BORDER.toString = $estr;
flash.display.StageScaleMode.NO_BORDER.__enum__ = flash.display.StageScaleMode;
flash.display.StageScaleMode.EXACT_FIT = ["EXACT_FIT",3];
flash.display.StageScaleMode.EXACT_FIT.toString = $estr;
flash.display.StageScaleMode.EXACT_FIT.__enum__ = flash.display.StageScaleMode;
flash.errors = {}
flash.errors.Error = function(message,id) {
	if(id == null) id = 0;
	if(message == null) message = "";
	this.message = message;
	this.errorID = id;
};
$hxClasses["flash.errors.Error"] = flash.errors.Error;
flash.errors.Error.__name__ = ["flash","errors","Error"];
flash.errors.Error.prototype = {
	toString: function() {
		if(this.message != null) return this.message; else return "Error";
	}
	,getStackTrace: function() {
		return haxe.CallStack.toString(haxe.CallStack.exceptionStack());
	}
	,__class__: flash.errors.Error
}
flash.errors.IOError = function(message) {
	if(message == null) message = "";
	flash.errors.Error.call(this,message);
};
$hxClasses["flash.errors.IOError"] = flash.errors.IOError;
flash.errors.IOError.__name__ = ["flash","errors","IOError"];
flash.errors.IOError.__super__ = flash.errors.Error;
flash.errors.IOError.prototype = $extend(flash.errors.Error.prototype,{
	__class__: flash.errors.IOError
});
flash.events.TextEvent = function(type,bubbles,cancelable,text) {
	if(text == null) text = "";
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.text = text;
};
$hxClasses["flash.events.TextEvent"] = flash.events.TextEvent;
flash.events.TextEvent.__name__ = ["flash","events","TextEvent"];
flash.events.TextEvent.__super__ = flash.events.Event;
flash.events.TextEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.TextEvent
});
flash.events.ErrorEvent = function(type,bubbles,cancelable,text,id) {
	if(id == null) id = 0;
	flash.events.TextEvent.call(this,type,bubbles,cancelable);
	this.text = text;
	this.errorID = id;
};
$hxClasses["flash.events.ErrorEvent"] = flash.events.ErrorEvent;
flash.events.ErrorEvent.__name__ = ["flash","events","ErrorEvent"];
flash.events.ErrorEvent.__super__ = flash.events.TextEvent;
flash.events.ErrorEvent.prototype = $extend(flash.events.TextEvent.prototype,{
	__class__: flash.events.ErrorEvent
});
flash.events.Listener = function(inListener,inUseCapture,inPriority) {
	this.mListner = inListener;
	this.mUseCapture = inUseCapture;
	this.mPriority = inPriority;
	this.mID = flash.events.Listener.sIDs++;
};
$hxClasses["flash.events.Listener"] = flash.events.Listener;
flash.events.Listener.__name__ = ["flash","events","Listener"];
flash.events.Listener.prototype = {
	Is: function(inListener,inCapture) {
		return Reflect.compareMethods(this.mListner,inListener) && this.mUseCapture == inCapture;
	}
	,dispatchEvent: function(event) {
		this.mListner(event);
	}
	,__class__: flash.events.Listener
}
flash.events.EventPhase = function() { }
$hxClasses["flash.events.EventPhase"] = flash.events.EventPhase;
flash.events.EventPhase.__name__ = ["flash","events","EventPhase"];
flash.events.FocusEvent = function(type,bubbles,cancelable,inObject,inShiftKey,inKeyCode) {
	if(inKeyCode == null) inKeyCode = 0;
	if(inShiftKey == null) inShiftKey = false;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.keyCode = inKeyCode;
	this.shiftKey = inShiftKey == null?false:inShiftKey;
	this.target = inObject;
};
$hxClasses["flash.events.FocusEvent"] = flash.events.FocusEvent;
flash.events.FocusEvent.__name__ = ["flash","events","FocusEvent"];
flash.events.FocusEvent.__super__ = flash.events.Event;
flash.events.FocusEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.FocusEvent
});
flash.events.HTTPStatusEvent = function(type,bubbles,cancelable,status) {
	if(status == null) status = 0;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	this.status = status;
	flash.events.Event.call(this,type,bubbles,cancelable);
};
$hxClasses["flash.events.HTTPStatusEvent"] = flash.events.HTTPStatusEvent;
flash.events.HTTPStatusEvent.__name__ = ["flash","events","HTTPStatusEvent"];
flash.events.HTTPStatusEvent.__super__ = flash.events.Event;
flash.events.HTTPStatusEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.HTTPStatusEvent
});
flash.events.IOErrorEvent = function(type,bubbles,cancelable,inText) {
	if(inText == null) inText = "";
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.text = inText;
};
$hxClasses["flash.events.IOErrorEvent"] = flash.events.IOErrorEvent;
flash.events.IOErrorEvent.__name__ = ["flash","events","IOErrorEvent"];
flash.events.IOErrorEvent.__super__ = flash.events.Event;
flash.events.IOErrorEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.IOErrorEvent
});
flash.events.KeyboardEvent = function(type,bubbles,cancelable,inCharCode,inKeyCode,inKeyLocation,inCtrlKey,inAltKey,inShiftKey,controlKeyValue,commandKeyValue) {
	if(commandKeyValue == null) commandKeyValue = false;
	if(controlKeyValue == null) controlKeyValue = false;
	if(inShiftKey == null) inShiftKey = false;
	if(inAltKey == null) inAltKey = false;
	if(inCtrlKey == null) inCtrlKey = false;
	if(inKeyLocation == null) inKeyLocation = 0;
	if(inKeyCode == null) inKeyCode = 0;
	if(inCharCode == null) inCharCode = 0;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.altKey = inAltKey == null?false:inAltKey;
	this.charCode = inCharCode == null?0:inCharCode;
	this.ctrlKey = inCtrlKey == null?false:inCtrlKey;
	this.commandKey = commandKeyValue;
	this.controlKey = controlKeyValue;
	this.keyCode = inKeyCode;
	this.keyLocation = inKeyLocation == null?0:inKeyLocation;
	this.shiftKey = inShiftKey == null?false:inShiftKey;
};
$hxClasses["flash.events.KeyboardEvent"] = flash.events.KeyboardEvent;
flash.events.KeyboardEvent.__name__ = ["flash","events","KeyboardEvent"];
flash.events.KeyboardEvent.__super__ = flash.events.Event;
flash.events.KeyboardEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.KeyboardEvent
});
flash.events.ProgressEvent = function(type,bubbles,cancelable,bytesLoaded,bytesTotal) {
	if(bytesTotal == null) bytesTotal = 0;
	if(bytesLoaded == null) bytesLoaded = 0;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.bytesLoaded = bytesLoaded;
	this.bytesTotal = bytesTotal;
};
$hxClasses["flash.events.ProgressEvent"] = flash.events.ProgressEvent;
flash.events.ProgressEvent.__name__ = ["flash","events","ProgressEvent"];
flash.events.ProgressEvent.__super__ = flash.events.Event;
flash.events.ProgressEvent.prototype = $extend(flash.events.Event.prototype,{
	__class__: flash.events.ProgressEvent
});
flash.events.SecurityErrorEvent = function(type,bubbles,cancelable,text) {
	if(text == null) text = "";
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.ErrorEvent.call(this,type,bubbles,cancelable);
	this.text = text;
};
$hxClasses["flash.events.SecurityErrorEvent"] = flash.events.SecurityErrorEvent;
flash.events.SecurityErrorEvent.__name__ = ["flash","events","SecurityErrorEvent"];
flash.events.SecurityErrorEvent.__super__ = flash.events.ErrorEvent;
flash.events.SecurityErrorEvent.prototype = $extend(flash.events.ErrorEvent.prototype,{
	__class__: flash.events.SecurityErrorEvent
});
flash.events.TimerEvent = function(type,bubbles,cancelable) {
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = false;
	flash.events.Event.call(this,type,bubbles,cancelable);
};
$hxClasses["flash.events.TimerEvent"] = flash.events.TimerEvent;
flash.events.TimerEvent.__name__ = ["flash","events","TimerEvent"];
flash.events.TimerEvent.__super__ = flash.events.Event;
flash.events.TimerEvent.prototype = $extend(flash.events.Event.prototype,{
	updateAfterEvent: function() {
	}
	,__class__: flash.events.TimerEvent
});
flash.events.TouchEvent = function(type,bubbles,cancelable,localX,localY,relatedObject,ctrlKey,altKey,shiftKey,buttonDown,delta,commandKey,clickCount) {
	if(clickCount == null) clickCount = 0;
	if(commandKey == null) commandKey = false;
	if(delta == null) delta = 0;
	if(buttonDown == null) buttonDown = false;
	if(shiftKey == null) shiftKey = false;
	if(altKey == null) altKey = false;
	if(ctrlKey == null) ctrlKey = false;
	if(localY == null) localY = 0;
	if(localX == null) localX = 0;
	if(cancelable == null) cancelable = false;
	if(bubbles == null) bubbles = true;
	flash.events.Event.call(this,type,bubbles,cancelable);
	this.shiftKey = shiftKey;
	this.altKey = altKey;
	this.ctrlKey = ctrlKey;
	this.bubbles = bubbles;
	this.relatedObject = relatedObject;
	this.delta = delta;
	this.localX = localX;
	this.localY = localY;
	this.buttonDown = buttonDown;
	this.commandKey = commandKey;
	this.touchPointID = 0;
	this.isPrimaryTouchPoint = true;
};
$hxClasses["flash.events.TouchEvent"] = flash.events.TouchEvent;
flash.events.TouchEvent.__name__ = ["flash","events","TouchEvent"];
flash.events.TouchEvent.__create = function(type,event,touch,local,target) {
	var evt = new flash.events.TouchEvent(type,true,false,local.x,local.y,null,event.ctrlKey,event.altKey,event.shiftKey,false,0,null,0);
	evt.stageX = flash.Lib.get_current().get_stage().get_mouseX();
	evt.stageY = flash.Lib.get_current().get_stage().get_mouseY();
	evt.target = target;
	return evt;
}
flash.events.TouchEvent.__super__ = flash.events.Event;
flash.events.TouchEvent.prototype = $extend(flash.events.Event.prototype,{
	__createSimilar: function(type,related,targ) {
		var result = new flash.events.TouchEvent(type,this.bubbles,this.cancelable,this.localX,this.localY,related == null?this.relatedObject:related,this.ctrlKey,this.altKey,this.shiftKey,this.buttonDown,this.delta,this.commandKey);
		result.touchPointID = this.touchPointID;
		result.isPrimaryTouchPoint = this.isPrimaryTouchPoint;
		if(targ != null) result.target = targ;
		return result;
	}
	,__class__: flash.events.TouchEvent
});
flash.filters = {}
flash.filters.BitmapFilter = function(inType) {
	this._mType = inType;
};
$hxClasses["flash.filters.BitmapFilter"] = flash.filters.BitmapFilter;
flash.filters.BitmapFilter.__name__ = ["flash","filters","BitmapFilter"];
flash.filters.BitmapFilter.prototype = {
	__applyFilter: function(surface,rect,refreshCache) {
		if(refreshCache == null) refreshCache = false;
	}
	,__preFilter: function(surface) {
	}
	,clone: function() {
		return new flash.filters.BitmapFilter(this._mType);
	}
	,__class__: flash.filters.BitmapFilter
}
flash.filters.DropShadowFilter = function(in_distance,in_angle,in_color,in_alpha,in_blurX,in_blurY,in_strength,in_quality,in_inner,in_knockout,in_hideObject) {
	if(in_hideObject == null) in_hideObject = false;
	if(in_knockout == null) in_knockout = false;
	if(in_inner == null) in_inner = false;
	if(in_quality == null) in_quality = 1;
	if(in_strength == null) in_strength = 1.0;
	if(in_blurY == null) in_blurY = 4.0;
	if(in_blurX == null) in_blurX = 4.0;
	if(in_alpha == null) in_alpha = 1.0;
	if(in_color == null) in_color = 0;
	if(in_angle == null) in_angle = 45.0;
	if(in_distance == null) in_distance = 4.0;
	flash.filters.BitmapFilter.call(this,"DropShadowFilter");
	this.distance = in_distance;
	this.angle = in_angle;
	this.color = in_color;
	this.alpha = in_alpha;
	this.blurX = in_blurX;
	this.blurY = in_blurX;
	this.strength = in_strength;
	this.quality = in_quality;
	this.inner = in_inner;
	this.knockout = in_knockout;
	this.hideObject = in_hideObject;
	this.___cached = false;
};
$hxClasses["flash.filters.DropShadowFilter"] = flash.filters.DropShadowFilter;
flash.filters.DropShadowFilter.__name__ = ["flash","filters","DropShadowFilter"];
flash.filters.DropShadowFilter.__super__ = flash.filters.BitmapFilter;
flash.filters.DropShadowFilter.prototype = $extend(flash.filters.BitmapFilter.prototype,{
	__applyFilter: function(surface,rect,refreshCache) {
		if(refreshCache == null) refreshCache = false;
		if(!this.___cached || refreshCache) {
			var distanceX = this.distance * Math.sin(2 * Math.PI * this.angle / 360.0);
			var distanceY = this.distance * Math.cos(2 * Math.PI * this.angle / 360.0);
			var blurRadius = Math.max(this.blurX,this.blurY);
			var context = surface.getContext("2d");
			context.shadowOffsetX = distanceX;
			context.shadowOffsetY = distanceY;
			context.shadowBlur = blurRadius;
			context.shadowColor = "rgba(" + (this.color >> 16 & 255) + "," + (this.color >> 8 & 255) + "," + (this.color & 255) + "," + this.alpha + ")";
			this.___cached = true;
		}
	}
	,clone: function() {
		return new flash.filters.DropShadowFilter(this.distance,this.angle,this.color,this.alpha,this.blurX,this.blurY,this.strength,this.quality,this.inner,this.knockout,this.hideObject);
	}
	,__class__: flash.filters.DropShadowFilter
});
flash.geom = {}
flash.geom.ColorTransform = function(inRedMultiplier,inGreenMultiplier,inBlueMultiplier,inAlphaMultiplier,inRedOffset,inGreenOffset,inBlueOffset,inAlphaOffset) {
	if(inAlphaOffset == null) inAlphaOffset = 0;
	if(inBlueOffset == null) inBlueOffset = 0;
	if(inGreenOffset == null) inGreenOffset = 0;
	if(inRedOffset == null) inRedOffset = 0;
	if(inAlphaMultiplier == null) inAlphaMultiplier = 1;
	if(inBlueMultiplier == null) inBlueMultiplier = 1;
	if(inGreenMultiplier == null) inGreenMultiplier = 1;
	if(inRedMultiplier == null) inRedMultiplier = 1;
	this.redMultiplier = inRedMultiplier == null?1.0:inRedMultiplier;
	this.greenMultiplier = inGreenMultiplier == null?1.0:inGreenMultiplier;
	this.blueMultiplier = inBlueMultiplier == null?1.0:inBlueMultiplier;
	this.alphaMultiplier = inAlphaMultiplier == null?1.0:inAlphaMultiplier;
	this.redOffset = inRedOffset == null?0.0:inRedOffset;
	this.greenOffset = inGreenOffset == null?0.0:inGreenOffset;
	this.blueOffset = inBlueOffset == null?0.0:inBlueOffset;
	this.alphaOffset = inAlphaOffset == null?0.0:inAlphaOffset;
};
$hxClasses["flash.geom.ColorTransform"] = flash.geom.ColorTransform;
flash.geom.ColorTransform.__name__ = ["flash","geom","ColorTransform"];
flash.geom.ColorTransform.prototype = {
	set_color: function(value) {
		this.redOffset = value >> 16 & 255;
		this.greenOffset = value >> 8 & 255;
		this.blueOffset = value & 255;
		this.redMultiplier = 0;
		this.greenMultiplier = 0;
		this.blueMultiplier = 0;
		return this.get_color();
	}
	,get_color: function() {
		return (this.redOffset | 0) << 16 | (this.greenOffset | 0) << 8 | (this.blueOffset | 0);
	}
	,concat: function(second) {
		this.redMultiplier += second.redMultiplier;
		this.greenMultiplier += second.greenMultiplier;
		this.blueMultiplier += second.blueMultiplier;
		this.alphaMultiplier += second.alphaMultiplier;
	}
	,__class__: flash.geom.ColorTransform
	,__properties__: {set_color:"set_color",get_color:"get_color"}
}
flash.geom.Matrix = function(in_a,in_b,in_c,in_d,in_tx,in_ty) {
	if(in_ty == null) in_ty = 0;
	if(in_tx == null) in_tx = 0;
	if(in_d == null) in_d = 1;
	if(in_c == null) in_c = 0;
	if(in_b == null) in_b = 0;
	if(in_a == null) in_a = 1;
	this.a = in_a;
	this.b = in_b;
	this.c = in_c;
	this.d = in_d;
	this.set_tx(in_tx);
	this.set_ty(in_ty);
	this._sx = 1.0;
	this._sy = 1.0;
};
$hxClasses["flash.geom.Matrix"] = flash.geom.Matrix;
flash.geom.Matrix.__name__ = ["flash","geom","Matrix"];
flash.geom.Matrix.prototype = {
	set_ty: function(inValue) {
		this.ty = inValue;
		return this.ty;
	}
	,set_tx: function(inValue) {
		this.tx = inValue;
		return this.tx;
	}
	,__translateTransformed: function(inPos) {
		this.set_tx(inPos.x * this.a + inPos.y * this.c + this.tx);
		this.set_ty(inPos.x * this.b + inPos.y * this.d + this.ty);
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,__transformY: function(inPos) {
		return inPos.x * this.b + inPos.y * this.d + this.ty;
	}
	,__transformX: function(inPos) {
		return inPos.x * this.a + inPos.y * this.c + this.tx;
	}
	,translate: function(inDX,inDY) {
		var m = new flash.geom.Matrix();
		m.set_tx(inDX);
		m.set_ty(inDY);
		this.concat(m);
	}
	,transformPoint: function(inPos) {
		return new flash.geom.Point(inPos.x * this.a + inPos.y * this.c + this.tx,inPos.x * this.b + inPos.y * this.d + this.ty);
	}
	,toString: function() {
		return "matrix(" + this.a + ", " + this.b + ", " + this.c + ", " + this.d + ", " + this.tx + ", " + this.ty + ")";
	}
	,toMozString: function() {
		return "matrix(" + this.a + ", " + this.b + ", " + this.c + ", " + this.d + ", " + this.tx + "px, " + this.ty + "px)";
	}
	,to3DString: function() {
		return "matrix3d(" + this.a + ", " + this.b + ", " + "0, 0, " + this.c + ", " + this.d + ", " + "0, 0, 0, 0, 1, 0, " + this.tx + ", " + this.ty + ", " + "0, 1" + ")";
	}
	,setRotation: function(inTheta,inScale) {
		if(inScale == null) inScale = 1;
		var scale = inScale;
		this.a = Math.cos(inTheta) * scale;
		this.c = Math.sin(inTheta) * scale;
		this.b = -this.c;
		this.d = this.a;
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,scale: function(inSX,inSY) {
		this._sx = inSX;
		this._sy = inSY;
		this.a *= inSX;
		this.b *= inSY;
		this.c *= inSX;
		this.d *= inSY;
		var _g = this;
		_g.set_tx(_g.tx * inSX);
		var _g = this;
		_g.set_ty(_g.ty * inSY);
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,rotate: function(inTheta) {
		var cos = Math.cos(inTheta);
		var sin = Math.sin(inTheta);
		var a1 = this.a * cos - this.b * sin;
		this.b = this.a * sin + this.b * cos;
		this.a = a1;
		var c1 = this.c * cos - this.d * sin;
		this.d = this.c * sin + this.d * cos;
		this.c = c1;
		var tx1 = this.tx * cos - this.ty * sin;
		this.set_ty(this.tx * sin + this.ty * cos);
		this.set_tx(tx1);
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,mult: function(m) {
		var result = this.clone();
		result.concat(m);
		return result;
	}
	,invert: function() {
		var norm = this.a * this.d - this.b * this.c;
		if(norm == 0) {
			this.a = this.b = this.c = this.d = 0;
			this.set_tx(-this.tx);
			this.set_ty(-this.ty);
		} else {
			norm = 1.0 / norm;
			var a1 = this.d * norm;
			this.d = this.a * norm;
			this.a = a1;
			this.b *= -norm;
			this.c *= -norm;
			var tx1 = -this.a * this.tx - this.c * this.ty;
			this.set_ty(-this.b * this.tx - this.d * this.ty);
			this.set_tx(tx1);
		}
		this._sx /= this._sx;
		this._sy /= this._sy;
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
		return this;
	}
	,identity: function() {
		this.a = 1;
		this.b = 0;
		this.c = 0;
		this.d = 1;
		this.set_tx(0);
		this.set_ty(0);
		this._sx = 1.0;
		this._sy = 1.0;
	}
	,createGradientBox: function(in_width,in_height,rotation,in_tx,in_ty) {
		if(in_ty == null) in_ty = 0;
		if(in_tx == null) in_tx = 0;
		if(rotation == null) rotation = 0;
		this.a = in_width / 1638.4;
		this.d = in_height / 1638.4;
		if(rotation != null && rotation != 0.0) {
			var cos = Math.cos(rotation);
			var sin = Math.sin(rotation);
			this.b = sin * this.d;
			this.c = -sin * this.a;
			this.a *= cos;
			this.d *= cos;
		} else {
			this.b = 0;
			this.c = 0;
		}
		this.set_tx(in_tx != null?in_tx + in_width / 2:in_width / 2);
		this.set_ty(in_ty != null?in_ty + in_height / 2:in_height / 2);
	}
	,copy: function(m) {
		this.a = m.a;
		this.b = m.b;
		this.c = m.c;
		this.d = m.d;
		this.set_tx(m.tx);
		this.set_ty(m.ty);
		this._sx = m._sx;
		this._sy = m._sy;
	}
	,concat: function(m) {
		var a1 = this.a * m.a + this.b * m.c;
		this.b = this.a * m.b + this.b * m.d;
		this.a = a1;
		var c1 = this.c * m.a + this.d * m.c;
		this.d = this.c * m.b + this.d * m.d;
		this.c = c1;
		var tx1 = this.tx * m.a + this.ty * m.c + m.tx;
		this.set_ty(this.tx * m.b + this.ty * m.d + m.ty);
		this.set_tx(tx1);
		this._sx *= m._sx;
		this._sy *= m._sy;
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,clone: function() {
		var m = new flash.geom.Matrix(this.a,this.b,this.c,this.d,this.tx,this.ty);
		m._sx = this._sx;
		m._sy = this._sy;
		return m;
	}
	,cleanValues: function() {
		this.a = Math.round(this.a * 1000) / 1000;
		this.b = Math.round(this.b * 1000) / 1000;
		this.c = Math.round(this.c * 1000) / 1000;
		this.d = Math.round(this.d * 1000) / 1000;
		this.set_tx(Math.round(this.tx * 10) / 10);
		this.set_ty(Math.round(this.ty * 10) / 10);
	}
	,__class__: flash.geom.Matrix
	,__properties__: {set_tx:"set_tx",set_ty:"set_ty"}
}
flash.geom.Point = function(inX,inY) {
	if(inY == null) inY = 0;
	if(inX == null) inX = 0;
	this.x = inX;
	this.y = inY;
};
$hxClasses["flash.geom.Point"] = flash.geom.Point;
flash.geom.Point.__name__ = ["flash","geom","Point"];
flash.geom.Point.distance = function(pt1,pt2) {
	var dx = pt1.x - pt2.x;
	var dy = pt1.y - pt2.y;
	return Math.sqrt(dx * dx + dy * dy);
}
flash.geom.Point.interpolate = function(pt1,pt2,f) {
	return new flash.geom.Point(pt2.x + f * (pt1.x - pt2.x),pt2.y + f * (pt1.y - pt2.y));
}
flash.geom.Point.polar = function(len,angle) {
	return new flash.geom.Point(len * Math.cos(angle),len * Math.sin(angle));
}
flash.geom.Point.prototype = {
	get_length: function() {
		return Math.sqrt(this.x * this.x + this.y * this.y);
	}
	,subtract: function(v) {
		return new flash.geom.Point(this.x - v.x,this.y - v.y);
	}
	,setTo: function(xa,ya) {
		this.x = xa;
		this.y = ya;
	}
	,offset: function(dx,dy) {
		this.x += dx;
		this.y += dy;
	}
	,normalize: function(thickness) {
		if(this.x == 0 && this.y == 0) return; else {
			var norm = thickness / Math.sqrt(this.x * this.x + this.y * this.y);
			this.x *= norm;
			this.y *= norm;
		}
	}
	,equals: function(toCompare) {
		return toCompare.x == this.x && toCompare.y == this.y;
	}
	,clone: function() {
		return new flash.geom.Point(this.x,this.y);
	}
	,add: function(v) {
		return new flash.geom.Point(v.x + this.x,v.y + this.y);
	}
	,__class__: flash.geom.Point
	,__properties__: {get_length:"get_length"}
}
flash.geom.Rectangle = function(inX,inY,inWidth,inHeight) {
	if(inHeight == null) inHeight = 0;
	if(inWidth == null) inWidth = 0;
	if(inY == null) inY = 0;
	if(inX == null) inX = 0;
	this.x = inX;
	this.y = inY;
	this.width = inWidth;
	this.height = inHeight;
};
$hxClasses["flash.geom.Rectangle"] = flash.geom.Rectangle;
flash.geom.Rectangle.__name__ = ["flash","geom","Rectangle"];
flash.geom.Rectangle.prototype = {
	set_topLeft: function(p) {
		this.x = p.x;
		this.y = p.y;
		return p.clone();
	}
	,get_topLeft: function() {
		return new flash.geom.Point(this.x,this.y);
	}
	,set_top: function(t) {
		this.height -= t - this.y;
		this.y = t;
		return t;
	}
	,get_top: function() {
		return this.y;
	}
	,set_size: function(p) {
		this.width = p.x;
		this.height = p.y;
		return p.clone();
	}
	,get_size: function() {
		return new flash.geom.Point(this.width,this.height);
	}
	,set_right: function(r) {
		this.width = r - this.x;
		return r;
	}
	,get_right: function() {
		return this.x + this.width;
	}
	,set_left: function(l) {
		this.width -= l - this.x;
		this.x = l;
		return l;
	}
	,get_left: function() {
		return this.x;
	}
	,set_bottomRight: function(p) {
		this.width = p.x - this.x;
		this.height = p.y - this.y;
		return p.clone();
	}
	,get_bottomRight: function() {
		return new flash.geom.Point(this.x + this.width,this.y + this.height);
	}
	,set_bottom: function(b) {
		this.height = b - this.y;
		return b;
	}
	,get_bottom: function() {
		return this.y + this.height;
	}
	,union: function(toUnion) {
		var x0 = this.x > toUnion.x?toUnion.x:this.x;
		var x1 = this.get_right() < toUnion.get_right()?toUnion.get_right():this.get_right();
		var y0 = this.y > toUnion.y?toUnion.y:this.y;
		var y1 = this.get_bottom() < toUnion.get_bottom()?toUnion.get_bottom():this.get_bottom();
		return new flash.geom.Rectangle(x0,y0,x1 - x0,y1 - y0);
	}
	,transform: function(m) {
		var tx0 = m.a * this.x + m.c * this.y;
		var tx1 = tx0;
		var ty0 = m.b * this.x + m.d * this.y;
		var ty1 = tx0;
		var tx = m.a * (this.x + this.width) + m.c * this.y;
		var ty = m.b * (this.x + this.width) + m.d * this.y;
		if(tx < tx0) tx0 = tx;
		if(ty < ty0) ty0 = ty;
		if(tx > tx1) tx1 = tx;
		if(ty > ty1) ty1 = ty;
		tx = m.a * (this.x + this.width) + m.c * (this.y + this.height);
		ty = m.b * (this.x + this.width) + m.d * (this.y + this.height);
		if(tx < tx0) tx0 = tx;
		if(ty < ty0) ty0 = ty;
		if(tx > tx1) tx1 = tx;
		if(ty > ty1) ty1 = ty;
		tx = m.a * this.x + m.c * (this.y + this.height);
		ty = m.b * this.x + m.d * (this.y + this.height);
		if(tx < tx0) tx0 = tx;
		if(ty < ty0) ty0 = ty;
		if(tx > tx1) tx1 = tx;
		if(ty > ty1) ty1 = ty;
		return new flash.geom.Rectangle(tx0 + m.tx,ty0 + m.ty,tx1 - tx0,ty1 - ty0);
	}
	,setEmpty: function() {
		this.x = this.y = this.width = this.height = 0;
	}
	,offsetPoint: function(point) {
		this.x += point.x;
		this.y += point.y;
	}
	,offset: function(dx,dy) {
		this.x += dx;
		this.y += dy;
	}
	,isEmpty: function() {
		return this.width <= 0 || this.height <= 0;
	}
	,intersects: function(toIntersect) {
		var x0 = this.x < toIntersect.x?toIntersect.x:this.x;
		var x1 = this.get_right() > toIntersect.get_right()?toIntersect.get_right():this.get_right();
		if(x1 <= x0) return false;
		var y0 = this.y < toIntersect.y?toIntersect.y:this.y;
		var y1 = this.get_bottom() > toIntersect.get_bottom()?toIntersect.get_bottom():this.get_bottom();
		return y1 > y0;
	}
	,intersection: function(toIntersect) {
		var x0 = this.x < toIntersect.x?toIntersect.x:this.x;
		var x1 = this.get_right() > toIntersect.get_right()?toIntersect.get_right():this.get_right();
		if(x1 <= x0) return new flash.geom.Rectangle();
		var y0 = this.y < toIntersect.y?toIntersect.y:this.y;
		var y1 = this.get_bottom() > toIntersect.get_bottom()?toIntersect.get_bottom():this.get_bottom();
		if(y1 <= y0) return new flash.geom.Rectangle();
		return new flash.geom.Rectangle(x0,y0,x1 - x0,y1 - y0);
	}
	,inflatePoint: function(point) {
		this.inflate(point.x,point.y);
	}
	,inflate: function(dx,dy) {
		this.x -= dx;
		this.width += dx * 2;
		this.y -= dy;
		this.height += dy * 2;
	}
	,extendBounds: function(r) {
		var dx = this.x - r.x;
		if(dx > 0) {
			this.x -= dx;
			this.width += dx;
		}
		var dy = this.y - r.y;
		if(dy > 0) {
			this.y -= dy;
			this.height += dy;
		}
		if(r.get_right() > this.get_right()) this.set_right(r.get_right());
		if(r.get_bottom() > this.get_bottom()) this.set_bottom(r.get_bottom());
	}
	,equals: function(toCompare) {
		return this.x == toCompare.x && this.y == toCompare.y && this.width == toCompare.width && this.height == toCompare.height;
	}
	,containsRect: function(rect) {
		if(rect.width <= 0 || rect.height <= 0) return rect.x > this.x && rect.y > this.y && rect.get_right() < this.get_right() && rect.get_bottom() < this.get_bottom(); else return rect.x >= this.x && rect.y >= this.y && rect.get_right() <= this.get_right() && rect.get_bottom() <= this.get_bottom();
	}
	,containsPoint: function(point) {
		return this.contains(point.x,point.y);
	}
	,contains: function(inX,inY) {
		return inX >= this.x && inY >= this.y && inX < this.get_right() && inY < this.get_bottom();
	}
	,clone: function() {
		return new flash.geom.Rectangle(this.x,this.y,this.width,this.height);
	}
	,__class__: flash.geom.Rectangle
	,__properties__: {set_bottom:"set_bottom",get_bottom:"get_bottom",set_bottomRight:"set_bottomRight",get_bottomRight:"get_bottomRight",set_left:"set_left",get_left:"get_left",set_right:"set_right",get_right:"get_right",set_size:"set_size",get_size:"get_size",set_top:"set_top",get_top:"get_top",set_topLeft:"set_topLeft",get_topLeft:"get_topLeft"}
}
flash.geom.Transform = function(displayObject) {
	if(displayObject == null) throw "Cannot create Transform with no DisplayObject.";
	this._displayObject = displayObject;
	this._matrix = new flash.geom.Matrix();
	this._fullMatrix = new flash.geom.Matrix();
	this.set_colorTransform(new flash.geom.ColorTransform());
};
$hxClasses["flash.geom.Transform"] = flash.geom.Transform;
flash.geom.Transform.__name__ = ["flash","geom","Transform"];
flash.geom.Transform.prototype = {
	get_pixelBounds: function() {
		return this._displayObject.getBounds(null);
	}
	,set_matrix: function(inValue) {
		this._matrix.copy(inValue);
		this._displayObject.__matrixOverridden();
		return this._matrix;
	}
	,get_matrix: function() {
		return this._matrix.clone();
	}
	,get_concatenatedMatrix: function() {
		return this.__getFullMatrix(this._matrix);
	}
	,set_colorTransform: function(inValue) {
		this.colorTransform = inValue;
		return inValue;
	}
	,__setMatrix: function(inValue) {
		this._matrix.copy(inValue);
	}
	,__setFullMatrix: function(inValue) {
		this._fullMatrix.copy(inValue);
		return this._fullMatrix;
	}
	,__getFullMatrix: function(localMatrix) {
		var m;
		if(localMatrix != null) m = localMatrix.mult(this._fullMatrix); else m = this._fullMatrix.clone();
		return m;
	}
	,__class__: flash.geom.Transform
	,__properties__: {set_colorTransform:"set_colorTransform",get_concatenatedMatrix:"get_concatenatedMatrix",set_matrix:"set_matrix",get_matrix:"get_matrix",get_pixelBounds:"get_pixelBounds"}
}
flash.media = {}
flash.media.Sound = function(stream,context) {
	flash.events.EventDispatcher.call(this,this);
	this.bytesLoaded = 0;
	this.bytesTotal = 0;
	this.id3 = null;
	this.isBuffering = false;
	this.length = 0;
	this.url = null;
	this.__soundChannels = new haxe.ds.IntMap();
	this.__soundIdx = 0;
	if(stream != null) this.load(stream,context);
};
$hxClasses["flash.media.Sound"] = flash.media.Sound;
flash.media.Sound.__name__ = ["flash","media","Sound"];
flash.media.Sound.__canPlayMime = function(mime) {
	var audio = js.Browser.document.createElement("audio");
	var playable = function(ok) {
		if(ok != "" && ok != "no") return true; else return false;
	};
	return playable(audio.canPlayType(mime,null));
}
flash.media.Sound.__canPlayType = function(extension) {
	var mime = flash.media.Sound.__mimeForExtension(extension);
	if(mime == null) return false;
	return flash.media.Sound.__canPlayMime(mime);
}
flash.media.Sound.__mimeForExtension = function(extension) {
	var mime = null;
	switch(extension) {
	case "mp3":
		mime = "audio/mpeg";
		break;
	case "ogg":
		mime = "audio/ogg; codecs=\"vorbis\"";
		break;
	case "wav":
		mime = "audio/wav; codecs=\"1\"";
		break;
	case "aac":
		mime = "audio/mp4; codecs=\"mp4a.40.2\"";
		break;
	default:
		mime = null;
	}
	return mime;
}
flash.media.Sound.__super__ = flash.events.EventDispatcher;
flash.media.Sound.prototype = $extend(flash.events.EventDispatcher.prototype,{
	__onSoundLoaded: function(evt) {
		this.__removeEventListeners();
		var evt1 = new flash.events.Event(flash.events.Event.COMPLETE);
		this.dispatchEvent(evt1);
	}
	,__onSoundLoadError: function(evt) {
		this.__removeEventListeners();
		var evt1 = new flash.events.IOErrorEvent(flash.events.IOErrorEvent.IO_ERROR);
		this.dispatchEvent(evt1);
	}
	,__removeEventListeners: function() {
		this.__soundCache.removeEventListener(flash.events.Event.COMPLETE,$bind(this,this.__onSoundLoaded),false);
		this.__soundCache.removeEventListener(flash.events.IOErrorEvent.IO_ERROR,$bind(this,this.__onSoundLoadError),false);
	}
	,__load: function(stream,context,mime) {
		if(mime == null) mime = "";
		this.__streamUrl = stream.url;
		try {
			this.__soundCache = new flash.net.URLLoader();
			this.__addEventListeners();
			this.__soundCache.load(stream);
		} catch( e ) {
		}
	}
	,__addEventListeners: function() {
		this.__soundCache.addEventListener(flash.events.Event.COMPLETE,$bind(this,this.__onSoundLoaded));
		this.__soundCache.addEventListener(flash.events.IOErrorEvent.IO_ERROR,$bind(this,this.__onSoundLoadError));
	}
	,play: function(startTime,loops,sndTransform) {
		if(loops == null) loops = 0;
		if(startTime == null) startTime = 0.0;
		if(this.__streamUrl == null) return null;
		var self = this;
		var curIdx = this.__soundIdx;
		var removeRef = function() {
			self.__soundChannels.remove(curIdx);
		};
		var channel = flash.media.SoundChannel.__create(this.__streamUrl,startTime,loops,sndTransform,removeRef);
		this.__soundChannels.set(curIdx,channel);
		this.__soundIdx++;
		var audio = channel.__audio;
		return channel;
	}
	,load: function(stream,context) {
		this.__load(stream,context);
	}
	,close: function() {
	}
	,__class__: flash.media.Sound
});
flash.media.SoundChannel = function() {
	flash.events.EventDispatcher.call(this,this);
	this.ChannelId = -1;
	this.leftPeak = 0.;
	this.position = 0.;
	this.rightPeak = 0.;
	this.__audioCurrentLoop = 1;
	this.__audioTotalLoops = 1;
};
$hxClasses["flash.media.SoundChannel"] = flash.media.SoundChannel;
flash.media.SoundChannel.__name__ = ["flash","media","SoundChannel"];
flash.media.SoundChannel.__create = function(src,startTime,loops,sndTransform,removeRef) {
	if(loops == null) loops = 0;
	if(startTime == null) startTime = 0.0;
	var channel = new flash.media.SoundChannel();
	channel.__audio = js.Browser.document.createElement("audio");
	channel.__removeRef = removeRef;
	channel.__audio.addEventListener("ended",$bind(channel,channel.__onSoundChannelFinished),false);
	channel.__audio.addEventListener("seeked",$bind(channel,channel.__onSoundSeeked),false);
	channel.__audio.addEventListener("stalled",$bind(channel,channel.__onStalled),false);
	channel.__audio.addEventListener("progress",$bind(channel,channel.__onProgress),false);
	if(loops > 0) {
		channel.__audioTotalLoops = loops;
		channel.__audio.loop = true;
	}
	channel.__startTime = startTime;
	if(startTime > 0.) {
		var onLoad = null;
		onLoad = function(_) {
			channel.__audio.currentTime = channel.__startTime;
			channel.__audio.play();
			channel.__audio.removeEventListener("canplaythrough",onLoad,false);
		};
		channel.__audio.addEventListener("canplaythrough",onLoad,false);
	} else channel.__audio.autoplay = true;
	channel.__audio.src = src;
	return channel;
}
flash.media.SoundChannel.__super__ = flash.events.EventDispatcher;
flash.media.SoundChannel.prototype = $extend(flash.events.EventDispatcher.prototype,{
	set_soundTransform: function(v) {
		this.__audio.volume = v.volume;
		return this.soundTransform = v;
	}
	,__onStalled: function(evt) {
		if(this.__audio != null) this.__audio.load();
	}
	,__onSoundSeeked: function(evt) {
		if(this.__audioCurrentLoop >= this.__audioTotalLoops) {
			this.__audio.loop = false;
			this.stop();
		} else this.__audioCurrentLoop++;
	}
	,__onSoundChannelFinished: function(evt) {
		if(this.__audioCurrentLoop >= this.__audioTotalLoops) {
			this.__audio.removeEventListener("ended",$bind(this,this.__onSoundChannelFinished),false);
			this.__audio.removeEventListener("seeked",$bind(this,this.__onSoundSeeked),false);
			this.__audio.removeEventListener("stalled",$bind(this,this.__onStalled),false);
			this.__audio.removeEventListener("progress",$bind(this,this.__onProgress),false);
			this.__audio = null;
			var evt1 = new flash.events.Event(flash.events.Event.SOUND_COMPLETE);
			evt1.target = this;
			this.dispatchEvent(evt1);
			if(this.__removeRef != null) this.__removeRef();
		} else {
			this.__audio.currentTime = this.__startTime;
			this.__audio.play();
		}
	}
	,__onProgress: function(evt) {
	}
	,stop: function() {
		if(this.__audio != null) {
			this.__audio.pause();
			this.__audio = null;
			if(this.__removeRef != null) this.__removeRef();
		}
	}
	,__class__: flash.media.SoundChannel
	,__properties__: {set_soundTransform:"set_soundTransform"}
});
flash.media.SoundLoaderContext = function(bufferTime,checkPolicyFile) {
	if(checkPolicyFile == null) checkPolicyFile = false;
	if(bufferTime == null) bufferTime = 0;
	this.bufferTime = bufferTime;
	this.checkPolicyFile = checkPolicyFile;
};
$hxClasses["flash.media.SoundLoaderContext"] = flash.media.SoundLoaderContext;
flash.media.SoundLoaderContext.__name__ = ["flash","media","SoundLoaderContext"];
flash.media.SoundLoaderContext.prototype = {
	__class__: flash.media.SoundLoaderContext
}
flash.media.SoundTransform = function(vol,panning) {
	if(panning == null) panning = 0;
	if(vol == null) vol = 1;
	this.volume = vol;
	this.pan = panning;
	this.leftToLeft = 0;
	this.leftToRight = 0;
	this.rightToLeft = 0;
	this.rightToRight = 0;
};
$hxClasses["flash.media.SoundTransform"] = flash.media.SoundTransform;
flash.media.SoundTransform.__name__ = ["flash","media","SoundTransform"];
flash.media.SoundTransform.prototype = {
	__class__: flash.media.SoundTransform
}
flash.net = {}
flash.net.URLLoader = function(request) {
	flash.events.EventDispatcher.call(this);
	this.bytesLoaded = 0;
	this.bytesTotal = 0;
	this.set_dataFormat(flash.net.URLLoaderDataFormat.TEXT);
	if(request != null) this.load(request);
};
$hxClasses["flash.net.URLLoader"] = flash.net.URLLoader;
flash.net.URLLoader.__name__ = ["flash","net","URLLoader"];
flash.net.URLLoader.__super__ = flash.events.EventDispatcher;
flash.net.URLLoader.prototype = $extend(flash.events.EventDispatcher.prototype,{
	set_dataFormat: function(inputVal) {
		if(inputVal == flash.net.URLLoaderDataFormat.BINARY && !Reflect.hasField(js.Browser.window,"ArrayBuffer")) this.dataFormat = flash.net.URLLoaderDataFormat.TEXT; else this.dataFormat = inputVal;
		return this.dataFormat;
	}
	,onStatus: function(status) {
		var evt = new flash.events.HTTPStatusEvent(flash.events.HTTPStatusEvent.HTTP_STATUS,false,false,status);
		evt.currentTarget = this;
		this.dispatchEvent(evt);
	}
	,onSecurityError: function(msg) {
		var evt = new flash.events.SecurityErrorEvent(flash.events.SecurityErrorEvent.SECURITY_ERROR);
		evt.text = msg;
		evt.currentTarget = this;
		this.dispatchEvent(evt);
	}
	,onProgress: function(event) {
		var evt = new flash.events.ProgressEvent(flash.events.ProgressEvent.PROGRESS);
		evt.currentTarget = this;
		evt.bytesLoaded = event.loaded;
		evt.bytesTotal = event.total;
		this.dispatchEvent(evt);
	}
	,onOpen: function() {
		var evt = new flash.events.Event(flash.events.Event.OPEN);
		evt.currentTarget = this;
		this.dispatchEvent(evt);
	}
	,onError: function(msg) {
		var evt = new flash.events.IOErrorEvent(flash.events.IOErrorEvent.IO_ERROR);
		evt.text = msg;
		evt.currentTarget = this;
		this.dispatchEvent(evt);
	}
	,onData: function(_) {
		var content = this.getData();
		var _g = this;
		switch( (_g.dataFormat)[1] ) {
		case 0:
			this.data = flash.utils.ByteArray.__ofBuffer(content);
			break;
		default:
			this.data = Std.string(content);
		}
		var evt = new flash.events.Event(flash.events.Event.COMPLETE);
		evt.currentTarget = this;
		this.dispatchEvent(evt);
	}
	,requestUrl: function(url,method,data,requestHeaders) {
		var xmlHttpRequest = new XMLHttpRequest();
		this.registerEvents(xmlHttpRequest);
		var uri = "";
		if(js.Boot.__instanceof(data,flash.utils.ByteArray)) {
			var data1 = data;
			var _g = this;
			switch( (_g.dataFormat)[1] ) {
			case 0:
				uri = data1.data.buffer;
				break;
			default:
				uri = data1.readUTFBytes(data1.length);
			}
		} else if(js.Boot.__instanceof(data,flash.net.URLVariables)) {
			var data1 = data;
			var _g = 0, _g1 = Reflect.fields(data1);
			while(_g < _g1.length) {
				var p = _g1[_g];
				++_g;
				if(uri.length != 0) uri += "&";
				uri += StringTools.urlEncode(p) + "=" + StringTools.urlEncode(Reflect.field(data1,p));
			}
		} else if(data != null) uri = data.toString();
		try {
			if(method == "GET" && uri != null && uri != "") {
				var question = url.split("?").length <= 1;
				xmlHttpRequest.open(method,url + (question?"?":"&") + Std.string(uri),true);
				uri = "";
			} else xmlHttpRequest.open(method,url,true);
		} catch( e ) {
			this.onError(e.toString());
			return;
		}
		var _g = this;
		switch( (_g.dataFormat)[1] ) {
		case 0:
			xmlHttpRequest.responseType = "arraybuffer";
			break;
		default:
		}
		var _g1 = 0;
		while(_g1 < requestHeaders.length) {
			var header = requestHeaders[_g1];
			++_g1;
			xmlHttpRequest.setRequestHeader(header.name,header.value);
		}
		xmlHttpRequest.send(uri);
		this.onOpen();
		this.getData = function() {
			if(xmlHttpRequest.response != null) return xmlHttpRequest.response; else return xmlHttpRequest.responseText;
		};
	}
	,registerEvents: function(subject) {
		var self = this;
		if(typeof XMLHttpRequestProgressEvent != "undefined") subject.addEventListener("progress",$bind(this,this.onProgress),false);
		subject.onreadystatechange = function() {
			if(subject.readyState != 4) return;
			var s = (function($this) {
				var $r;
				try {
					$r = subject.status;
				} catch( e ) {
					$r = null;
				}
				return $r;
			}(this));
			if(s == undefined) s = null;
			if(s != null) self.onStatus(s);
			if(s != null && s >= 200 && s < 400) self.onData(subject.response); else if(s == null) self.onError("Failed to connect or resolve host"); else if(s == 12029) self.onError("Failed to connect to host"); else if(s == 12007) self.onError("Unknown host"); else if(s == 0) {
				self.onError("Unable to make request (may be blocked due to cross-domain permissions)");
				self.onSecurityError("Unable to make request (may be blocked due to cross-domain permissions)");
			} else self.onError("Http Error #" + subject.status);
		};
	}
	,load: function(request) {
		this.requestUrl(request.url,request.method,request.data,request.formatRequestHeaders());
	}
	,getData: function() {
		return null;
	}
	,close: function() {
	}
	,__class__: flash.net.URLLoader
	,__properties__: {set_dataFormat:"set_dataFormat"}
});
flash.net.URLLoaderDataFormat = $hxClasses["flash.net.URLLoaderDataFormat"] = { __ename__ : true, __constructs__ : ["BINARY","TEXT","VARIABLES"] }
flash.net.URLLoaderDataFormat.BINARY = ["BINARY",0];
flash.net.URLLoaderDataFormat.BINARY.toString = $estr;
flash.net.URLLoaderDataFormat.BINARY.__enum__ = flash.net.URLLoaderDataFormat;
flash.net.URLLoaderDataFormat.TEXT = ["TEXT",1];
flash.net.URLLoaderDataFormat.TEXT.toString = $estr;
flash.net.URLLoaderDataFormat.TEXT.__enum__ = flash.net.URLLoaderDataFormat;
flash.net.URLLoaderDataFormat.VARIABLES = ["VARIABLES",2];
flash.net.URLLoaderDataFormat.VARIABLES.toString = $estr;
flash.net.URLLoaderDataFormat.VARIABLES.__enum__ = flash.net.URLLoaderDataFormat;
flash.net.URLRequest = function(inURL) {
	if(inURL != null) this.url = inURL;
	this.requestHeaders = [];
	this.method = flash.net.URLRequestMethod.GET;
	this.contentType = null;
};
$hxClasses["flash.net.URLRequest"] = flash.net.URLRequest;
flash.net.URLRequest.__name__ = ["flash","net","URLRequest"];
flash.net.URLRequest.prototype = {
	formatRequestHeaders: function() {
		var res = this.requestHeaders;
		if(res == null) res = [];
		if(this.method == flash.net.URLRequestMethod.GET || this.data == null) return res;
		if(js.Boot.__instanceof(this.data,String) || js.Boot.__instanceof(this.data,flash.utils.ByteArray)) {
			res = res.slice();
			res.push(new flash.net.URLRequestHeader("Content-Type",this.contentType != null?this.contentType:"application/x-www-form-urlencoded"));
		}
		return res;
	}
	,__class__: flash.net.URLRequest
}
flash.net.URLRequestHeader = function(name,value) {
	if(value == null) value = "";
	if(name == null) name = "";
	this.name = name;
	this.value = value;
};
$hxClasses["flash.net.URLRequestHeader"] = flash.net.URLRequestHeader;
flash.net.URLRequestHeader.__name__ = ["flash","net","URLRequestHeader"];
flash.net.URLRequestHeader.prototype = {
	__class__: flash.net.URLRequestHeader
}
flash.net.URLRequestMethod = function() { }
$hxClasses["flash.net.URLRequestMethod"] = flash.net.URLRequestMethod;
flash.net.URLRequestMethod.__name__ = ["flash","net","URLRequestMethod"];
flash.net.URLVariables = function(inEncoded) {
	if(inEncoded != null) this.decode(inEncoded);
};
$hxClasses["flash.net.URLVariables"] = flash.net.URLVariables;
flash.net.URLVariables.__name__ = ["flash","net","URLVariables"];
flash.net.URLVariables.prototype = {
	toString: function() {
		var result = new Array();
		var fields = Reflect.fields(this);
		var _g = 0;
		while(_g < fields.length) {
			var f = fields[_g];
			++_g;
			result.push(StringTools.urlEncode(f) + "=" + StringTools.urlEncode(Reflect.field(this,f)));
		}
		return result.join("&");
	}
	,decode: function(inVars) {
		var fields = Reflect.fields(this);
		var _g = 0;
		while(_g < fields.length) {
			var f = fields[_g];
			++_g;
			Reflect.deleteField(this,f);
		}
		var fields1 = inVars.split(";").join("&").split("&");
		var _g = 0;
		while(_g < fields1.length) {
			var f = fields1[_g];
			++_g;
			var eq = f.indexOf("=");
			if(eq > 0) this[StringTools.urlDecode(HxOverrides.substr(f,0,eq))] = StringTools.urlDecode(HxOverrides.substr(f,eq + 1,null)); else if(eq != 0) this[StringTools.urlDecode(f)] = "";
		}
	}
	,__class__: flash.net.URLVariables
}
flash.system = {}
flash.system.ApplicationDomain = function(parentDomain) {
	if(parentDomain != null) this.parentDomain = parentDomain; else this.parentDomain = flash.system.ApplicationDomain.currentDomain;
};
$hxClasses["flash.system.ApplicationDomain"] = flash.system.ApplicationDomain;
flash.system.ApplicationDomain.__name__ = ["flash","system","ApplicationDomain"];
flash.system.ApplicationDomain.prototype = {
	hasDefinition: function(name) {
		return Type.resolveClass(name) != null;
	}
	,getDefinition: function(name) {
		return Type.resolveClass(name);
	}
	,__class__: flash.system.ApplicationDomain
}
flash.system.LoaderContext = function(checkPolicyFile,applicationDomain,securityDomain) {
	if(checkPolicyFile == null) checkPolicyFile = false;
	this.checkPolicyFile = checkPolicyFile;
	this.securityDomain = securityDomain;
	if(applicationDomain != null) this.applicationDomain = applicationDomain; else this.applicationDomain = flash.system.ApplicationDomain.currentDomain;
};
$hxClasses["flash.system.LoaderContext"] = flash.system.LoaderContext;
flash.system.LoaderContext.__name__ = ["flash","system","LoaderContext"];
flash.system.LoaderContext.prototype = {
	__class__: flash.system.LoaderContext
}
flash.system.SecurityDomain = function() {
};
$hxClasses["flash.system.SecurityDomain"] = flash.system.SecurityDomain;
flash.system.SecurityDomain.__name__ = ["flash","system","SecurityDomain"];
flash.system.SecurityDomain.prototype = {
	__class__: flash.system.SecurityDomain
}
flash.text = {}
flash.text.Font = function() {
	this.__metrics = [];
	this.__fontScale = 9.0;
	var className = Type.getClassName(Type.getClass(this));
	if(flash.text.Font.__fontData == null) {
		flash.text.Font.__fontData = [];
		flash.text.Font.__fontData["Bitstream_Vera_Sans"] = haxe.Unserializer.run(flash.text.Font.DEFAULT_FONT_DATA);
	}
	if(className == "flash.text.Font") this.set_fontName("Bitstream_Vera_Sans"); else this.set_fontName(className.split(".").pop());
};
$hxClasses["flash.text.Font"] = flash.text.Font;
flash.text.Font.__name__ = ["flash","text","Font"];
flash.text.Font.enumerateFonts = function(enumerateDeviceFonts) {
	if(enumerateDeviceFonts == null) enumerateDeviceFonts = false;
	return flash.text.Font.__registeredFonts.slice();
}
flash.text.Font.__ofResource = function(resourceName,fontName) {
	if(fontName == null) fontName = "";
	var data = haxe.Unserializer.run(haxe.Resource.getString(resourceName));
	if(data == null) {
	} else {
		if(fontName == "") {
			flash.text.Font.__fontData[resourceName] = data.hash;
			fontName = data.fontName;
		}
		flash.text.Font.__fontData[data.fontName] = data.hash;
	}
	return fontName;
}
flash.text.Font.registerFont = function(font) {
	var instance = js.Boot.__cast(Type.createInstance(font,[]) , flash.text.Font);
	if(instance != null) {
		if(Reflect.hasField(font,"resourceName")) instance.set_fontName(flash.text.Font.__ofResource(Reflect.field(font,"resourceName")));
		flash.text.Font.__registeredFonts.push(instance);
	}
}
flash.text.Font.prototype = {
	set_fontName: function(name) {
		if(name == "_sans" || name == "_serif" || name == "_typewriter") name = "Bitstream_Vera_Sans";
		this.fontName = name;
		if(flash.text.Font.__fontData[this.fontName] == null) try {
			flash.text.Font.__ofResource(name);
		} catch( e ) {
			this.fontName = "Bitstream_Vera_Sans";
		}
		if(flash.text.Font.__fontData[this.fontName] != null) try {
			this.__glyphData = flash.text.Font.__fontData[this.fontName];
		} catch( e ) {
			this.fontName = "Bitstream_Vera_Sans";
		}
		return name;
	}
	,__setScale: function(scale) {
		this.__fontScale = scale / 1024;
	}
	,__render: function(graphics,inChar,inX,inY,inOutline) {
		var index = 0;
		var glyph = this.__glyphData.get(inChar);
		if(glyph == null) return;
		var commands = glyph.commands;
		var data = glyph.data;
		var _g = 0;
		while(_g < commands.length) {
			var c = commands[_g];
			++_g;
			switch(c) {
			case 1:
				graphics.moveTo(inX + data[index++] * this.__fontScale,inY + data[index++] * this.__fontScale);
				break;
			case 2:
				graphics.lineTo(inX + data[index++] * this.__fontScale,inY + data[index++] * this.__fontScale);
				break;
			case 3:
				graphics.curveTo(inX + data[index++] * this.__fontScale,inY + data[index++] * this.__fontScale,inX + data[index++] * this.__fontScale,inY + data[index++] * this.__fontScale);
				break;
			}
		}
	}
	,__getAdvance: function(inGlyph,height) {
		var m = this.__metrics[inGlyph];
		if(m == null) {
			var glyph = this.__glyphData.get(inGlyph);
			if(glyph == null) return 0;
			this.__metrics[inGlyph] = m = glyph._width * this.__fontScale | 0;
		}
		if(m == null) return 0;
		return m;
	}
	,hasGlyph: function(str) {
		return this.__glyphData.exists(HxOverrides.cca(str,0));
	}
	,__class__: flash.text.Font
	,__properties__: {set_fontName:"set_fontName"}
}
flash.text.FontStyle = $hxClasses["flash.text.FontStyle"] = { __ename__ : true, __constructs__ : ["REGULAR","ITALIC","BOLD_ITALIC","BOLD"] }
flash.text.FontStyle.REGULAR = ["REGULAR",0];
flash.text.FontStyle.REGULAR.toString = $estr;
flash.text.FontStyle.REGULAR.__enum__ = flash.text.FontStyle;
flash.text.FontStyle.ITALIC = ["ITALIC",1];
flash.text.FontStyle.ITALIC.toString = $estr;
flash.text.FontStyle.ITALIC.__enum__ = flash.text.FontStyle;
flash.text.FontStyle.BOLD_ITALIC = ["BOLD_ITALIC",2];
flash.text.FontStyle.BOLD_ITALIC.toString = $estr;
flash.text.FontStyle.BOLD_ITALIC.__enum__ = flash.text.FontStyle;
flash.text.FontStyle.BOLD = ["BOLD",3];
flash.text.FontStyle.BOLD.toString = $estr;
flash.text.FontStyle.BOLD.__enum__ = flash.text.FontStyle;
flash.text.FontType = $hxClasses["flash.text.FontType"] = { __ename__ : true, __constructs__ : ["EMBEDDED","DEVICE"] }
flash.text.FontType.EMBEDDED = ["EMBEDDED",0];
flash.text.FontType.EMBEDDED.toString = $estr;
flash.text.FontType.EMBEDDED.__enum__ = flash.text.FontType;
flash.text.FontType.DEVICE = ["DEVICE",1];
flash.text.FontType.DEVICE.toString = $estr;
flash.text.FontType.DEVICE.__enum__ = flash.text.FontType;
flash.text.GridFitType = $hxClasses["flash.text.GridFitType"] = { __ename__ : true, __constructs__ : ["NONE","PIXEL","SUBPIXEL"] }
flash.text.GridFitType.NONE = ["NONE",0];
flash.text.GridFitType.NONE.toString = $estr;
flash.text.GridFitType.NONE.__enum__ = flash.text.GridFitType;
flash.text.GridFitType.PIXEL = ["PIXEL",1];
flash.text.GridFitType.PIXEL.toString = $estr;
flash.text.GridFitType.PIXEL.__enum__ = flash.text.GridFitType;
flash.text.GridFitType.SUBPIXEL = ["SUBPIXEL",2];
flash.text.GridFitType.SUBPIXEL.toString = $estr;
flash.text.GridFitType.SUBPIXEL.__enum__ = flash.text.GridFitType;
flash.text.TextField = function() {
	flash.display.InteractiveObject.call(this);
	this.mWidth = 100;
	this.mHeight = 20;
	this.mHTMLMode = false;
	this.multiline = false;
	this.__graphics = new flash.display.Graphics();
	this.mFace = flash.text.TextField.mDefaultFont;
	this.mAlign = flash.text.TextFormatAlign.LEFT;
	this.mParagraphs = new Array();
	this.mSelStart = -1;
	this.mSelEnd = -1;
	this.scrollH = 0;
	this.scrollV = 1;
	this.mType = flash.text.TextFieldType.DYNAMIC;
	this.set_autoSize("NONE");
	this.mTextHeight = 12;
	this.mMaxHeight = this.mTextHeight;
	this.mHTMLText = " ";
	this.mText = " ";
	this.mTextColour = 0;
	this.tabEnabled = false;
	this.mTryFreeType = true;
	this.selectable = true;
	this.mInsertPos = 0;
	this.__inputEnabled = false;
	this.mDownChar = 0;
	this.mSelectDrag = -1;
	this.mLineInfo = [];
	this.set_defaultTextFormat(new flash.text.TextFormat());
	this.set_borderColor(0);
	this.set_border(false);
	this.set_backgroundColor(16777215);
	this.set_background(false);
	this.gridFitType = flash.text.GridFitType.PIXEL;
	this.sharpness = 0;
};
$hxClasses["flash.text.TextField"] = flash.text.TextField;
flash.text.TextField.__name__ = ["flash","text","TextField"];
flash.text.TextField.__super__ = flash.display.InteractiveObject;
flash.text.TextField.prototype = $extend(flash.display.InteractiveObject.prototype,{
	set_wordWrap: function(inWordWrap) {
		this.wordWrap = inWordWrap;
		this.Rebuild();
		return this.get_wordWrap();
	}
	,get_wordWrap: function() {
		return this.wordWrap;
	}
	,set_width: function(inValue) {
		if(this.parent != null) this.parent.__invalidateBounds();
		if(this.get__boundsInvalid()) this.validateBounds();
		if(inValue != this.mWidth) {
			this.mWidth = inValue;
			this.Rebuild();
		}
		return this.mWidth;
	}
	,get_width: function() {
		return Math.max(this.mWidth,this.getBounds(this.get_stage()).width);
	}
	,set_type: function(inType) {
		this.mType = inType;
		this.__inputEnabled = this.mType == flash.text.TextFieldType.INPUT;
		if(this.mHTMLMode) {
			if(this.__inputEnabled) flash.Lib.__setContentEditable(this.__graphics.__surface,true); else flash.Lib.__setContentEditable(this.__graphics.__surface,false);
		} else if(this.__inputEnabled) {
			this.set_htmlText(StringTools.replace(this.mText,"\n","<BR />"));
			flash.Lib.__setContentEditable(this.__graphics.__surface,true);
		}
		this.tabEnabled = this.get_type() == flash.text.TextFieldType.INPUT;
		this.Rebuild();
		return inType;
	}
	,get_type: function() {
		return this.mType;
	}
	,get_textHeight: function() {
		return this.mMaxHeight;
	}
	,get_textWidth: function() {
		return this.mMaxWidth;
	}
	,set_textColor: function(inCol) {
		this.mTextColour = inCol;
		this.RebuildText();
		return inCol;
	}
	,get_textColor: function() {
		return this.mTextColour;
	}
	,set_text: function(inText) {
		this.mText = Std.string(inText);
		this.mHTMLMode = false;
		this.RebuildText();
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
		return this.mText;
	}
	,get_text: function() {
		if(this.mHTMLMode) this.ConvertHTMLToText(false);
		return this.mText;
	}
	,set_scrollV: function(value) {
		return this.scrollV = value;
	}
	,get_scrollV: function() {
		return this.scrollV;
	}
	,set_scrollH: function(value) {
		return this.scrollH = value;
	}
	,get_scrollH: function() {
		return this.scrollH;
	}
	,get_numLines: function() {
		return 0;
	}
	,set_multiline: function(value) {
		return this.multiline = value;
	}
	,get_multiline: function() {
		return this.multiline;
	}
	,get_maxScrollV: function() {
		return 0;
	}
	,get_maxScrollH: function() {
		return 0;
	}
	,set_htmlText: function(inHTMLText) {
		this.mParagraphs = new Array();
		this.mHTMLText = inHTMLText;
		if(!this.mHTMLMode) {
			var domElement = js.Browser.document.createElement("div");
			if(this.background || this.border) {
				domElement.style.width = this.mWidth + "px";
				domElement.style.height = this.mHeight + "px";
			}
			if(this.background) domElement.style.backgroundColor = "#" + StringTools.hex(this.backgroundColor,6);
			if(this.border) domElement.style.border = "1px solid #" + StringTools.hex(this.borderColor,6);
			domElement.style.color = "#" + StringTools.hex(this.mTextColour,6);
			domElement.style.fontFamily = this.mFace;
			domElement.style.fontSize = this.mTextHeight + "px";
			domElement.style.textAlign = Std.string(this.mAlign);
			var wrapper = domElement;
			wrapper.innerHTML = inHTMLText;
			var destination = new flash.display.Graphics(wrapper);
			var __surface = this.__graphics.__surface;
			if(flash.Lib.__isOnStage(__surface)) {
				flash.Lib.__appendSurface(wrapper);
				flash.Lib.__copyStyle(__surface,wrapper);
				flash.Lib.__swapSurface(__surface,wrapper);
				flash.Lib.__removeSurface(__surface);
			}
			this.__graphics = destination;
			this.__graphics.__extent.width = wrapper.width;
			this.__graphics.__extent.height = wrapper.height;
		} else this.__graphics.__surface.innerHTML = inHTMLText;
		this.mHTMLMode = true;
		this.RebuildText();
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
		return this.mHTMLText;
	}
	,get_htmlText: function() {
		return this.mHTMLText;
	}
	,set_height: function(inValue) {
		if(this.parent != null) this.parent.__invalidateBounds();
		if(this.get__boundsInvalid()) this.validateBounds();
		if(inValue != this.mHeight) {
			this.mHeight = inValue;
			this.Rebuild();
		}
		return this.mHeight;
	}
	,get_height: function() {
		return Math.max(this.mHeight,this.getBounds(this.get_stage()).height);
	}
	,set_defaultTextFormat: function(inFmt) {
		this.setTextFormat(inFmt);
		this._defaultTextFormat = inFmt;
		return inFmt;
	}
	,get_defaultTextFormat: function() {
		return this._defaultTextFormat;
	}
	,get_caretPos: function() {
		return this.mInsertPos;
	}
	,get_bottomScrollV: function() {
		return 0;
	}
	,set_borderColor: function(inBorderCol) {
		this.borderColor = inBorderCol;
		this.Rebuild();
		return inBorderCol;
	}
	,set_border: function(inBorder) {
		this.border = inBorder;
		this.Rebuild();
		return inBorder;
	}
	,set_backgroundColor: function(inCol) {
		this.backgroundColor = inCol;
		this.Rebuild();
		return inCol;
	}
	,set_background: function(inBack) {
		this.background = inBack;
		this.Rebuild();
		return inBack;
	}
	,set_autoSize: function(inAutoSize) {
		this.autoSize = inAutoSize;
		this.Rebuild();
		return inAutoSize;
	}
	,get_autoSize: function() {
		return this.autoSize;
	}
	,__render: function(inMask,clipRect) {
		if(!this.__combinedVisible) return;
		if((this.___renderFlags & 4) != 0 || (this.___renderFlags & 8) != 0) this.__validateMatrix();
		if(this.__graphics.__render(inMask,this.__filters,1,1)) {
			this.___renderFlags |= 64;
			if(this.parent != null) this.parent.___renderFlags |= 64;
			this.__applyFilters(this.__graphics.__surface);
			this.___renderFlags |= 32;
		}
		if(!this.mHTMLMode && inMask != null) {
			var m = this.getSurfaceTransform(this.__graphics);
			flash.Lib.__drawToSurface(this.__graphics.__surface,inMask,m,(this.parent != null?this.parent.__combinedAlpha:1) * this.alpha,clipRect,this.gridFitType != flash.text.GridFitType.PIXEL);
		} else {
			if((this.___renderFlags & 32) != 0) {
				var m = this.getSurfaceTransform(this.__graphics);
				flash.Lib.__setSurfaceTransform(this.__graphics.__surface,m);
				this.___renderFlags &= -33;
			}
			flash.Lib.__setSurfaceOpacity(this.__graphics.__surface,(this.parent != null?this.parent.__combinedAlpha:1) * this.alpha);
		}
	}
	,__getObjectUnderPoint: function(point) {
		if(!this.get_visible()) return null; else if(this.mText.length > 1) {
			var local = this.globalToLocal(point);
			if(local.x < 0 || local.y < 0 || local.x > this.mMaxWidth || local.y > this.mMaxHeight) return null; else return this;
		} else return flash.display.InteractiveObject.prototype.__getObjectUnderPoint.call(this,point);
	}
	,__getGraphics: function() {
		return this.__graphics;
	}
	,toString: function() {
		return "[TextField name=" + this.name + " id=" + this.___id + "]";
	}
	,setTextFormat: function(inFmt,beginIndex,endIndex) {
		if(endIndex == null) endIndex = 0;
		if(beginIndex == null) beginIndex = 0;
		if(inFmt.font != null) this.mFace = inFmt.font;
		if(inFmt.size != null) this.mTextHeight = inFmt.size | 0;
		if(inFmt.align != null) this.mAlign = inFmt.align;
		if(inFmt.color != null) this.mTextColour = inFmt.color;
		this.RebuildText();
		this.___renderFlags |= 64;
		if(this.parent != null) this.parent.___renderFlags |= 64;
		return this.getTextFormat();
	}
	,setSelection: function(beginIndex,endIndex) {
	}
	,RenderRow: function(inRow,inY,inCharIdx,inAlign,inInsert) {
		if(inInsert == null) inInsert = 0;
		var h = 0;
		var w = 0;
		var _g = 0;
		while(_g < inRow.length) {
			var chr = inRow[_g];
			++_g;
			if(chr.fh > h) h = chr.fh;
			w += chr.adv;
		}
		if(w > this.mMaxWidth) this.mMaxWidth = w;
		var full_height = h * 1.2 | 0;
		var align_x = 0;
		var insert_x = 0;
		if(inInsert != null) {
			if(this.autoSize != "NONE") {
				this.scrollH = 0;
				insert_x = inInsert;
			} else {
				insert_x = inInsert - this.scrollH;
				if(insert_x < 0) this.scrollH -= (this.mLimitRenderX * 3 >> 2) - insert_x; else if(insert_x > this.mLimitRenderX) this.scrollH += insert_x - (this.mLimitRenderX * 3 >> 2);
				if(this.scrollH < 0) this.scrollH = 0;
			}
		}
		if(this.autoSize == "NONE" && w <= this.mLimitRenderX) {
			if(inAlign == flash.text.TextFormatAlign.CENTER) align_x = Math.round(this.mWidth) - w >> 1; else if(inAlign == flash.text.TextFormatAlign.RIGHT) align_x = Math.round(this.mWidth) - w;
		}
		var x_list = new Array();
		this.mLineInfo.push({ mY0 : inY, mIndex : inCharIdx - 1, mX : x_list});
		var cache_sel_font = null;
		var cache_normal_font = null;
		var x = align_x - this.scrollH;
		var x0 = x;
		var _g = 0;
		while(_g < inRow.length) {
			var chr = inRow[_g];
			++_g;
			var adv = chr.adv;
			if(x + adv > this.mLimitRenderX) break;
			x_list.push(x);
			if(x >= 0) {
				var font = chr.font;
				if(chr.sel) {
					this.__graphics.lineStyle();
					this.__graphics.beginFill(2105440);
					this.__graphics.drawRect(x,inY,adv,full_height);
					this.__graphics.endFill();
					if(cache_normal_font == chr.font) font = cache_sel_font; else {
						font = flash.text.FontInstance.CreateSolid(chr.font.GetFace(),chr.fh,16777215,1.0);
						cache_sel_font = font;
						cache_normal_font = chr.font;
					}
				}
				font.RenderChar(this.__graphics,chr.chr,x,inY + (h - chr.fh) | 0);
			}
			x += adv;
		}
		x += this.scrollH;
		return full_height;
	}
	,RebuildText: function() {
		this.mParagraphs = [];
		if(!this.mHTMLMode) {
			var font = flash.text.FontInstance.CreateSolid(this.mFace,this.mTextHeight,this.mTextColour,1.0);
			var paras = this.mText.split("\n");
			var _g = 0;
			while(_g < paras.length) {
				var paragraph = paras[_g];
				++_g;
				this.mParagraphs.push({ align : this.mAlign, spans : [{ font : font, text : paragraph + "\n"}]});
			}
		}
		this.Rebuild();
	}
	,Rebuild: function() {
		if(this.mHTMLMode) return;
		this.mLineInfo = [];
		this.__graphics.clear();
		if(this.background) {
			this.__graphics.beginFill(this.backgroundColor);
			this.__graphics.drawRect(0,0,this.get_width(),this.get_height());
			this.__graphics.endFill();
		}
		this.__graphics.lineStyle(this.mTextColour);
		var insert_x = null;
		this.mMaxWidth = 0;
		var wrap = this.mLimitRenderX = this.get_wordWrap() && !this.__inputEnabled?this.mWidth | 0:999999;
		var char_idx = 0;
		var h = 0;
		var s0 = this.mSelStart;
		var s1 = this.mSelEnd;
		var _g = 0, _g1 = this.mParagraphs;
		while(_g < _g1.length) {
			var paragraph = _g1[_g];
			++_g;
			var row = [];
			var row_width = 0;
			var last_word_break = 0;
			var last_word_break_width = 0;
			var last_word_char_idx = 0;
			var start_idx = char_idx;
			var tx = 0;
			var _g2 = 0, _g3 = paragraph.spans;
			while(_g2 < _g3.length) {
				var span = _g3[_g2];
				++_g2;
				var text = span.text;
				var font = span.font;
				var fh = font.get_height();
				last_word_break = row.length;
				last_word_break_width = row_width;
				last_word_char_idx = char_idx;
				var _g5 = 0, _g4 = text.length;
				while(_g5 < _g4) {
					var ch = _g5++;
					var g = HxOverrides.cca(text,ch);
					var adv = font.__getAdvance(g);
					if(g == 32) {
						last_word_break = row.length;
						last_word_break_width = tx;
						last_word_char_idx = char_idx;
					}
					if(tx + adv > wrap) {
						if(last_word_break > 0) {
							var row_end = row.splice(last_word_break,row.length - last_word_break);
							h += this.RenderRow(row,h,start_idx,paragraph.align);
							row = row_end;
							tx -= last_word_break_width;
							start_idx = last_word_char_idx;
							last_word_break = 0;
							last_word_break_width = 0;
							last_word_char_idx = 0;
							if(row_end.length > 0 && row_end[0].chr == 32) {
								row_end.shift();
								start_idx++;
							}
						} else {
							h += this.RenderRow(row,h,char_idx,paragraph.align);
							row = [];
							tx = 0;
							start_idx = char_idx;
						}
					}
					row.push({ font : font, chr : g, x : tx, fh : fh, sel : char_idx >= s0 && char_idx < s1, adv : adv});
					tx += adv;
					char_idx++;
				}
			}
			if(row.length > 0) {
				h += this.RenderRow(row,h,start_idx,paragraph.align,insert_x);
				insert_x = null;
			}
		}
		var w = this.mMaxWidth;
		if(h < this.mTextHeight) h = this.mTextHeight;
		this.mMaxHeight = h;
		var _g = this;
		switch(_g.autoSize) {
		case "LEFT":
			break;
		case "RIGHT":
			var x0 = this.get_x() + this.get_width();
			this.set_x(this.mWidth - x0);
			break;
		case "CENTER":
			var x0 = this.get_x() + this.get_width() / 2;
			this.set_x(this.mWidth / 2 - x0);
			break;
		default:
			if(this.get_wordWrap()) this.set_height(h);
		}
		if(this.border) {
			this.__graphics.endFill();
			this.__graphics.lineStyle(1,this.borderColor,1,true);
			this.__graphics.drawRect(.5,.5,this.get_width() - .5,this.get_height() - .5);
		}
	}
	,getTextFormat: function(beginIndex,endIndex) {
		if(endIndex == null) endIndex = 0;
		if(beginIndex == null) beginIndex = 0;
		return new flash.text.TextFormat(this.mFace,this.mTextHeight,this.mTextColour);
	}
	,getLineIndexAtPoint: function(inX,inY) {
		if(this.mLineInfo.length < 1) return -1;
		if(inY <= 0) return 0;
		var _g1 = 0, _g = this.mLineInfo.length;
		while(_g1 < _g) {
			var l = _g1++;
			if(this.mLineInfo[l].mY0 > inY) return l == 0?0:l - 1;
		}
		return this.mLineInfo.length - 1;
	}
	,getCharIndexAtPoint: function(inX,inY) {
		var li = this.getLineIndexAtPoint(inX,inY);
		if(li < 0) return -1;
		var line = this.mLineInfo[li];
		var idx = line.mIndex;
		var _g = 0, _g1 = line.mX;
		while(_g < _g1.length) {
			var x = _g1[_g];
			++_g;
			if(x > inX) return idx;
			idx++;
		}
		return idx;
	}
	,getCharBoundaries: function(a) {
		return null;
	}
	,DecodeColour: function(col) {
		return Std.parseInt("0x" + HxOverrides.substr(col,1,null));
	}
	,ConvertHTMLToText: function(inUnSetHTML) {
		this.mText = "";
		var _g = 0, _g1 = this.mParagraphs;
		while(_g < _g1.length) {
			var paragraph = _g1[_g];
			++_g;
			var _g2 = 0, _g3 = paragraph.spans;
			while(_g2 < _g3.length) {
				var span = _g3[_g2];
				++_g2;
				this.mText += span.text;
			}
		}
		if(inUnSetHTML) {
			this.mHTMLMode = false;
			this.RebuildText();
		}
	}
	,appendText: function(newText) {
		var _g = this;
		_g.set_text(_g.get_text() + newText);
	}
	,__class__: flash.text.TextField
	,__properties__: $extend(flash.display.InteractiveObject.prototype.__properties__,{set_autoSize:"set_autoSize",set_background:"set_background",set_backgroundColor:"set_backgroundColor",set_border:"set_border",set_borderColor:"set_borderColor",get_bottomScrollV:"get_bottomScrollV",get_caretPos:"get_caretPos",set_defaultTextFormat:"set_defaultTextFormat",get_defaultTextFormat:"get_defaultTextFormat",set_htmlText:"set_htmlText",get_htmlText:"get_htmlText",get_maxScrollH:"get_maxScrollH",get_maxScrollV:"get_maxScrollV",get_numLines:"get_numLines",set_text:"set_text",get_text:"get_text",set_textColor:"set_textColor",get_textColor:"get_textColor",get_textHeight:"get_textHeight",get_textWidth:"get_textWidth",set_type:"set_type",get_type:"get_type",set_wordWrap:"set_wordWrap",get_wordWrap:"get_wordWrap"})
});
flash.text.FontInstanceMode = $hxClasses["flash.text.FontInstanceMode"] = { __ename__ : true, __constructs__ : ["fimSolid"] }
flash.text.FontInstanceMode.fimSolid = ["fimSolid",0];
flash.text.FontInstanceMode.fimSolid.toString = $estr;
flash.text.FontInstanceMode.fimSolid.__enum__ = flash.text.FontInstanceMode;
flash.text.FontInstance = function(inFont,inHeight) {
	this.mFont = inFont;
	this.mHeight = inHeight;
	this.mTryFreeType = true;
	this.mGlyphs = [];
	this.mCacheAsBitmap = false;
};
$hxClasses["flash.text.FontInstance"] = flash.text.FontInstance;
flash.text.FontInstance.__name__ = ["flash","text","FontInstance"];
flash.text.FontInstance.CreateSolid = function(inFace,inHeight,inColour,inAlpha) {
	var id = "SOLID:" + inFace + ":" + inHeight + ":" + inColour + ":" + inAlpha;
	var f = flash.text.FontInstance.mSolidFonts.get(id);
	if(f != null) return f;
	var font = new flash.text.Font();
	font.__setScale(inHeight);
	font.set_fontName(inFace);
	if(font == null) return null;
	f = new flash.text.FontInstance(font,inHeight);
	f.SetSolid(inColour,inAlpha);
	flash.text.FontInstance.mSolidFonts.set(id,f);
	return f;
}
flash.text.FontInstance.prototype = {
	get_height: function() {
		return this.mHeight;
	}
	,__getAdvance: function(inChar) {
		if(this.mFont == null) return 0;
		return this.mFont.__getAdvance(inChar,this.mHeight);
	}
	,toString: function() {
		return "FontInstance:" + Std.string(this.mFont) + ":" + this.mColour + "(" + this.mGlyphs.length + ")";
	}
	,RenderChar: function(inGraphics,inGlyph,inX,inY) {
		inGraphics.__clearLine();
		inGraphics.beginFill(this.mColour,this.mAlpha);
		this.mFont.__render(inGraphics,inGlyph,inX,inY,this.mTryFreeType);
		inGraphics.endFill();
	}
	,SetSolid: function(inCol,inAlpha) {
		this.mColour = inCol;
		this.mAlpha = inAlpha;
		this.mMode = flash.text.FontInstanceMode.fimSolid;
	}
	,GetFace: function() {
		return this.mFont.fontName;
	}
	,__class__: flash.text.FontInstance
	,__properties__: {get_height:"get_height"}
}
flash.text.TextFieldAutoSize = function() { }
$hxClasses["flash.text.TextFieldAutoSize"] = flash.text.TextFieldAutoSize;
flash.text.TextFieldAutoSize.__name__ = ["flash","text","TextFieldAutoSize"];
flash.text.TextFieldType = function() { }
$hxClasses["flash.text.TextFieldType"] = flash.text.TextFieldType;
flash.text.TextFieldType.__name__ = ["flash","text","TextFieldType"];
flash.text.TextFormat = function(in_font,in_size,in_color,in_bold,in_italic,in_underline,in_url,in_target,in_align,in_leftMargin,in_rightMargin,in_indent,in_leading) {
	this.font = in_font;
	this.size = in_size;
	this.color = in_color;
	this.bold = in_bold;
	this.italic = in_italic;
	this.underline = in_underline;
	this.url = in_url;
	this.target = in_target;
	this.align = in_align;
	this.leftMargin = in_leftMargin;
	this.rightMargin = in_rightMargin;
	this.indent = in_indent;
	this.leading = in_leading;
};
$hxClasses["flash.text.TextFormat"] = flash.text.TextFormat;
flash.text.TextFormat.__name__ = ["flash","text","TextFormat"];
flash.text.TextFormat.prototype = {
	clone: function() {
		var newFormat = new flash.text.TextFormat(this.font,this.size,this.color,this.bold,this.italic,this.underline,this.url,this.target);
		newFormat.align = this.align;
		newFormat.leftMargin = this.leftMargin;
		newFormat.rightMargin = this.rightMargin;
		newFormat.indent = this.indent;
		newFormat.leading = this.leading;
		newFormat.blockIndent = this.blockIndent;
		newFormat.bullet = this.bullet;
		newFormat.display = this.display;
		newFormat.kerning = this.kerning;
		newFormat.letterSpacing = this.letterSpacing;
		newFormat.tabStops = this.tabStops;
		return newFormat;
	}
	,__class__: flash.text.TextFormat
}
flash.text.TextFormatAlign = $hxClasses["flash.text.TextFormatAlign"] = { __ename__ : true, __constructs__ : ["LEFT","RIGHT","JUSTIFY","CENTER"] }
flash.text.TextFormatAlign.LEFT = ["LEFT",0];
flash.text.TextFormatAlign.LEFT.toString = $estr;
flash.text.TextFormatAlign.LEFT.__enum__ = flash.text.TextFormatAlign;
flash.text.TextFormatAlign.RIGHT = ["RIGHT",1];
flash.text.TextFormatAlign.RIGHT.toString = $estr;
flash.text.TextFormatAlign.RIGHT.__enum__ = flash.text.TextFormatAlign;
flash.text.TextFormatAlign.JUSTIFY = ["JUSTIFY",2];
flash.text.TextFormatAlign.JUSTIFY.toString = $estr;
flash.text.TextFormatAlign.JUSTIFY.__enum__ = flash.text.TextFormatAlign;
flash.text.TextFormatAlign.CENTER = ["CENTER",3];
flash.text.TextFormatAlign.CENTER.toString = $estr;
flash.text.TextFormatAlign.CENTER.__enum__ = flash.text.TextFormatAlign;
flash.ui = {}
flash.ui.Keyboard = function() { }
$hxClasses["flash.ui.Keyboard"] = flash.ui.Keyboard;
flash.ui.Keyboard.__name__ = ["flash","ui","Keyboard"];
flash.ui.Keyboard.isAccessible = function() {
	return false;
}
flash.ui.Keyboard.__convertMozillaCode = function(code) {
	switch(code) {
	case 8:
		return 8;
	case 9:
		return 9;
	case 13:
		return 13;
	case 14:
		return 13;
	case 16:
		return 16;
	case 17:
		return 17;
	case 20:
		return 18;
	case 27:
		return 27;
	case 32:
		return 32;
	case 33:
		return 33;
	case 34:
		return 34;
	case 35:
		return 35;
	case 36:
		return 36;
	case 37:
		return 37;
	case 39:
		return 39;
	case 38:
		return 38;
	case 40:
		return 40;
	case 45:
		return 45;
	case 46:
		return 46;
	case 144:
		return 144;
	default:
		return code;
	}
}
flash.ui.Keyboard.__convertWebkitCode = function(code) {
	var _g = code.toLowerCase();
	switch(_g) {
	case "backspace":
		return 8;
	case "tab":
		return 9;
	case "enter":
		return 13;
	case "shift":
		return 16;
	case "control":
		return 17;
	case "capslock":
		return 18;
	case "escape":
		return 27;
	case "space":
		return 32;
	case "pageup":
		return 33;
	case "pagedown":
		return 34;
	case "end":
		return 35;
	case "home":
		return 36;
	case "left":
		return 37;
	case "right":
		return 39;
	case "up":
		return 38;
	case "down":
		return 40;
	case "insert":
		return 45;
	case "delete":
		return 46;
	case "numlock":
		return 144;
	case "break":
		return 19;
	}
	if(code.indexOf("U+") == 0) return Std.parseInt("0x" + HxOverrides.substr(code,3,null));
	throw "Unrecognized key code: " + code;
	return 0;
}
flash.utils = {}
flash.utils.ByteArray = function() {
	this.littleEndian = false;
	this.allocated = 0;
	this.position = 0;
	this.length = 0;
	this.___resizeBuffer(this.allocated);
};
$hxClasses["flash.utils.ByteArray"] = flash.utils.ByteArray;
flash.utils.ByteArray.__name__ = ["flash","utils","ByteArray"];
flash.utils.ByteArray.fromBytes = function(inBytes) {
	var result = new flash.utils.ByteArray();
	result.byteView = new Uint8Array(inBytes.b);
	result.set_length(result.byteView.length);
	result.allocated = result.length;
	return result;
}
flash.utils.ByteArray.__ofBuffer = function(buffer) {
	var bytes = new flash.utils.ByteArray();
	bytes.set_length(bytes.allocated = buffer.byteLength);
	bytes.data = new DataView(buffer);
	bytes.byteView = new Uint8Array(buffer);
	return bytes;
}
flash.utils.ByteArray.prototype = {
	set_length: function(value) {
		if(this.allocated < value) this.___resizeBuffer(this.allocated = Math.max(value,this.allocated * 2) | 0); else if(this.allocated > value) this.___resizeBuffer(this.allocated = value);
		this.length = value;
		return value;
	}
	,set_endian: function(endian) {
		this.littleEndian = endian == "littleEndian";
		return endian;
	}
	,get_endian: function() {
		return this.littleEndian?"littleEndian":"bigEndian";
	}
	,get_bytesAvailable: function() {
		return this.length - this.position;
	}
	,__set: function(pos,v) {
		this.data.setUint8(pos,v);
	}
	,__getBuffer: function() {
		return this.data.buffer;
	}
	,___resizeBuffer: function(len) {
		var oldByteView = this.byteView;
		var newByteView = new Uint8Array(len);
		if(oldByteView != null) {
			if(oldByteView.length <= len) newByteView.set(oldByteView); else newByteView.set(oldByteView.subarray(0,len));
		}
		this.byteView = newByteView;
		this.data = new DataView(newByteView.buffer);
	}
	,_getUTFBytesCount: function(value) {
		var count = 0;
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = value.charCodeAt(i);
			if(c <= 127) count += 1; else if(c <= 2047) count += 2; else if(c <= 65535) count += 3; else count += 4;
		}
		return count;
	}
	,__get: function(pos) {
		return this.data.getUint8(pos);
	}
	,__fromBytes: function(inBytes) {
		this.byteView = new Uint8Array(inBytes.b);
		this.set_length(this.byteView.length);
		this.allocated = this.length;
	}
	,writeUTFBytes: function(value) {
		var _g1 = 0, _g = value.length;
		while(_g1 < _g) {
			var i = _g1++;
			var c = value.charCodeAt(i);
			if(c <= 127) this.writeByte(c); else if(c <= 2047) {
				this.writeByte(192 | c >> 6);
				this.writeByte(128 | c & 63);
			} else if(c <= 65535) {
				this.writeByte(224 | c >> 12);
				this.writeByte(128 | c >> 6 & 63);
				this.writeByte(128 | c & 63);
			} else {
				this.writeByte(240 | c >> 18);
				this.writeByte(128 | c >> 12 & 63);
				this.writeByte(128 | c >> 6 & 63);
				this.writeByte(128 | c & 63);
			}
		}
	}
	,writeUTF: function(value) {
		this.writeUnsignedShort(this._getUTFBytesCount(value));
		this.writeUTFBytes(value);
	}
	,writeUnsignedShort: function(value) {
		var lengthToEnsure = this.position + 2;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setUint16(this.position,value,this.littleEndian);
		this.position += 2;
	}
	,writeUnsignedInt: function(value) {
		var lengthToEnsure = this.position + 4;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setUint32(this.position,value,this.littleEndian);
		this.position += 4;
	}
	,writeShort: function(value) {
		var lengthToEnsure = this.position + 2;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setInt16(this.position,value,this.littleEndian);
		this.position += 2;
	}
	,writeInt: function(value) {
		var lengthToEnsure = this.position + 4;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setInt32(this.position,value,this.littleEndian);
		this.position += 4;
	}
	,writeFloat: function(x) {
		var lengthToEnsure = this.position + 4;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setFloat32(this.position,x,this.littleEndian);
		this.position += 4;
	}
	,writeDouble: function(x) {
		var lengthToEnsure = this.position + 8;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.data.setFloat64(this.position,x,this.littleEndian);
		this.position += 8;
	}
	,writeBytes: function(bytes,offset,length) {
		if(offset < 0 || length < 0) throw new flash.errors.IOError("Write error - Out of bounds");
		var lengthToEnsure = this.position + length;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		this.byteView.set(bytes.byteView.subarray(offset,offset + length),this.position);
		this.position += length;
	}
	,writeByte: function(value) {
		var lengthToEnsure = this.position + 1;
		if(this.length < lengthToEnsure) {
			if(this.allocated < lengthToEnsure) this.___resizeBuffer(this.allocated = Math.max(lengthToEnsure,this.allocated * 2) | 0); else if(this.allocated > lengthToEnsure) this.___resizeBuffer(this.allocated = lengthToEnsure);
			this.length = lengthToEnsure;
			lengthToEnsure;
		}
		var data = this.data;
		data.setInt8(this.position,value);
		this.position += 1;
	}
	,writeBoolean: function(value) {
		this.writeByte(value?1:0);
	}
	,toString: function() {
		var cachePosition = this.position;
		this.position = 0;
		var value = this.readUTFBytes(this.length);
		this.position = cachePosition;
		return value;
	}
	,readUTFBytes: function(len) {
		var value = "";
		var max = this.position + len;
		while(this.position < max) {
			var data = this.data;
			var c = data.getUint8(this.position++);
			if(c < 128) {
				if(c == 0) break;
				value += String.fromCharCode(c);
			} else if(c < 224) value += String.fromCharCode((c & 63) << 6 | data.getUint8(this.position++) & 127); else if(c < 240) {
				var c2 = data.getUint8(this.position++);
				value += String.fromCharCode((c & 31) << 12 | (c2 & 127) << 6 | data.getUint8(this.position++) & 127);
			} else {
				var c2 = data.getUint8(this.position++);
				var c3 = data.getUint8(this.position++);
				value += String.fromCharCode((c & 15) << 18 | (c2 & 127) << 12 | c3 << 6 & 127 | data.getUint8(this.position++) & 127);
			}
		}
		return value;
	}
	,readUTF: function() {
		var bytesCount = this.readUnsignedShort();
		return this.readUTFBytes(bytesCount);
	}
	,readUnsignedShort: function() {
		var uShort = this.data.getUint16(this.position,this.littleEndian);
		this.position += 2;
		return uShort;
	}
	,readUnsignedInt: function() {
		var uInt = this.data.getUint32(this.position,this.littleEndian);
		this.position += 4;
		return uInt;
	}
	,readUnsignedByte: function() {
		var data = this.data;
		return data.getUint8(this.position++);
	}
	,readShort: function() {
		var $short = this.data.getInt16(this.position,this.littleEndian);
		this.position += 2;
		return $short;
	}
	,readInt: function() {
		var $int = this.data.getInt32(this.position,this.littleEndian);
		this.position += 4;
		return $int;
	}
	,readFullBytes: function(bytes,pos,len) {
		if(this.length < len) {
			if(this.allocated < len) this.___resizeBuffer(this.allocated = Math.max(len,this.allocated * 2) | 0); else if(this.allocated > len) this.___resizeBuffer(this.allocated = len);
			this.length = len;
			len;
		}
		var _g1 = pos, _g = pos + len;
		while(_g1 < _g) {
			var i = _g1++;
			var data = this.data;
			data.setInt8(this.position++,bytes.b[i]);
		}
	}
	,readFloat: function() {
		var $float = this.data.getFloat32(this.position,this.littleEndian);
		this.position += 4;
		return $float;
	}
	,readDouble: function() {
		var $double = this.data.getFloat64(this.position,this.littleEndian);
		this.position += 8;
		return $double;
	}
	,readBytes: function(bytes,offset,length) {
		if(offset < 0 || length < 0) throw new flash.errors.IOError("Read error - Out of bounds");
		if(offset == null) offset = 0;
		if(length == null) length = this.length;
		var lengthToEnsure = offset + length;
		if(bytes.length < lengthToEnsure) {
			if(bytes.allocated < lengthToEnsure) bytes.___resizeBuffer(bytes.allocated = Math.max(lengthToEnsure,bytes.allocated * 2) | 0); else if(bytes.allocated > lengthToEnsure) bytes.___resizeBuffer(bytes.allocated = lengthToEnsure);
			bytes.length = lengthToEnsure;
			lengthToEnsure;
		}
		bytes.byteView.set(this.byteView.subarray(this.position,this.position + length),offset);
		bytes.position = offset;
		this.position += length;
		if(bytes.position + length > bytes.length) bytes.set_length(bytes.position + length);
	}
	,readByte: function() {
		var data = this.data;
		return data.getUint8(this.position++);
	}
	,readBoolean: function() {
		return this.readByte() != 0;
	}
	,clear: function() {
		if(this.allocated < 0) this.___resizeBuffer(this.allocated = Math.max(0,this.allocated * 2) | 0); else if(this.allocated > 0) this.___resizeBuffer(this.allocated = 0);
		this.length = 0;
		0;
	}
	,__class__: flash.utils.ByteArray
	,__properties__: {get_bytesAvailable:"get_bytesAvailable",set_endian:"set_endian",get_endian:"get_endian",set_length:"set_length"}
}
flash.utils.Endian = function() { }
$hxClasses["flash.utils.Endian"] = flash.utils.Endian;
flash.utils.Endian.__name__ = ["flash","utils","Endian"];
flash.utils.Timer = function(delay,repeatCount) {
	if(repeatCount == null) repeatCount = 0;
	flash.events.EventDispatcher.call(this);
	this.running = false;
	this.set_delay(delay);
	this.set_repeatCount(repeatCount);
	this.currentCount = 0;
};
$hxClasses["flash.utils.Timer"] = flash.utils.Timer;
flash.utils.Timer.__name__ = ["flash","utils","Timer"];
flash.utils.Timer.__super__ = flash.events.EventDispatcher;
flash.utils.Timer.prototype = $extend(flash.events.EventDispatcher.prototype,{
	set_repeatCount: function(v) {
		if(this.running && v != 0 && v <= this.currentCount) this.stop();
		this.repeatCount = v;
		return v;
	}
	,set_delay: function(v) {
		if(v != this.delay) {
			var wasRunning = this.running;
			if(this.running) this.stop();
			this.delay = v;
			if(wasRunning) this.start();
		}
		return v;
	}
	,__onInterval: function() {
		this.currentCount++;
		if(this.repeatCount > 0 && this.currentCount >= this.repeatCount) {
			this.stop();
			this.dispatchEvent(new flash.events.TimerEvent("timer"));
			this.dispatchEvent(new flash.events.TimerEvent("timerComplete"));
		} else this.dispatchEvent(new flash.events.TimerEvent("timer"));
	}
	,stop: function() {
		if(this.timerId != null) {
			window.clearInterval(this.timerId);
			this.timerId = null;
		}
		this.running = false;
	}
	,start: function() {
		if(this.running) return;
		this.running = true;
		this.timerId = window.setInterval($bind(this,this.__onInterval),this.delay | 0);
	}
	,reset: function() {
		this.stop();
		this.currentCount = 0;
	}
	,__class__: flash.utils.Timer
	,__properties__: {set_delay:"set_delay",set_repeatCount:"set_repeatCount"}
});
flash.utils.Uuid = function() { }
$hxClasses["flash.utils.Uuid"] = flash.utils.Uuid;
flash.utils.Uuid.__name__ = ["flash","utils","Uuid"];
flash.utils.Uuid.random = function(size) {
	if(size == null) size = 32;
	var nchars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".length;
	var uid = new StringBuf();
	var _g = 0;
	while(_g < size) {
		var i = _g++;
		uid.b += Std.string("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ".charAt(Math.random() * nchars | 0));
	}
	return uid.b;
}
flash.utils.Uuid.uuid = function() {
	return flash.utils.Uuid.random(8) + "-" + flash.utils.Uuid.random(4) + "-" + flash.utils.Uuid.random(4) + "-" + flash.utils.Uuid.random(4) + "-" + flash.utils.Uuid.random(12);
}
haxe.StackItem = $hxClasses["haxe.StackItem"] = { __ename__ : true, __constructs__ : ["CFunction","Module","FilePos","Method","Lambda"] }
haxe.StackItem.CFunction = ["CFunction",0];
haxe.StackItem.CFunction.toString = $estr;
haxe.StackItem.CFunction.__enum__ = haxe.StackItem;
haxe.StackItem.Module = function(m) { var $x = ["Module",1,m]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.FilePos = function(s,file,line) { var $x = ["FilePos",2,s,file,line]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.Method = function(classname,method) { var $x = ["Method",3,classname,method]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.StackItem.Lambda = function(v) { var $x = ["Lambda",4,v]; $x.__enum__ = haxe.StackItem; $x.toString = $estr; return $x; }
haxe.CallStack = function() { }
$hxClasses["haxe.CallStack"] = haxe.CallStack;
haxe.CallStack.__name__ = ["haxe","CallStack"];
haxe.CallStack.exceptionStack = function() {
	return [];
}
haxe.CallStack.toString = function(stack) {
	var b = new StringBuf();
	var _g = 0;
	while(_g < stack.length) {
		var s = stack[_g];
		++_g;
		b.b += "\nCalled from ";
		haxe.CallStack.itemToString(b,s);
	}
	return b.b;
}
haxe.CallStack.itemToString = function(b,s) {
	var $e = (s);
	switch( $e[1] ) {
	case 0:
		b.b += "a C function";
		break;
	case 1:
		var m = $e[2];
		b.b += "module ";
		b.b += Std.string(m);
		break;
	case 2:
		var line = $e[4], file = $e[3], s1 = $e[2];
		if(s1 != null) {
			haxe.CallStack.itemToString(b,s1);
			b.b += " (";
		}
		b.b += Std.string(file);
		b.b += " line ";
		b.b += Std.string(line);
		if(s1 != null) b.b += ")";
		break;
	case 3:
		var meth = $e[3], cname = $e[2];
		b.b += Std.string(cname);
		b.b += ".";
		b.b += Std.string(meth);
		break;
	case 4:
		var n = $e[2];
		b.b += "local function #";
		b.b += Std.string(n);
		break;
	}
}
haxe.Resource = function() { }
$hxClasses["haxe.Resource"] = haxe.Resource;
haxe.Resource.__name__ = ["haxe","Resource"];
haxe.Resource.listNames = function() {
	var names = new Array();
	var _g = 0, _g1 = haxe.Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		names.push(x.name);
	}
	return names;
}
haxe.Resource.getString = function(name) {
	var _g = 0, _g1 = haxe.Resource.content;
	while(_g < _g1.length) {
		var x = _g1[_g];
		++_g;
		if(x.name == name) {
			if(x.str != null) return x.str;
			var b = haxe.Unserializer.run(x.data);
			return b.toString();
		}
	}
	return null;
}
haxe._Template = {}
haxe._Template.TemplateExpr = $hxClasses["haxe._Template.TemplateExpr"] = { __ename__ : true, __constructs__ : ["OpVar","OpExpr","OpIf","OpStr","OpBlock","OpForeach","OpMacro"] }
haxe._Template.TemplateExpr.OpVar = function(v) { var $x = ["OpVar",0,v]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpExpr = function(expr) { var $x = ["OpExpr",1,expr]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpIf = function(expr,eif,eelse) { var $x = ["OpIf",2,expr,eif,eelse]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpStr = function(str) { var $x = ["OpStr",3,str]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpBlock = function(l) { var $x = ["OpBlock",4,l]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpForeach = function(expr,loop) { var $x = ["OpForeach",5,expr,loop]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe._Template.TemplateExpr.OpMacro = function(name,params) { var $x = ["OpMacro",6,name,params]; $x.__enum__ = haxe._Template.TemplateExpr; $x.toString = $estr; return $x; }
haxe.Template = function(str) {
	var tokens = this.parseTokens(str);
	this.expr = this.parseBlock(tokens);
	if(!tokens.isEmpty()) throw "Unexpected '" + Std.string(tokens.first().s) + "'";
};
$hxClasses["haxe.Template"] = haxe.Template;
haxe.Template.__name__ = ["haxe","Template"];
haxe.Template.prototype = {
	run: function(e) {
		var $e = (e);
		switch( $e[1] ) {
		case 0:
			var v = $e[2];
			this.buf.b += Std.string(Std.string(this.resolve(v)));
			break;
		case 1:
			var e1 = $e[2];
			this.buf.b += Std.string(Std.string(e1()));
			break;
		case 2:
			var eelse = $e[4], eif = $e[3], e1 = $e[2];
			var v = e1();
			if(v == null || v == false) {
				if(eelse != null) this.run(eelse);
			} else this.run(eif);
			break;
		case 3:
			var str = $e[2];
			this.buf.b += Std.string(str);
			break;
		case 4:
			var l = $e[2];
			var $it0 = l.iterator();
			while( $it0.hasNext() ) {
				var e1 = $it0.next();
				this.run(e1);
			}
			break;
		case 5:
			var loop = $e[3], e1 = $e[2];
			var v = e1();
			try {
				var x = $iterator(v)();
				if(x.hasNext == null) throw null;
				v = x;
			} catch( e2 ) {
				try {
					if(v.hasNext == null) throw null;
				} catch( e3 ) {
					throw "Cannot iter on " + Std.string(v);
				}
			}
			this.stack.push(this.context);
			var v1 = v;
			while( v1.hasNext() ) {
				var ctx = v1.next();
				this.context = ctx;
				this.run(loop);
			}
			this.context = this.stack.pop();
			break;
		case 6:
			var params = $e[3], m = $e[2];
			var v = Reflect.field(this.macros,m);
			var pl = new Array();
			var old = this.buf;
			pl.push($bind(this,this.resolve));
			var $it1 = params.iterator();
			while( $it1.hasNext() ) {
				var p = $it1.next();
				var $e = (p);
				switch( $e[1] ) {
				case 0:
					var v1 = $e[2];
					pl.push(this.resolve(v1));
					break;
				default:
					this.buf = new StringBuf();
					this.run(p);
					pl.push(this.buf.b);
				}
			}
			this.buf = old;
			try {
				this.buf.b += Std.string(Std.string(v.apply(this.macros,pl)));
			} catch( e1 ) {
				var plstr = (function($this) {
					var $r;
					try {
						$r = pl.join(",");
					} catch( e2 ) {
						$r = "???";
					}
					return $r;
				}(this));
				var msg = "Macro call " + m + "(" + plstr + ") failed (" + Std.string(e1) + ")";
				throw msg;
			}
			break;
		}
	}
	,makeExpr2: function(l) {
		var p = l.pop();
		if(p == null) throw "<eof>";
		if(p.s) return this.makeConst(p.p);
		switch(p.p) {
		case "(":
			var e1 = this.makeExpr(l);
			var p1 = l.pop();
			if(p1 == null || p1.s) throw p1.p;
			if(p1.p == ")") return e1;
			var e2 = this.makeExpr(l);
			var p2 = l.pop();
			if(p2 == null || p2.p != ")") throw p2.p;
			return (function($this) {
				var $r;
				switch(p1.p) {
				case "+":
					$r = function() {
						return e1() + e2();
					};
					break;
				case "-":
					$r = function() {
						return e1() - e2();
					};
					break;
				case "*":
					$r = function() {
						return e1() * e2();
					};
					break;
				case "/":
					$r = function() {
						return e1() / e2();
					};
					break;
				case ">":
					$r = function() {
						return e1() > e2();
					};
					break;
				case "<":
					$r = function() {
						return e1() < e2();
					};
					break;
				case ">=":
					$r = function() {
						return e1() >= e2();
					};
					break;
				case "<=":
					$r = function() {
						return e1() <= e2();
					};
					break;
				case "==":
					$r = function() {
						return e1() == e2();
					};
					break;
				case "!=":
					$r = function() {
						return e1() != e2();
					};
					break;
				case "&&":
					$r = function() {
						return e1() && e2();
					};
					break;
				case "||":
					$r = function() {
						return e1() || e2();
					};
					break;
				default:
					$r = (function($this) {
						var $r;
						throw "Unknown operation " + p1.p;
						return $r;
					}($this));
				}
				return $r;
			}(this));
		case "!":
			var e = this.makeExpr(l);
			return function() {
				var v = e();
				return v == null || v == false;
			};
		case "-":
			var e3 = this.makeExpr(l);
			return function() {
				return -e3();
			};
		}
		throw p.p;
	}
	,makeExpr: function(l) {
		return this.makePath(this.makeExpr2(l),l);
	}
	,makePath: function(e,l) {
		var p = l.first();
		if(p == null || p.p != ".") return e;
		l.pop();
		var field = l.pop();
		if(field == null || !field.s) throw field.p;
		var f = field.p;
		haxe.Template.expr_trim.match(f);
		f = haxe.Template.expr_trim.matched(1);
		return this.makePath(function() {
			return Reflect.field(e(),f);
		},l);
	}
	,makeConst: function(v) {
		haxe.Template.expr_trim.match(v);
		v = haxe.Template.expr_trim.matched(1);
		if(HxOverrides.cca(v,0) == 34) {
			var str = HxOverrides.substr(v,1,v.length - 2);
			return function() {
				return str;
			};
		}
		if(haxe.Template.expr_int.match(v)) {
			var i = Std.parseInt(v);
			return function() {
				return i;
			};
		}
		if(haxe.Template.expr_float.match(v)) {
			var f = Std.parseFloat(v);
			return function() {
				return f;
			};
		}
		var me = this;
		return function() {
			return me.resolve(v);
		};
	}
	,parseExpr: function(data) {
		var l = new List();
		var expr = data;
		while(haxe.Template.expr_splitter.match(data)) {
			var p = haxe.Template.expr_splitter.matchedPos();
			var k = p.pos + p.len;
			if(p.pos != 0) l.add({ p : HxOverrides.substr(data,0,p.pos), s : true});
			var p1 = haxe.Template.expr_splitter.matched(0);
			l.add({ p : p1, s : p1.indexOf("\"") >= 0});
			data = haxe.Template.expr_splitter.matchedRight();
		}
		if(data.length != 0) l.add({ p : data, s : true});
		var e;
		try {
			e = this.makeExpr(l);
			if(!l.isEmpty()) throw l.first().p;
		} catch( s ) {
			if( js.Boot.__instanceof(s,String) ) {
				throw "Unexpected '" + s + "' in " + expr;
			} else throw(s);
		}
		return function() {
			try {
				return e();
			} catch( exc ) {
				throw "Error : " + Std.string(exc) + " in " + expr;
			}
		};
	}
	,parse: function(tokens) {
		var t = tokens.pop();
		var p = t.p;
		if(t.s) return haxe._Template.TemplateExpr.OpStr(p);
		if(t.l != null) {
			var pe = new List();
			var _g = 0, _g1 = t.l;
			while(_g < _g1.length) {
				var p1 = _g1[_g];
				++_g;
				pe.add(this.parseBlock(this.parseTokens(p1)));
			}
			return haxe._Template.TemplateExpr.OpMacro(p,pe);
		}
		if(HxOverrides.substr(p,0,3) == "if ") {
			p = HxOverrides.substr(p,3,p.length - 3);
			var e = this.parseExpr(p);
			var eif = this.parseBlock(tokens);
			var t1 = tokens.first();
			var eelse;
			if(t1 == null) throw "Unclosed 'if'";
			if(t1.p == "end") {
				tokens.pop();
				eelse = null;
			} else if(t1.p == "else") {
				tokens.pop();
				eelse = this.parseBlock(tokens);
				t1 = tokens.pop();
				if(t1 == null || t1.p != "end") throw "Unclosed 'else'";
			} else {
				t1.p = HxOverrides.substr(t1.p,4,t1.p.length - 4);
				eelse = this.parse(tokens);
			}
			return haxe._Template.TemplateExpr.OpIf(e,eif,eelse);
		}
		if(HxOverrides.substr(p,0,8) == "foreach ") {
			p = HxOverrides.substr(p,8,p.length - 8);
			var e = this.parseExpr(p);
			var efor = this.parseBlock(tokens);
			var t1 = tokens.pop();
			if(t1 == null || t1.p != "end") throw "Unclosed 'foreach'";
			return haxe._Template.TemplateExpr.OpForeach(e,efor);
		}
		if(haxe.Template.expr_splitter.match(p)) return haxe._Template.TemplateExpr.OpExpr(this.parseExpr(p));
		return haxe._Template.TemplateExpr.OpVar(p);
	}
	,parseBlock: function(tokens) {
		var l = new List();
		while(true) {
			var t = tokens.first();
			if(t == null) break;
			if(!t.s && (t.p == "end" || t.p == "else" || HxOverrides.substr(t.p,0,7) == "elseif ")) break;
			l.add(this.parse(tokens));
		}
		if(l.length == 1) return l.first();
		return haxe._Template.TemplateExpr.OpBlock(l);
	}
	,parseTokens: function(data) {
		var tokens = new List();
		while(haxe.Template.splitter.match(data)) {
			var p = haxe.Template.splitter.matchedPos();
			if(p.pos > 0) tokens.add({ p : HxOverrides.substr(data,0,p.pos), s : true, l : null});
			if(HxOverrides.cca(data,p.pos) == 58) {
				tokens.add({ p : HxOverrides.substr(data,p.pos + 2,p.len - 4), s : false, l : null});
				data = haxe.Template.splitter.matchedRight();
				continue;
			}
			var parp = p.pos + p.len;
			var npar = 1;
			while(npar > 0) {
				var c = HxOverrides.cca(data,parp);
				if(c == 40) npar++; else if(c == 41) npar--; else if(c == null) throw "Unclosed macro parenthesis";
				parp++;
			}
			var params = HxOverrides.substr(data,p.pos + p.len,parp - (p.pos + p.len) - 1).split(",");
			tokens.add({ p : haxe.Template.splitter.matched(2), s : false, l : params});
			data = HxOverrides.substr(data,parp,data.length - parp);
		}
		if(data.length > 0) tokens.add({ p : data, s : true, l : null});
		return tokens;
	}
	,resolve: function(v) {
		if(Reflect.hasField(this.context,v)) return Reflect.field(this.context,v);
		var $it0 = this.stack.iterator();
		while( $it0.hasNext() ) {
			var ctx = $it0.next();
			if(Reflect.hasField(ctx,v)) return Reflect.field(ctx,v);
		}
		if(v == "__current__") return this.context;
		return Reflect.field(haxe.Template.globals,v);
	}
	,execute: function(context,macros) {
		this.macros = macros == null?{ }:macros;
		this.context = context;
		this.stack = new List();
		this.buf = new StringBuf();
		this.run(this.expr);
		return this.buf.b;
	}
	,__class__: haxe.Template
}
haxe.Unserializer = function(buf) {
	this.buf = buf;
	this.length = buf.length;
	this.pos = 0;
	this.scache = new Array();
	this.cache = new Array();
	var r = haxe.Unserializer.DEFAULT_RESOLVER;
	if(r == null) {
		r = Type;
		haxe.Unserializer.DEFAULT_RESOLVER = r;
	}
	this.setResolver(r);
};
$hxClasses["haxe.Unserializer"] = haxe.Unserializer;
haxe.Unserializer.__name__ = ["haxe","Unserializer"];
haxe.Unserializer.initCodes = function() {
	var codes = new Array();
	var _g1 = 0, _g = haxe.Unserializer.BASE64.length;
	while(_g1 < _g) {
		var i = _g1++;
		codes[haxe.Unserializer.BASE64.charCodeAt(i)] = i;
	}
	return codes;
}
haxe.Unserializer.run = function(v) {
	return new haxe.Unserializer(v).unserialize();
}
haxe.Unserializer.prototype = {
	unserialize: function() {
		var _g = this.buf.charCodeAt(this.pos++);
		switch(_g) {
		case 110:
			return null;
		case 116:
			return true;
		case 102:
			return false;
		case 122:
			return 0;
		case 105:
			return this.readDigits();
		case 100:
			var p1 = this.pos;
			while(true) {
				var c = this.buf.charCodeAt(this.pos);
				if(c >= 43 && c < 58 || c == 101 || c == 69) this.pos++; else break;
			}
			return Std.parseFloat(HxOverrides.substr(this.buf,p1,this.pos - p1));
		case 121:
			var len = this.readDigits();
			if(this.buf.charCodeAt(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid string length";
			var s = HxOverrides.substr(this.buf,this.pos,len);
			this.pos += len;
			s = StringTools.urlDecode(s);
			this.scache.push(s);
			return s;
		case 107:
			return Math.NaN;
		case 109:
			return Math.NEGATIVE_INFINITY;
		case 112:
			return Math.POSITIVE_INFINITY;
		case 97:
			var buf = this.buf;
			var a = new Array();
			this.cache.push(a);
			while(true) {
				var c = this.buf.charCodeAt(this.pos);
				if(c == 104) {
					this.pos++;
					break;
				}
				if(c == 117) {
					this.pos++;
					var n = this.readDigits();
					a[a.length + n - 1] = null;
				} else a.push(this.unserialize());
			}
			return a;
		case 111:
			var o = { };
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 114:
			var n = this.readDigits();
			if(n < 0 || n >= this.cache.length) throw "Invalid reference";
			return this.cache[n];
		case 82:
			var n = this.readDigits();
			if(n < 0 || n >= this.scache.length) throw "Invalid string reference";
			return this.scache[n];
		case 120:
			throw this.unserialize();
			break;
		case 99:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			this.unserializeObject(o);
			return o;
		case 119:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			var e = this.unserializeEnum(edecl,this.unserialize());
			this.cache.push(e);
			return e;
		case 106:
			var name = this.unserialize();
			var edecl = this.resolver.resolveEnum(name);
			if(edecl == null) throw "Enum not found " + name;
			this.pos++;
			var index = this.readDigits();
			var tag = Type.getEnumConstructs(edecl)[index];
			if(tag == null) throw "Unknown enum index " + name + "@" + index;
			var e = this.unserializeEnum(edecl,tag);
			this.cache.push(e);
			return e;
		case 108:
			var l = new List();
			this.cache.push(l);
			var buf = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) l.add(this.unserialize());
			this.pos++;
			return l;
		case 98:
			var h = new haxe.ds.StringMap();
			this.cache.push(h);
			var buf = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) {
				var s = this.unserialize();
				h.set(s,this.unserialize());
			}
			this.pos++;
			return h;
		case 113:
			var h = new haxe.ds.IntMap();
			this.cache.push(h);
			var buf = this.buf;
			var c = this.buf.charCodeAt(this.pos++);
			while(c == 58) {
				var i = this.readDigits();
				h.set(i,this.unserialize());
				c = this.buf.charCodeAt(this.pos++);
			}
			if(c != 104) throw "Invalid IntMap format";
			return h;
		case 77:
			var h = new haxe.ds.ObjectMap();
			this.cache.push(h);
			var buf = this.buf;
			while(this.buf.charCodeAt(this.pos) != 104) {
				var s = this.unserialize();
				h.set(s,this.unserialize());
			}
			this.pos++;
			return h;
		case 118:
			var d = HxOverrides.strDate(HxOverrides.substr(this.buf,this.pos,19));
			this.cache.push(d);
			this.pos += 19;
			return d;
		case 115:
			var len = this.readDigits();
			var buf = this.buf;
			if(this.buf.charCodeAt(this.pos++) != 58 || this.length - this.pos < len) throw "Invalid bytes length";
			var codes = haxe.Unserializer.CODES;
			if(codes == null) {
				codes = haxe.Unserializer.initCodes();
				haxe.Unserializer.CODES = codes;
			}
			var i = this.pos;
			var rest = len & 3;
			var size = (len >> 2) * 3 + (rest >= 2?rest - 1:0);
			var max = i + (len - rest);
			var bytes = haxe.io.Bytes.alloc(size);
			var bpos = 0;
			while(i < max) {
				var c1 = codes[buf.charCodeAt(i++)];
				var c2 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				var c3 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c2 << 4 | c3 >> 2) & 255;
				var c4 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c3 << 6 | c4) & 255;
			}
			if(rest >= 2) {
				var c1 = codes[buf.charCodeAt(i++)];
				var c2 = codes[buf.charCodeAt(i++)];
				bytes.b[bpos++] = (c1 << 2 | c2 >> 4) & 255;
				if(rest == 3) {
					var c3 = codes[buf.charCodeAt(i++)];
					bytes.b[bpos++] = (c2 << 4 | c3 >> 2) & 255;
				}
			}
			this.pos += len;
			this.cache.push(bytes);
			return bytes;
		case 67:
			var name = this.unserialize();
			var cl = this.resolver.resolveClass(name);
			if(cl == null) throw "Class not found " + name;
			var o = Type.createEmptyInstance(cl);
			this.cache.push(o);
			o.hxUnserialize(this);
			if(this.buf.charCodeAt(this.pos++) != 103) throw "Invalid custom data";
			return o;
		default:
		}
		this.pos--;
		throw "Invalid char " + this.buf.charAt(this.pos) + " at position " + this.pos;
	}
	,unserializeEnum: function(edecl,tag) {
		if(this.buf.charCodeAt(this.pos++) != 58) throw "Invalid enum format";
		var nargs = this.readDigits();
		if(nargs == 0) return Type.createEnum(edecl,tag);
		var args = new Array();
		while(nargs-- > 0) args.push(this.unserialize());
		return Type.createEnum(edecl,tag,args);
	}
	,unserializeObject: function(o) {
		while(true) {
			if(this.pos >= this.length) throw "Invalid object";
			if(this.buf.charCodeAt(this.pos) == 103) break;
			var k = this.unserialize();
			if(!js.Boot.__instanceof(k,String)) throw "Invalid object key";
			var v = this.unserialize();
			o[k] = v;
		}
		this.pos++;
	}
	,readDigits: function() {
		var k = 0;
		var s = false;
		var fpos = this.pos;
		while(true) {
			var c = this.buf.charCodeAt(this.pos);
			if(c != c) break;
			if(c == 45) {
				if(this.pos != fpos) break;
				s = true;
				this.pos++;
				continue;
			}
			if(c < 48 || c > 57) break;
			k = k * 10 + (c - 48);
			this.pos++;
		}
		if(s) k *= -1;
		return k;
	}
	,setResolver: function(r) {
		if(r == null) this.resolver = { resolveClass : function(_) {
			return null;
		}, resolveEnum : function(_) {
			return null;
		}}; else this.resolver = r;
	}
	,__class__: haxe.Unserializer
}
haxe.ds = {}
haxe.ds.IntMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.IntMap"] = haxe.ds.IntMap;
haxe.ds.IntMap.__name__ = ["haxe","ds","IntMap"];
haxe.ds.IntMap.__interfaces__ = [IMap];
haxe.ds.IntMap.prototype = {
	remove: function(key) {
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,exists: function(key) {
		return this.h.hasOwnProperty(key);
	}
	,get: function(key) {
		return this.h[key];
	}
	,set: function(key,value) {
		this.h[key] = value;
	}
	,__class__: haxe.ds.IntMap
}
haxe.ds.ObjectMap = function() {
	this.h = { };
	this.h.__keys__ = { };
};
$hxClasses["haxe.ds.ObjectMap"] = haxe.ds.ObjectMap;
haxe.ds.ObjectMap.__name__ = ["haxe","ds","ObjectMap"];
haxe.ds.ObjectMap.__interfaces__ = [IMap];
haxe.ds.ObjectMap.prototype = {
	set: function(key,value) {
		var id = key.__id__ != null?key.__id__:key.__id__ = ++haxe.ds.ObjectMap.count;
		this.h[id] = value;
		this.h.__keys__[id] = key;
	}
	,__class__: haxe.ds.ObjectMap
}
haxe.ds.StringMap = function() {
	this.h = { };
};
$hxClasses["haxe.ds.StringMap"] = haxe.ds.StringMap;
haxe.ds.StringMap.__name__ = ["haxe","ds","StringMap"];
haxe.ds.StringMap.__interfaces__ = [IMap];
haxe.ds.StringMap.prototype = {
	keys: function() {
		var a = [];
		for( var key in this.h ) {
		if(this.h.hasOwnProperty(key)) a.push(key.substr(1));
		}
		return HxOverrides.iter(a);
	}
	,remove: function(key) {
		key = "$" + key;
		if(!this.h.hasOwnProperty(key)) return false;
		delete(this.h[key]);
		return true;
	}
	,exists: function(key) {
		return this.h.hasOwnProperty("$" + key);
	}
	,get: function(key) {
		return this.h["$" + key];
	}
	,set: function(key,value) {
		this.h["$" + key] = value;
	}
	,__class__: haxe.ds.StringMap
}
haxe.io = {}
haxe.io.Bytes = function(length,b) {
	this.length = length;
	this.b = b;
};
$hxClasses["haxe.io.Bytes"] = haxe.io.Bytes;
haxe.io.Bytes.__name__ = ["haxe","io","Bytes"];
haxe.io.Bytes.alloc = function(length) {
	var a = new Array();
	var _g = 0;
	while(_g < length) {
		var i = _g++;
		a.push(0);
	}
	return new haxe.io.Bytes(length,a);
}
haxe.io.Bytes.prototype = {
	toString: function() {
		return this.readString(0,this.length);
	}
	,readString: function(pos,len) {
		if(pos < 0 || len < 0 || pos + len > this.length) throw haxe.io.Error.OutsideBounds;
		var s = "";
		var b = this.b;
		var fcc = String.fromCharCode;
		var i = pos;
		var max = pos + len;
		while(i < max) {
			var c = b[i++];
			if(c < 128) {
				if(c == 0) break;
				s += fcc(c);
			} else if(c < 224) s += fcc((c & 63) << 6 | b[i++] & 127); else if(c < 240) {
				var c2 = b[i++];
				s += fcc((c & 31) << 12 | (c2 & 127) << 6 | b[i++] & 127);
			} else {
				var c2 = b[i++];
				var c3 = b[i++];
				s += fcc((c & 15) << 18 | (c2 & 127) << 12 | c3 << 6 & 127 | b[i++] & 127);
			}
		}
		return s;
	}
	,__class__: haxe.io.Bytes
}
haxe.io.Eof = function() { }
$hxClasses["haxe.io.Eof"] = haxe.io.Eof;
haxe.io.Eof.__name__ = ["haxe","io","Eof"];
haxe.io.Eof.prototype = {
	toString: function() {
		return "Eof";
	}
	,__class__: haxe.io.Eof
}
haxe.io.Error = $hxClasses["haxe.io.Error"] = { __ename__ : true, __constructs__ : ["Blocked","Overflow","OutsideBounds","Custom"] }
haxe.io.Error.Blocked = ["Blocked",0];
haxe.io.Error.Blocked.toString = $estr;
haxe.io.Error.Blocked.__enum__ = haxe.io.Error;
haxe.io.Error.Overflow = ["Overflow",1];
haxe.io.Error.Overflow.toString = $estr;
haxe.io.Error.Overflow.__enum__ = haxe.io.Error;
haxe.io.Error.OutsideBounds = ["OutsideBounds",2];
haxe.io.Error.OutsideBounds.toString = $estr;
haxe.io.Error.OutsideBounds.__enum__ = haxe.io.Error;
haxe.io.Error.Custom = function(e) { var $x = ["Custom",3,e]; $x.__enum__ = haxe.io.Error; $x.toString = $estr; return $x; }
var js = {}
js.Boot = function() { }
$hxClasses["js.Boot"] = js.Boot;
js.Boot.__name__ = ["js","Boot"];
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ || o.__ename__)) t = "object";
	switch(t) {
	case "object":
		if(o instanceof Array) {
			if(o.__enum__) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				var _g1 = 2, _g = o.length;
				while(_g1 < _g) {
					var i = _g1++;
					if(i != 2) str += "," + js.Boot.__string_rec(o[i],s); else str += js.Boot.__string_rec(o[i],s);
				}
				return str + ")";
			}
			var l = o.length;
			var i;
			var str = "[";
			s += "\t";
			var _g = 0;
			while(_g < l) {
				var i1 = _g++;
				str += (i1 > 0?",":"") + js.Boot.__string_rec(o[i1],s);
			}
			str += "]";
			return str;
		}
		var tostr;
		try {
			tostr = o.toString;
		} catch( e ) {
			return "???";
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = o.hasOwnProperty != null;
		for( var k in o ) { ;
		if(hasp && !o.hasOwnProperty(k)) {
			continue;
		}
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__" || k == "__properties__") {
			continue;
		}
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	case "function":
		return "<function>";
	case "string":
		return o;
	default:
		return String(o);
	}
}
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0, _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
}
js.Boot.__instanceof = function(o,cl) {
	if(cl == null) return false;
	switch(cl) {
	case Int:
		return (o|0) === o;
	case Float:
		return typeof(o) == "number";
	case Bool:
		return typeof(o) == "boolean";
	case String:
		return typeof(o) == "string";
	case Dynamic:
		return true;
	default:
		if(o != null) {
			if(typeof(cl) == "function") {
				if(o instanceof cl) {
					if(cl == Array) return o.__enum__ == null;
					return true;
				}
				if(js.Boot.__interfLoop(o.__class__,cl)) return true;
			}
		} else return false;
		if(cl == Class && o.__name__ != null) return true;
		if(cl == Enum && o.__ename__ != null) return true;
		return o.__enum__ == cl;
	}
}
js.Boot.__cast = function(o,t) {
	if(js.Boot.__instanceof(o,t)) return o; else throw "Cannot cast " + Std.string(o) + " to " + Std.string(t);
}
js.Browser = function() { }
$hxClasses["js.Browser"] = js.Browser;
js.Browser.__name__ = ["js","Browser"];
openfl.AssetCache = function() {
	this.enabled = true;
	this.bitmapData = new haxe.ds.StringMap();
	this.font = new haxe.ds.StringMap();
	this.sound = new haxe.ds.StringMap();
};
$hxClasses["openfl.AssetCache"] = openfl.AssetCache;
openfl.AssetCache.__name__ = ["openfl","AssetCache"];
openfl.AssetCache.prototype = {
	clear: function() {
		this.bitmapData = new haxe.ds.StringMap();
		this.font = new haxe.ds.StringMap();
		this.sound = new haxe.ds.StringMap();
	}
	,__class__: openfl.AssetCache
}
openfl.Assets = function() { }
$hxClasses["openfl.Assets"] = openfl.Assets;
openfl.Assets.__name__ = ["openfl","Assets"];
openfl.Assets.exists = function(id,type) {
	openfl.Assets.initialize();
	if(type == null) type = openfl.AssetType.BINARY;
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) return library.exists(symbolName,type);
	return false;
}
openfl.Assets.getBitmapData = function(id,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.bitmapData.exists(id)) {
		var bitmapData = openfl.Assets.cache.bitmapData.get(id);
		if(openfl.Assets.isValidBitmapData(bitmapData)) return bitmapData;
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.IMAGE)) {
			if(library.isLocal(symbolName,openfl.AssetType.IMAGE)) {
				var bitmapData = library.getBitmapData(symbolName);
				if(useCache && openfl.Assets.cache.enabled) openfl.Assets.cache.bitmapData.set(id,bitmapData);
				return bitmapData;
			} else console.log("[openfl.Assets] BitmapData asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no BitmapData asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getBytes = function(id) {
	openfl.Assets.initialize();
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.BINARY)) {
			if(library.isLocal(symbolName,openfl.AssetType.BINARY)) return library.getBytes(symbolName); else console.log("[openfl.Assets] String or ByteArray asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no String or ByteArray asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getFont = function(id,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.font.exists(id)) return openfl.Assets.cache.font.get(id);
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.FONT)) {
			if(library.isLocal(symbolName,openfl.AssetType.FONT)) {
				var font = library.getFont(symbolName);
				if(useCache && openfl.Assets.cache.enabled) openfl.Assets.cache.font.set(id,font);
				return font;
			} else console.log("[openfl.Assets] Font asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no Font asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getLibrary = function(name) {
	if(name == null || name == "") name = "default";
	return openfl.Assets.libraries.get(name);
}
openfl.Assets.getMovieClip = function(id) {
	openfl.Assets.initialize();
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.MOVIE_CLIP)) {
			if(library.isLocal(symbolName,openfl.AssetType.MOVIE_CLIP)) return library.getMovieClip(symbolName); else console.log("[openfl.Assets] MovieClip asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no MovieClip asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getMusic = function(id,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.sound.exists(id)) {
		var sound = openfl.Assets.cache.sound.get(id);
		if(openfl.Assets.isValidSound(sound)) return sound;
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.MUSIC)) {
			if(library.isLocal(symbolName,openfl.AssetType.MUSIC)) {
				var sound = library.getMusic(symbolName);
				if(useCache && openfl.Assets.cache.enabled) openfl.Assets.cache.sound.set(id,sound);
				return sound;
			} else console.log("[openfl.Assets] Sound asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no Sound asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getPath = function(id) {
	openfl.Assets.initialize();
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,null)) return library.getPath(symbolName); else console.log("[openfl.Assets] There is no asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getSound = function(id,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.sound.exists(id)) {
		var sound = openfl.Assets.cache.sound.get(id);
		if(openfl.Assets.isValidSound(sound)) return sound;
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.SOUND)) {
			if(library.isLocal(symbolName,openfl.AssetType.SOUND)) {
				var sound = library.getSound(symbolName);
				if(useCache && openfl.Assets.cache.enabled) openfl.Assets.cache.sound.set(id,sound);
				return sound;
			} else console.log("[openfl.Assets] Sound asset \"" + id + "\" exists, but only asynchronously");
		} else console.log("[openfl.Assets] There is no Sound asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	return null;
}
openfl.Assets.getText = function(id) {
	var bytes = openfl.Assets.getBytes(id);
	if(bytes == null) return null; else return bytes.readUTFBytes(bytes.length);
}
openfl.Assets.initialize = function() {
	if(!openfl.Assets.initialized) {
		openfl.Assets.registerLibrary("default",new DefaultAssetLibrary());
		openfl.Assets.initialized = true;
	}
}
openfl.Assets.isLocal = function(id,type,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled) {
		if(type == openfl.AssetType.IMAGE || type == null) {
			if(openfl.Assets.cache.bitmapData.exists(id)) return true;
		}
		if(type == openfl.AssetType.FONT || type == null) {
			if(openfl.Assets.cache.font.exists(id)) return true;
		}
		if(type == openfl.AssetType.SOUND || type == openfl.AssetType.MUSIC || type == null) {
			if(openfl.Assets.cache.sound.exists(id)) return true;
		}
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) return library.isLocal(symbolName,type);
	return false;
}
openfl.Assets.isValidBitmapData = function(bitmapData) {
	return true;
}
openfl.Assets.isValidSound = function(sound) {
	return true;
}
openfl.Assets.loadBitmapData = function(id,handler,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.bitmapData.exists(id)) {
		var bitmapData = openfl.Assets.cache.bitmapData.get(id);
		if(openfl.Assets.isValidBitmapData(bitmapData)) {
			handler(bitmapData);
			return;
		}
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.IMAGE)) {
			if(useCache && openfl.Assets.cache.enabled) library.loadBitmapData(symbolName,function(bitmapData) {
				openfl.Assets.cache.bitmapData.set(id,bitmapData);
				handler(bitmapData);
			}); else library.loadBitmapData(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no BitmapData asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadBytes = function(id,handler) {
	openfl.Assets.initialize();
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.BINARY)) {
			library.loadBytes(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no String or ByteArray asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadFont = function(id,handler,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.font.exists(id)) {
		handler(openfl.Assets.cache.font.get(id));
		return;
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.FONT)) {
			if(useCache && openfl.Assets.cache.enabled) library.loadFont(symbolName,function(font) {
				openfl.Assets.cache.font.set(id,font);
				handler(font);
			}); else library.loadFont(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no Font asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadLibrary = function(name,handler) {
	openfl.Assets.initialize();
	var data = openfl.Assets.getText("libraries/" + name + ".dat");
	if(data != null && data != "") {
		var unserializer = new haxe.Unserializer(data);
		unserializer.setResolver({ resolveEnum : openfl.Assets.resolveEnum, resolveClass : openfl.Assets.resolveClass});
		var library = unserializer.unserialize();
		openfl.Assets.libraries.set(name,library);
		library.load(handler);
	} else console.log("[openfl.Assets] There is no asset library named \"" + name + "\"");
}
openfl.Assets.loadMusic = function(id,handler,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.sound.exists(id)) {
		var sound = openfl.Assets.cache.sound.get(id);
		if(openfl.Assets.isValidSound(sound)) {
			handler(sound);
			return;
		}
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.MUSIC)) {
			if(useCache && openfl.Assets.cache.enabled) library.loadMusic(symbolName,function(sound) {
				openfl.Assets.cache.sound.set(id,sound);
				handler(sound);
			}); else library.loadMusic(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no Sound asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadMovieClip = function(id,handler) {
	openfl.Assets.initialize();
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.MOVIE_CLIP)) {
			library.loadMovieClip(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no MovieClip asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadSound = function(id,handler,useCache) {
	if(useCache == null) useCache = true;
	openfl.Assets.initialize();
	if(useCache && openfl.Assets.cache.enabled && openfl.Assets.cache.sound.exists(id)) {
		var sound = openfl.Assets.cache.sound.get(id);
		if(openfl.Assets.isValidSound(sound)) {
			handler(sound);
			return;
		}
	}
	var libraryName = id.substring(0,id.indexOf(":"));
	var symbolName = HxOverrides.substr(id,id.indexOf(":") + 1,null);
	var library = openfl.Assets.getLibrary(libraryName);
	if(library != null) {
		if(library.exists(symbolName,openfl.AssetType.SOUND)) {
			if(useCache && openfl.Assets.cache.enabled) library.loadSound(symbolName,function(sound) {
				openfl.Assets.cache.sound.set(id,sound);
				handler(sound);
			}); else library.loadSound(symbolName,handler);
			return;
		} else console.log("[openfl.Assets] There is no Sound asset with an ID of \"" + id + "\"");
	} else console.log("[openfl.Assets] There is no asset library named \"" + libraryName + "\"");
	handler(null);
}
openfl.Assets.loadText = function(id,handler) {
	openfl.Assets.initialize();
	var callback = function(bytes) {
		if(bytes == null) handler(null); else handler(bytes.readUTFBytes(bytes.length));
	};
	openfl.Assets.loadBytes(id,callback);
}
openfl.Assets.registerLibrary = function(name,library) {
	if(openfl.Assets.libraries.exists(name)) openfl.Assets.unloadLibrary(name);
	openfl.Assets.libraries.set(name,library);
}
openfl.Assets.resolveClass = function(name) {
	return Type.resolveClass(name);
}
openfl.Assets.resolveEnum = function(name) {
	var value = Type.resolveEnum(name);
	return value;
}
openfl.Assets.unloadLibrary = function(name) {
	openfl.Assets.initialize();
	var keys = openfl.Assets.cache.bitmapData.keys();
	while( keys.hasNext() ) {
		var key = keys.next();
		var libraryName = key.substring(0,key.indexOf(":"));
		var symbolName = HxOverrides.substr(key,key.indexOf(":") + 1,null);
		if(libraryName == name) openfl.Assets.cache.bitmapData.remove(key);
	}
	openfl.Assets.libraries.remove(name);
}
openfl.AssetData = function() {
};
$hxClasses["openfl.AssetData"] = openfl.AssetData;
openfl.AssetData.__name__ = ["openfl","AssetData"];
openfl.AssetData.prototype = {
	__class__: openfl.AssetData
}
openfl.AssetType = $hxClasses["openfl.AssetType"] = { __ename__ : true, __constructs__ : ["BINARY","FONT","IMAGE","MOVIE_CLIP","MUSIC","SOUND","TEMPLATE","TEXT"] }
openfl.AssetType.BINARY = ["BINARY",0];
openfl.AssetType.BINARY.toString = $estr;
openfl.AssetType.BINARY.__enum__ = openfl.AssetType;
openfl.AssetType.FONT = ["FONT",1];
openfl.AssetType.FONT.toString = $estr;
openfl.AssetType.FONT.__enum__ = openfl.AssetType;
openfl.AssetType.IMAGE = ["IMAGE",2];
openfl.AssetType.IMAGE.toString = $estr;
openfl.AssetType.IMAGE.__enum__ = openfl.AssetType;
openfl.AssetType.MOVIE_CLIP = ["MOVIE_CLIP",3];
openfl.AssetType.MOVIE_CLIP.toString = $estr;
openfl.AssetType.MOVIE_CLIP.__enum__ = openfl.AssetType;
openfl.AssetType.MUSIC = ["MUSIC",4];
openfl.AssetType.MUSIC.toString = $estr;
openfl.AssetType.MUSIC.__enum__ = openfl.AssetType;
openfl.AssetType.SOUND = ["SOUND",5];
openfl.AssetType.SOUND.toString = $estr;
openfl.AssetType.SOUND.__enum__ = openfl.AssetType;
openfl.AssetType.TEMPLATE = ["TEMPLATE",6];
openfl.AssetType.TEMPLATE.toString = $estr;
openfl.AssetType.TEMPLATE.__enum__ = openfl.AssetType;
openfl.AssetType.TEXT = ["TEXT",7];
openfl.AssetType.TEXT.toString = $estr;
openfl.AssetType.TEXT.__enum__ = openfl.AssetType;
openfl.display = {}
openfl.display.Tilesheet = function(image) {
	this.__bitmap = image;
	this.__centerPoints = new Array();
	this.__tileRects = new Array();
	this.__tileUVs = new Array();
};
$hxClasses["openfl.display.Tilesheet"] = openfl.display.Tilesheet;
openfl.display.Tilesheet.__name__ = ["openfl","display","Tilesheet"];
openfl.display.Tilesheet.prototype = {
	getTileUVs: function(index) {
		return this.__tileUVs[index];
	}
	,getTileRect: function(index) {
		return this.__tileRects[index];
	}
	,getTileCenter: function(index) {
		return this.__centerPoints[index];
	}
	,drawTiles: function(graphics,tileData,smooth,flags) {
		if(flags == null) flags = 0;
		if(smooth == null) smooth = false;
		graphics.drawTiles(this,tileData,smooth,flags);
	}
	,addTileRect: function(rectangle,centerPoint) {
		this.__tileRects.push(rectangle);
		if(centerPoint == null) centerPoint = new flash.geom.Point();
		this.__centerPoints.push(centerPoint);
		this.__tileUVs.push(new flash.geom.Rectangle(rectangle.get_left() / this.__bitmap.get_width(),rectangle.get_top() / this.__bitmap.get_height(),rectangle.get_right() / this.__bitmap.get_width(),rectangle.get_bottom() / this.__bitmap.get_height()));
		return this.__tileRects.length - 1;
	}
	,__class__: openfl.display.Tilesheet
}
var tardis = {}
tardis.Deep = function() { }
$hxClasses["tardis.Deep"] = tardis.Deep;
tardis.Deep.__name__ = ["tardis","Deep"];
tardis.Deep.copy = function(v) {
	if(!Reflect.isObject(v)) return v; else if(js.Boot.__instanceof(v,String)) return v; else if(js.Boot.__instanceof(v,tardis.Pointer)) return tardis.Pointer.copy(v); else if(js.Boot.__instanceof(v,tardis.Closure)) return v; else if(js.Boot.__instanceof(v,Array)) {
		var result = Type.createInstance(Type.getClass(v),[]);
		var _g1 = 0, _g = v.length;
		while(_g1 < _g) {
			var ii = _g1++;
			result.push(tardis.Deep.copy(v[ii]));
		}
		return result;
	} else if(js.Boot.__instanceof(v,_Map.Map_Impl_)) {
		var result = Type.createInstance(Type.getClass(v),[]);
		var keys = v.keys();
		while( keys.hasNext() ) {
			var key = keys.next();
			result.set(key,tardis.Deep.copy(v.get(key)));
		}
		return result;
	} else if(js.Boot.__instanceof(v,List)) {
		var result = Type.createInstance(Type.getClass(v),[]);
		var iter = $iterator(v)();
		while( iter.hasNext() ) {
			var ii = iter.next();
			result.add(ii);
		}
		return result;
	} else if(Type.getClass(v) == null) {
		var obj = { };
		var _g = 0, _g1 = Reflect.fields(v);
		while(_g < _g1.length) {
			var ff = _g1[_g];
			++_g;
			obj[ff] = tardis.Deep.copy(Reflect.field(v,ff));
		}
		return obj;
	} else {
		var obj = Type.createEmptyInstance(Type.getClass(v));
		var _g = 0, _g1 = Reflect.fields(v);
		while(_g < _g1.length) {
			var ff = _g1[_g];
			++_g;
			obj[ff] = tardis.Deep.copy(Reflect.field(v,ff));
		}
		return obj;
	}
}
tardis.Force = function() { }
$hxClasses["tardis.Force"] = tardis.Force;
tardis.Force.__name__ = ["tardis","Force"];
tardis.Force.toUint8 = function(v) {
	return v & 255;
}
tardis.Force.toUint16 = function(v) {
	return v & 65535;
}
tardis.Force.toUint32 = function(v) {
	return v & 0xffffffff;
}
tardis.Force.toUint64 = function(v) {
	return v;
}
tardis.Force.toInt8 = function(v) {
	var r = v & 255;
	if((r & 128) != 0) return -256 + r;
	return r;
}
tardis.Force.toInt16 = function(v) {
	var r = v & 65535;
	if((r & 32768) != 0) return -65536 + r;
	return r;
}
tardis.Force.toInt32 = function(v) {
	var int32_mostNeg = -2147483648;
	var r = v & 0x7FFFFFFF;
	if((v & 0x80000000) != 0) return int32_mostNeg + r;
	return r;
}
tardis.Force.toInt64 = function(v) {
	return v;
}
tardis.Force.toInt = function(v) {
	if(!Reflect.isObject(v)) return v; else if(js.Boot.__instanceof(v,tardis.Interface)) {
		v = v.val;
		if(!Reflect.isObject(v)) return v; else return (function($this) {
			var $r;
			var v1 = v;
			$r = tardis.Int64.getLow(v1);
			return $r;
		}(this));
	} else return (function($this) {
		var $r;
		var v1 = v;
		$r = tardis.Int64.getLow(v1);
		return $r;
	}(this));
}
tardis.Force.toFloat = function(v) {
	return v;
}
tardis.Force.uintCompare = function(x,y) {
	if(x == y) return 0;
	if(x >= 0) {
		if(y >= 0) return x - y; else return -1;
	} else if(y >= 0) return 1; else return x - y;
}
tardis.Force.checkIntDiv = function(x,y,byts) {
	var r = y;
	switch(y) {
	case 0:
		tardis.Scheduler.panicFromHaxe("attempt to divide integer value by 0");
		break;
	case -1:
		switch(byts) {
		case 1:
			if(x == -128) r = 1;
			break;
		case 2:
			if(x == -32768) r = 1;
			break;
		case 4:
			if(x == -2147483648) r = 1;
			break;
		default:
		}
		break;
	}
	return r;
}
tardis.Force.intDiv = function(x,y,sv) {
	y = tardis.Force.checkIntDiv(x,y,sv);
	if(y == 1) return x;
	var f = x / y;
	return f >= 0?Math.floor(f):Math.ceil(f);
}
tardis.Force.intMod = function(x,y,sv) {
	y = tardis.Force.checkIntDiv(x,y,sv);
	if(y == 1) return 0;
	return x % y;
}
tardis.Force.floatDiv = function(x,y) {
	if(y == 0.0) tardis.Scheduler.panicFromHaxe("attempt to divide float value by 0");
	return x / y;
}
tardis.Force.floatMod = function(x,y) {
	if(y == 0.0) tardis.Scheduler.panicFromHaxe("attempt to modulo float value by 0");
	return x % y;
}
tardis.Force.toUTF8length = function(gr,s) {
	return "字".length == 3?s.length:tardis.Force.toUTF8slice(gr,s).len();
}
tardis.Force.toUTF8slice = function(gr,s) {
	var a = new Array();
	var mask = 255;
	if("字".length == 1) mask = 65535;
	var _g1 = 0, _g = s.length;
	while(_g1 < _g) {
		var i = _g1++;
		var t = HxOverrides.cca(s,i);
		if(t == null) tardis.Scheduler.panicFromHaxe("Haxe runtime Force.toUTF8slice() unexpected null encountered"); else a[i] = js.Boot.__cast(t , Int) & mask;
	}
	var sl = new tardis.Slice(new tardis.Pointer(a),0,-1);
	if("字".length == 3) return sl;
	var v1 = tardis.Go_haxegoruntime_UTF16toRunes.callFromRT(gr,sl);
	return tardis.Go_haxegoruntime_RunesToUTF8.callFromRT(gr,v1);
}
tardis.Force.toRawString = function(gr,sl) {
	var ret = "";
	var mask = 255;
	if("字".length == 1) {
		var v1 = tardis.Go_haxegoruntime_UTF8toRunes.callFromRT(gr,sl);
		sl = tardis.Go_haxegoruntime_RunesToUTF16.callFromRT(gr,v1);
		mask = 65535;
	}
	var _g1 = 0, _g = sl.end - sl.start;
	while(_g1 < _g) {
		var i = _g1++;
		ret += String.fromCharCode(sl.getAt(i) & mask);
	}
	return ret;
}
tardis.Pointer = function(from) {
	this.heapObj = from;
	this.offs = new Array();
};
$hxClasses["tardis.Pointer"] = tardis.Pointer;
tardis.Pointer.__name__ = ["tardis","Pointer"];
tardis.Pointer.copy = function(v) {
	var r = new tardis.Pointer(v.heapObj);
	r.offs = v.offs.slice();
	return r;
}
tardis.Pointer.prototype = {
	len: function() {
		return this.ref().length;
	}
	,addr: function(off) {
		if(off < 0 || off >= this.ref().length) tardis.Scheduler.panicFromHaxe("index out of range for valid pointer address");
		var ret = new tardis.Pointer(this.heapObj);
		ret.offs = this.offs.slice();
		ret.offs[this.offs.length] = off;
		return ret;
	}
	,store: function(v) {
		if(this.offs == null) this.offs = [];
		var _g = this;
		switch(_g.offs.length) {
		case 0:
			this.heapObj = v;
			break;
		case 1:
			this.heapObj[this.offs[0]] = v;
			break;
		default:
			var a = this.heapObj;
			var _g2 = 0, _g1 = this.offs.length - 1;
			while(_g2 < _g1) {
				var i = _g2++;
				a = a[this.offs[i]];
			}
			a[this.offs[this.offs.length - 1]] = v;
		}
	}
	,ref: function() {
		var ret = this.heapObj;
		var _g1 = 0, _g = this.offs.length;
		while(_g1 < _g) {
			var i = _g1++;
			ret = ret[this.offs[i]];
		}
		return ret;
	}
	,load: function() {
		return this.ref();
	}
	,__class__: tardis.Pointer
}
tardis.UnsafePointer = function(x) {
	tardis.Pointer.call(this,x);
};
$hxClasses["tardis.UnsafePointer"] = tardis.UnsafePointer;
tardis.UnsafePointer.__name__ = ["tardis","UnsafePointer"];
tardis.UnsafePointer.__super__ = tardis.Pointer;
tardis.UnsafePointer.prototype = $extend(tardis.Pointer.prototype,{
	__class__: tardis.UnsafePointer
});
tardis.Slice = function(fromArray,low,high) {
	this.baseArray = fromArray;
	if(this.baseArray == null) {
		this.start = 0;
		this.end = 0;
	} else {
		if(high == -1) high = this.baseArray.ref().length;
		if(low < 0) tardis.Scheduler.panicFromHaxe("new Slice() low bound -ve");
		if(high > this.baseArray.ref().length) tardis.Scheduler.panicFromHaxe("new Slice() high bound exceeds underlying array length");
		if(low > high) tardis.Scheduler.panicFromHaxe("new Slice() low bound exceeds high bound");
		this.start = low;
		this.end = high;
	}
};
$hxClasses["tardis.Slice"] = tardis.Slice;
tardis.Slice.__name__ = ["tardis","Slice"];
tardis.Slice.prototype = {
	toString: function() {
		var ret = "Slice{" + this.start + "," + this.end + ",[";
		if(this.baseArray != null) {
			var _g1 = 0, _g = this.baseArray.ref().length;
			while(_g1 < _g) {
				var i = _g1++;
				if(i != 0) ret += ",";
				ret += this.baseArray.ref()[i];
			}
		}
		return ret + "]}";
	}
	,addr: function(dynIdx) {
		var idx = tardis.Force.toInt(dynIdx);
		if(idx < 0 || idx >= this.end - this.start) tardis.Scheduler.panicFromHaxe("Slice index out of range for addr()");
		if(this.baseArray == null) tardis.Scheduler.panicFromHaxe("Slice base array is null");
		return this.baseArray.addr(idx + this.start);
	}
	,cap: function() {
		if(this.baseArray == null) return 0;
		return js.Boot.__cast(this.baseArray.ref().length , Int) - this.start;
	}
	,len: function() {
		return this.end - this.start;
	}
	,setAt: function(dynIdx,v) {
		var idx = tardis.Force.toInt(dynIdx);
		if(idx < 0 || idx >= this.end - this.start) tardis.Scheduler.panicFromHaxe("Slice index out of range for setAt()");
		if(this.baseArray == null) tardis.Scheduler.panicFromHaxe("Slice base array is null");
		this.baseArray.ref()[idx + this.start] = v;
	}
	,getAt: function(dynIdx) {
		var idx = tardis.Force.toInt(dynIdx);
		if(idx < 0 || idx >= this.end - this.start) tardis.Scheduler.panicFromHaxe("Slice index out of range for getAt()");
		if(this.baseArray == null) tardis.Scheduler.panicFromHaxe("Slice base array is null");
		return this.baseArray.ref()[idx + this.start];
	}
	,subSlice: function(low,high) {
		if(high == -1) high = this.end - this.start;
		return new tardis.Slice(this.baseArray,low + this.start,high + this.start);
	}
	,__class__: tardis.Slice
}
tardis.Closure = function(f,b) {
	if(js.Boot.__instanceof(f,tardis.Closure)) {
		if(!Reflect.isFunction(f.fn)) tardis.Scheduler.panicFromHaxe("invalid function reference passed to make Closure(): " + Std.string(f.fn));
		this.fn = f.fn;
	} else {
		if(!Reflect.isFunction(f)) tardis.Scheduler.panicFromHaxe("invalid function reference passed to make Closure(): " + Std.string(f));
		this.fn = f;
	}
	if(this.fn == null) tardis.Scheduler.panicFromHaxe("new Closure() function has become null!");
	this.bds = b;
};
$hxClasses["tardis.Closure"] = tardis.Closure;
tardis.Closure.__name__ = ["tardis","Closure"];
tardis.Closure.prototype = {
	callFn: function(params) {
		if(this.fn == null) tardis.Scheduler.panicFromHaxe("attempt to call null function reference in Closure()");
		if(!Reflect.isFunction(this.fn)) tardis.Scheduler.panicFromHaxe("invalid function reference in Closure(): " + Std.string(this.fn));
		return this.fn.apply(null,params);
	}
	,methVal: function(t,v) {
		var tmp = tardis.Deep.copy(t);
		return this.fn.apply(null,[[],tmp,v]);
	}
	,toString: function() {
		var ret = "Closure{" + Std.string(this.fn) + ",[";
		var _g1 = 0, _g = this.bds.length;
		while(_g1 < _g) {
			var i = _g1++;
			if(i != 0) ret += ",";
			ret += this.bds[i];
		}
		return ret + "]}";
	}
	,__class__: tardis.Closure
}
tardis.Interface = function(t,v) {
	this.typ = t;
	this.val = tardis.Deep.copy(v);
};
$hxClasses["tardis.Interface"] = tardis.Interface;
tardis.Interface.__name__ = ["tardis","Interface"];
tardis.Interface.change = function(t,i) {
	if(i == null) {
		if(tardis.TypeInfo.isConcrete(t)) return new tardis.Interface(t,tardis.TypeInfo.zeroValue(t)); else {
			tardis.Scheduler.panicFromHaxe("can't change the Interface of a nil value to Interface type: " + tardis.TypeInfo.getName(t));
			return new tardis.Interface(t,tardis.TypeInfo.zeroValue(t));
		}
	} else if(js.Boot.__instanceof(i,tardis.Interface)) {
		if(tardis.TypeInfo.isConcrete(t)) return new tardis.Interface(t,tardis.Deep.copy(i.val)); else return new tardis.Interface(i.typ,tardis.Deep.copy(i.val));
	} else {
		tardis.Scheduler.panicFromHaxe("Can't change the Interface of a non-Interface type:" + Std.string(i) + " to: " + tardis.TypeInfo.getName(t));
		return new tardis.Interface(t,tardis.TypeInfo.zeroValue(t));
	}
}
tardis.Interface.isEqual = function(a,b) {
	if(a == null) {
		if(b == null) return true; else return false;
	}
	if(b == null) return false;
	if(!(tardis.TypeInfo.isIdentical(a.typ,b.typ) || tardis.TypeInfo.isAssignableTo(a.typ,b.typ) || tardis.TypeInfo.isAssignableTo(b.typ,a.typ))) return false; else if(a.val == b.val) return true; else if(js.Boot.__instanceof(a.val,tardis.Pointer) && js.Boot.__instanceof(b.val,tardis.Pointer)) return a.val.load() == b.val.load(); else return false;
}
tardis.Interface.assert = function(assTyp,ifce) {
	if(ifce == null) tardis.Scheduler.panicFromHaxe("Interface.assert null Interface");
	if(!(tardis.TypeInfo.isAssignableTo(ifce.typ,assTyp) || tardis.TypeInfo.isIdentical(assTyp,ifce.typ))) tardis.Scheduler.panicFromHaxe("type assert failed: expected " + tardis.TypeInfo.getName(assTyp) + ", got " + tardis.TypeInfo.getName(ifce.typ));
	if(tardis.TypeInfo.isConcrete(assTyp)) return tardis.Deep.copy(ifce.val); else return new tardis.Interface(ifce.typ,ifce.val);
}
tardis.Interface.assertOk = function(assTyp,ifce) {
	if(ifce == null) return { r0 : tardis.TypeInfo.zeroValue(assTyp), r1 : false};
	if(!(tardis.TypeInfo.isAssignableTo(ifce.typ,assTyp) || tardis.TypeInfo.isIdentical(assTyp,ifce.typ))) return { r0 : tardis.TypeInfo.zeroValue(assTyp), r1 : false};
	if(tardis.TypeInfo.isConcrete(assTyp)) return { r0 : tardis.Deep.copy(ifce.val), r1 : true}; else return { r0 : new tardis.Interface(ifce.typ,ifce.val), r1 : true};
}
tardis.Interface.invoke = function(ifce,meth,args) {
	if(ifce == null) tardis.Scheduler.panicFromHaxe("Interface.invoke null Interface");
	if(!js.Boot.__instanceof(ifce,tardis.Interface)) tardis.Scheduler.panicFromHaxe("Interface.invoke on non-Interface value");
	var fn = tardis.TypeInfo.method(ifce.typ,meth);
	return fn.apply(null,args);
}
tardis.Interface.prototype = {
	toString: function() {
		if(this.val == null) return "Interface{null:" + tardis.TypeInfo.getName(this.typ) + "}"; else return "Interface{" + Std.string(this.val) + ":" + tardis.TypeInfo.getName(this.typ) + "}";
	}
	,__class__: tardis.Interface
}
tardis.Channel = function(how_many_entries) {
	if(how_many_entries <= 0) how_many_entries = 1;
	this.entries = new Array();
	this.max_entries = how_many_entries;
	this.oldest_entry = 0;
	this.num_entries = 0;
	this.closed = false;
};
$hxClasses["tardis.Channel"] = tardis.Channel;
tardis.Channel.__name__ = ["tardis","Channel"];
tardis.Channel.prototype = {
	close: function() {
		this.closed = true;
	}
	,cap: function() {
		return this.max_entries;
	}
	,len: function() {
		return this.num_entries;
	}
	,receive: function(zero) {
		var ret = zero;
		if(this.num_entries > 0) {
			ret = this.entries[this.oldest_entry];
			this.oldest_entry = (this.oldest_entry + 1) % this.max_entries;
			this.num_entries--;
			return { r0 : ret, r1 : true};
		} else if(this.closed) return { r0 : ret, r1 : false}; else {
			tardis.Scheduler.panicFromHaxe("channel receive unreachable code!");
			return { r0 : ret, r1 : false};
		}
	}
	,hasContents: function() {
		if(this.closed) return true;
		return this.num_entries != 0;
	}
	,hasNoContents: function() {
		if(this.closed) return false; else return this.num_entries == 0;
	}
	,send: function(source) {
		if(this.closed) tardis.Scheduler.panicFromHaxe("attempt to send to closed channel");
		var next_element;
		if(this.hasSpace()) {
			next_element = (this.oldest_entry + this.num_entries) % this.max_entries;
			this.num_entries++;
			this.entries[next_element] = tardis.Deep.copy(source);
			return true;
		} else return false;
	}
	,hasSpace: function() {
		if(this.closed) return false;
		return this.num_entries < this.max_entries;
	}
	,__class__: tardis.Channel
}
tardis.Complex = function(r,i) {
	this.real = r;
	this.imag = i;
};
$hxClasses["tardis.Complex"] = tardis.Complex;
tardis.Complex.__name__ = ["tardis","Complex"];
tardis.Complex.neg = function(x) {
	return new tardis.Complex(0.0 - x.real,0.0 - x.imag);
}
tardis.Complex.add = function(x,y) {
	return new tardis.Complex(x.real + y.real,x.imag + y.imag);
}
tardis.Complex.sub = function(x,y) {
	return new tardis.Complex(x.real - y.real,x.imag - y.imag);
}
tardis.Complex.mul = function(x,y) {
	return new tardis.Complex(x.real * y.real - x.imag * y.imag,x.imag * y.real + x.real * y.imag);
}
tardis.Complex.div = function(x,y) {
	if(y.real == 0.0 && y.imag == 0.0) {
		tardis.Scheduler.panicFromHaxe("complex divide by zero");
		return new tardis.Complex(0.0,0.0);
	} else return new tardis.Complex((x.real * y.real + x.imag * y.imag) / (y.real * y.real + y.imag * y.imag),(x.imag * y.real - x.real * y.imag) / (y.real * y.real + y.imag * y.imag));
}
tardis.Complex.eq = function(x,y) {
	return x.real == y.real && x.imag == y.imag;
}
tardis.Complex.neq = function(x,y) {
	return x.real != y.real || x.imag != y.imag;
}
tardis.Complex.prototype = {
	__class__: tardis.Complex
}
tardis._Go = {}
tardis._Go.HaxeInt64abs_Impl_ = function() { }
$hxClasses["tardis._Go.HaxeInt64abs_Impl_"] = tardis._Go.HaxeInt64abs_Impl_;
tardis._Go.HaxeInt64abs_Impl_.__name__ = ["tardis","_Go","HaxeInt64abs_Impl_"];
tardis._Go.HaxeInt64abs_Impl_._new = function(v) {
	return v;
}
tardis._Go.HaxeInt64abs_Impl_.toInt = function(v) {
	return tardis.Int64.getLow(v);
}
tardis._Go.HaxeInt64abs_Impl_.ofInt = function(v) {
	return new tardis.Int64(v >> 31,v);
}
tardis._Go.HaxeInt64abs_Impl_.toFloat = function(vp) {
	var v = vp;
	var isNegVal = false;
	if(v.high < 0) {
		if(tardis.Int64.compare(v,new tardis.Int64(-2147483648,0)) == 0) return -9223372036854775808.0;
		isNegVal = true;
		v = tardis.Int64.neg(v);
	}
	var ret = 0.0;
	var multiplier = 1.0;
	var one = new tardis.Int64(0,1);
	var _g = 0;
	while(_g < 63) {
		var i = _g++;
		if(!(function($this) {
			var $r;
			var v1 = new tardis.Int64(v.high & one.high,v.low & one.low);
			$r = (v1.high | v1.low) == 0;
			return $r;
		}(this))) ret += multiplier;
		multiplier *= 2.0;
		v = new tardis.Int64(v.high >>> 1,v.low >>> 1 | v.high << 31);
	}
	if(isNegVal) return -ret;
	return ret;
}
tardis._Go.HaxeInt64abs_Impl_.toUFloat = function(vp) {
	var v = vp;
	var ret = 0.0;
	var multiplier = 1.0;
	var one = new tardis.Int64(0,1);
	var _g = 0;
	while(_g < 64) {
		var i = _g++;
		if(!(function($this) {
			var $r;
			var v1 = new tardis.Int64(v.high & one.high,v.low & one.low);
			$r = (v1.high | v1.low) == 0;
			return $r;
		}(this))) ret += multiplier;
		multiplier *= 2.0;
		v = new tardis.Int64(v.high >>> 1,v.low >>> 1 | v.high << 31);
	}
	return ret;
}
tardis._Go.HaxeInt64abs_Impl_.ofFloat = function(v) {
	if(v == 0.0) return new tardis.Int64(0,0);
	if(Math.isNaN(v)) return new tardis.Int64(-2147483648,0);
	var isNegVal = false;
	if(v < 0.0) {
		isNegVal = true;
		v = -v;
	}
	if(v < 2147483647.0) {
		if(isNegVal) return tardis.Int64.neg(tardis.Int64.ofInt(Math.ceil(v))); else return tardis.Int64.ofInt(Math.floor(v));
	}
	if(v > 9223372036854775807.0) {
		if(isNegVal) return new tardis.Int64(-2147483648,0); else return new tardis.Int64(2147483647,-1);
	}
	var f32 = 4294967296.0;
	var f16 = 65536.0;
	var high = Math.floor(v / f32);
	var lowFloat = Math.floor(v - high * f32);
	var lowTop16 = Math.floor(lowFloat / f16);
	var lowBot16 = Math.floor(lowFloat - lowTop16 * f16);
	var res = new tardis.Int64(high,lowBot16);
	res = tardis.Int64.or(res,tardis.Int64.shl(new tardis.Int64(0,lowTop16),16));
	if(isNegVal) return tardis.Int64.neg(res);
	return res;
}
tardis._Go.HaxeInt64abs_Impl_.ofUFloat = function(v) {
	if(v <= 0.0) return new tardis.Int64(0,0);
	if(Math.isNaN(v)) return new tardis.Int64(-2147483648,0);
	if(v < 2147483647.0) return (function($this) {
		var $r;
		var v1 = Math.floor(v);
		$r = new tardis.Int64(v1 >> 31,v1);
		return $r;
	}(this));
	if(v > 18446744073709551615.0) return new tardis.Int64(-1,-1);
	var f32 = 4294967296.0;
	var f16 = 65536.0;
	var high = Math.floor(v / f32);
	var lowFloat = Math.floor(v - high * f32);
	var lowTop16 = Math.floor(lowFloat / f16);
	var lowBot16 = Math.floor(lowFloat - lowTop16 * f16);
	var res = new tardis.Int64(high,lowBot16);
	res = tardis.Int64.or(res,tardis.Int64.shl(new tardis.Int64(0,lowTop16),16));
	return res;
}
tardis._Go.HaxeInt64abs_Impl_.make = function(h,l) {
	return new tardis.Int64(h,l);
}
tardis._Go.HaxeInt64abs_Impl_.toString = function(v) {
	return v.toString();
}
tardis._Go.HaxeInt64abs_Impl_.toStr = function(v) {
	return v.toString();
}
tardis._Go.HaxeInt64abs_Impl_.neg = function(v) {
	return tardis.Int64.neg(v);
}
tardis._Go.HaxeInt64abs_Impl_.isZero = function(v) {
	return (v.high | v.low) == 0;
}
tardis._Go.HaxeInt64abs_Impl_.isNeg = function(v) {
	return v.high < 0;
}
tardis._Go.HaxeInt64abs_Impl_.add = function(x,y) {
	return tardis.Int64.add(x,y);
}
tardis._Go.HaxeInt64abs_Impl_.and = function(x,y) {
	return new tardis.Int64(x.high & y.high,x.low & y.low);
}
tardis._Go.HaxeInt64abs_Impl_.checkDiv = function(x,y,isSigned) {
	if((y.high | y.low) == 0) tardis.Scheduler.panicFromHaxe("attempt to divide 64-bit value by 0");
	if(isSigned && tardis.Int64.compare(y,new tardis.Int64(-1,-1)) == 0 && tardis.Int64.compare(x,new tardis.Int64(-2147483648,0)) == 0) y = new tardis.Int64(0,1);
	return y;
}
tardis._Go.HaxeInt64abs_Impl_.div = function(x,y,isSigned) {
	y = tardis._Go.HaxeInt64abs_Impl_.checkDiv(x,y,isSigned);
	if(tardis.Int64.compare(y,new tardis.Int64(0,1)) == 0) return x;
	return tardis.Int64.div(x,y);
}
tardis._Go.HaxeInt64abs_Impl_.mod = function(x,y,isSigned) {
	y = tardis._Go.HaxeInt64abs_Impl_.checkDiv(x,y,isSigned);
	if(tardis.Int64.compare(y,new tardis.Int64(0,1)) == 0) return new tardis.Int64(0,0);
	return tardis.Int64.mod(x,tardis._Go.HaxeInt64abs_Impl_.checkDiv(x,y,isSigned));
}
tardis._Go.HaxeInt64abs_Impl_.mul = function(x,y) {
	return tardis.Int64.mul(x,y);
}
tardis._Go.HaxeInt64abs_Impl_.or = function(x,y) {
	return new tardis.Int64(x.high | y.high,x.low | y.low);
}
tardis._Go.HaxeInt64abs_Impl_.shl = function(x,y) {
	return (y & 63) == 0?x:(y & 63) < 32?new tardis.Int64(x.high << y | x.low >>> (32 - (y & 63) | 0),x.low << y):new tardis.Int64(x.low << (y - 32 | 0),0);
}
tardis._Go.HaxeInt64abs_Impl_.ushr = function(x,y) {
	return (y & 63) == 0?x:(y & 63) < 32?new tardis.Int64(x.high >>> y,x.low >>> y | x.high << (32 - (y & 63) | 0)):new tardis.Int64(0,x.high >>> (y - 32 | 0));
}
tardis._Go.HaxeInt64abs_Impl_.sub = function(x,y) {
	return tardis.Int64.sub(x,y);
}
tardis._Go.HaxeInt64abs_Impl_.xor = function(x,y) {
	return new tardis.Int64(x.high ^ y.high,x.low ^ y.low);
}
tardis._Go.HaxeInt64abs_Impl_.compare = function(x,y) {
	return tardis.Int64.compare(x,y);
}
tardis._Go.HaxeInt64abs_Impl_.ucompare = function(x,y) {
	return tardis.Int64.ucompare(x,y);
}
tardis.Int64 = function(high,low) {
	this.high = high | 0;
	this.low = low | 0;
};
$hxClasses["tardis.Int64"] = tardis.Int64;
tardis.Int64.__name__ = ["tardis","Int64"];
tardis.Int64.ushr32 = function(v,n) {
	return v >>> n;
}
tardis.Int64.make = function(high,low) {
	return new tardis.Int64(high,low);
}
tardis.Int64.ofInt = function(x) {
	return new tardis.Int64(x >> 31,x);
}
tardis.Int64.toInt = function(x) {
	if(x.high != 0) {
		if(x.high < 0) return -tardis.Int64.toInt(tardis.Int64.neg(x));
		throw "Overflow";
	}
	return x.low;
}
tardis.Int64.getLow = function(x) {
	return x.low;
}
tardis.Int64.getHigh = function(x) {
	return x.high;
}
tardis.Int64.add = function(a,b) {
	var high = a.high + b.high | 0;
	var low = a.low + b.low | 0;
	if(tardis.Int64.uicompare(low,a.low) < 0) high++;
	return new tardis.Int64(high,low);
}
tardis.Int64.sub = function(a,b) {
	var high = a.high - b.high | 0;
	var low = a.low - b.low | 0;
	if(tardis.Int64.uicompare(a.low,b.low) < 0) high--;
	return new tardis.Int64(high,low);
}
tardis.Int64.mul = function(a,b) {
	var mask = 65535;
	var al = a.low & mask, ah = a.low >>> 16;
	var bl = b.low & mask, bh = b.low >>> 16;
	var p00 = al * bl;
	var p10 = ah * bl;
	var p01 = al * bh;
	var p11 = ah * bh;
	var low = p00;
	var high = p11 + (p01 >>> 16) + (p10 >>> 16) | 0;
	p01 = p01 << 16 | 0;
	low = low + p01 | 0;
	if(tardis.Int64.uicompare(low,p01) < 0) high = high + 1 | 0;
	p10 = p10 << 16 | 0;
	low = low + p10 | 0;
	if(tardis.Int64.uicompare(low,p10) < 0) high = high + 1 | 0;
	high = high + (function($this) {
		var $r;
		var a1 = a.low, b1 = b.high;
		$r = (a1 * (b1 >>> 16) << 16 | 0) + a1 * (b1 & 65535) | 0;
		return $r;
	}(this)) | 0;
	high = high + (function($this) {
		var $r;
		var a1 = a.high, b1 = b.low;
		$r = (a1 * (b1 >>> 16) << 16 | 0) + a1 * (b1 & 65535) | 0;
		return $r;
	}(this)) | 0;
	return new tardis.Int64(high,low);
}
tardis.Int64.divMod = function(modulus,divisor) {
	var quotient = new tardis.Int64(0,0);
	var mask_high = 0, mask_low = 1;
	divisor = new tardis.Int64(divisor.high,divisor.low);
	while(divisor.high >= 0) {
		var cmp = tardis.Int64.ucompare(divisor,modulus);
		divisor.high = divisor.high << 1 | 0 | divisor.low >>> 31 | 0;
		divisor.low = divisor.low << 1 | 0;
		mask_high = mask_high << 1 | 0 | mask_low >>> 31 | 0;
		mask_low = mask_low << 1 | 0;
		if(cmp >= 0) break;
	}
	while((mask_low | mask_high | 0) != 0) {
		if(tardis.Int64.ucompare(modulus,divisor) >= 0) {
			quotient.high = quotient.high | mask_high | 0;
			quotient.low = quotient.low | mask_low | 0;
			modulus = tardis.Int64.sub(modulus,divisor);
		}
		mask_low = mask_low >>> 1 | (mask_high << 31 | 0) | 0;
		mask_high = mask_high >>> 1;
		divisor.low = divisor.low >>> 1 | (divisor.high << 31 | 0) | 0;
		divisor.high = divisor.high >>> 1;
	}
	return { quotient : quotient, modulus : modulus};
}
tardis.Int64.div = function(a,b) {
	if(b.high == 0) switch(b.low) {
	case 0:
		throw "divide by zero";
		break;
	case 1:
		return new tardis.Int64(a.high,a.low);
	}
	var sign = (a.high < 0 || b.high < 0) && !(a.high < 0 && b.high < 0);
	if(a.high < 0) a = tardis.Int64.neg(a);
	if(b.high < 0) b = tardis.Int64.neg(b);
	var q = tardis.Int64.divMod(a,b).quotient;
	return sign?tardis.Int64.neg(q):q;
}
tardis.Int64.mod = function(a,b) {
	if(b.high == 0) switch(b.low) {
	case 0:
		throw "modulus by zero";
		break;
	case 1:
		return new tardis.Int64(0,0);
	}
	var sign = a.high < 0;
	if(a.high < 0) a = tardis.Int64.neg(a);
	if(b.high < 0) b = tardis.Int64.neg(b);
	var m = tardis.Int64.divMod(a,b).modulus;
	return sign?tardis.Int64.neg(m):m;
}
tardis.Int64.shl = function(a,b) {
	return (b & 63) == 0?a:(b & 63) < 32?new tardis.Int64(a.high << b | a.low >>> (32 - (b & 63) | 0),a.low << b):new tardis.Int64(a.low << (b - 32 | 0),0);
}
tardis.Int64.shr = function(a,b) {
	return (b & 63) == 0?a:(b & 63) < 32?new tardis.Int64(a.high >> b,a.low >>> b | a.high << (32 - (b & 63) | 0)):new tardis.Int64(a.high >> 31,a.high >> (b - 32 | 0));
}
tardis.Int64.ushr = function(a,b) {
	return (b & 63) == 0?a:(b & 63) < 32?new tardis.Int64(a.high >>> b,a.low >>> b | a.high << (32 - (b & 63) | 0)):new tardis.Int64(0,a.high >>> (b - 32 | 0));
}
tardis.Int64.and = function(a,b) {
	return new tardis.Int64(a.high & b.high,a.low & b.low);
}
tardis.Int64.or = function(a,b) {
	return new tardis.Int64(a.high | b.high,a.low | b.low);
}
tardis.Int64.xor = function(a,b) {
	return new tardis.Int64(a.high ^ b.high,a.low ^ b.low);
}
tardis.Int64.neg = function(a) {
	var high = ~a.high | 0;
	var low = -a.low | 0;
	if(low == 0) high++;
	return new tardis.Int64(high,low);
}
tardis.Int64.isNeg = function(a) {
	return a.high < 0;
}
tardis.Int64.isZero = function(a) {
	return (a.high | a.low) == 0;
}
tardis.Int64.uicompare = function(a,b) {
	return a < 0?b < 0?~b - ~a | 0:1:b < 0?-1:a - b | 0;
}
tardis.Int64.compare = function(a,b) {
	var v = a.high - b.high | 0;
	return v != 0?v:tardis.Int64.uicompare(a.low,b.low);
}
tardis.Int64.ucompare = function(a,b) {
	var v = tardis.Int64.uicompare(a.high,b.high);
	return v != 0?v:tardis.Int64.uicompare(a.low,b.low);
}
tardis.Int64.toStr = function(a) {
	return a.toString();
}
tardis.Int64.prototype = {
	toString: function() {
		if((this.high | this.low) == 0) return "0";
		var str = "";
		var neg = false;
		var i = this;
		if(i.high < 0) {
			neg = true;
			i = tardis.Int64.neg(i);
		}
		var ten = new tardis.Int64(0,10);
		while(!((i.high | i.low) == 0)) {
			var r = tardis.Int64.divMod(i,ten);
			str = r.modulus.low + str;
			i = r.quotient;
		}
		if(neg) str = "-" + str;
		return str;
	}
	,__class__: tardis.Int64
}
tardis.StackFrameBasis = function(gr,ph,name) {
	this._latestBlock = 0;
	this._latestPH = 0;
	this._incomplete = true;
	this._goroutine = gr;
	this._functionPH = ph;
	this._functionName = name;
	this._deferStack = new List();
};
$hxClasses["tardis.StackFrameBasis"] = tardis.StackFrameBasis;
tardis.StackFrameBasis.__name__ = ["tardis","StackFrameBasis"];
tardis.StackFrameBasis.prototype = {
	runDefers: function() {
		while(!this._deferStack.isEmpty()) tardis.Scheduler.push(this._goroutine,this._deferStack.pop());
	}
	,defer: function(fn) {
		this._deferStack.add(fn);
	}
	,setPH: function(ph) {
		this._latestPH = ph;
	}
	,setLatest: function(ph,blk) {
		this._latestPH = ph;
		this._latestBlock = blk;
	}
	,__class__: tardis.StackFrameBasis
}
tardis.StackFrame = function() { }
$hxClasses["tardis.StackFrame"] = tardis.StackFrame;
tardis.StackFrame.__name__ = ["tardis","StackFrame"];
tardis.StackFrame.prototype = {
	__class__: tardis.StackFrame
}
tardis.Scheduler = function() { }
$hxClasses["tardis.Scheduler"] = tardis.Scheduler;
tardis.Scheduler.__name__ = ["tardis","Scheduler"];
tardis.Scheduler.timerEventHandler = function(dummy) {
	tardis.Scheduler.runAll();
}
tardis.Scheduler.runAll = function() {
	var cg = 0;
	tardis.Scheduler.entryCount++;
	if(tardis.Scheduler.entryCount > 2) throw "Scheduler.runAll() entryCount exceeded - " + tardis.Scheduler.stackDump();
	if(tardis.Scheduler.grStacks[0].isEmpty()) {
		if(tardis.Scheduler.grStacks.length <= 1) throw "Scheduler: there is only one goroutine and its stack is empty\n" + tardis.Scheduler.stackDump();
	} else tardis.Scheduler.runOne(0,tardis.Scheduler.entryCount);
	if(tardis.Scheduler.doneInit && tardis.Scheduler.entryCount == 1) {
		var _g1 = 1, _g = tardis.Scheduler.grStacks.length;
		while(_g1 < _g) {
			var cg1 = _g1++;
			if(!tardis.Scheduler.grStacks[cg1].isEmpty()) tardis.Scheduler.runOne(cg1,tardis.Scheduler.entryCount);
		}
		while(tardis.Scheduler.grStacks.length > 1) if(tardis.Scheduler.grStacks[tardis.Scheduler.grStacks.length - 1].isEmpty()) tardis.Scheduler.grStacks.pop(); else break;
	}
	tardis.Scheduler.entryCount--;
}
tardis.Scheduler.runOne = function(gr,entryCount) {
	if(tardis.Scheduler.grInPanic[gr]) {
		if(entryCount != 1) {
			if(tardis.Scheduler.grStacks[gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + gr + "\n" + tardis.Scheduler.stackDump(); else {
				tardis.Scheduler.currentGR = gr;
				tardis.Scheduler.grStacks[gr].first().run();
			}
		} else while(tardis.Scheduler.grInPanic[gr]) if(tardis.Scheduler.grStacks[gr].isEmpty()) throw "Panic in goroutine " + gr + "\n" + tardis.Scheduler.panicStackDump; else {
			var sf = tardis.Scheduler.grStacks[gr].pop();
			while(!sf._deferStack.isEmpty()) {
				var def = sf._deferStack.pop();
				tardis.Scheduler.push(gr,def);
				while(def._incomplete) tardis.Scheduler.runAll();
			}
		}
	} else if(tardis.Scheduler.grStacks[gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = gr;
		tardis.Scheduler.grStacks[gr].first().run();
	}
}
tardis.Scheduler.run1 = function(gr) {
	if(tardis.Scheduler.grStacks[gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = gr;
		tardis.Scheduler.grStacks[gr].first().run();
	}
}
tardis.Scheduler.makeGoroutine = function() {
	var _g1 = 0, _g = tardis.Scheduler.grStacks.length;
	while(_g1 < _g) {
		var r = _g1++;
		if(tardis.Scheduler.grStacks[r].isEmpty()) {
			tardis.Scheduler.grInPanic[r] = false;
			tardis.Scheduler.grPanicMsg[r] = null;
			return r;
		}
	}
	var l = tardis.Scheduler.grStacks.length;
	tardis.Scheduler.grStacks[l] = new List();
	tardis.Scheduler.grInPanic[l] = false;
	tardis.Scheduler.grPanicMsg[l] = null;
	return l;
}
tardis.Scheduler.pop = function(gr) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.pop() invalid goroutine";
	return tardis.Scheduler.grStacks[gr].pop();
}
tardis.Scheduler.push = function(gr,sf) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.push() invalid goroutine";
	tardis.Scheduler.grStacks[gr].push(sf);
}
tardis.Scheduler.stackDump = function() {
	var ret = "";
	var gr;
	ret += "runAll() entryCount=" + tardis.Scheduler.entryCount + "\n";
	var _g1 = 0, _g = tardis.Scheduler.grStacks.length;
	while(_g1 < _g) {
		var gr1 = _g1++;
		ret += "Goroutine " + gr1 + " " + Std.string(tardis.Scheduler.grPanicMsg[gr1]) + "\n";
		if(tardis.Scheduler.grStacks[gr1].isEmpty()) ret += "Stack is empty\n"; else {
			ret += "Stack has " + tardis.Scheduler.grStacks[gr1].length + " entries:\n";
			var it = tardis.Scheduler.grStacks[gr1].iterator();
			while(it.hasNext()) {
				var ent = it.next();
				if(ent == null) ret += "\tStack entry is null\n"; else {
					ret += "\t" + ent._functionName + " starting at " + tardis.Go.CPos(ent._functionPH);
					ret += " latest position " + tardis.Go.CPos(ent._latestPH);
					ret += " latest block " + ent._latestBlock + "\n";
				}
			}
		}
	}
	return ret;
}
tardis.Scheduler.traceStackDump = function() {
	console.log(tardis.Scheduler.stackDump());
}
tardis.Scheduler.panic = function(gr,err) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.panic() invalid goroutine";
	if(!tardis.Scheduler.grInPanic[gr]) {
		tardis.Scheduler.grInPanic[gr] = true;
		tardis.Scheduler.grPanicMsg[gr] = err;
		tardis.Scheduler.panicStackDump = tardis.Scheduler.stackDump();
	}
}
tardis.Scheduler.recover = function(gr) {
	if(gr >= tardis.Scheduler.grStacks.length || gr < 0) throw "Scheduler.recover() invalid goroutine";
	tardis.Scheduler.grInPanic[gr] = false;
	return tardis.Scheduler.grPanicMsg[gr];
}
tardis.Scheduler.panicFromHaxe = function(err) {
	if(tardis.Scheduler.currentGR >= tardis.Scheduler.grStacks.length || tardis.Scheduler.currentGR < 0) tardis.Scheduler.panic(0,new tardis.Interface(tardis.TypeInfo.getId("string"),"Runtime panic, unknown goroutine, " + err + " ")); else tardis.Scheduler.panic(tardis.Scheduler.currentGR,new tardis.Interface(tardis.TypeInfo.getId("string"),"Runtime panic, " + err + " "));
}
tardis.Scheduler.bbi = function() {
	tardis.Scheduler.panicFromHaxe("bad block ID (internal phi error)");
}
tardis.Scheduler.ioor = function() {
	tardis.Scheduler.panicFromHaxe("index out of range");
}
tardis.Scheduler.NumGoroutine = function() {
	return tardis.Scheduler.grStacks.length;
}
tardis.Go_haxegoruntime_RunesToUTF16 = function(gr,_bds,p_r) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,123,"Go_haxegoruntime_RunesToUTF16");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_RunesToUTF16"] = tardis.Go_haxegoruntime_RunesToUTF16;
$hxExpose(tardis.Go_haxegoruntime_RunesToUTF16, "Go_haxegoruntime_RunesToUTF16");
tardis.Go_haxegoruntime_RunesToUTF16.__name__ = ["tardis","Go_haxegoruntime_RunesToUTF16"];
tardis.Go_haxegoruntime_RunesToUTF16.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_RunesToUTF16.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_RunesToUTF16(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_RunesToUTF16.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_haxegoruntime_RunesToUTF16(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_RunesToUTF16.call = function(gr,_bds,p_r) {
	return new tardis.Go_haxegoruntime_RunesToUTF16(gr,_bds,p_r);
}
tardis.Go_haxegoruntime_RunesToUTF16.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_RunesToUTF16.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 123;
				this._latestBlock = 0;
				this._latestPH = 124;
				this._SF1 = new tardis.Go_utf16_Encode(this._goroutine,[],this.p_r);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 124;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_RunesToUTF16
});
tardis._Go.Go_utf16_init = function(gr,_bds) {
	this._Next = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,124,"Go_utf16_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_utf16_init"] = tardis._Go.Go_utf16_init;
tardis._Go.Go_utf16_init.__name__ = ["tardis","_Go","Go_utf16_init"];
tardis._Go.Go_utf16_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf16_init.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_utf16_init(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_utf16_init.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_utf16_init(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_utf16_init.call = function(gr,_bds) {
	return new tardis._Go.Go_utf16_init(gr,_bds);
}
tardis._Go.Go_utf16_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf16_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn1: function() {
		tardis.Go.utf16_init_36_guard.store(true);
		this._Next = 2;
	}
	,SubFn0: function() {
		var _t0;
		_t0 = tardis.Go.utf16_init_36_guard.ref();
		this._Next = _t0?2:1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 124;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 124;
				this._latestBlock = 1;
				tardis.Go.utf16_init_36_guard.store(true);
				this._Next = 2;
				break;
			case 2:
				this._latestPH = 124;
				this._latestBlock = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_utf16_init
});
tardis.Go_haxegoruntime_M1 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,216,"Go_haxegoruntime_M1");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M1"] = tardis.Go_haxegoruntime_M1;
$hxExpose(tardis.Go_haxegoruntime_M1, "Go_haxegoruntime_M1");
tardis.Go_haxegoruntime_M1.__name__ = ["tardis","Go_haxegoruntime_M1"];
tardis.Go_haxegoruntime_M1.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M1.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M1(0,[],p_rx,p_typ,p_meth,p_a1).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M1.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1) {
	var _sf = new tardis.Go_haxegoruntime_M1(_gr,[],p_rx,p_typ,p_meth,p_a1).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M1.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1) {
	return new tardis.Go_haxegoruntime_M1(gr,_bds,p_rx,p_typ,p_meth,p_a1);
}
tardis.Go_haxegoruntime_M1.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 216;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M1
});
tardis._Go.Go_haxegoruntime_funcline_go = function(gr,_bds,p_arg0,p_arg1) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,415,"Go_haxegoruntime_funcline_go");
	this._bds = _bds;
	this.p_arg0 = p_arg0;
	this.p_arg1 = p_arg1;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_funcline_go"] = tardis._Go.Go_haxegoruntime_funcline_go;
tardis._Go.Go_haxegoruntime_funcline_go.__name__ = ["tardis","_Go","Go_haxegoruntime_funcline_go"];
tardis._Go.Go_haxegoruntime_funcline_go.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_funcline_go.callFromHaxe = function(p_arg0,p_arg1) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_funcline_go(0,[],p_arg0,p_arg1).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcline_go.callFromRT = function(_gr,p_arg0,p_arg1) {
	var _sf = new tardis._Go.Go_haxegoruntime_funcline_go(_gr,[],p_arg0,p_arg1).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcline_go.call = function(gr,_bds,p_arg0,p_arg1) {
	return new tardis._Go.Go_haxegoruntime_funcline_go(gr,_bds,p_arg0,p_arg1);
}
tardis._Go.Go_haxegoruntime_funcline_go.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_funcline_go.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.funcline_go() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 415;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.funcline_go() not yet implemented");
				this._latestPH = 416;
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 416;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_funcline_go
});
tardis._Go.Go_utf8_decodeRuneInStringInternal = function(gr,_bds,p_s) {
	this._Next = 0;
	this._t56 = false;
	this._t55 = false;
	this._t54 = 0;
	this._t53 = 0;
	this._t52 = 0;
	this._t51 = 0;
	this._t50 = 0;
	this._t49 = 0;
	this._t48 = 0;
	this._t47 = 0;
	this._t46 = 0;
	this._t45 = 0;
	this._t44 = 0;
	this._t43 = 0;
	this._t42 = 0;
	this._t41 = 0;
	this._t40 = false;
	this._t39 = false;
	this._t38 = false;
	this._t37 = 0;
	this._t36 = false;
	this._t35 = false;
	this._t34 = false;
	this._t33 = false;
	this._t32 = 0;
	this._t31 = 0;
	this._t30 = 0;
	this._t29 = 0;
	this._t28 = 0;
	this._t27 = 0;
	this._t26 = 0;
	this._t25 = 0;
	this._t24 = 0;
	this._t23 = 0;
	this._t22 = false;
	this._t21 = false;
	this._t20 = false;
	this._t19 = 0;
	this._t18 = false;
	this._t17 = false;
	this._t16 = 0;
	this._t15 = 0;
	this._t14 = 0;
	this._t13 = 0;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = false;
	this._t9 = false;
	this._t8 = false;
	this._t7 = 0;
	this._t6 = false;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = false;
	this._t2 = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,673,"Go_utf8_decodeRuneInStringInternal");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_utf8_decodeRuneInStringInternal"] = tardis._Go.Go_utf8_decodeRuneInStringInternal;
tardis._Go.Go_utf8_decodeRuneInStringInternal.__name__ = ["tardis","_Go","Go_utf8_decodeRuneInStringInternal"];
tardis._Go.Go_utf8_decodeRuneInStringInternal.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf8_decodeRuneInStringInternal.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_utf8_decodeRuneInStringInternal(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_utf8_decodeRuneInStringInternal.callFromRT = function(_gr,p_s) {
	var _sf = new tardis._Go.Go_utf8_decodeRuneInStringInternal(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_utf8_decodeRuneInStringInternal.call = function(gr,_bds,p_s) {
	return new tardis._Go.Go_utf8_decodeRuneInStringInternal(gr,_bds,p_s);
}
tardis._Go.Go_utf8_decodeRuneInStringInternal.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf8_decodeRuneInStringInternal.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn21: function() {
		var _t56;
		_t56 = 1114111 < this._t54;
		this._Next = _t56?35:36;
	}
	,SubFn20: function() {
		var _t41;
		var _t42;
		var _t43;
		var _t44;
		var _t45;
		var _t46;
		var _t47;
		var _t48;
		var _t49;
		var _t50;
		var _t51;
		var _t52;
		var _t53;
		var _t55;
		this._latestPH = 740;
		_t41 = this._t2 & 7 & 255;
		_t42 = _t41;
		_t43 = _t42 << tardis.Int64.getLow(new tardis.Int64(0,18));
		_t44 = this._t7 & 63 & 255;
		_t45 = _t44;
		_t46 = _t45 << tardis.Int64.getLow(new tardis.Int64(0,12));
		_t47 = tardis.Force.toInt32(_t43 | _t46);
		_t48 = this._t19 & 63 & 255;
		_t49 = _t48;
		_t50 = _t49 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t51 = tardis.Force.toInt32(_t47 | _t50);
		_t52 = this._t37 & 63 & 255;
		_t53 = _t52;
		this._t54 = tardis.Force.toInt32(_t51 | _t53);
		this._latestPH = 741;
		_t55 = this._t54 <= 65535;
		this._Next = _t55?35:37;
	}
	,SubFn19: function() {
		var _t40;
		this._latestPH = 734;
		_t40 = tardis.Force.uintCompare(192,this._t37) <= 0;
		this._Next = _t40?30:31;
	}
	,SubFn18: function() {
		var _t39;
		this._latestPH = 739;
		_t39 = tardis.Force.uintCompare(this._t2,248) < 0;
		this._Next = _t39?33:34;
	}
	,SubFn17: function() {
		var _t38;
		this._latestPH = 733;
		this._t37 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(3);
		this._latestPH = 734;
		_t38 = tardis.Force.uintCompare(this._t37,128) < 0;
		this._Next = _t38?30:32;
	}
	,SubFn16: function() {
		var _t36;
		_t36 = this._t32 <= 57343;
		this._Next = _t36?25:26;
	}
	,SubFn15: function() {
		var _t35;
		this._latestPH = 723;
		_t35 = 55296 <= this._t32;
		this._Next = _t35?27:26;
	}
	,SubFn14: function() {
		var _t34;
		this._latestPH = 730;
		_t34 = this._t0 < 4;
		this._Next = _t34?28:29;
	}
	,SubFn13: function() {
		var _t23;
		var _t24;
		var _t25;
		var _t26;
		var _t27;
		var _t28;
		var _t29;
		var _t30;
		var _t31;
		var _t33;
		this._latestPH = 719;
		_t23 = this._t2 & 15 & 255;
		_t24 = _t23;
		_t25 = _t24 << tardis.Int64.getLow(new tardis.Int64(0,12));
		_t26 = this._t7 & 63 & 255;
		_t27 = _t26;
		_t28 = _t27 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t29 = tardis.Force.toInt32(_t25 | _t28);
		_t30 = this._t19 & 63 & 255;
		_t31 = _t30;
		this._t32 = tardis.Force.toInt32(_t29 | _t31);
		this._latestPH = 720;
		_t33 = this._t32 <= 2047;
		this._Next = _t33?23:24;
	}
	,SubFn12: function() {
		var _t22;
		this._latestPH = 713;
		_t22 = tardis.Force.uintCompare(192,this._t19) <= 0;
		this._Next = _t22?18:19;
	}
	,SubFn11: function() {
		var _t21;
		this._latestPH = 718;
		_t21 = tardis.Force.uintCompare(this._t2,240) < 0;
		this._Next = _t21?21:22;
	}
	,SubFn10: function() {
		var _t20;
		this._latestPH = 712;
		this._t19 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(2);
		this._latestPH = 713;
		_t20 = tardis.Force.uintCompare(this._t19,128) < 0;
		this._Next = _t20?18:20;
	}
	,SubFn9: function() {
		var _t18;
		this._latestPH = 709;
		_t18 = this._t0 < 3;
		this._Next = _t18?16:17;
	}
	,SubFn8: function() {
		var _t11;
		var _t12;
		var _t13;
		var _t14;
		var _t15;
		var _t17;
		this._latestPH = 701;
		_t11 = this._t2 & 31 & 255;
		_t12 = _t11;
		_t13 = _t12 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t14 = this._t7 & 63 & 255;
		_t15 = _t14;
		this._t16 = tardis.Force.toInt32(_t13 | _t15);
		this._latestPH = 702;
		_t17 = this._t16 <= 127;
		this._Next = _t17?14:15;
	}
	,SubFn7: function() {
		var _t10;
		this._latestPH = 695;
		_t10 = tardis.Force.uintCompare(192,this._t7) <= 0;
		this._Next = _t10?9:10;
	}
	,SubFn6: function() {
		var _t9;
		this._latestPH = 700;
		_t9 = tardis.Force.uintCompare(this._t2,224) < 0;
		this._Next = _t9?12:13;
	}
	,SubFn5: function() {
		var _t8;
		this._latestPH = 694;
		this._t7 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(1);
		this._latestPH = 695;
		_t8 = tardis.Force.uintCompare(this._t7,128) < 0;
		this._Next = _t8?9:11;
	}
	,SubFn4: function() {
		var _t6;
		this._latestPH = 691;
		_t6 = this._t0 < 2;
		this._Next = _t6?7:8;
	}
	,SubFn3: function() {
		var _t5;
		this._latestPH = 686;
		_t5 = tardis.Force.uintCompare(this._t2,192) < 0;
		this._Next = _t5?5:6;
	}
	,SubFn2: function() {
		this._latestPH = 682;
		this._t4 = this._t2;
	}
	,SubFn1: function() {
		var _t3;
		this._latestPH = 678;
		this._t2 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(0);
		this._latestPH = 681;
		_t3 = tardis.Force.uintCompare(this._t2,128) < 0;
		this._Next = _t3?3:4;
	}
	,SubFn0: function() {
		var _t1;
		this._latestPH = 674;
		this._t0 = tardis.Force.toUTF8length(this._goroutine,this.p_s);
		this._latestPH = 675;
		_t1 = this._t0 < 1;
		this._Next = _t1?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 673;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 673;
				this._latestBlock = 1;
				this._latestPH = 676;
				this._res = { r0 : 65533, r1 : 0, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 676;
				this._latestBlock = 2;
				this.SubFn1();
				break;
			case 3:
				this._latestPH = 676;
				this._latestBlock = 3;
				this._latestPH = 682;
				this._t4 = this._t2;
				this._latestPH = 682;
				this._res = { r0 : this._t4, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 682;
				this._latestBlock = 4;
				this.SubFn3();
				break;
			case 5:
				this._latestPH = 682;
				this._latestBlock = 5;
				this._latestPH = 687;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 6:
				this._latestPH = 687;
				this._latestBlock = 6;
				this.SubFn4();
				break;
			case 7:
				this._latestPH = 687;
				this._latestBlock = 7;
				this._latestPH = 692;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 692;
				this._latestBlock = 8;
				this.SubFn5();
				break;
			case 9:
				this._latestPH = 692;
				this._latestBlock = 9;
				this._latestPH = 696;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 10:
				this._latestPH = 696;
				this._latestBlock = 10;
				this.SubFn6();
				break;
			case 11:
				this._latestPH = 696;
				this._latestBlock = 11;
				this.SubFn7();
				break;
			case 12:
				this._latestPH = 696;
				this._latestBlock = 12;
				this.SubFn8();
				break;
			case 13:
				this._latestPH = 696;
				this._latestBlock = 13;
				this.SubFn9();
				break;
			case 14:
				this._latestPH = 696;
				this._latestBlock = 14;
				this._latestPH = 703;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 15:
				this._latestPH = 703;
				this._latestBlock = 15;
				this._latestPH = 705;
				this._res = { r0 : this._t16, r1 : 2, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 16:
				this._latestPH = 705;
				this._latestBlock = 16;
				this._latestPH = 710;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 17:
				this._latestPH = 710;
				this._latestBlock = 17;
				this.SubFn10();
				break;
			case 18:
				this._latestPH = 710;
				this._latestBlock = 18;
				this._latestPH = 714;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 19:
				this._latestPH = 714;
				this._latestBlock = 19;
				this.SubFn11();
				break;
			case 20:
				this._latestPH = 714;
				this._latestBlock = 20;
				this.SubFn12();
				break;
			case 21:
				this._latestPH = 714;
				this._latestBlock = 21;
				this.SubFn13();
				break;
			case 22:
				this._latestPH = 714;
				this._latestBlock = 22;
				this.SubFn14();
				break;
			case 23:
				this._latestPH = 714;
				this._latestBlock = 23;
				this._latestPH = 721;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 24:
				this._latestPH = 721;
				this._latestBlock = 24;
				this.SubFn15();
				break;
			case 25:
				this._latestPH = 721;
				this._latestBlock = 25;
				this._latestPH = 724;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 26:
				this._latestPH = 724;
				this._latestBlock = 26;
				this._latestPH = 726;
				this._res = { r0 : this._t32, r1 : 3, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 27:
				this._latestPH = 726;
				this._latestBlock = 27;
				this.SubFn16();
				break;
			case 28:
				this._latestPH = 726;
				this._latestBlock = 28;
				this._latestPH = 731;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 29:
				this._latestPH = 731;
				this._latestBlock = 29;
				this.SubFn17();
				break;
			case 30:
				this._latestPH = 731;
				this._latestBlock = 30;
				this._latestPH = 735;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 31:
				this._latestPH = 735;
				this._latestBlock = 31;
				this.SubFn18();
				break;
			case 32:
				this._latestPH = 735;
				this._latestBlock = 32;
				this.SubFn19();
				break;
			case 33:
				this._latestPH = 735;
				this._latestBlock = 33;
				this.SubFn20();
				break;
			case 34:
				this._latestPH = 735;
				this._latestBlock = 34;
				this._latestPH = 748;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 35:
				this._latestPH = 748;
				this._latestBlock = 35;
				this._latestPH = 742;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 36:
				this._latestPH = 742;
				this._latestBlock = 36;
				this._latestPH = 744;
				this._res = { r0 : this._t54, r1 : 4, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 37:
				this._latestPH = 744;
				this._latestBlock = 37;
				this.SubFn21();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_utf8_decodeRuneInStringInternal
});
tardis.Go_utf8_Valid = function(gr,_bds,p_p) {
	this._Next = 0;
	this._Phi = 0;
	this._t12 = 0;
	this._t11 = false;
	this._t10 = 0;
	this._t8 = null;
	this._t7 = null;
	this._t6 = 0;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = false;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,945,"Go_utf8_Valid");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_Valid"] = tardis.Go_utf8_Valid;
$hxExpose(tardis.Go_utf8_Valid, "Go_utf8_Valid");
tardis.Go_utf8_Valid.__name__ = ["tardis","Go_utf8_Valid"];
tardis.Go_utf8_Valid.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_Valid.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_Valid(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_Valid.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_Valid(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_Valid.call = function(gr,_bds,p_p) {
	return new tardis.Go_utf8_Valid(gr,_bds,p_p);
}
tardis.Go_utf8_Valid.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_Valid.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn6: function() {
		this._t12 = this._t3 + this._t10;
		this._Next = 3;
	}
	,SubFn5: function() {
		var _t11;
		this._t10 = this._t8.r1;
		this._latestPH = 952;
		_t11 = this._t10 == 1;
		this._Next = _t11?6:7;
	}
	,SubFn4: function() {
		this._latestPH = 951;
		this._t7 = this.p_p.subSlice(this._t3,-1);
	}
	,SubFn3: function() {
		this._t6 = this._t3 + 1;
		this._Next = 3;
	}
	,SubFn2: function() {
		var _t4;
		var _t5;
		this._latestPH = 947;
		_t4 = (function($this) {
			var $r;
			var _v = $this.p_p;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t5 = this._t3 < _t4;
		this._Next = _t5?1:2;
	}
	,SubFn1: function() {
		var _t0;
		var _t1;
		var _t2;
		this._latestPH = 948;
		if(this._t3 < 0 || this._t3 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t0 = this.p_p.addr(this._t3);
		_t1 = _t0.ref() | 0;
		_t2 = tardis.Force.uintCompare(_t1,128) < 0;
		this._Next = _t2?4:5;
	}
	,SubFn0: function() {
		this._Next = 3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 945;
				this._latestBlock = 0;
				this._Next = 3;
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 945;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 945;
				this._latestBlock = 2;
				this._latestPH = 961;
				this._res = true;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 961;
				this._latestBlock = 3;
				this._latestPH = 946;
				this._t3 = this._Phi == 0?0:this._Phi == 4?this._t6:this._Phi == 7?this._t12:0;
				this.SubFn2();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 946;
				this._latestBlock = 4;
				this._t6 = this._t3 + 1;
				this._Next = 3;
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 946;
				this._latestBlock = 5;
				this._latestPH = 951;
				this._t7 = this.p_p.subSlice(this._t3,-1);
				this._latestPH = 951;
				this._SF1 = new tardis.Go_utf8_DecodeRune(this._goroutine,[],this._t7);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 951;
				this._latestBlock = -1;
				this._t8 = this._SF1.res();
				this.SubFn5();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 951;
				this._latestBlock = 6;
				this._latestPH = 956;
				this._res = false;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 7:
				this._latestPH = 956;
				this._latestBlock = 7;
				this._t12 = this._t3 + this._t10;
				this._Next = 3;
				this._Phi = 7;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_Valid
});
tardis.Go_hxutil_NumGoroutine = function(gr,_bds) {
	this._Next = 0;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,1033,"Go_hxutil_NumGoroutine");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_NumGoroutine"] = tardis.Go_hxutil_NumGoroutine;
$hxExpose(tardis.Go_hxutil_NumGoroutine, "Go_hxutil_NumGoroutine");
tardis.Go_hxutil_NumGoroutine.__name__ = ["tardis","Go_hxutil_NumGoroutine"];
tardis.Go_hxutil_NumGoroutine.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_NumGoroutine.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_NumGoroutine(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_NumGoroutine.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_NumGoroutine(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_NumGoroutine.call = function(gr,_bds) {
	return new tardis.Go_hxutil_NumGoroutine(gr,_bds);
}
tardis.Go_hxutil_NumGoroutine.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_NumGoroutine.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = js.Boot.__cast(this._t0 , Int);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1033;
				this._latestBlock = 0;
				this._t0 = tardis.Scheduler.grStacks.length;
				this._t1 = js.Boot.__cast(this._t0 , Int);
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_NumGoroutine
});
tardis.Go_haxegoruntime_Platform = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,196,"Go_haxegoruntime_Platform");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Platform"] = tardis.Go_haxegoruntime_Platform;
$hxExpose(tardis.Go_haxegoruntime_Platform, "Go_haxegoruntime_Platform");
tardis.Go_haxegoruntime_Platform.__name__ = ["tardis","Go_haxegoruntime_Platform"];
tardis.Go_haxegoruntime_Platform.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Platform.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Platform(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Platform.callFromRT = function(_gr) {
	var _sf = new tardis.Go_haxegoruntime_Platform(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Platform.call = function(gr,_bds) {
	return new tardis.Go_haxegoruntime_Platform(gr,_bds);
}
tardis.Go_haxegoruntime_Platform.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Platform.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 196;
				this._latestBlock = 0;
				this._res = "go";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Platform
});
tardis._Go.Go_utf8_init = function(gr,_bds) {
	this._Next = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,196,"Go_utf8_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_utf8_init"] = tardis._Go.Go_utf8_init;
tardis._Go.Go_utf8_init.__name__ = ["tardis","_Go","Go_utf8_init"];
tardis._Go.Go_utf8_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf8_init.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_utf8_init(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_utf8_init.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_utf8_init(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_utf8_init.call = function(gr,_bds) {
	return new tardis._Go.Go_utf8_init(gr,_bds);
}
tardis._Go.Go_utf8_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf8_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn1: function() {
		tardis.Go.utf8_init_36_guard.store(true);
		this._Next = 2;
	}
	,SubFn0: function() {
		var _t0;
		_t0 = tardis.Go.utf8_init_36_guard.ref();
		this._Next = _t0?2:1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 196;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 196;
				this._latestBlock = 1;
				tardis.Go.utf8_init_36_guard.store(true);
				this._Next = 2;
				break;
			case 2:
				this._latestPH = 196;
				this._latestBlock = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_utf8_init
});
tardis.Go_utf8_RuneCountInString = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t4 = 0;
	this._t3 = false;
	this._t2 = null;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,932,"Go_utf8_RuneCountInString");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_RuneCountInString"] = tardis.Go_utf8_RuneCountInString;
$hxExpose(tardis.Go_utf8_RuneCountInString, "Go_utf8_RuneCountInString");
tardis.Go_utf8_RuneCountInString.__name__ = ["tardis","Go_utf8_RuneCountInString"];
tardis.Go_utf8_RuneCountInString.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_RuneCountInString.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_RuneCountInString(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_RuneCountInString.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf8_RuneCountInString(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_RuneCountInString.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf8_RuneCountInString(gr,_bds,p_s);
}
tardis.Go_utf8_RuneCountInString.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_RuneCountInString.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn2: function() {
		this._t4 = this._t1 + 1;
		this._Next = 1;
	}
	,SubFn1: function() {
		var _t2;
		var _t3;
		_t2 = (function($this) {
			var $r;
			var _thisK = $this._t0.k;
			$r = $this._t0.k >= $this._t0.v.len()?{ r0 : false, r1 : 0, r2 : 0}:(function($this) {
				var $r;
				var _dr = tardis.Go_utf8_DecodeRune.callFromRT($this._goroutine,$this._t0.v.subSlice(_thisK,-1));
				$this._t0.k += _dr.r1;
				$r = { r0 : true, r1 : js.Boot.__cast(_thisK , Int), r2 : js.Boot.__cast(_dr.r0 , Int)};
				return $r;
			}($this));
			return $r;
		}(this));
		_t3 = _t2.r0;
		this._Next = _t3?2:3;
	}
	,SubFn0: function() {
		this._latestPH = 933;
		this._t0 = { k : 0, v : tardis.Force.toUTF8slice(this._goroutine,this.p_s)};
		this._Next = 1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 932;
				this._latestBlock = 0;
				this._latestPH = 933;
				this._t0 = { k : 0, v : tardis.Force.toUTF8slice(this._goroutine,this.p_s)};
				this._Next = 1;
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 932;
				this._latestBlock = 1;
				this._t1 = this._Phi == 0?0:this._Phi == 2?this._t4:0;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 932;
				this._latestBlock = 2;
				this._t4 = this._t1 + 1;
				this._Next = 1;
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 932;
				this._latestBlock = 3;
				this._latestPH = 936;
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_RuneCountInString
});
tardis.Go_hxutil_StringsUTF16 = function(gr,_bds) {
	this._Next = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,1023,"Go_hxutil_StringsUTF16");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_StringsUTF16"] = tardis.Go_hxutil_StringsUTF16;
$hxExpose(tardis.Go_hxutil_StringsUTF16, "Go_hxutil_StringsUTF16");
tardis.Go_hxutil_StringsUTF16.__name__ = ["tardis","Go_hxutil_StringsUTF16"];
tardis.Go_hxutil_StringsUTF16.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_StringsUTF16.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_StringsUTF16(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_StringsUTF16.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_StringsUTF16(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_StringsUTF16.call = function(gr,_bds) {
	return new tardis.Go_hxutil_StringsUTF16(gr,_bds);
}
tardis.Go_hxutil_StringsUTF16.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_StringsUTF16.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = tardis.Force.uintCompare(this._t0,1) == 0;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1023;
				this._latestBlock = 0;
				this._t0 = "字".length;
				this._t1 = tardis.Force.uintCompare(this._t0,1) == 0;
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_StringsUTF16
});
tardis.Go_haxegoruntime_UTF8toRunes = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t25 = false;
	this._t24 = 0;
	this._t23 = 0;
	this._t22 = 0;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = null;
	this._t18 = 0;
	this._t17 = 0;
	this._t16 = null;
	this._t15 = 0;
	this._t14 = 0;
	this._t13 = null;
	this._t12 = 0;
	this._t11 = null;
	this._t10 = false;
	this._t9 = 0;
	this._t8 = false;
	this._t7 = 0;
	this._t6 = 0;
	this._t5 = 0;
	this._t4 = null;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = null;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,86,"Go_haxegoruntime_UTF8toRunes");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_UTF8toRunes"] = tardis.Go_haxegoruntime_UTF8toRunes;
$hxExpose(tardis.Go_haxegoruntime_UTF8toRunes, "Go_haxegoruntime_UTF8toRunes");
tardis.Go_haxegoruntime_UTF8toRunes.__name__ = ["tardis","Go_haxegoruntime_UTF8toRunes"];
tardis.Go_haxegoruntime_UTF8toRunes.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_UTF8toRunes.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_UTF8toRunes(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_UTF8toRunes.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_haxegoruntime_UTF8toRunes(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_UTF8toRunes.call = function(gr,_bds,p_s) {
	return new tardis.Go_haxegoruntime_UTF8toRunes(gr,_bds,p_s);
}
tardis.Go_haxegoruntime_UTF8toRunes.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_UTF8toRunes.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn6: function() {
		var _t23;
		var _t24;
		var _t25;
		this._latestPH = 91;
		_t23 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t24 = _t23 - this._t5;
		_t25 = this._t22 < _t24;
		this._Next = _t25?5:6;
	}
	,SubFn5: function() {
		var _t19;
		this._t17 = this._t16.r0;
		this._t18 = this._t16.r1;
		this._latestPH = 95;
		if(this._t6 < 0 || this._t6 >= this._t1.len()) tardis.Scheduler.ioor();
		_t19 = this._t1.addr(this._t6);
		_t19.store(this._t17);
		this._t20 = this._t5 + this._t18;
		this._t21 = this._t6 + 1;
		this._Next = 3;
	}
	,SubFn4: function() {
		var _t11;
		var _t12;
		var _t13;
		var _t14;
		this._latestPH = 92;
		if(this._t22 < 0 || this._t22 >= this._t4.len()) tardis.Scheduler.ioor();
		_t11 = this._t4.addr(this._t22);
		_t12 = this._t5 + this._t22;
		if(_t12 < 0 || _t12 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t13 = this.p_s.addr(_t12);
		_t14 = _t13.ref() | 0;
		_t11.store(_t14);
		this._t15 = this._t22 + 1;
		this._Next = 7;
	}
	,SubFn3: function() {
		var _t9;
		var _t10;
		_t9 = (function($this) {
			var $r;
			var _v = $this._t1;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t10 = this._t6 < _t9;
		this._Next = _t10?1:2;
	}
	,SubFn2: function() {
		var _t7;
		var _t8;
		this._latestPH = 89;
		_t7 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t8 = this._t5 < _t7;
		this._Next = _t8?4:2;
	}
	,SubFn1: function() {
		var _t2;
		var _t3;
		this._latestPH = 90;
		_t2 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t3 = _t2 - this._t5;
		this._t4 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t3) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t3);
		this._Next = 7;
	}
	,SubFn0: function() {
		this._latestPH = 87;
		this._t1 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g1 = 0, _g = $this._t0;
				while(_g1 < _g) {
					var _i = _g1++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,this._t0);
		this._Next = 3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 86;
				this._latestBlock = 0;
				this._latestPH = 87;
				this._SF1 = new tardis.Go_utf8_RuneCount(this._goroutine,[],this.p_s);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 87;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 87;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 87;
				this._latestBlock = 2;
				this._latestPH = 98;
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 98;
				this._latestBlock = 3;
				this._latestPH = 88;
				this._t5 = this._Phi == 0?0:this._Phi == 6?this._t20:0;
				this._latestPH = 89;
				this._t6 = this._Phi == 0?0:this._Phi == 6?this._t21:0;
				this.SubFn2();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 89;
				this._latestBlock = 4;
				this.SubFn3();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 89;
				this._latestBlock = 5;
				this.SubFn4();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 89;
				this._latestBlock = 6;
				this._latestPH = 94;
				this._SF2 = new tardis.Go_utf8_DecodeRune(this._goroutine,[],this._t4);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 94;
				this._latestBlock = -2;
				this._t16 = this._SF2.res();
				this.SubFn5();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 94;
				this._latestBlock = 7;
				this._latestPH = 91;
				this._t22 = this._Phi == 1?0:this._Phi == 5?this._t15:0;
				this.SubFn6();
				this._Phi = 7;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_UTF8toRunes
});
tardis.Go_utf16_EncodeRune = function(gr,_bds,p_r) {
	this._Next = 0;
	this._t8 = false;
	this._t7 = false;
	this._t6 = 0;
	this._t5 = 0;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,489,"Go_utf16_EncodeRune");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf16_EncodeRune"] = tardis.Go_utf16_EncodeRune;
$hxExpose(tardis.Go_utf16_EncodeRune, "Go_utf16_EncodeRune");
tardis.Go_utf16_EncodeRune.__name__ = ["tardis","Go_utf16_EncodeRune"];
tardis.Go_utf16_EncodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_EncodeRune.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf16_EncodeRune(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf16_EncodeRune.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_utf16_EncodeRune(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf16_EncodeRune.call = function(gr,_bds,p_r) {
	return new tardis.Go_utf16_EncodeRune(gr,_bds,p_r);
}
tardis.Go_utf16_EncodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_EncodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn3: function() {
		var _t8;
		this._latestPH = 490;
		_t8 = this.p_r > 1114111;
		this._Next = _t8?1:3;
	}
	,SubFn2: function() {
		this._Next = this._t7?1:2;
	}
	,SubFn1: function() {
		var _t2;
		var _t3;
		var _t5;
		this._t1 = tardis.Force.toInt32(this.p_r - 65536);
		this._latestPH = 494;
		_t2 = this._t1 >> tardis.Int64.getLow(new tardis.Int64(0,10));
		_t3 = tardis.Force.toInt32(_t2 & 1023);
		this._t4 = tardis.Force.toInt32(55296 + _t3);
		_t5 = tardis.Force.toInt32(this._t1 & 1023);
		this._t6 = tardis.Force.toInt32(56320 + _t5);
	}
	,SubFn0: function() {
		var _t0;
		_t0 = this.p_r < 65536;
		this._Next = _t0?1:4;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 489;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 489;
				this._latestBlock = 1;
				this._latestPH = 491;
				this._res = { r0 : 65533, r1 : 65533};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 491;
				this._latestBlock = 2;
				this.SubFn1();
				this._latestPH = 494;
				this._res = { r0 : this._t4, r1 : this._t6};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 494;
				this._latestBlock = 3;
				this._latestPH = 490;
				this._SF1 = new tardis.Go_utf16_IsSurrogate(this._goroutine,[],this.p_r);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 490;
				this._latestBlock = -1;
				this._t7 = this._SF1.res();
				this._Next = this._t7?1:2;
				break;
			case 4:
				this._latestPH = 490;
				this._latestBlock = 4;
				this.SubFn3();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf16_EncodeRune
});
tardis.Go_utf8_RuneLen = function(gr,_bds,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t7 = false;
	this._t6 = false;
	this._t5 = false;
	this._t4 = false;
	this._t3 = false;
	this._t2 = false;
	this._t1 = false;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,860,"Go_utf8_RuneLen");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_RuneLen"] = tardis.Go_utf8_RuneLen;
$hxExpose(tardis.Go_utf8_RuneLen, "Go_utf8_RuneLen");
tardis.Go_utf8_RuneLen.__name__ = ["tardis","Go_utf8_RuneLen"];
tardis.Go_utf8_RuneLen.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_RuneLen.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_RuneLen(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_RuneLen.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_utf8_RuneLen(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_RuneLen.call = function(gr,_bds,p_r) {
	return new tardis.Go_utf8_RuneLen(gr,_bds,p_r);
}
tardis.Go_utf8_RuneLen.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_RuneLen.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn7: function() {
		var _t7;
		this._latestPH = 872;
		_t7 = this.p_r <= 1114111;
		this._Next = _t7?12:14;
	}
	,SubFn6: function() {
		this._Next = this._t6?6:9;
	}
	,SubFn5: function() {
		this._latestPH = 868;
		this._t5 = this.p_r <= 57343;
		this._Next = 11;
	}
	,SubFn4: function() {
		var _t4;
		this._latestPH = 870;
		_t4 = this.p_r <= 65535;
		this._Next = _t4?8:13;
	}
	,SubFn3: function() {
		var _t3;
		this._latestPH = 868;
		_t3 = 55296 <= this.p_r;
		this._Next = _t3?10:11;
	}
	,SubFn2: function() {
		var _t2;
		this._latestPH = 866;
		_t2 = this.p_r <= 2047;
		this._Next = _t2?4:7;
	}
	,SubFn1: function() {
		var _t1;
		this._latestPH = 864;
		_t1 = this.p_r <= 127;
		this._Next = _t1?2:5;
	}
	,SubFn0: function() {
		var _t0;
		this._latestPH = 862;
		_t0 = this.p_r < 0;
		this._Next = _t0?1:3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 860;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 860;
				this._latestBlock = 1;
				this._latestPH = 863;
				this._res = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 863;
				this._latestBlock = 2;
				this._latestPH = 865;
				this._res = 1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 865;
				this._latestBlock = 3;
				this.SubFn1();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 865;
				this._latestBlock = 4;
				this._latestPH = 867;
				this._res = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 5:
				this._latestPH = 867;
				this._latestBlock = 5;
				this.SubFn2();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 867;
				this._latestBlock = 6;
				this._latestPH = 869;
				this._res = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 7:
				this._latestPH = 869;
				this._latestBlock = 7;
				this.SubFn3();
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 869;
				this._latestBlock = 8;
				this._latestPH = 871;
				this._res = 3;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 9:
				this._latestPH = 871;
				this._latestBlock = 9;
				this.SubFn4();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 871;
				this._latestBlock = 10;
				this._latestPH = 868;
				this._t5 = this.p_r <= 57343;
				this._Next = 11;
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 871;
				this._latestBlock = 11;
				this._latestPH = 868;
				this._t6 = this._Phi == 7?false:this._Phi == 10?this._t5:false;
				this._Next = this._t6?6:9;
				this._Phi = 11;
				break;
			case 12:
				this._latestPH = 868;
				this._latestBlock = 12;
				this._latestPH = 873;
				this._res = 4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 13:
				this._latestPH = 873;
				this._latestBlock = 13;
				this.SubFn7();
				this._Phi = 13;
				break;
			case 14:
				this._latestPH = 873;
				this._latestBlock = 14;
				this._latestPH = 875;
				this._res = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_RuneLen
});
tardis._Go.Go_haxegoruntime_init_36_1 = function(gr,_bds) {
	this._Next = 0;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,79,"Go_haxegoruntime_init_36_1");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_init_36_1"] = tardis._Go.Go_haxegoruntime_init_36_1;
tardis._Go.Go_haxegoruntime_init_36_1.__name__ = ["tardis","_Go","Go_haxegoruntime_init_36_1"];
tardis._Go.Go_haxegoruntime_init_36_1.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_init_36_1.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_init_36_1(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_haxegoruntime_init_36_1.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_haxegoruntime_init_36_1(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_haxegoruntime_init_36_1.call = function(gr,_bds) {
	return new tardis._Go.Go_haxegoruntime_init_36_1(gr,_bds);
}
tardis._Go.Go_haxegoruntime_init_36_1.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_init_36_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t1;
		_t1 = js.Boot.__cast(this._t0 , Int);
		tardis.Go.haxegoruntime_ZiLen.store(_t1);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 79;
				this._latestBlock = 0;
				this._latestPH = 80;
				this._t0 = "字".length;
				this.SubFn0();
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_haxegoruntime_init_36_1
});
tardis.Go_haxegoruntime_M5 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,220,"Go_haxegoruntime_M5");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	this.p_a5 = p_a5;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M5"] = tardis.Go_haxegoruntime_M5;
$hxExpose(tardis.Go_haxegoruntime_M5, "Go_haxegoruntime_M5");
tardis.Go_haxegoruntime_M5.__name__ = ["tardis","Go_haxegoruntime_M5"];
tardis.Go_haxegoruntime_M5.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M5.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M5(0,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M5.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5) {
	var _sf = new tardis.Go_haxegoruntime_M5(_gr,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M5.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5) {
	return new tardis.Go_haxegoruntime_M5(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5);
}
tardis.Go_haxegoruntime_M5.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M5.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 220;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M5
});
tardis._Go.Go_haxegoruntime_getgoroot = function(gr,_bds) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,435,"Go_haxegoruntime_getgoroot");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_getgoroot"] = tardis._Go.Go_haxegoruntime_getgoroot;
tardis._Go.Go_haxegoruntime_getgoroot.__name__ = ["tardis","_Go","Go_haxegoruntime_getgoroot"];
tardis._Go.Go_haxegoruntime_getgoroot.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_getgoroot.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_getgoroot(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_getgoroot.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_haxegoruntime_getgoroot(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_getgoroot.call = function(gr,_bds) {
	return new tardis._Go.Go_haxegoruntime_getgoroot(gr,_bds);
}
tardis._Go.Go_haxegoruntime_getgoroot.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_getgoroot.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.getgoroot() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 435;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.getgoroot() not yet implemented");
				this._latestPH = 436;
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 436;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_getgoroot
});
tardis.Go_haxegoruntime_C0 = function(gr,_bds,p_funcName) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,204,"Go_haxegoruntime_C0");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C0"] = tardis.Go_haxegoruntime_C0;
$hxExpose(tardis.Go_haxegoruntime_C0, "Go_haxegoruntime_C0");
tardis.Go_haxegoruntime_C0.__name__ = ["tardis","Go_haxegoruntime_C0"];
tardis.Go_haxegoruntime_C0.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C0.callFromHaxe = function(p_funcName) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C0(0,[],p_funcName).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C0.callFromRT = function(_gr,p_funcName) {
	var _sf = new tardis.Go_haxegoruntime_C0(_gr,[],p_funcName).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C0.call = function(gr,_bds,p_funcName) {
	return new tardis.Go_haxegoruntime_C0(gr,_bds,p_funcName);
}
tardis.Go_haxegoruntime_C0.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C0.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 204;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C0
});
tardis.Go_hxutil_CPos = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1013,"Go_hxutil_CPos");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_CPos"] = tardis.Go_hxutil_CPos;
$hxExpose(tardis.Go_hxutil_CPos, "Go_hxutil_CPos");
tardis.Go_hxutil_CPos.__name__ = ["tardis","Go_hxutil_CPos"];
tardis.Go_hxutil_CPos.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_CPos.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_CPos(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_CPos.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_CPos(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_CPos.call = function(gr,_bds) {
	return new tardis.Go_hxutil_CPos(gr,_bds);
}
tardis.Go_hxutil_CPos.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_CPos.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1013;
				this._latestBlock = 0;
				this._res = "<<go code pos>>";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_CPos
});
tardis._Go.Go_utf8_decodeRuneInternal = function(gr,_bds,p_p) {
	this._Next = 0;
	this._t60 = false;
	this._t59 = false;
	this._t58 = 0;
	this._t57 = 0;
	this._t56 = 0;
	this._t55 = 0;
	this._t54 = 0;
	this._t53 = 0;
	this._t52 = 0;
	this._t51 = 0;
	this._t50 = 0;
	this._t49 = 0;
	this._t48 = 0;
	this._t47 = 0;
	this._t46 = 0;
	this._t45 = 0;
	this._t44 = false;
	this._t43 = false;
	this._t42 = false;
	this._t41 = 0;
	this._t40 = null;
	this._t39 = false;
	this._t38 = false;
	this._t37 = false;
	this._t36 = false;
	this._t35 = 0;
	this._t34 = 0;
	this._t33 = 0;
	this._t32 = 0;
	this._t31 = 0;
	this._t30 = 0;
	this._t29 = 0;
	this._t28 = 0;
	this._t27 = 0;
	this._t26 = 0;
	this._t25 = false;
	this._t24 = false;
	this._t23 = false;
	this._t22 = 0;
	this._t21 = null;
	this._t20 = false;
	this._t19 = false;
	this._t18 = 0;
	this._t17 = 0;
	this._t16 = 0;
	this._t15 = 0;
	this._t14 = 0;
	this._t13 = 0;
	this._t12 = false;
	this._t11 = false;
	this._t10 = false;
	this._t9 = 0;
	this._t8 = null;
	this._t7 = false;
	this._t6 = false;
	this._t5 = 0;
	this._t4 = false;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,595,"Go_utf8_decodeRuneInternal");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_utf8_decodeRuneInternal"] = tardis._Go.Go_utf8_decodeRuneInternal;
tardis._Go.Go_utf8_decodeRuneInternal.__name__ = ["tardis","_Go","Go_utf8_decodeRuneInternal"];
tardis._Go.Go_utf8_decodeRuneInternal.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_utf8_decodeRuneInternal.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_utf8_decodeRuneInternal(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_utf8_decodeRuneInternal.callFromRT = function(_gr,p_p) {
	var _sf = new tardis._Go.Go_utf8_decodeRuneInternal(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_utf8_decodeRuneInternal.call = function(gr,_bds,p_p) {
	return new tardis._Go.Go_utf8_decodeRuneInternal(gr,_bds,p_p);
}
tardis._Go.Go_utf8_decodeRuneInternal.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_utf8_decodeRuneInternal.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn21: function() {
		var _t60;
		_t60 = 1114111 < this._t58;
		this._Next = _t60?35:36;
	}
	,SubFn20: function() {
		var _t45;
		var _t46;
		var _t47;
		var _t48;
		var _t49;
		var _t50;
		var _t51;
		var _t52;
		var _t53;
		var _t54;
		var _t55;
		var _t56;
		var _t57;
		var _t59;
		this._latestPH = 662;
		_t45 = this._t3 & 7 & 255;
		_t46 = _t45;
		_t47 = _t46 << tardis.Int64.getLow(new tardis.Int64(0,18));
		_t48 = this._t9 & 63 & 255;
		_t49 = _t48;
		_t50 = _t49 << tardis.Int64.getLow(new tardis.Int64(0,12));
		_t51 = tardis.Force.toInt32(_t47 | _t50);
		_t52 = this._t22 & 63 & 255;
		_t53 = _t52;
		_t54 = _t53 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t55 = tardis.Force.toInt32(_t51 | _t54);
		_t56 = this._t41 & 63 & 255;
		_t57 = _t56;
		this._t58 = tardis.Force.toInt32(_t55 | _t57);
		this._latestPH = 663;
		_t59 = this._t58 <= 65535;
		this._Next = _t59?35:37;
	}
	,SubFn19: function() {
		var _t44;
		this._latestPH = 656;
		_t44 = tardis.Force.uintCompare(192,this._t41) <= 0;
		this._Next = _t44?30:31;
	}
	,SubFn18: function() {
		var _t43;
		this._latestPH = 661;
		_t43 = tardis.Force.uintCompare(this._t3,248) < 0;
		this._Next = _t43?33:34;
	}
	,SubFn17: function() {
		var _t40;
		var _t42;
		this._latestPH = 655;
		if(3 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t40 = this.p_p.addr(3);
		this._t41 = _t40.ref() | 0;
		this._latestPH = 656;
		_t42 = tardis.Force.uintCompare(this._t41,128) < 0;
		this._Next = _t42?30:32;
	}
	,SubFn16: function() {
		var _t39;
		_t39 = this._t35 <= 57343;
		this._Next = _t39?25:26;
	}
	,SubFn15: function() {
		var _t38;
		this._latestPH = 645;
		_t38 = 55296 <= this._t35;
		this._Next = _t38?27:26;
	}
	,SubFn14: function() {
		var _t37;
		this._latestPH = 652;
		_t37 = this._t0 < 4;
		this._Next = _t37?28:29;
	}
	,SubFn13: function() {
		var _t26;
		var _t27;
		var _t28;
		var _t29;
		var _t30;
		var _t31;
		var _t32;
		var _t33;
		var _t34;
		var _t36;
		this._latestPH = 641;
		_t26 = this._t3 & 15 & 255;
		_t27 = _t26;
		_t28 = _t27 << tardis.Int64.getLow(new tardis.Int64(0,12));
		_t29 = this._t9 & 63 & 255;
		_t30 = _t29;
		_t31 = _t30 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t32 = tardis.Force.toInt32(_t28 | _t31);
		_t33 = this._t22 & 63 & 255;
		_t34 = _t33;
		this._t35 = tardis.Force.toInt32(_t32 | _t34);
		this._latestPH = 642;
		_t36 = this._t35 <= 2047;
		this._Next = _t36?23:24;
	}
	,SubFn12: function() {
		var _t25;
		this._latestPH = 635;
		_t25 = tardis.Force.uintCompare(192,this._t22) <= 0;
		this._Next = _t25?18:19;
	}
	,SubFn11: function() {
		var _t24;
		this._latestPH = 640;
		_t24 = tardis.Force.uintCompare(this._t3,240) < 0;
		this._Next = _t24?21:22;
	}
	,SubFn10: function() {
		var _t21;
		var _t23;
		this._latestPH = 634;
		if(2 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t21 = this.p_p.addr(2);
		this._t22 = _t21.ref() | 0;
		this._latestPH = 635;
		_t23 = tardis.Force.uintCompare(this._t22,128) < 0;
		this._Next = _t23?18:20;
	}
	,SubFn9: function() {
		var _t20;
		this._latestPH = 631;
		_t20 = this._t0 < 3;
		this._Next = _t20?16:17;
	}
	,SubFn8: function() {
		var _t13;
		var _t14;
		var _t15;
		var _t16;
		var _t17;
		var _t19;
		this._latestPH = 623;
		_t13 = this._t3 & 31 & 255;
		_t14 = _t13;
		_t15 = _t14 << tardis.Int64.getLow(new tardis.Int64(0,6));
		_t16 = this._t9 & 63 & 255;
		_t17 = _t16;
		this._t18 = tardis.Force.toInt32(_t15 | _t17);
		this._latestPH = 624;
		_t19 = this._t18 <= 127;
		this._Next = _t19?14:15;
	}
	,SubFn7: function() {
		var _t12;
		this._latestPH = 617;
		_t12 = tardis.Force.uintCompare(192,this._t9) <= 0;
		this._Next = _t12?9:10;
	}
	,SubFn6: function() {
		var _t11;
		this._latestPH = 622;
		_t11 = tardis.Force.uintCompare(this._t3,224) < 0;
		this._Next = _t11?12:13;
	}
	,SubFn5: function() {
		var _t8;
		var _t10;
		this._latestPH = 616;
		if(1 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t8 = this.p_p.addr(1);
		this._t9 = _t8.ref() | 0;
		this._latestPH = 617;
		_t10 = tardis.Force.uintCompare(this._t9,128) < 0;
		this._Next = _t10?9:11;
	}
	,SubFn4: function() {
		var _t7;
		this._latestPH = 613;
		_t7 = this._t0 < 2;
		this._Next = _t7?7:8;
	}
	,SubFn3: function() {
		var _t6;
		this._latestPH = 608;
		_t6 = tardis.Force.uintCompare(this._t3,192) < 0;
		this._Next = _t6?5:6;
	}
	,SubFn2: function() {
		this._latestPH = 604;
		this._t5 = this._t3;
	}
	,SubFn1: function() {
		var _t2;
		var _t4;
		this._latestPH = 600;
		if(0 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t2 = this.p_p.addr(0);
		this._t3 = _t2.ref() | 0;
		this._latestPH = 603;
		_t4 = tardis.Force.uintCompare(this._t3,128) < 0;
		this._Next = _t4?3:4;
	}
	,SubFn0: function() {
		var _t1;
		this._latestPH = 596;
		this._t0 = (function($this) {
			var $r;
			var _v = $this.p_p;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._latestPH = 597;
		_t1 = this._t0 < 1;
		this._Next = _t1?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 595;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 595;
				this._latestBlock = 1;
				this._latestPH = 598;
				this._res = { r0 : 65533, r1 : 0, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 598;
				this._latestBlock = 2;
				this.SubFn1();
				break;
			case 3:
				this._latestPH = 598;
				this._latestBlock = 3;
				this._latestPH = 604;
				this._t5 = this._t3;
				this._latestPH = 604;
				this._res = { r0 : this._t5, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 604;
				this._latestBlock = 4;
				this.SubFn3();
				break;
			case 5:
				this._latestPH = 604;
				this._latestBlock = 5;
				this._latestPH = 609;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 6:
				this._latestPH = 609;
				this._latestBlock = 6;
				this.SubFn4();
				break;
			case 7:
				this._latestPH = 609;
				this._latestBlock = 7;
				this._latestPH = 614;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 614;
				this._latestBlock = 8;
				this.SubFn5();
				break;
			case 9:
				this._latestPH = 614;
				this._latestBlock = 9;
				this._latestPH = 618;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 10:
				this._latestPH = 618;
				this._latestBlock = 10;
				this.SubFn6();
				break;
			case 11:
				this._latestPH = 618;
				this._latestBlock = 11;
				this.SubFn7();
				break;
			case 12:
				this._latestPH = 618;
				this._latestBlock = 12;
				this.SubFn8();
				break;
			case 13:
				this._latestPH = 618;
				this._latestBlock = 13;
				this.SubFn9();
				break;
			case 14:
				this._latestPH = 618;
				this._latestBlock = 14;
				this._latestPH = 625;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 15:
				this._latestPH = 625;
				this._latestBlock = 15;
				this._latestPH = 627;
				this._res = { r0 : this._t18, r1 : 2, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 16:
				this._latestPH = 627;
				this._latestBlock = 16;
				this._latestPH = 632;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 17:
				this._latestPH = 632;
				this._latestBlock = 17;
				this.SubFn10();
				break;
			case 18:
				this._latestPH = 632;
				this._latestBlock = 18;
				this._latestPH = 636;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 19:
				this._latestPH = 636;
				this._latestBlock = 19;
				this.SubFn11();
				break;
			case 20:
				this._latestPH = 636;
				this._latestBlock = 20;
				this.SubFn12();
				break;
			case 21:
				this._latestPH = 636;
				this._latestBlock = 21;
				this.SubFn13();
				break;
			case 22:
				this._latestPH = 636;
				this._latestBlock = 22;
				this.SubFn14();
				break;
			case 23:
				this._latestPH = 636;
				this._latestBlock = 23;
				this._latestPH = 643;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 24:
				this._latestPH = 643;
				this._latestBlock = 24;
				this.SubFn15();
				break;
			case 25:
				this._latestPH = 643;
				this._latestBlock = 25;
				this._latestPH = 646;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 26:
				this._latestPH = 646;
				this._latestBlock = 26;
				this._latestPH = 648;
				this._res = { r0 : this._t35, r1 : 3, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 27:
				this._latestPH = 648;
				this._latestBlock = 27;
				this.SubFn16();
				break;
			case 28:
				this._latestPH = 648;
				this._latestBlock = 28;
				this._latestPH = 653;
				this._res = { r0 : 65533, r1 : 1, r2 : true};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 29:
				this._latestPH = 653;
				this._latestBlock = 29;
				this.SubFn17();
				break;
			case 30:
				this._latestPH = 653;
				this._latestBlock = 30;
				this._latestPH = 657;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 31:
				this._latestPH = 657;
				this._latestBlock = 31;
				this.SubFn18();
				break;
			case 32:
				this._latestPH = 657;
				this._latestBlock = 32;
				this.SubFn19();
				break;
			case 33:
				this._latestPH = 657;
				this._latestBlock = 33;
				this.SubFn20();
				break;
			case 34:
				this._latestPH = 657;
				this._latestBlock = 34;
				this._latestPH = 670;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 35:
				this._latestPH = 670;
				this._latestBlock = 35;
				this._latestPH = 664;
				this._res = { r0 : 65533, r1 : 1, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 36:
				this._latestPH = 664;
				this._latestBlock = 36;
				this._latestPH = 666;
				this._res = { r0 : this._t58, r1 : 4, r2 : false};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 37:
				this._latestPH = 666;
				this._latestBlock = 37;
				this.SubFn21();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_utf8_decodeRuneInternal
});
tardis.Go_utf16_IsSurrogate = function(gr,_bds,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t2 = false;
	this._t1 = false;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,472,"Go_utf16_IsSurrogate");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf16_IsSurrogate"] = tardis.Go_utf16_IsSurrogate;
$hxExpose(tardis.Go_utf16_IsSurrogate, "Go_utf16_IsSurrogate");
tardis.Go_utf16_IsSurrogate.__name__ = ["tardis","Go_utf16_IsSurrogate"];
tardis.Go_utf16_IsSurrogate.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_IsSurrogate.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf16_IsSurrogate(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf16_IsSurrogate.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_utf16_IsSurrogate(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf16_IsSurrogate.call = function(gr,_bds,p_r) {
	return new tardis.Go_utf16_IsSurrogate(gr,_bds,p_r);
}
tardis.Go_utf16_IsSurrogate.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_IsSurrogate.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn1: function() {
		this._t1 = this.p_r < 57344;
		this._Next = 2;
	}
	,SubFn0: function() {
		var _t0;
		_t0 = 55296 <= this.p_r;
		this._Next = _t0?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 472;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 472;
				this._latestBlock = 1;
				this._t1 = this.p_r < 57344;
				this._Next = 2;
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 472;
				this._latestBlock = 2;
				this._latestPH = 473;
				this._t2 = this._Phi == 0?false:this._Phi == 1?this._t1:false;
				this._res = this._t2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf16_IsSurrogate
});
tardis.Go_haxegoruntime_M2 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,217,"Go_haxegoruntime_M2");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M2"] = tardis.Go_haxegoruntime_M2;
$hxExpose(tardis.Go_haxegoruntime_M2, "Go_haxegoruntime_M2");
tardis.Go_haxegoruntime_M2.__name__ = ["tardis","Go_haxegoruntime_M2"];
tardis.Go_haxegoruntime_M2.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M2.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1,p_a2) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M2(0,[],p_rx,p_typ,p_meth,p_a1,p_a2).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M2.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1,p_a2) {
	var _sf = new tardis.Go_haxegoruntime_M2(_gr,[],p_rx,p_typ,p_meth,p_a1,p_a2).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M2.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2) {
	return new tardis.Go_haxegoruntime_M2(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2);
}
tardis.Go_haxegoruntime_M2.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M2.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 217;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M2
});
tardis._Go.Go_haxegoruntime_funcname_go = function(gr,_bds,p_arg0) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,419,"Go_haxegoruntime_funcname_go");
	this._bds = _bds;
	this.p_arg0 = p_arg0;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_funcname_go"] = tardis._Go.Go_haxegoruntime_funcname_go;
tardis._Go.Go_haxegoruntime_funcname_go.__name__ = ["tardis","_Go","Go_haxegoruntime_funcname_go"];
tardis._Go.Go_haxegoruntime_funcname_go.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_funcname_go.callFromHaxe = function(p_arg0) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_funcname_go(0,[],p_arg0).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcname_go.callFromRT = function(_gr,p_arg0) {
	var _sf = new tardis._Go.Go_haxegoruntime_funcname_go(_gr,[],p_arg0).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcname_go.call = function(gr,_bds,p_arg0) {
	return new tardis._Go.Go_haxegoruntime_funcname_go(gr,_bds,p_arg0);
}
tardis._Go.Go_haxegoruntime_funcname_go.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_funcname_go.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.funcname_go() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 419;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.funcname_go() not yet implemented");
				this._latestPH = 420;
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 420;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_funcname_go
});
tardis.Go_utf8_RuneStart = function(gr,_bds,p_b) {
	this._Next = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,942,"Go_utf8_RuneStart");
	this._bds = _bds;
	this.p_b = p_b;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_RuneStart"] = tardis.Go_utf8_RuneStart;
$hxExpose(tardis.Go_utf8_RuneStart, "Go_utf8_RuneStart");
tardis.Go_utf8_RuneStart.__name__ = ["tardis","Go_utf8_RuneStart"];
tardis.Go_utf8_RuneStart.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_RuneStart.callFromHaxe = function(p_b) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_RuneStart(0,[],p_b).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_RuneStart.callFromRT = function(_gr,p_b) {
	var _sf = new tardis.Go_utf8_RuneStart(_gr,[],p_b).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_RuneStart.call = function(gr,_bds,p_b) {
	return new tardis.Go_utf8_RuneStart(gr,_bds,p_b);
}
tardis.Go_utf8_RuneStart.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_RuneStart.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t0;
		_t0 = this.p_b & 192 & 255;
		this._t1 = tardis.Force.uintCompare(_t0,128) != 0;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 942;
				this._latestBlock = 0;
				this.SubFn0();
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_RuneStart
});
tardis.Go_hxutil_Gosched = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1030,"Go_hxutil_Gosched");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_Gosched"] = tardis.Go_hxutil_Gosched;
$hxExpose(tardis.Go_hxutil_Gosched, "Go_hxutil_Gosched");
tardis.Go_hxutil_Gosched.__name__ = ["tardis","Go_hxutil_Gosched"];
tardis.Go_hxutil_Gosched.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_Gosched.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_Gosched(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_hxutil_Gosched.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_Gosched(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_hxutil_Gosched.call = function(gr,_bds) {
	return new tardis.Go_hxutil_Gosched(gr,_bds);
}
tardis.Go_hxutil_Gosched.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_Gosched.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1030;
				this._latestBlock = 0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_hxutil_Gosched
});
tardis.Go_utf16_Decode = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t42 = false;
	this._t41 = false;
	this._t40 = 0;
	this._t39 = 0;
	this._t38 = null;
	this._t37 = false;
	this._t36 = false;
	this._t35 = 0;
	this._t34 = 0;
	this._t33 = false;
	this._t32 = 0;
	this._t31 = null;
	this._t30 = 0;
	this._t29 = false;
	this._t28 = false;
	this._t27 = 0;
	this._t26 = null;
	this._t25 = 0;
	this._t24 = false;
	this._t23 = 0;
	this._t22 = null;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = 0;
	this._t18 = 0;
	this._t17 = 0;
	this._t16 = null;
	this._t15 = 0;
	this._t14 = 0;
	this._t13 = null;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = 0;
	this._t9 = false;
	this._t8 = 0;
	this._t7 = 0;
	this._t6 = 0;
	this._t5 = null;
	this._t4 = false;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = null;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,528,"Go_utf16_Decode");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf16_Decode"] = tardis.Go_utf16_Decode;
$hxExpose(tardis.Go_utf16_Decode, "Go_utf16_Decode");
tardis.Go_utf16_Decode.__name__ = ["tardis","Go_utf16_Decode"];
tardis.Go_utf16_Decode.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_Decode.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf16_Decode(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf16_Decode.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf16_Decode(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf16_Decode.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf16_Decode(gr,_bds,p_s);
}
tardis.Go_utf16_Decode.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_Decode.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn16: function() {
		this._Next = this._t42?6:13;
	}
	,SubFn15: function() {
		this._latestPH = 539;
		this._t41 = tardis.Force.uintCompare(this._t3,57344) < 0;
		this._Next = 15;
	}
	,SubFn14: function() {
		var _t38;
		var _t39;
		this._latestPH = 545;
		if(this._t6 < 0 || this._t6 >= this._t1.len()) tardis.Scheduler.ioor();
		_t38 = this._t1.addr(this._t6);
		_t39 = this._t3;
		_t38.store(_t39);
		this._t40 = this._t6 + 1;
		this._Next = 4;
	}
	,SubFn13: function() {
		var _t37;
		_t37 = tardis.Force.uintCompare(this._t3,56320) < 0;
		this._Next = _t37?11:9;
	}
	,SubFn12: function() {
		var _t34;
		var _t35;
		var _t36;
		this._latestPH = 533;
		_t34 = this._t7 + 1;
		_t35 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t36 = _t34 < _t35;
		this._Next = _t36?10:9;
	}
	,SubFn11: function() {
		var _t30;
		var _t31;
		var _t32;
		var _t33;
		_t30 = this._t7 + 1;
		if(_t30 < 0 || _t30 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t31 = this.p_s.addr(_t30);
		_t32 = _t31.ref() | 0;
		_t33 = tardis.Force.uintCompare(56320,_t32) <= 0;
		this._Next = _t33?8:9;
	}
	,SubFn10: function() {
		this._Next = this._t29?5:7;
	}
	,SubFn9: function() {
		var _t25;
		var _t26;
		var _t27;
		this._latestPH = 534;
		_t25 = this._t7 + 1;
		if(_t25 < 0 || _t25 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t26 = this.p_s.addr(_t25);
		_t27 = _t26.ref() | 0;
		this._t28 = tardis.Force.uintCompare(_t27,57344) < 0;
		this._Next = 9;
	}
	,SubFn8: function() {
		var _t24;
		this._latestPH = 539;
		_t24 = tardis.Force.uintCompare(55296,this._t3) <= 0;
		this._Next = _t24?14:15;
	}
	,SubFn7: function() {
		var _t22;
		this._latestPH = 541;
		if(this._t6 < 0 || this._t6 >= this._t1.len()) tardis.Scheduler.ioor();
		_t22 = this._t1.addr(this._t6);
		_t22.store(65533);
		this._t23 = this._t6 + 1;
		this._Next = 4;
	}
	,SubFn6: function() {
		this._t13.store(this._t19);
		this._t20 = this._t7 + 1;
		this._t21 = this._t6 + 1;
		this._Next = 4;
	}
	,SubFn5: function() {
		var _t15;
		var _t16;
		var _t17;
		this._latestPH = 536;
		if(this._t6 < 0 || this._t6 >= this._t1.len()) tardis.Scheduler.ioor();
		this._t13 = this._t1.addr(this._t6);
		this._t14 = this._t3;
		_t15 = this._t7 + 1;
		if(_t15 < 0 || _t15 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t16 = this.p_s.addr(_t15);
		_t17 = _t16.ref() | 0;
		this._t18 = _t17;
	}
	,SubFn4: function() {
		this._t12 = this._t11 + 1;
		this._Next = 3;
	}
	,SubFn3: function() {
		var _t8;
		var _t9;
		this._latestPH = 531;
		_t8 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t9 = this._t7 < _t8;
		this._Next = _t9?1:2;
	}
	,SubFn2: function() {
		this._latestPH = 549;
		this._t5 = this._t1.subSlice(0,this._t6);
	}
	,SubFn1: function() {
		var _t2;
		var _t4;
		this._latestPH = 532;
		if(this._t7 < 0 || this._t7 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t2 = this.p_s.addr(this._t7);
		this._t3 = _t2.ref() | 0;
		this._latestPH = 533;
		_t4 = tardis.Force.uintCompare(55296,this._t3) <= 0;
		this._Next = _t4?12:9;
	}
	,SubFn0: function() {
		var _t0;
		this._latestPH = 529;
		_t0 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t1 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t0) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t0);
		this._Next = 3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 528;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 528;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 528;
				this._latestBlock = 2;
				this._latestPH = 549;
				this._t5 = this._t1.subSlice(0,this._t6);
				this._latestPH = 549;
				this._res = this._t5;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 549;
				this._latestBlock = 3;
				this._latestPH = 530;
				this._t6 = this._Phi == 0?0:this._Phi == 4?this._t10:0;
				this._latestPH = 531;
				this._t7 = this._Phi == 0?0:this._Phi == 4?this._t12:0;
				this.SubFn3();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 531;
				this._latestBlock = 4;
				this._latestPH = 530;
				this._t10 = this._Phi == 5?this._t21:this._Phi == 6?this._t23:this._Phi == 13?this._t40:0;
				this._latestPH = 531;
				this._t11 = this._Phi == 5?this._t20:this._Phi == 6?this._t7:this._Phi == 13?this._t7:0;
				this._t12 = this._t11 + 1;
				this._Next = 3;
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 531;
				this._latestBlock = 5;
				this.SubFn5();
				this._latestPH = 536;
				this._SF1 = new tardis.Go_utf16_DecodeRune(this._goroutine,[],this._t14,this._t18);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 536;
				this._latestBlock = -1;
				this._t19 = this._SF1.res();
				this._t13.store(this._t19);
				this._t20 = this._t7 + 1;
				this._t21 = this._t6 + 1;
				this._Next = 4;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 536;
				this._latestBlock = 6;
				this.SubFn7();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 536;
				this._latestBlock = 7;
				this.SubFn8();
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 536;
				this._latestBlock = 8;
				this.SubFn9();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 536;
				this._latestBlock = 9;
				this._latestPH = 534;
				this._t29 = this._Phi == 1?false:this._Phi == 12?false:this._Phi == 11?false:this._Phi == 10?false:this._Phi == 8?this._t28:false;
				this._Next = this._t29?5:7;
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 534;
				this._latestBlock = 10;
				this.SubFn11();
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 534;
				this._latestBlock = 11;
				this.SubFn12();
				this._Phi = 11;
				break;
			case 12:
				this._latestPH = 534;
				this._latestBlock = 12;
				this.SubFn13();
				this._Phi = 12;
				break;
			case 13:
				this._latestPH = 534;
				this._latestBlock = 13;
				this.SubFn14();
				this._Phi = 13;
				break;
			case 14:
				this._latestPH = 534;
				this._latestBlock = 14;
				this._latestPH = 539;
				this._t41 = tardis.Force.uintCompare(this._t3,57344) < 0;
				this._Next = 15;
				this._Phi = 14;
				break;
			case 15:
				this._latestPH = 534;
				this._latestBlock = 15;
				this._latestPH = 539;
				this._t42 = this._Phi == 7?false:this._Phi == 14?this._t41:false;
				this._Next = this._t42?6:13;
				this._Phi = 15;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf16_Decode
});
tardis.Go_utf8_RuneCount = function(gr,_bds,p_p) {
	this._Next = 0;
	this._Phi = 0;
	this._t16 = 0;
	this._t15 = 0;
	this._t13 = null;
	this._t12 = null;
	this._t11 = 0;
	this._t10 = 0;
	this._t9 = 0;
	this._t8 = 0;
	this._t7 = false;
	this._t6 = 0;
	this._t5 = 0;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = false;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,917,"Go_utf8_RuneCount");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_RuneCount"] = tardis.Go_utf8_RuneCount;
$hxExpose(tardis.Go_utf8_RuneCount, "Go_utf8_RuneCount");
tardis.Go_utf8_RuneCount.__name__ = ["tardis","Go_utf8_RuneCount"];
tardis.Go_utf8_RuneCount.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_RuneCount.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_RuneCount(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_RuneCount.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_RuneCount(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_RuneCount.call = function(gr,_bds,p_p) {
	return new tardis.Go_utf8_RuneCount(gr,_bds,p_p);
}
tardis.Go_utf8_RuneCount.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_RuneCount.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn6: function() {
		this._t15 = this._t13.r1;
		this._t16 = this._t3 + this._t15;
		this._Next = 5;
	}
	,SubFn5: function() {
		this._latestPH = 924;
		this._t12 = this.p_p.subSlice(this._t3,-1);
	}
	,SubFn4: function() {
		this._t11 = this._t4 + 1;
		this._Next = 3;
	}
	,SubFn3: function() {
		this._t8 = this._t3 + 1;
		this._Next = 5;
	}
	,SubFn2: function() {
		var _t6;
		var _t7;
		this._latestPH = 920;
		_t6 = (function($this) {
			var $r;
			var _v = $this.p_p;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t7 = this._t3 < _t6;
		this._Next = _t7?1:2;
	}
	,SubFn1: function() {
		var _t0;
		var _t1;
		var _t2;
		this._latestPH = 921;
		if(this._t3 < 0 || this._t3 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t0 = this.p_p.addr(this._t3);
		_t1 = _t0.ref() | 0;
		_t2 = tardis.Force.uintCompare(_t1,128) < 0;
		this._Next = _t2?4:6;
	}
	,SubFn0: function() {
		this._Next = 3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 917;
				this._latestBlock = 0;
				this._Next = 3;
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 917;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 917;
				this._latestBlock = 2;
				this._latestPH = 928;
				this._res = this._t4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 928;
				this._latestBlock = 3;
				this._latestPH = 918;
				this._t3 = this._Phi == 0?0:this._Phi == 5?this._t9:0;
				this._latestPH = 919;
				this._t4 = this._Phi == 0?0:this._Phi == 5?this._t11:0;
				this._latestPH = 924;
				this._t5 = this._Phi == 0?0:this._Phi == 5?this._t10:0;
				this.SubFn2();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 924;
				this._latestBlock = 4;
				this._t8 = this._t3 + 1;
				this._Next = 5;
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 924;
				this._latestBlock = 5;
				this._latestPH = 918;
				this._t9 = this._Phi == 4?this._t8:this._Phi == 6?this._t16:0;
				this._latestPH = 924;
				this._t10 = this._Phi == 4?this._t5:this._Phi == 6?this._t15:0;
				this._t11 = this._t4 + 1;
				this._Next = 3;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 924;
				this._latestBlock = 6;
				this._latestPH = 924;
				this._t12 = this.p_p.subSlice(this._t3,-1);
				this._SF1 = new tardis.Go_utf8_DecodeRune(this._goroutine,[],this._t12);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 924;
				this._latestBlock = -1;
				this._t13 = this._SF1.res();
				this._t15 = this._t13.r1;
				this._t16 = this._t3 + this._t15;
				this._Next = 5;
				this._Phi = 6;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_RuneCount
});
tardis._Go.Go_haxegoruntime_init = function(gr,_bds) {
	this._Next = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,924,"Go_haxegoruntime_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_init"] = tardis._Go.Go_haxegoruntime_init;
tardis._Go.Go_haxegoruntime_init.__name__ = ["tardis","_Go","Go_haxegoruntime_init"];
tardis._Go.Go_haxegoruntime_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_init.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_init(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_haxegoruntime_init.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_haxegoruntime_init(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_haxegoruntime_init.call = function(gr,_bds) {
	return new tardis._Go.Go_haxegoruntime_init(gr,_bds);
}
tardis._Go.Go_haxegoruntime_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn2: function() {
		this._Next = 2;
	}
	,SubFn1: function() {
		tardis.Go.haxegoruntime_init_36_guard.store(true);
	}
	,SubFn0: function() {
		var _t0;
		_t0 = tardis.Go.haxegoruntime_init_36_guard.ref();
		this._Next = _t0?2:1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 924;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 924;
				this._latestBlock = 1;
				tardis.Go.haxegoruntime_init_36_guard.store(true);
				new tardis._Go.Go_utf16_init(this._goroutine,[]);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 924;
				this._latestBlock = -1;
				new tardis._Go.Go_utf8_init(this._goroutine,[]);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 924;
				this._latestBlock = -2;
				new tardis._Go.Go_hxutil_init(this._goroutine,[]);
				this._Next = -3;
				return this;
			case -3:
				this._latestPH = 924;
				this._latestBlock = -3;
				new tardis._Go.Go_haxegoruntime_init_36_1(this._goroutine,[]);
				this._Next = -4;
				return this;
			case -4:
				this._latestPH = 924;
				this._latestBlock = -4;
				this._Next = 2;
				break;
			case 2:
				this._latestPH = 924;
				this._latestBlock = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_haxegoruntime_init
});
tardis.Go_hxutil_StringsUTF8 = function(gr,_bds) {
	this._Next = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,1020,"Go_hxutil_StringsUTF8");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_StringsUTF8"] = tardis.Go_hxutil_StringsUTF8;
$hxExpose(tardis.Go_hxutil_StringsUTF8, "Go_hxutil_StringsUTF8");
tardis.Go_hxutil_StringsUTF8.__name__ = ["tardis","Go_hxutil_StringsUTF8"];
tardis.Go_hxutil_StringsUTF8.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_StringsUTF8.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_StringsUTF8(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_StringsUTF8.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_StringsUTF8(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_StringsUTF8.call = function(gr,_bds) {
	return new tardis.Go_hxutil_StringsUTF8(gr,_bds);
}
tardis.Go_hxutil_StringsUTF8.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_StringsUTF8.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = tardis.Force.uintCompare(this._t0,3) == 0;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1020;
				this._latestBlock = 0;
				this._t0 = "字".length;
				this._t1 = tardis.Force.uintCompare(this._t0,3) == 0;
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_StringsUTF8
});
tardis.Go_haxegoruntime_M6 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,221,"Go_haxegoruntime_M6");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	this.p_a5 = p_a5;
	this.p_a6 = p_a6;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M6"] = tardis.Go_haxegoruntime_M6;
$hxExpose(tardis.Go_haxegoruntime_M6, "Go_haxegoruntime_M6");
tardis.Go_haxegoruntime_M6.__name__ = ["tardis","Go_haxegoruntime_M6"];
tardis.Go_haxegoruntime_M6.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M6.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M6(0,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M6.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	var _sf = new tardis.Go_haxegoruntime_M6(_gr,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M6.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	return new tardis.Go_haxegoruntime_M6(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6);
}
tardis.Go_haxegoruntime_M6.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M6.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 221;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M6
});
tardis.Go_haxegoruntime_C1 = function(gr,_bds,p_funcName,p_a1) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,205,"Go_haxegoruntime_C1");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C1"] = tardis.Go_haxegoruntime_C1;
$hxExpose(tardis.Go_haxegoruntime_C1, "Go_haxegoruntime_C1");
tardis.Go_haxegoruntime_C1.__name__ = ["tardis","Go_haxegoruntime_C1"];
tardis.Go_haxegoruntime_C1.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C1.callFromHaxe = function(p_funcName,p_a1) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C1(0,[],p_funcName,p_a1).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C1.callFromRT = function(_gr,p_funcName,p_a1) {
	var _sf = new tardis.Go_haxegoruntime_C1(_gr,[],p_funcName,p_a1).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C1.call = function(gr,_bds,p_funcName,p_a1) {
	return new tardis.Go_haxegoruntime_C1(gr,_bds,p_funcName,p_a1);
}
tardis.Go_haxegoruntime_C1.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 205;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C1
});
tardis._Go.Go_main_init = function(gr,_bds) {
	this._Next = 0;
	this._t1 = null;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,205,"Go_main_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_main_init"] = tardis._Go.Go_main_init;
tardis._Go.Go_main_init.__name__ = ["tardis","_Go","Go_main_init"];
tardis._Go.Go_main_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_init.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_main_init(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_main_init.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_main_init(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_main_init.call = function(gr,_bds) {
	return new tardis._Go.Go_main_init(gr,_bds);
}
tardis._Go.Go_main_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn2: function() {
		this._Next = 2;
	}
	,SubFn1: function() {
		var _t1;
		tardis.Go.main_init_36_guard.store(true);
		this._latestPH = 17;
		_t1 = new tardis.Channel(100);
		tardis.Go.main_mouseEvents.store(_t1);
	}
	,SubFn0: function() {
		var _t0;
		_t0 = tardis.Go.main_init_36_guard.ref();
		this._Next = _t0?2:1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 205;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 205;
				this._latestBlock = 1;
				this.SubFn1();
				new tardis._Go.Go_main_init_36_1(this._goroutine,[]);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 205;
				this._latestBlock = -1;
				this._Next = 2;
				break;
			case 2:
				this._latestPH = 205;
				this._latestBlock = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_main_init
});
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine = function(gr,_bds) {
	this._Next = 0;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,403,"Go_haxegoruntime_runtime_NumGoroutine");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_runtime_NumGoroutine"] = tardis._Go.Go_haxegoruntime_runtime_NumGoroutine;
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.__name__ = ["tardis","_Go","Go_haxegoruntime_runtime_NumGoroutine"];
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_runtime_NumGoroutine(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_haxegoruntime_runtime_NumGoroutine(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.call = function(gr,_bds) {
	return new tardis._Go.Go_haxegoruntime_runtime_NumGoroutine(gr,_bds);
}
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_runtime_NumGoroutine.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = js.Boot.__cast(this._t0 , Int);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 403;
				this._latestBlock = 0;
				this._t0 = tardis.Scheduler.grStacks.length;
				this._t1 = js.Boot.__cast(this._t0 , Int);
				this._res = this._t1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_runtime_NumGoroutine
});
tardis.Go_haxegoruntime_Host = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,192,"Go_haxegoruntime_Host");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Host"] = tardis.Go_haxegoruntime_Host;
$hxExpose(tardis.Go_haxegoruntime_Host, "Go_haxegoruntime_Host");
tardis.Go_haxegoruntime_Host.__name__ = ["tardis","Go_haxegoruntime_Host"];
tardis.Go_haxegoruntime_Host.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Host.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Host(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Host.callFromRT = function(_gr) {
	var _sf = new tardis.Go_haxegoruntime_Host(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Host.call = function(gr,_bds) {
	return new tardis.Go_haxegoruntime_Host(gr,_bds);
}
tardis.Go_haxegoruntime_Host.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Host.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 192;
				this._latestBlock = 0;
				this._res = "Go";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Host
});
tardis.Go_haxegoruntime_C3 = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,207,"Go_haxegoruntime_C3");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C3"] = tardis.Go_haxegoruntime_C3;
$hxExpose(tardis.Go_haxegoruntime_C3, "Go_haxegoruntime_C3");
tardis.Go_haxegoruntime_C3.__name__ = ["tardis","Go_haxegoruntime_C3"];
tardis.Go_haxegoruntime_C3.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C3.callFromHaxe = function(p_funcName,p_a1,p_a2,p_a3) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C3(0,[],p_funcName,p_a1,p_a2,p_a3).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C3.callFromRT = function(_gr,p_funcName,p_a1,p_a2,p_a3) {
	var _sf = new tardis.Go_haxegoruntime_C3(_gr,[],p_funcName,p_a1,p_a2,p_a3).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C3.call = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3) {
	return new tardis.Go_haxegoruntime_C3(gr,_bds,p_funcName,p_a1,p_a2,p_a3);
}
tardis.Go_haxegoruntime_C3.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C3.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 207;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C3
});
tardis.Go_main_MouseUp = function(gr,_bds,p_x,p_y) {
	this._Next = 0;
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,19,"Go_main_MouseUp");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_main_MouseUp"] = tardis.Go_main_MouseUp;
$hxExpose(tardis.Go_main_MouseUp, "Go_main_MouseUp");
tardis.Go_main_MouseUp.__name__ = ["tardis","Go_main_MouseUp"];
tardis.Go_main_MouseUp.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_MouseUp.callFromHaxe = function(p_x,p_y) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_main_MouseUp(0,[],p_x,p_y).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_main_MouseUp.callFromRT = function(_gr,p_x,p_y) {
	var _sf = new tardis.Go_main_MouseUp(_gr,[],p_x,p_y).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_main_MouseUp.call = function(gr,_bds,p_x,p_y) {
	return new tardis.Go_main_MouseUp(gr,_bds,p_x,p_y);
}
tardis.Go_main_MouseUp.__super__ = tardis.StackFrameBasis;
tardis.Go_main_MouseUp.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t1;
		var _t2;
		var _t3;
		var _t4;
		this._t0 = tardis.Go.main_mouseEvents.ref();
		_t1 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			_v = [0,0.0,0.0];
			$r = _v;
			return $r;
		}(this)));
		_t2 = _t1.addr(0);
		_t2.store(0);
		_t3 = _t1.addr(1);
		_t3.store(this.p_x);
		_t4 = _t1.addr(2);
		_t4.store(this.p_y);
		this._t5 = _t1.ref();
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 19;
				this._latestBlock = 0;
				this.SubFn0();
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 19;
				this._latestBlock = -1;
				if(!this._t0.hasSpace()) return this;
				this._t0.send(this._t5);
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_main_MouseUp
});
tardis.Go_utf8_DecodeLastRune = function(gr,_bds,p_p) {
	this._Next = 0;
	this._Phi = 0;
	this._t24 = false;
	this._t23 = 0;
	this._t22 = 0;
	this._t21 = 0;
	this._t20 = null;
	this._t19 = null;
	this._t18 = 0;
	this._t17 = 0;
	this._t16 = false;
	this._t15 = 0;
	this._t14 = false;
	this._t13 = false;
	this._t12 = 0;
	this._t11 = null;
	this._t10 = 0;
	this._t9 = 0;
	this._t8 = false;
	this._t7 = 0;
	this._t6 = false;
	this._t5 = 0;
	this._t4 = 0;
	this._t3 = null;
	this._t2 = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,789,"Go_utf8_DecodeLastRune");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_DecodeLastRune"] = tardis.Go_utf8_DecodeLastRune;
$hxExpose(tardis.Go_utf8_DecodeLastRune, "Go_utf8_DecodeLastRune");
tardis.Go_utf8_DecodeLastRune.__name__ = ["tardis","Go_utf8_DecodeLastRune"];
tardis.Go_utf8_DecodeLastRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_DecodeLastRune.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_DecodeLastRune(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_DecodeLastRune.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_DecodeLastRune(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_DecodeLastRune.call = function(gr,_bds,p_p) {
	return new tardis.Go_utf8_DecodeLastRune(gr,_bds,p_p);
}
tardis.Go_utf8_DecodeLastRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_DecodeLastRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn12: function() {
		var _t23;
		var _t24;
		this._t21 = this._t20.r0;
		this._t22 = this._t20.r1;
		this._latestPH = 815;
		_t23 = this._t18 + this._t22;
		_t24 = _t23 != this._t0;
		this._Next = _t24?13:14;
	}
	,SubFn11: function() {
		this._latestPH = 814;
		this._t19 = this.p_p.subSlice(this._t18,this._t0);
	}
	,SubFn10: function() {
		this._Next = 12;
	}
	,SubFn9: function() {
		this._t17 = this._t15 - 1;
		this._Next = 9;
	}
	,SubFn8: function() {
		var _t16;
		this._latestPH = 806;
		_t16 = this._t15 >= this._t9;
		this._Next = _t16?7:8;
	}
	,SubFn7: function() {
		var _t14;
		this._latestPH = 811;
		_t14 = this._t15 < 0;
		this._Next = _t14?11:12;
	}
	,SubFn6: function() {
		this._Next = this._t13?8:10;
	}
	,SubFn5: function() {
		var _t11;
		this._latestPH = 807;
		if(this._t15 < 0 || this._t15 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t11 = this.p_p.addr(this._t15);
		this._t12 = _t11.ref() | 0;
	}
	,SubFn4: function() {
		this._t10 = this._t2 - 1;
		this._Next = 9;
	}
	,SubFn3: function() {
		this._Next = 6;
	}
	,SubFn2: function() {
		var _t8;
		this._latestPH = 802;
		this._t7 = this._t0 - 4;
		this._latestPH = 803;
		_t8 = this._t7 < 0;
		this._Next = _t8?5:6;
	}
	,SubFn1: function() {
		var _t3;
		var _t4;
		var _t6;
		this._latestPH = 794;
		this._t2 = this._t0 - 1;
		this._latestPH = 795;
		if(this._t2 < 0 || this._t2 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t3 = this.p_p.addr(this._t2);
		_t4 = _t3.ref() | 0;
		this._t5 = _t4;
		this._latestPH = 796;
		_t6 = this._t5 < 128;
		this._Next = _t6?3:4;
	}
	,SubFn0: function() {
		var _t1;
		this._latestPH = 790;
		this._t0 = (function($this) {
			var $r;
			var _v = $this.p_p;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._latestPH = 791;
		_t1 = this._t0 == 0;
		this._Next = _t1?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 789;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 789;
				this._latestBlock = 1;
				this._latestPH = 792;
				this._res = { r0 : 65533, r1 : 0};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 792;
				this._latestBlock = 2;
				this.SubFn1();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 792;
				this._latestBlock = 3;
				this._latestPH = 797;
				this._res = { r0 : this._t5, r1 : 1};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 797;
				this._latestBlock = 4;
				this.SubFn2();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 797;
				this._latestBlock = 5;
				this._Next = 6;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 797;
				this._latestBlock = 6;
				this._latestPH = 802;
				this._t9 = this._Phi == 4?this._t7:this._Phi == 5?0:0;
				this._t10 = this._t2 - 1;
				this._Next = 9;
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 802;
				this._latestBlock = 7;
				this.SubFn5();
				this._latestPH = 807;
				this._SF1 = new tardis.Go_utf8_RuneStart(this._goroutine,[],this._t12);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 807;
				this._latestBlock = -1;
				this._t13 = this._SF1.res();
				this._Next = this._t13?8:10;
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 807;
				this._latestBlock = 8;
				this.SubFn7();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 807;
				this._latestBlock = 9;
				this._latestPH = 794;
				this._t15 = this._Phi == 6?this._t10:this._Phi == 10?this._t17:0;
				this.SubFn8();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 794;
				this._latestBlock = 10;
				this._t17 = this._t15 - 1;
				this._Next = 9;
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 794;
				this._latestBlock = 11;
				this._Next = 12;
				this._Phi = 11;
				break;
			case 12:
				this._latestPH = 794;
				this._latestBlock = 12;
				this._t18 = this._Phi == 8?this._t15:this._Phi == 11?0:0;
				this._latestPH = 814;
				this._t19 = this.p_p.subSlice(this._t18,this._t0);
				this._latestPH = 814;
				this._SF2 = new tardis.Go_utf8_DecodeRune(this._goroutine,[],this._t19);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 814;
				this._latestBlock = -2;
				this._t20 = this._SF2.res();
				this.SubFn12();
				this._Phi = 12;
				break;
			case 13:
				this._latestPH = 814;
				this._latestBlock = 13;
				this._latestPH = 816;
				this._res = { r0 : 65533, r1 : 1};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 14:
				this._latestPH = 816;
				this._latestBlock = 14;
				this._latestPH = 818;
				this._res = { r0 : this._t21, r1 : this._t22};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_DecodeLastRune
});
tardis.Go_hxutil_Host = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1006,"Go_hxutil_Host");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_Host"] = tardis.Go_hxutil_Host;
$hxExpose(tardis.Go_hxutil_Host, "Go_hxutil_Host");
tardis.Go_hxutil_Host.__name__ = ["tardis","Go_hxutil_Host"];
tardis.Go_hxutil_Host.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_Host.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_Host(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_Host.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_Host(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_Host.call = function(gr,_bds) {
	return new tardis.Go_hxutil_Host(gr,_bds);
}
tardis.Go_hxutil_Host.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_Host.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1006;
				this._latestBlock = 0;
				this._res = "go";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_Host
});
tardis.Go_utf16_Encode = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t37 = 0;
	this._t36 = 0;
	this._t35 = null;
	this._t34 = 0;
	this._t33 = 0;
	this._t32 = null;
	this._t31 = 0;
	this._t30 = 0;
	this._t29 = null;
	this._t28 = false;
	this._t27 = false;
	this._t26 = false;
	this._t25 = false;
	this._t24 = false;
	this._t23 = 0;
	this._t22 = 0;
	this._t21 = null;
	this._t20 = 0;
	this._t19 = null;
	this._t18 = false;
	this._t17 = 0;
	this._t16 = null;
	this._t15 = false;
	this._t14 = 0;
	this._t13 = 0;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = 0;
	this._t9 = null;
	this._t8 = false;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,498,"Go_utf16_Encode");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf16_Encode"] = tardis.Go_utf16_Encode;
$hxExpose(tardis.Go_utf16_Encode, "Go_utf16_Encode");
tardis.Go_utf16_Encode.__name__ = ["tardis","Go_utf16_Encode"];
tardis.Go_utf16_Encode.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_Encode.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf16_Encode(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf16_Encode.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf16_Encode(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf16_Encode.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf16_Encode(gr,_bds,p_s);
}
tardis.Go_utf16_Encode.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_Encode.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn15: function() {
		var _t32;
		var _t33;
		var _t34;
		var _t35;
		var _t36;
		this._t30 = this._t29.r0;
		this._t31 = this._t29.r1;
		this._latestPH = 518;
		if(this._t12 < 0 || this._t12 >= this._t9.len()) tardis.Scheduler.ioor();
		_t32 = this._t9.addr(this._t12);
		_t33 = this._t30;
		_t32.store(_t33);
		this._latestPH = 519;
		_t34 = this._t12 + 1;
		if(_t34 < 0 || _t34 >= this._t9.len()) tardis.Scheduler.ioor();
		_t35 = this._t9.addr(_t34);
		_t36 = this._t31;
		_t35.store(_t36);
		this._t37 = this._t12 + 2;
		this._Next = 5;
	}
	,SubFn14: function() {
		var _t28;
		this._latestPH = 513;
		_t28 = this._t17 < 65536;
		this._Next = _t28?9:15;
	}
	,SubFn13: function() {
		this._Next = this._t27?8:11;
	}
	,SubFn12: function() {
		this._t26 = this._t17 < 57344;
		this._Next = 13;
	}
	,SubFn11: function() {
		var _t25;
		_t25 = this._t17 > 1114111;
		this._Next = _t25?8:14;
	}
	,SubFn10: function() {
		var _t24;
		this._latestPH = 510;
		_t24 = 55296 <= this._t17;
		this._Next = _t24?12:13;
	}
	,SubFn9: function() {
		var _t21;
		var _t22;
		this._latestPH = 514;
		if(this._t12 < 0 || this._t12 >= this._t9.len()) tardis.Scheduler.ioor();
		_t21 = this._t9.addr(this._t12);
		_t22 = this._t20;
		_t21.store(_t22);
		this._t23 = this._t12 + 1;
		this._Next = 5;
	}
	,SubFn8: function() {
		this._Next = 9;
	}
	,SubFn7: function() {
		this._latestPH = 523;
		this._t19 = this._t9.subSlice(0,this._t12);
	}
	,SubFn6: function() {
		var _t16;
		var _t18;
		if(this._t14 < 0 || this._t14 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t16 = this.p_s.addr(this._t14);
		this._t17 = _t16.ref() | 0;
		this._latestPH = 510;
		_t18 = this._t17 < 0;
		this._Next = _t18?8:10;
	}
	,SubFn5: function() {
		var _t15;
		this._t14 = this._t13 + 1;
		_t15 = this._t14 < this._t10;
		this._Next = _t15?6:7;
	}
	,SubFn4: function() {
		this._t11 = this._t2 + 1;
		this._Next = 1;
	}
	,SubFn3: function() {
		this._latestPH = 506;
		this._t9 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g1 = 0, _g = $this._t2;
				while(_g1 < _g) {
					var _i = _g1++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,this._t2);
		this._t10 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 5;
	}
	,SubFn2: function() {
		var _t6;
		var _t8;
		if(this._t4 < 0 || this._t4 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t6 = this.p_s.addr(this._t4);
		this._t7 = _t6.ref() | 0;
		this._latestPH = 501;
		_t8 = this._t7 >= 65536;
		this._Next = _t8?4:1;
	}
	,SubFn1: function() {
		var _t5;
		this._t4 = this._t3 + 1;
		_t5 = this._t4 < this._t1;
		this._Next = _t5?2:3;
	}
	,SubFn0: function() {
		this._latestPH = 499;
		this._t0 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t1 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 498;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 498;
				this._latestBlock = 1;
				this._latestPH = 499;
				this._t2 = this._Phi == 0?this._t0:this._Phi == 2?this._t2:this._Phi == 4?this._t11:0;
				this._t3 = this._Phi == 0?-1:this._Phi == 2?this._t4:this._Phi == 4?this._t4:0;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 499;
				this._latestBlock = 2;
				this.SubFn2();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 499;
				this._latestBlock = 3;
				this.SubFn3();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 499;
				this._latestBlock = 4;
				this._t11 = this._t2 + 1;
				this._Next = 1;
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 499;
				this._latestBlock = 5;
				this._t12 = this._Phi == 3?0:this._Phi == 9?this._t23:this._Phi == 15?this._t37:0;
				this._t13 = this._Phi == 3?-1:this._Phi == 9?this._t14:this._Phi == 15?this._t14:0;
				this.SubFn5();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 499;
				this._latestBlock = 6;
				this.SubFn6();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 499;
				this._latestBlock = 7;
				this._latestPH = 523;
				this._t19 = this._t9.subSlice(0,this._t12);
				this._latestPH = 523;
				this._res = this._t19;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 523;
				this._latestBlock = 8;
				this._Next = 9;
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 523;
				this._latestBlock = 9;
				this._latestPH = 508;
				this._t20 = this._Phi == 8?65533:this._Phi == 14?this._t17:0;
				this.SubFn9();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 508;
				this._latestBlock = 10;
				this.SubFn10();
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 508;
				this._latestBlock = 11;
				this.SubFn11();
				this._Phi = 11;
				break;
			case 12:
				this._latestPH = 508;
				this._latestBlock = 12;
				this._t26 = this._t17 < 57344;
				this._Next = 13;
				this._Phi = 12;
				break;
			case 13:
				this._latestPH = 508;
				this._latestBlock = 13;
				this._latestPH = 510;
				this._t27 = this._Phi == 10?false:this._Phi == 12?this._t26:false;
				this._Next = this._t27?8:11;
				this._Phi = 13;
				break;
			case 14:
				this._latestPH = 510;
				this._latestBlock = 14;
				this.SubFn14();
				this._Phi = 14;
				break;
			case 15:
				this._latestPH = 510;
				this._latestBlock = 15;
				this._latestPH = 517;
				this._SF1 = new tardis.Go_utf16_EncodeRune(this._goroutine,[],this._t17);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 517;
				this._latestBlock = -1;
				this._t29 = this._SF1.res();
				this.SubFn15();
				this._Phi = 15;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf16_Encode
});
tardis.Go_utf8_EncodeRune = function(gr,_bds,p_p,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t52 = 0;
	this._t51 = 0;
	this._t50 = 0;
	this._t49 = null;
	this._t48 = 0;
	this._t47 = 0;
	this._t46 = 0;
	this._t45 = 0;
	this._t44 = null;
	this._t43 = 0;
	this._t42 = 0;
	this._t41 = 0;
	this._t40 = 0;
	this._t39 = null;
	this._t38 = 0;
	this._t37 = 0;
	this._t36 = 0;
	this._t35 = null;
	this._t34 = 0;
	this._t33 = 0;
	this._t32 = 0;
	this._t31 = null;
	this._t30 = 0;
	this._t29 = 0;
	this._t28 = 0;
	this._t27 = 0;
	this._t26 = null;
	this._t25 = 0;
	this._t24 = 0;
	this._t23 = 0;
	this._t22 = null;
	this._t21 = false;
	this._t20 = false;
	this._t19 = 0;
	this._t18 = 0;
	this._t17 = false;
	this._t16 = 0;
	this._t15 = false;
	this._t14 = 0;
	this._t13 = 0;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = null;
	this._t9 = 0;
	this._t8 = 0;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,880,"Go_utf8_EncodeRune");
	this._bds = _bds;
	this.p_p = p_p;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_EncodeRune"] = tardis.Go_utf8_EncodeRune;
$hxExpose(tardis.Go_utf8_EncodeRune, "Go_utf8_EncodeRune");
tardis.Go_utf8_EncodeRune.__name__ = ["tardis","Go_utf8_EncodeRune"];
tardis.Go_utf8_EncodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_EncodeRune.callFromHaxe = function(p_p,p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_EncodeRune(0,[],p_p,p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_EncodeRune.callFromRT = function(_gr,p_p,p_r) {
	var _sf = new tardis.Go_utf8_EncodeRune(_gr,[],p_p,p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_EncodeRune.call = function(gr,_bds,p_p,p_r) {
	return new tardis.Go_utf8_EncodeRune(gr,_bds,p_p,p_r);
}
tardis.Go_utf8_EncodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_EncodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn11: function() {
		var _t35;
		var _t36;
		var _t37;
		var _t38;
		var _t39;
		var _t40;
		var _t41;
		var _t42;
		var _t43;
		var _t44;
		var _t45;
		var _t46;
		var _t47;
		var _t48;
		var _t49;
		var _t50;
		var _t51;
		var _t52;
		this._latestPH = 908;
		if(0 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t35 = this.p_p.addr(0);
		_t36 = this._t18 >> tardis.Int64.getLow(new tardis.Int64(0,18));
		_t37 = _t36;
		_t38 = (240 | _t37) & 255;
		_t35.store(_t38);
		this._latestPH = 909;
		if(1 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t39 = this.p_p.addr(1);
		_t40 = this._t18 >> tardis.Int64.getLow(new tardis.Int64(0,12));
		_t41 = _t40;
		_t42 = _t41 & 63 & 255;
		_t43 = (128 | _t42) & 255;
		_t39.store(_t43);
		this._latestPH = 910;
		if(2 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t44 = this.p_p.addr(2);
		_t45 = this._t18 >> tardis.Int64.getLow(new tardis.Int64(0,6));
		_t46 = _t45;
		_t47 = _t46 & 63 & 255;
		_t48 = (128 | _t47) & 255;
		_t44.store(_t48);
		this._latestPH = 911;
		if(3 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t49 = this.p_p.addr(3);
		_t50 = this._t18;
		_t51 = _t50 & 63 & 255;
		_t52 = (128 | _t51) & 255;
		_t49.store(_t52);
	}
	,SubFn10: function() {
		var _t22;
		var _t23;
		var _t24;
		var _t25;
		var _t26;
		var _t27;
		var _t28;
		var _t29;
		var _t30;
		var _t31;
		var _t32;
		var _t33;
		var _t34;
		this._latestPH = 902;
		if(0 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t22 = this.p_p.addr(0);
		_t23 = this._t18 >> tardis.Int64.getLow(new tardis.Int64(0,12));
		_t24 = _t23;
		_t25 = (224 | _t24) & 255;
		_t22.store(_t25);
		this._latestPH = 903;
		if(1 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t26 = this.p_p.addr(1);
		_t27 = this._t18 >> tardis.Int64.getLow(new tardis.Int64(0,6));
		_t28 = _t27;
		_t29 = _t28 & 63 & 255;
		_t30 = (128 | _t29) & 255;
		_t26.store(_t30);
		this._latestPH = 904;
		if(2 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t31 = this.p_p.addr(2);
		_t32 = this._t18;
		_t33 = _t32 & 63 & 255;
		_t34 = (128 | _t33) & 255;
		_t31.store(_t34);
	}
	,SubFn9: function() {
		var _t21;
		this._latestPH = 897;
		_t21 = this._t16 <= 57343;
		this._Next = _t21?7:8;
	}
	,SubFn8: function() {
		var _t19;
		var _t20;
		this._latestPH = 901;
		_t19 = this._t18;
		_t20 = tardis.Force.uintCompare(_t19,65535) <= 0;
		this._Next = _t20?10:11;
	}
	,SubFn7: function() {
		this._Next = 8;
	}
	,SubFn6: function() {
		var _t17;
		this._latestPH = 897;
		_t17 = 55296 <= this._t16;
		this._Next = _t17?9:8;
	}
	,SubFn5: function() {
		this._Next = 6;
	}
	,SubFn4: function() {
		var _t14;
		var _t15;
		this._latestPH = 893;
		_t14 = this.p_r;
		_t15 = tardis.Force.uintCompare(_t14,1114111) > 0;
		this._Next = _t15?5:6;
	}
	,SubFn3: function() {
		var _t6;
		var _t7;
		var _t8;
		var _t9;
		var _t10;
		var _t11;
		var _t12;
		var _t13;
		this._latestPH = 888;
		if(0 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t6 = this.p_p.addr(0);
		_t7 = this.p_r >> tardis.Int64.getLow(new tardis.Int64(0,6));
		_t8 = _t7;
		_t9 = (192 | _t8) & 255;
		_t6.store(_t9);
		this._latestPH = 889;
		if(1 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t10 = this.p_p.addr(1);
		_t11 = this.p_r;
		_t12 = _t11 & 63 & 255;
		_t13 = (128 | _t12) & 255;
		_t10.store(_t13);
	}
	,SubFn2: function() {
		var _t4;
		var _t5;
		this._latestPH = 887;
		_t4 = this.p_r;
		_t5 = tardis.Force.uintCompare(_t4,2047) <= 0;
		this._Next = _t5?3:4;
	}
	,SubFn1: function() {
		var _t2;
		var _t3;
		this._latestPH = 883;
		if(0 >= this.p_p.len()) tardis.Scheduler.ioor();
		_t2 = this.p_p.addr(0);
		_t3 = this.p_r;
		_t2.store(_t3);
	}
	,SubFn0: function() {
		var _t0;
		var _t1;
		this._latestPH = 882;
		_t0 = this.p_r;
		_t1 = tardis.Force.uintCompare(_t0,127) <= 0;
		this._Next = _t1?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 880;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 880;
				this._latestBlock = 1;
				this.SubFn1();
				this._latestPH = 884;
				this._res = 1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 884;
				this._latestBlock = 2;
				this.SubFn2();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 884;
				this._latestBlock = 3;
				this.SubFn3();
				this._latestPH = 890;
				this._res = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 890;
				this._latestBlock = 4;
				this.SubFn4();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 890;
				this._latestBlock = 5;
				this._Next = 6;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 890;
				this._latestBlock = 6;
				this._latestPH = 880;
				this._t16 = this._Phi == 4?this.p_r:this._Phi == 5?65533:0;
				this.SubFn6();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 880;
				this._latestBlock = 7;
				this._Next = 8;
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 880;
				this._latestBlock = 8;
				this._t18 = this._Phi == 6?this._t16:this._Phi == 9?this._t16:this._Phi == 7?65533:0;
				this.SubFn8();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 880;
				this._latestBlock = 9;
				this.SubFn9();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 880;
				this._latestBlock = 10;
				this.SubFn10();
				this._latestPH = 905;
				this._res = 3;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 11:
				this._latestPH = 905;
				this._latestBlock = 11;
				this.SubFn11();
				this._latestPH = 912;
				this._res = 4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_EncodeRune
});
tardis.Go_haxegoruntime_CPos = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,198,"Go_haxegoruntime_CPos");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_CPos"] = tardis.Go_haxegoruntime_CPos;
$hxExpose(tardis.Go_haxegoruntime_CPos, "Go_haxegoruntime_CPos");
tardis.Go_haxegoruntime_CPos.__name__ = ["tardis","Go_haxegoruntime_CPos"];
tardis.Go_haxegoruntime_CPos.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_CPos.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_CPos(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_CPos.callFromRT = function(_gr) {
	var _sf = new tardis.Go_haxegoruntime_CPos(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_CPos.call = function(gr,_bds) {
	return new tardis.Go_haxegoruntime_CPos(gr,_bds);
}
tardis.Go_haxegoruntime_CPos.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_CPos.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 198;
				this._latestBlock = 0;
				this._res = "<<code pos>>";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_CPos
});
tardis.Go_haxegoruntime_M4 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,219,"Go_haxegoruntime_M4");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M4"] = tardis.Go_haxegoruntime_M4;
$hxExpose(tardis.Go_haxegoruntime_M4, "Go_haxegoruntime_M4");
tardis.Go_haxegoruntime_M4.__name__ = ["tardis","Go_haxegoruntime_M4"];
tardis.Go_haxegoruntime_M4.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M4.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M4(0,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M4.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4) {
	var _sf = new tardis.Go_haxegoruntime_M4(_gr,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M4.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4) {
	return new tardis.Go_haxegoruntime_M4(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3,p_a4);
}
tardis.Go_haxegoruntime_M4.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M4.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 219;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M4
});
tardis._Go.Go_haxegoruntime_cstringToGo = function(gr,_bds,p_arg0) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,430,"Go_haxegoruntime_cstringToGo");
	this._bds = _bds;
	this.p_arg0 = p_arg0;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_cstringToGo"] = tardis._Go.Go_haxegoruntime_cstringToGo;
tardis._Go.Go_haxegoruntime_cstringToGo.__name__ = ["tardis","_Go","Go_haxegoruntime_cstringToGo"];
tardis._Go.Go_haxegoruntime_cstringToGo.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_cstringToGo.callFromHaxe = function(p_arg0) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_cstringToGo(0,[],p_arg0).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_cstringToGo.callFromRT = function(_gr,p_arg0) {
	var _sf = new tardis._Go.Go_haxegoruntime_cstringToGo(_gr,[],p_arg0).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_cstringToGo.call = function(gr,_bds,p_arg0) {
	return new tardis._Go.Go_haxegoruntime_cstringToGo(gr,_bds,p_arg0);
}
tardis._Go.Go_haxegoruntime_cstringToGo.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_cstringToGo.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.cstringToGo() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 430;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.cstringToGo() not yet implemented");
				this._latestPH = 431;
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 431;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_cstringToGo
});
tardis.Go_haxegoruntime_StringCompare = function(gr,_bds,p_a,p_b) {
	this._Next = 0;
	this._Phi = 0;
	this._t23 = false;
	this._t22 = 0;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = false;
	this._t18 = 0;
	this._t17 = null;
	this._t16 = 0;
	this._t15 = null;
	this._t14 = false;
	this._t13 = 0;
	this._t12 = false;
	this._t11 = 0;
	this._t10 = 0;
	this._t9 = false;
	this._t8 = 0;
	this._t7 = 0;
	this._t6 = false;
	this._t5 = 0;
	this._t4 = null;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,168,"Go_haxegoruntime_StringCompare");
	this._bds = _bds;
	this.p_a = p_a;
	this.p_b = p_b;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_StringCompare"] = tardis.Go_haxegoruntime_StringCompare;
$hxExpose(tardis.Go_haxegoruntime_StringCompare, "Go_haxegoruntime_StringCompare");
tardis.Go_haxegoruntime_StringCompare.__name__ = ["tardis","Go_haxegoruntime_StringCompare"];
tardis.Go_haxegoruntime_StringCompare.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_StringCompare.callFromHaxe = function(p_a,p_b) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_StringCompare(0,[],p_a,p_b).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_StringCompare.callFromRT = function(_gr,p_a,p_b) {
	var _sf = new tardis.Go_haxegoruntime_StringCompare(_gr,[],p_a,p_b).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_StringCompare.call = function(gr,_bds,p_a,p_b) {
	return new tardis.Go_haxegoruntime_StringCompare(gr,_bds,p_a,p_b);
}
tardis.Go_haxegoruntime_StringCompare.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_StringCompare.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn7: function() {
		var _t21;
		var _t22;
		var _t23;
		this._latestPH = 185;
		_t21 = (function($this) {
			var $r;
			var _v = $this._t0;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t22 = (function($this) {
			var $r;
			var _v = $this._t1;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t23 = _t21 < _t22;
		this._Next = _t23?11:12;
	}
	,SubFn6: function() {
		this._t20 = this._t10 + 1;
		this._Next = 3;
	}
	,SubFn5: function() {
		var _t15;
		var _t16;
		var _t17;
		var _t18;
		var _t19;
		this._latestPH = 177;
		if(this._t10 < 0 || this._t10 >= this._t0.len()) tardis.Scheduler.ioor();
		_t15 = this._t0.addr(this._t10);
		_t16 = _t15.ref() | 0;
		if(this._t10 < 0 || this._t10 >= this._t1.len()) tardis.Scheduler.ioor();
		_t17 = this._t1.addr(this._t10);
		_t18 = _t17.ref() | 0;
		_t19 = tardis.Force.uintCompare(_t16,_t18) > 0;
		this._Next = _t19?7:8;
	}
	,SubFn4: function() {
		var _t13;
		var _t14;
		_t13 = (function($this) {
			var $r;
			var _v = $this._t1;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t14 = this._t10 < _t13;
		this._Next = _t14?1:2;
	}
	,SubFn3: function() {
		var _t11;
		var _t12;
		this._latestPH = 173;
		_t11 = (function($this) {
			var $r;
			var _v = $this._t0;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t12 = this._t10 < _t11;
		this._Next = _t12?4:2;
	}
	,SubFn2: function() {
		var _t7;
		var _t8;
		var _t9;
		this._latestPH = 182;
		_t7 = (function($this) {
			var $r;
			var _v = $this._t0;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t8 = (function($this) {
			var $r;
			var _v = $this._t1;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		_t9 = _t7 == _t8;
		this._Next = _t9?9:10;
	}
	,SubFn1: function() {
		var _t2;
		var _t3;
		var _t4;
		var _t5;
		var _t6;
		this._latestPH = 174;
		if(this._t10 < 0 || this._t10 >= this._t0.len()) tardis.Scheduler.ioor();
		_t2 = this._t0.addr(this._t10);
		_t3 = _t2.ref() | 0;
		if(this._t10 < 0 || this._t10 >= this._t1.len()) tardis.Scheduler.ioor();
		_t4 = this._t1.addr(this._t10);
		_t5 = _t4.ref() | 0;
		_t6 = tardis.Force.uintCompare(_t3,_t5) < 0;
		this._Next = _t6?5:6;
	}
	,SubFn0: function() {
		this._latestPH = 170;
		this._t0 = tardis.Force.toUTF8slice(this._goroutine,this.p_a);
		this._latestPH = 171;
		this._t1 = tardis.Force.toUTF8slice(this._goroutine,this.p_b);
		this._Next = 3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 168;
				this._latestBlock = 0;
				this._latestPH = 170;
				this._t0 = tardis.Force.toUTF8slice(this._goroutine,this.p_a);
				this._latestPH = 171;
				this._t1 = tardis.Force.toUTF8slice(this._goroutine,this.p_b);
				this._Next = 3;
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 168;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 168;
				this._latestBlock = 2;
				this.SubFn2();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 168;
				this._latestBlock = 3;
				this._latestPH = 172;
				this._t10 = this._Phi == 0?0:this._Phi == 8?this._t20:0;
				this.SubFn3();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 172;
				this._latestBlock = 4;
				this.SubFn4();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 172;
				this._latestBlock = 5;
				this._latestPH = 175;
				this._res = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 6:
				this._latestPH = 175;
				this._latestBlock = 6;
				this.SubFn5();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 175;
				this._latestBlock = 7;
				this._latestPH = 178;
				this._res = 1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 178;
				this._latestBlock = 8;
				this._t20 = this._t10 + 1;
				this._Next = 3;
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 178;
				this._latestBlock = 9;
				this._latestPH = 183;
				this._res = 0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 10:
				this._latestPH = 183;
				this._latestBlock = 10;
				this.SubFn7();
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 183;
				this._latestBlock = 11;
				this._latestPH = 186;
				this._res = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 12:
				this._latestPH = 186;
				this._latestBlock = 12;
				this._latestPH = 188;
				this._res = 1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_StringCompare
});
tardis._Go.Go_main_init_36_1 = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,30,"Go_main_init_36_1");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_main_init_36_1"] = tardis._Go.Go_main_init_36_1;
tardis._Go.Go_main_init_36_1.__name__ = ["tardis","_Go","Go_main_init_36_1"];
tardis._Go.Go_main_init_36_1.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_init_36_1.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_main_init_36_1(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_main_init_36_1.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_main_init_36_1(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_main_init_36_1.call = function(gr,_bds) {
	return new tardis._Go.Go_main_init_36_1(gr,_bds);
}
tardis._Go.Go_main_init_36_1.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_init_36_1.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		tardis.Go.main_SpriteX.store(100);
		tardis.Go.main_SpriteY.store(150);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 30;
				this._latestBlock = 0;
				tardis.Go.main_SpriteX.store(100);
				tardis.Go.main_SpriteY.store(150);
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_main_init_36_1
});
tardis.Go_hxutil_Zilen = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1017,"Go_hxutil_Zilen");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_Zilen"] = tardis.Go_hxutil_Zilen;
$hxExpose(tardis.Go_hxutil_Zilen, "Go_hxutil_Zilen");
tardis.Go_hxutil_Zilen.__name__ = ["tardis","Go_hxutil_Zilen"];
tardis.Go_hxutil_Zilen.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_Zilen.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_Zilen(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_Zilen.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_Zilen(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_Zilen.call = function(gr,_bds) {
	return new tardis.Go_hxutil_Zilen(gr,_bds);
}
tardis.Go_hxutil_Zilen.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_Zilen.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1017;
				this._latestBlock = 0;
				this._res = 3;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_Zilen
});
tardis._Go.Go_haxegoruntime_runtime_Gosched = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,402,"Go_haxegoruntime_runtime_Gosched");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_runtime_Gosched"] = tardis._Go.Go_haxegoruntime_runtime_Gosched;
tardis._Go.Go_haxegoruntime_runtime_Gosched.__name__ = ["tardis","_Go","Go_haxegoruntime_runtime_Gosched"];
tardis._Go.Go_haxegoruntime_runtime_Gosched.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_runtime_Gosched.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_runtime_Gosched(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_haxegoruntime_runtime_Gosched.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_haxegoruntime_runtime_Gosched(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_haxegoruntime_runtime_Gosched.call = function(gr,_bds) {
	return new tardis._Go.Go_haxegoruntime_runtime_Gosched(gr,_bds);
}
tardis._Go.Go_haxegoruntime_runtime_Gosched.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_runtime_Gosched.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 402;
				this._latestBlock = 0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_haxegoruntime_runtime_Gosched
});
tardis.Go_haxegoruntime_C2 = function(gr,_bds,p_funcName,p_a1,p_a2) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,206,"Go_haxegoruntime_C2");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C2"] = tardis.Go_haxegoruntime_C2;
$hxExpose(tardis.Go_haxegoruntime_C2, "Go_haxegoruntime_C2");
tardis.Go_haxegoruntime_C2.__name__ = ["tardis","Go_haxegoruntime_C2"];
tardis.Go_haxegoruntime_C2.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C2.callFromHaxe = function(p_funcName,p_a1,p_a2) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C2(0,[],p_funcName,p_a1,p_a2).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C2.callFromRT = function(_gr,p_funcName,p_a1,p_a2) {
	var _sf = new tardis.Go_haxegoruntime_C2(_gr,[],p_funcName,p_a1,p_a2).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C2.call = function(gr,_bds,p_funcName,p_a1,p_a2) {
	return new tardis.Go_haxegoruntime_C2(gr,_bds,p_funcName,p_a1,p_a2);
}
tardis.Go_haxegoruntime_C2.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C2.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 206;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C2
});
tardis._Go.Go_main_main = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,3,"Go_main_main");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_main_main"] = tardis._Go.Go_main_main;
tardis._Go.Go_main_main.__name__ = ["tardis","_Go","Go_main_main"];
tardis._Go.Go_main_main.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_main.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_main_main(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_main_main.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_main_main(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_main_main.call = function(gr,_bds) {
	return new tardis._Go.Go_main_main(gr,_bds);
}
tardis._Go.Go_main_main.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_main.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 3;
				this._latestBlock = 0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_main_main
});
tardis.Go_haxegoruntime_UTF16toRunes = function(gr,_bds,p_s) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,83,"Go_haxegoruntime_UTF16toRunes");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_UTF16toRunes"] = tardis.Go_haxegoruntime_UTF16toRunes;
$hxExpose(tardis.Go_haxegoruntime_UTF16toRunes, "Go_haxegoruntime_UTF16toRunes");
tardis.Go_haxegoruntime_UTF16toRunes.__name__ = ["tardis","Go_haxegoruntime_UTF16toRunes"];
tardis.Go_haxegoruntime_UTF16toRunes.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_UTF16toRunes.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_UTF16toRunes(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_UTF16toRunes.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_haxegoruntime_UTF16toRunes(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_UTF16toRunes.call = function(gr,_bds,p_s) {
	return new tardis.Go_haxegoruntime_UTF16toRunes(gr,_bds,p_s);
}
tardis.Go_haxegoruntime_UTF16toRunes.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_UTF16toRunes.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 83;
				this._latestBlock = 0;
				this._latestPH = 84;
				this._SF1 = new tardis.Go_utf16_Decode(this._goroutine,[],this.p_s);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 84;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_UTF16toRunes
});
tardis.Go_hxutil_HAXE = function(gr,_bds,p_code) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1003,"Go_hxutil_HAXE");
	this._bds = _bds;
	this.p_code = p_code;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_HAXE"] = tardis.Go_hxutil_HAXE;
$hxExpose(tardis.Go_hxutil_HAXE, "Go_hxutil_HAXE");
tardis.Go_hxutil_HAXE.__name__ = ["tardis","Go_hxutil_HAXE"];
tardis.Go_hxutil_HAXE.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_HAXE.callFromHaxe = function(p_code) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_HAXE(0,[],p_code).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_HAXE.callFromRT = function(_gr,p_code) {
	var _sf = new tardis.Go_hxutil_HAXE(_gr,[],p_code).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_HAXE.call = function(gr,_bds,p_code) {
	return new tardis.Go_hxutil_HAXE(gr,_bds,p_code);
}
tardis.Go_hxutil_HAXE.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_HAXE.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1003;
				this._latestBlock = 0;
				this._res = 0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_HAXE
});
tardis.Go_haxegoruntime_C4 = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,208,"Go_haxegoruntime_C4");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C4"] = tardis.Go_haxegoruntime_C4;
$hxExpose(tardis.Go_haxegoruntime_C4, "Go_haxegoruntime_C4");
tardis.Go_haxegoruntime_C4.__name__ = ["tardis","Go_haxegoruntime_C4"];
tardis.Go_haxegoruntime_C4.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C4.callFromHaxe = function(p_funcName,p_a1,p_a2,p_a3,p_a4) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C4(0,[],p_funcName,p_a1,p_a2,p_a3,p_a4).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C4.callFromRT = function(_gr,p_funcName,p_a1,p_a2,p_a3,p_a4) {
	var _sf = new tardis.Go_haxegoruntime_C4(_gr,[],p_funcName,p_a1,p_a2,p_a3,p_a4).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C4.call = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4) {
	return new tardis.Go_haxegoruntime_C4(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4);
}
tardis.Go_haxegoruntime_C4.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C4.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 208;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C4
});
tardis.Go_haxegoruntime_Goexit = function(gr,_bds) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,409,"Go_haxegoruntime_Goexit");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Goexit"] = tardis.Go_haxegoruntime_Goexit;
$hxExpose(tardis.Go_haxegoruntime_Goexit, "Go_haxegoruntime_Goexit");
tardis.Go_haxegoruntime_Goexit.__name__ = ["tardis","Go_haxegoruntime_Goexit"];
tardis.Go_haxegoruntime_Goexit.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Goexit.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Goexit(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_haxegoruntime_Goexit.callFromRT = function(_gr) {
	var _sf = new tardis.Go_haxegoruntime_Goexit(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_haxegoruntime_Goexit.call = function(gr,_bds) {
	return new tardis.Go_haxegoruntime_Goexit(gr,_bds);
}
tardis.Go_haxegoruntime_Goexit.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Goexit.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.Goexit() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 409;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.Goexit() not yet implemented");
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 409;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_haxegoruntime_Goexit
});
tardis.Go_main_MouseDown = function(gr,_bds,p_x,p_y) {
	this._Next = 0;
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,20,"Go_main_MouseDown");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_main_MouseDown"] = tardis.Go_main_MouseDown;
$hxExpose(tardis.Go_main_MouseDown, "Go_main_MouseDown");
tardis.Go_main_MouseDown.__name__ = ["tardis","Go_main_MouseDown"];
tardis.Go_main_MouseDown.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_MouseDown.callFromHaxe = function(p_x,p_y) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_main_MouseDown(0,[],p_x,p_y).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_main_MouseDown.callFromRT = function(_gr,p_x,p_y) {
	var _sf = new tardis.Go_main_MouseDown(_gr,[],p_x,p_y).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_main_MouseDown.call = function(gr,_bds,p_x,p_y) {
	return new tardis.Go_main_MouseDown(gr,_bds,p_x,p_y);
}
tardis.Go_main_MouseDown.__super__ = tardis.StackFrameBasis;
tardis.Go_main_MouseDown.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t1;
		var _t2;
		var _t3;
		var _t4;
		this._t0 = tardis.Go.main_mouseEvents.ref();
		_t1 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			_v = [0,0.0,0.0];
			$r = _v;
			return $r;
		}(this)));
		_t2 = _t1.addr(0);
		_t2.store(1);
		_t3 = _t1.addr(1);
		_t3.store(this.p_x);
		_t4 = _t1.addr(2);
		_t4.store(this.p_y);
		this._t5 = _t1.ref();
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 20;
				this._latestBlock = 0;
				this.SubFn0();
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 20;
				this._latestBlock = -1;
				if(!this._t0.hasSpace()) return this;
				this._t0.send(this._t5);
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_main_MouseDown
});
tardis.Go_utf8_DecodeRuneInString = function(gr,_bds,p_s) {
	this._Next = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,779,"Go_utf8_DecodeRuneInString");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_DecodeRuneInString"] = tardis.Go_utf8_DecodeRuneInString;
$hxExpose(tardis.Go_utf8_DecodeRuneInString, "Go_utf8_DecodeRuneInString");
tardis.Go_utf8_DecodeRuneInString.__name__ = ["tardis","Go_utf8_DecodeRuneInString"];
tardis.Go_utf8_DecodeRuneInString.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_DecodeRuneInString.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_DecodeRuneInString(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_DecodeRuneInString.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf8_DecodeRuneInString(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_DecodeRuneInString.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf8_DecodeRuneInString(gr,_bds,p_s);
}
tardis.Go_utf8_DecodeRuneInString.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_DecodeRuneInString.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = this._t0.r0;
		this._t2 = this._t0.r1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 779;
				this._latestBlock = 0;
				this._latestPH = 780;
				this._SF1 = new tardis._Go.Go_utf8_decodeRuneInStringInternal(this._goroutine,[],this.p_s);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 780;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._t1 = this._t0.r0;
				this._t2 = this._t0.r1;
				this._latestPH = 781;
				this._res = { r0 : this._t1, r1 : this._t2};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_DecodeRuneInString
});
tardis.Go_haxegoruntime_Runes2Raw = function(gr,_bds,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t27 = 0;
	this._t26 = 0;
	this._t25 = null;
	this._t24 = null;
	this._t23 = false;
	this._t22 = 0;
	this._t21 = 0;
	this._t20 = null;
	this._t19 = null;
	this._t17 = 0;
	this._t16 = 0;
	this._t15 = null;
	this._t14 = null;
	this._t13 = false;
	this._t12 = 0;
	this._t11 = 0;
	this._t10 = false;
	this._t9 = 0;
	this._t8 = null;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = 0;
	this._t4 = null;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,138,"Go_haxegoruntime_Runes2Raw");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Runes2Raw"] = tardis.Go_haxegoruntime_Runes2Raw;
$hxExpose(tardis.Go_haxegoruntime_Runes2Raw, "Go_haxegoruntime_Runes2Raw");
tardis.Go_haxegoruntime_Runes2Raw.__name__ = ["tardis","Go_haxegoruntime_Runes2Raw"];
tardis.Go_haxegoruntime_Runes2Raw.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Runes2Raw.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Runes2Raw(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Runes2Raw.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_haxegoruntime_Runes2Raw(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Runes2Raw.call = function(gr,_bds,p_r) {
	return new tardis.Go_haxegoruntime_Runes2Raw(gr,_bds,p_r);
}
tardis.Go_haxegoruntime_Runes2Raw.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Runes2Raw.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn8: function() {
		var _t24;
		var _t25;
		var _t26;
		var _t27;
		this._latestPH = 151;
		if(this._t22 < 0 || this._t22 >= this._t8.len()) tardis.Scheduler.ioor();
		_t24 = this._t8.addr(this._t22);
		if(this._t22 < 0 || this._t22 >= this._t6.len()) tardis.Scheduler.ioor();
		_t25 = this._t6.addr(this._t22);
		_t26 = _t25.ref() | 0;
		_t27 = _t26;
		_t24.store(_t27);
		this._Next = 8;
	}
	,SubFn7: function() {
		var _t23;
		this._t22 = this._t21 + 1;
		_t23 = this._t22 < this._t9;
		this._Next = _t23?9:10;
	}
	,SubFn6: function() {
		var _t19;
		this._latestPH = 158;
		_t19 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < 0) {
					var _vi = _g++;
					_v[_vi] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this)));
		this._t20 = new tardis.Slice(_t19,0,-1);
	}
	,SubFn5: function() {
		var _t14;
		var _t15;
		var _t16;
		var _t17;
		this._latestPH = 144;
		if(this._t12 < 0 || this._t12 >= this._t4.len()) tardis.Scheduler.ioor();
		_t14 = this._t4.addr(this._t12);
		if(this._t12 < 0 || this._t12 >= this._t2.len()) tardis.Scheduler.ioor();
		_t15 = this._t2.addr(this._t12);
		_t16 = _t15.ref() | 0;
		_t17 = _t16;
		_t14.store(_t17);
		this._Next = 4;
	}
	,SubFn4: function() {
		var _t13;
		this._t12 = this._t11 + 1;
		_t13 = this._t12 < this._t5;
		this._Next = _t13?5:6;
	}
	,SubFn3: function() {
		var _t10;
		_t10 = tardis.Force.uintCompare(this._t0,3) == 0;
		this._Next = _t10?2:7;
	}
	,SubFn2: function() {
		var _t7;
		this._latestPH = 149;
		_t7 = (function($this) {
			var $r;
			var _v = $this._t6;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t8 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t7) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t7);
		this._t9 = (function($this) {
			var $r;
			var _v = $this._t6;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 8;
	}
	,SubFn1: function() {
		var _t3;
		this._latestPH = 142;
		_t3 = (function($this) {
			var $r;
			var _v = $this._t2;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t4 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t3) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t3);
		this._t5 = (function($this) {
			var $r;
			var _v = $this._t2;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 4;
	}
	,SubFn0: function() {
		var _t1;
		this._t0 = tardis.Go.haxegoruntime_ZiLen.ref() | 0;
		_t1 = tardis.Force.uintCompare(this._t0,1) == 0;
		this._Next = _t1?1:3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 138;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 138;
				this._latestBlock = 1;
				this._latestPH = 141;
				this._SF1 = new tardis.Go_haxegoruntime_RunesToUTF16(this._goroutine,[],this.p_r);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 141;
				this._latestBlock = -1;
				this._t2 = this._SF1.res();
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 141;
				this._latestBlock = 2;
				this._latestPH = 148;
				this._SF2 = new tardis.Go_haxegoruntime_RunesToUTF8(this._goroutine,[],this.p_r);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 148;
				this._latestBlock = -2;
				this._t6 = this._SF2.res();
				this.SubFn2();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 148;
				this._latestBlock = 3;
				this.SubFn3();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 148;
				this._latestBlock = 4;
				this._t11 = this._Phi == 1?-1:this._Phi == 5?this._t12:0;
				this.SubFn4();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 148;
				this._latestBlock = 5;
				this.SubFn5();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 148;
				this._latestBlock = 6;
				this._latestPH = 146;
				this._res = this._t4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 7:
				this._latestPH = 146;
				this._latestBlock = 7;
				this._latestPH = 156;
				throw "goruntime.Runes2Raw() unrecognised encoding";
				this.SubFn6();
				this._latestPH = 158;
				this._res = this._t20;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 158;
				this._latestBlock = 8;
				this._t21 = this._Phi == 2?-1:this._Phi == 9?this._t22:0;
				this.SubFn7();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 158;
				this._latestBlock = 9;
				this.SubFn8();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 158;
				this._latestBlock = 10;
				this._latestPH = 153;
				this._res = this._t8;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Runes2Raw
});
tardis.Go_utf8_ValidRune = function(gr,_bds,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t4 = false;
	this._t3 = false;
	this._t2 = false;
	this._t1 = false;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,983,"Go_utf8_ValidRune");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_ValidRune"] = tardis.Go_utf8_ValidRune;
$hxExpose(tardis.Go_utf8_ValidRune, "Go_utf8_ValidRune");
tardis.Go_utf8_ValidRune.__name__ = ["tardis","Go_utf8_ValidRune"];
tardis.Go_utf8_ValidRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_ValidRune.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_ValidRune(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_ValidRune.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_utf8_ValidRune(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_ValidRune.call = function(gr,_bds,p_r) {
	return new tardis.Go_utf8_ValidRune(gr,_bds,p_r);
}
tardis.Go_utf8_ValidRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_ValidRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn4: function() {
		this._Next = this._t4?2:5;
	}
	,SubFn3: function() {
		this._latestPH = 987;
		this._t3 = this.p_r <= 57343;
		this._Next = 7;
	}
	,SubFn2: function() {
		var _t2;
		this._latestPH = 989;
		_t2 = this.p_r > 1114111;
		this._Next = _t2?4:8;
	}
	,SubFn1: function() {
		var _t1;
		this._latestPH = 987;
		_t1 = 55296 <= this.p_r;
		this._Next = _t1?6:7;
	}
	,SubFn0: function() {
		var _t0;
		this._latestPH = 985;
		_t0 = this.p_r < 0;
		this._Next = _t0?1:3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 983;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 983;
				this._latestBlock = 1;
				this._latestPH = 986;
				this._res = false;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 986;
				this._latestBlock = 2;
				this._latestPH = 988;
				this._res = false;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 988;
				this._latestBlock = 3;
				this.SubFn1();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 988;
				this._latestBlock = 4;
				this._latestPH = 990;
				this._res = false;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 5:
				this._latestPH = 990;
				this._latestBlock = 5;
				this.SubFn2();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 990;
				this._latestBlock = 6;
				this._latestPH = 987;
				this._t3 = this.p_r <= 57343;
				this._Next = 7;
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 990;
				this._latestBlock = 7;
				this._latestPH = 987;
				this._t4 = this._Phi == 3?false:this._Phi == 6?this._t3:false;
				this._Next = this._t4?2:5;
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 987;
				this._latestBlock = 8;
				this._latestPH = 992;
				this._res = true;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_ValidRune
});
tardis.Go_utf8_FullRuneInString = function(gr,_bds,p_s) {
	this._Next = 0;
	this._t4 = false;
	this._t3 = false;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,759,"Go_utf8_FullRuneInString");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_FullRuneInString"] = tardis.Go_utf8_FullRuneInString;
$hxExpose(tardis.Go_utf8_FullRuneInString, "Go_utf8_FullRuneInString");
tardis.Go_utf8_FullRuneInString.__name__ = ["tardis","Go_utf8_FullRuneInString"];
tardis.Go_utf8_FullRuneInString.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_FullRuneInString.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_FullRuneInString(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_FullRuneInString.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf8_FullRuneInString(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_FullRuneInString.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf8_FullRuneInString(gr,_bds,p_s);
}
tardis.Go_utf8_FullRuneInString.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_FullRuneInString.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t3 = this._t0.r2;
		this._t4 = !this._t3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 759;
				this._latestBlock = 0;
				this._latestPH = 760;
				this._SF1 = new tardis._Go.Go_utf8_decodeRuneInStringInternal(this._goroutine,[],this.p_s);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 760;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._t3 = this._t0.r2;
				this._t4 = !this._t3;
				this._latestPH = 761;
				this._res = this._t4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_FullRuneInString
});
tardis.Go_haxegoruntime_RunesToUTF8 = function(gr,_bds,p_r) {
	this._Next = 0;
	this._Phi = 0;
	this._t13 = null;
	this._t11 = 0;
	this._t10 = null;
	this._t9 = null;
	this._t8 = 0;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = null;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,126,"Go_haxegoruntime_RunesToUTF8");
	this._bds = _bds;
	this.p_r = p_r;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_RunesToUTF8"] = tardis.Go_haxegoruntime_RunesToUTF8;
$hxExpose(tardis.Go_haxegoruntime_RunesToUTF8, "Go_haxegoruntime_RunesToUTF8");
tardis.Go_haxegoruntime_RunesToUTF8.__name__ = ["tardis","Go_haxegoruntime_RunesToUTF8"];
tardis.Go_haxegoruntime_RunesToUTF8.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_RunesToUTF8.callFromHaxe = function(p_r) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_RunesToUTF8(0,[],p_r).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_RunesToUTF8.callFromRT = function(_gr,p_r) {
	var _sf = new tardis.Go_haxegoruntime_RunesToUTF8(_gr,[],p_r).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_RunesToUTF8.call = function(gr,_bds,p_r) {
	return new tardis.Go_haxegoruntime_RunesToUTF8(gr,_bds,p_r);
}
tardis.Go_haxegoruntime_RunesToUTF8.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_RunesToUTF8.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn4: function() {
		this._latestPH = 132;
		this._t13 = (function($this) {
			var $r;
			var _v;
			if($this._t2 == null) _v = $this._t9; else if($this._t2.len() == 0) _v = $this._t9; else if($this._t9 == null) _v = $this._t2; else if($this._t9.len() == 0) _v = $this._t2; else {
				var l0 = $this._t2.len();
				_v = new tardis.Slice(new tardis.Pointer((function($this) {
					var $r;
					var _v1 = new Array();
					{
						var _g1 = 0, _g = $this._t2.len() + $this._t9.len();
						while(_g1 < _g) {
							var _i = _g1++;
							_v1[_i] = 0;
						}
					}
					$r = _v1;
					return $r;
				}($this))),0,$this._t2.len() + $this._t9.len());
				var _g = 0;
				while(_g < l0) {
					var _i = _g++;
					_v.setAt(_i,tardis.Deep.copy($this._t2.getAt(_i)));
				}
				var _g1 = 0, _g = $this._t9.len();
				while(_g1 < _g) {
					var _i = _g1++;
					_v.setAt(_i + l0,tardis.Deep.copy($this._t9.getAt(_i)));
				}
			}
			$r = _v;
			return $r;
		}(this));
		this._Next = 1;
	}
	,SubFn3: function() {
		var _t10;
		this._t9 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g1 = 0, _g = $this._t8;
				while(_g1 < _g) {
					var _i = _g1++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,this._t8);
		this._latestPH = 131;
		if(this._t4 < 0 || this._t4 >= this.p_r.len()) tardis.Scheduler.ioor();
		_t10 = this.p_r.addr(this._t4);
		this._t11 = _t10.ref() | 0;
	}
	,SubFn2: function() {
		var _t6;
		this._latestPH = 130;
		if(this._t4 < 0 || this._t4 >= this.p_r.len()) tardis.Scheduler.ioor();
		_t6 = this.p_r.addr(this._t4);
		this._t7 = _t6.ref() | 0;
	}
	,SubFn1: function() {
		var _t5;
		this._t4 = this._t3 + 1;
		_t5 = this._t4 < this._t1;
		this._Next = _t5?2:3;
	}
	,SubFn0: function() {
		this._latestPH = 128;
		this._t0 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < 0) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,0);
		this._t1 = (function($this) {
			var $r;
			var _v = $this.p_r;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 126;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 126;
				this._latestBlock = 1;
				this._latestPH = 127;
				this._t2 = this._Phi == 0?this._t0:this._Phi == 2?this._t13:new tardis.Slice(new tardis.Pointer(new Array()),0,0);
				this._t3 = this._Phi == 0?-1:this._Phi == 2?this._t4:0;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 127;
				this._latestBlock = 2;
				this.SubFn2();
				this._latestPH = 130;
				this._SF1 = new tardis.Go_utf8_RuneLen(this._goroutine,[],this._t7);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 130;
				this._latestBlock = -1;
				this._t8 = this._SF1.res();
				this.SubFn3();
				this._latestPH = 131;
				new tardis.Go_utf8_EncodeRune(this._goroutine,[],this._t9,this._t11);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 131;
				this._latestBlock = -2;
				this.SubFn4();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 131;
				this._latestBlock = 3;
				this._latestPH = 134;
				this._res = this._t2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_RunesToUTF8
});
tardis.Go_utf8_DecodeLastRuneInString = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t22 = false;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = 0;
	this._t18 = null;
	this._t17 = "";
	this._t16 = 0;
	this._t15 = 0;
	this._t14 = false;
	this._t13 = 0;
	this._t12 = false;
	this._t11 = false;
	this._t10 = 0;
	this._t9 = 0;
	this._t8 = 0;
	this._t7 = false;
	this._t6 = 0;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,826,"Go_utf8_DecodeLastRuneInString");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_DecodeLastRuneInString"] = tardis.Go_utf8_DecodeLastRuneInString;
$hxExpose(tardis.Go_utf8_DecodeLastRuneInString, "Go_utf8_DecodeLastRuneInString");
tardis.Go_utf8_DecodeLastRuneInString.__name__ = ["tardis","Go_utf8_DecodeLastRuneInString"];
tardis.Go_utf8_DecodeLastRuneInString.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_DecodeLastRuneInString.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_DecodeLastRuneInString(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_DecodeLastRuneInString.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf8_DecodeLastRuneInString(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_DecodeLastRuneInString.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf8_DecodeLastRuneInString(gr,_bds,p_s);
}
tardis.Go_utf8_DecodeLastRuneInString.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_DecodeLastRuneInString.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn12: function() {
		var _t21;
		var _t22;
		this._t19 = this._t18.r0;
		this._t20 = this._t18.r1;
		this._latestPH = 852;
		_t21 = this._t16 + this._t20;
		_t22 = _t21 != this._t0;
		this._Next = _t22?13:14;
	}
	,SubFn11: function() {
		this._latestPH = 851;
		this._t17 = tardis.Force.toRawString(this._goroutine,tardis.Force.toUTF8slice(this._goroutine,this.p_s).subSlice(this._t16,this._t0));
	}
	,SubFn10: function() {
		this._Next = 12;
	}
	,SubFn9: function() {
		this._t15 = this._t13 - 1;
		this._Next = 9;
	}
	,SubFn8: function() {
		var _t14;
		this._latestPH = 843;
		_t14 = this._t13 >= this._t8;
		this._Next = _t14?7:8;
	}
	,SubFn7: function() {
		var _t12;
		this._latestPH = 848;
		_t12 = this._t13 < 0;
		this._Next = _t12?11:12;
	}
	,SubFn6: function() {
		this._Next = this._t11?8:10;
	}
	,SubFn5: function() {
		this._latestPH = 844;
		this._t10 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(this._t13);
	}
	,SubFn4: function() {
		this._t9 = this._t2 - 1;
		this._Next = 9;
	}
	,SubFn3: function() {
		this._Next = 6;
	}
	,SubFn2: function() {
		var _t7;
		this._latestPH = 839;
		this._t6 = this._t0 - 4;
		this._latestPH = 840;
		_t7 = this._t6 < 0;
		this._Next = _t7?5:6;
	}
	,SubFn1: function() {
		var _t3;
		var _t5;
		this._latestPH = 831;
		this._t2 = this._t0 - 1;
		this._latestPH = 832;
		_t3 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(this._t2);
		this._t4 = _t3;
		this._latestPH = 833;
		_t5 = this._t4 < 128;
		this._Next = _t5?3:4;
	}
	,SubFn0: function() {
		var _t1;
		this._latestPH = 827;
		this._t0 = tardis.Force.toUTF8length(this._goroutine,this.p_s);
		this._latestPH = 828;
		_t1 = this._t0 == 0;
		this._Next = _t1?1:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 826;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 826;
				this._latestBlock = 1;
				this._latestPH = 829;
				this._res = { r0 : 65533, r1 : 0};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 829;
				this._latestBlock = 2;
				this.SubFn1();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 829;
				this._latestBlock = 3;
				this._latestPH = 834;
				this._res = { r0 : this._t4, r1 : 1};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 834;
				this._latestBlock = 4;
				this.SubFn2();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 834;
				this._latestBlock = 5;
				this._Next = 6;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 834;
				this._latestBlock = 6;
				this._latestPH = 839;
				this._t8 = this._Phi == 4?this._t6:this._Phi == 5?0:0;
				this._t9 = this._t2 - 1;
				this._Next = 9;
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 839;
				this._latestBlock = 7;
				this._latestPH = 844;
				this._t10 = tardis.Force.toUTF8slice(this._goroutine,this.p_s).getAt(this._t13);
				this._latestPH = 844;
				this._SF1 = new tardis.Go_utf8_RuneStart(this._goroutine,[],this._t10);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 844;
				this._latestBlock = -1;
				this._t11 = this._SF1.res();
				this._Next = this._t11?8:10;
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 844;
				this._latestBlock = 8;
				this.SubFn7();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 844;
				this._latestBlock = 9;
				this._latestPH = 831;
				this._t13 = this._Phi == 6?this._t9:this._Phi == 10?this._t15:0;
				this.SubFn8();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 831;
				this._latestBlock = 10;
				this._t15 = this._t13 - 1;
				this._Next = 9;
				this._Phi = 10;
				break;
			case 11:
				this._latestPH = 831;
				this._latestBlock = 11;
				this._Next = 12;
				this._Phi = 11;
				break;
			case 12:
				this._latestPH = 831;
				this._latestBlock = 12;
				this._t16 = this._Phi == 8?this._t13:this._Phi == 11?0:0;
				this._latestPH = 851;
				this._t17 = tardis.Force.toRawString(this._goroutine,tardis.Force.toUTF8slice(this._goroutine,this.p_s).subSlice(this._t16,this._t0));
				this._latestPH = 851;
				this._SF2 = new tardis.Go_utf8_DecodeRuneInString(this._goroutine,[],this._t17);
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 851;
				this._latestBlock = -2;
				this._t18 = this._SF2.res();
				this.SubFn12();
				this._Phi = 12;
				break;
			case 13:
				this._latestPH = 851;
				this._latestBlock = 13;
				this._latestPH = 853;
				this._res = { r0 : 65533, r1 : 1};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 14:
				this._latestPH = 853;
				this._latestBlock = 14;
				this._latestPH = 855;
				this._res = { r0 : this._t19, r1 : this._t20};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_DecodeLastRuneInString
});
tardis.Go_hxutil_Platform = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,1010,"Go_hxutil_Platform");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_hxutil_Platform"] = tardis.Go_hxutil_Platform;
$hxExpose(tardis.Go_hxutil_Platform, "Go_hxutil_Platform");
tardis.Go_hxutil_Platform.__name__ = ["tardis","Go_hxutil_Platform"];
tardis.Go_hxutil_Platform.__interfaces__ = [tardis.StackFrame];
tardis.Go_hxutil_Platform.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_hxutil_Platform(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_hxutil_Platform.callFromRT = function(_gr) {
	var _sf = new tardis.Go_hxutil_Platform(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_hxutil_Platform.call = function(gr,_bds) {
	return new tardis.Go_hxutil_Platform(gr,_bds);
}
tardis.Go_hxutil_Platform.__super__ = tardis.StackFrameBasis;
tardis.Go_hxutil_Platform.prototype = $extend(tardis.StackFrameBasis.prototype,{
	run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 1010;
				this._latestBlock = 0;
				this._res = "go";
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_hxutil_Platform
});
tardis.Go_utf8_DecodeRune = function(gr,_bds,p_p) {
	this._Next = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,769,"Go_utf8_DecodeRune");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_DecodeRune"] = tardis.Go_utf8_DecodeRune;
$hxExpose(tardis.Go_utf8_DecodeRune, "Go_utf8_DecodeRune");
tardis.Go_utf8_DecodeRune.__name__ = ["tardis","Go_utf8_DecodeRune"];
tardis.Go_utf8_DecodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_DecodeRune.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_DecodeRune(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_DecodeRune.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_DecodeRune(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_DecodeRune.call = function(gr,_bds,p_p) {
	return new tardis.Go_utf8_DecodeRune(gr,_bds,p_p);
}
tardis.Go_utf8_DecodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_DecodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t1 = this._t0.r0;
		this._t2 = this._t0.r1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 769;
				this._latestBlock = 0;
				this._latestPH = 770;
				this._SF1 = new tardis._Go.Go_utf8_decodeRuneInternal(this._goroutine,[],this.p_p);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 770;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._t1 = this._t0.r0;
				this._t2 = this._t0.r1;
				this._latestPH = 771;
				this._res = { r0 : this._t1, r1 : this._t2};
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_DecodeRune
});
tardis._Go.Go_hxutil_init = function(gr,_bds) {
	this._Next = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,771,"Go_hxutil_init");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_hxutil_init"] = tardis._Go.Go_hxutil_init;
tardis._Go.Go_hxutil_init.__name__ = ["tardis","_Go","Go_hxutil_init"];
tardis._Go.Go_hxutil_init.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_hxutil_init.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_hxutil_init(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_hxutil_init.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_hxutil_init(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_hxutil_init.call = function(gr,_bds) {
	return new tardis._Go.Go_hxutil_init(gr,_bds);
}
tardis._Go.Go_hxutil_init.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_hxutil_init.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn1: function() {
		tardis.Go.hxutil_init_36_guard.store(true);
		this._Next = 2;
	}
	,SubFn0: function() {
		var _t0;
		_t0 = tardis.Go.hxutil_init_36_guard.ref();
		this._Next = _t0?2:1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 771;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 771;
				this._latestBlock = 1;
				tardis.Go.hxutil_init_36_guard.store(true);
				this._Next = 2;
				break;
			case 2:
				this._latestPH = 771;
				this._latestBlock = 2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_hxutil_init
});
tardis.Go_haxegoruntime_Callers = function(gr,_bds,p_skip,p_pc) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,410,"Go_haxegoruntime_Callers");
	this._bds = _bds;
	this.p_skip = p_skip;
	this.p_pc = p_pc;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Callers"] = tardis.Go_haxegoruntime_Callers;
$hxExpose(tardis.Go_haxegoruntime_Callers, "Go_haxegoruntime_Callers");
tardis.Go_haxegoruntime_Callers.__name__ = ["tardis","Go_haxegoruntime_Callers"];
tardis.Go_haxegoruntime_Callers.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Callers.callFromHaxe = function(p_skip,p_pc) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Callers(0,[],p_skip,p_pc).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Callers.callFromRT = function(_gr,p_skip,p_pc) {
	var _sf = new tardis.Go_haxegoruntime_Callers(_gr,[],p_skip,p_pc).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Callers.call = function(gr,_bds,p_skip,p_pc) {
	return new tardis.Go_haxegoruntime_Callers(gr,_bds,p_skip,p_pc);
}
tardis.Go_haxegoruntime_Callers.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Callers.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.Callers() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 410;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.Callers() not yet implemented");
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 410;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Callers
});
tardis.Go_haxegoruntime_Rune2Raw = function(gr,_bds,p_oneRune) {
	this._Next = 0;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,161,"Go_haxegoruntime_Rune2Raw");
	this._bds = _bds;
	this.p_oneRune = p_oneRune;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Rune2Raw"] = tardis.Go_haxegoruntime_Rune2Raw;
$hxExpose(tardis.Go_haxegoruntime_Rune2Raw, "Go_haxegoruntime_Rune2Raw");
tardis.Go_haxegoruntime_Rune2Raw.__name__ = ["tardis","Go_haxegoruntime_Rune2Raw"];
tardis.Go_haxegoruntime_Rune2Raw.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Rune2Raw.callFromHaxe = function(p_oneRune) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Rune2Raw(0,[],p_oneRune).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Rune2Raw.callFromRT = function(_gr,p_oneRune) {
	var _sf = new tardis.Go_haxegoruntime_Rune2Raw(_gr,[],p_oneRune).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Rune2Raw.call = function(gr,_bds,p_oneRune) {
	return new tardis.Go_haxegoruntime_Rune2Raw(gr,_bds,p_oneRune);
}
tardis.Go_haxegoruntime_Rune2Raw.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Rune2Raw.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t1;
		this._latestPH = 162;
		this._t0 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < 1) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,1);
		this._latestPH = 163;
		if(0 >= this._t0.len()) tardis.Scheduler.ioor();
		_t1 = this._t0.addr(0);
		_t1.store(this.p_oneRune);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 161;
				this._latestBlock = 0;
				this.SubFn0();
				this._latestPH = 164;
				this._SF1 = new tardis.Go_haxegoruntime_Runes2Raw(this._goroutine,[],this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 164;
				this._latestBlock = -1;
				this._t2 = this._SF1.res();
				this._res = this._t2;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Rune2Raw
});
tardis.Go_haxegoruntime_C5 = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,209,"Go_haxegoruntime_C5");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	this.p_a5 = p_a5;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C5"] = tardis.Go_haxegoruntime_C5;
$hxExpose(tardis.Go_haxegoruntime_C5, "Go_haxegoruntime_C5");
tardis.Go_haxegoruntime_C5.__name__ = ["tardis","Go_haxegoruntime_C5"];
tardis.Go_haxegoruntime_C5.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C5.callFromHaxe = function(p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C5(0,[],p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C5.callFromRT = function(_gr,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5) {
	var _sf = new tardis.Go_haxegoruntime_C5(_gr,[],p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C5.call = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5) {
	return new tardis.Go_haxegoruntime_C5(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5);
}
tardis.Go_haxegoruntime_C5.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C5.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 209;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C5
});
tardis.Go_main_MouseMove = function(gr,_bds,p_x,p_y) {
	this._Next = 0;
	this._t5 = null;
	this._t4 = null;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,21,"Go_main_MouseMove");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_y = p_y;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_main_MouseMove"] = tardis.Go_main_MouseMove;
$hxExpose(tardis.Go_main_MouseMove, "Go_main_MouseMove");
tardis.Go_main_MouseMove.__name__ = ["tardis","Go_main_MouseMove"];
tardis.Go_main_MouseMove.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_MouseMove.callFromHaxe = function(p_x,p_y) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_main_MouseMove(0,[],p_x,p_y).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_main_MouseMove.callFromRT = function(_gr,p_x,p_y) {
	var _sf = new tardis.Go_main_MouseMove(_gr,[],p_x,p_y).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_main_MouseMove.call = function(gr,_bds,p_x,p_y) {
	return new tardis.Go_main_MouseMove(gr,_bds,p_x,p_y);
}
tardis.Go_main_MouseMove.__super__ = tardis.StackFrameBasis;
tardis.Go_main_MouseMove.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		var _t1;
		var _t2;
		var _t3;
		var _t4;
		this._t0 = tardis.Go.main_mouseEvents.ref();
		_t1 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			_v = [0,0.0,0.0];
			$r = _v;
			return $r;
		}(this)));
		_t2 = _t1.addr(0);
		_t2.store(2);
		_t3 = _t1.addr(1);
		_t3.store(this.p_x);
		_t4 = _t1.addr(2);
		_t4.store(this.p_y);
		this._t5 = _t1.ref();
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 21;
				this._latestBlock = 0;
				this.SubFn0();
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 21;
				this._latestBlock = -1;
				if(!this._t0.hasSpace()) return this;
				this._t0.send(this._t5);
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_main_MouseMove
});
tardis.Go_haxegoruntime_Raw2Runes = function(gr,_bds,p_s) {
	this._Next = 0;
	this._Phi = 0;
	this._t27 = null;
	this._t26 = 0;
	this._t25 = 0;
	this._t24 = null;
	this._t23 = null;
	this._t22 = false;
	this._t21 = 0;
	this._t20 = 0;
	this._t19 = null;
	this._t18 = null;
	this._t16 = null;
	this._t15 = 0;
	this._t14 = 0;
	this._t13 = null;
	this._t12 = null;
	this._t11 = false;
	this._t10 = 0;
	this._t9 = 0;
	this._t8 = false;
	this._t7 = 0;
	this._t6 = null;
	this._t5 = 0;
	this._t4 = 0;
	this._t3 = null;
	this._t2 = 0;
	this._t1 = false;
	this._t0 = 0;
	tardis.StackFrameBasis.call(this,gr,102,"Go_haxegoruntime_Raw2Runes");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_Raw2Runes"] = tardis.Go_haxegoruntime_Raw2Runes;
$hxExpose(tardis.Go_haxegoruntime_Raw2Runes, "Go_haxegoruntime_Raw2Runes");
tardis.Go_haxegoruntime_Raw2Runes.__name__ = ["tardis","Go_haxegoruntime_Raw2Runes"];
tardis.Go_haxegoruntime_Raw2Runes.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_Raw2Runes.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_Raw2Runes(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_Raw2Runes.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_haxegoruntime_Raw2Runes(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_Raw2Runes.call = function(gr,_bds,p_s) {
	return new tardis.Go_haxegoruntime_Raw2Runes(gr,_bds,p_s);
}
tardis.Go_haxegoruntime_Raw2Runes.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_Raw2Runes.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn8: function() {
		var _t23;
		var _t24;
		var _t25;
		var _t26;
		this._latestPH = 113;
		if(this._t21 < 0 || this._t21 >= this._t6.len()) tardis.Scheduler.ioor();
		_t23 = this._t6.addr(this._t21);
		if(this._t21 < 0 || this._t21 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t24 = this.p_s.addr(this._t21);
		_t25 = _t24.ref() | 0;
		_t26 = _t25;
		_t23.store(_t26);
		this._Next = 8;
	}
	,SubFn7: function() {
		var _t22;
		this._t21 = this._t20 + 1;
		_t22 = this._t21 < this._t7;
		this._Next = _t22?9:10;
	}
	,SubFn6: function() {
		var _t18;
		this._latestPH = 120;
		_t18 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < 0) {
					var _vi = _g++;
					_v[_vi] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this)));
		this._t19 = new tardis.Slice(_t18,0,-1);
	}
	,SubFn5: function() {
		var _t12;
		var _t13;
		var _t14;
		var _t15;
		this._latestPH = 107;
		if(this._t10 < 0 || this._t10 >= this._t3.len()) tardis.Scheduler.ioor();
		_t12 = this._t3.addr(this._t10);
		if(this._t10 < 0 || this._t10 >= this.p_s.len()) tardis.Scheduler.ioor();
		_t13 = this.p_s.addr(this._t10);
		_t14 = _t13.ref() | 0;
		_t15 = _t14;
		_t12.store(_t15);
		this._Next = 4;
	}
	,SubFn4: function() {
		var _t11;
		this._t10 = this._t9 + 1;
		_t11 = this._t10 < this._t4;
		this._Next = _t11?5:6;
	}
	,SubFn3: function() {
		var _t8;
		_t8 = tardis.Force.uintCompare(this._t0,3) == 0;
		this._Next = _t8?2:7;
	}
	,SubFn2: function() {
		var _t5;
		this._latestPH = 111;
		_t5 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t6 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t5) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t5);
		this._t7 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 8;
	}
	,SubFn1: function() {
		var _t2;
		this._latestPH = 105;
		_t2 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._t3 = new tardis.Slice(new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			{
				var _g = 0;
				while(_g < _t2) {
					var _i = _g++;
					_v[_i] = 0;
				}
			}
			$r = _v;
			return $r;
		}(this))),0,_t2);
		this._t4 = (function($this) {
			var $r;
			var _v = $this.p_s;
			$r = _v == null?0:_v.end - _v.start;
			return $r;
		}(this));
		this._Next = 4;
	}
	,SubFn0: function() {
		var _t1;
		this._t0 = tardis.Go.haxegoruntime_ZiLen.ref() | 0;
		_t1 = tardis.Force.uintCompare(this._t0,1) == 0;
		this._Next = _t1?1:3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 102;
				this._latestBlock = 0;
				this.SubFn0();
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 102;
				this._latestBlock = 1;
				this.SubFn1();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 102;
				this._latestBlock = 2;
				this.SubFn2();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 102;
				this._latestBlock = 3;
				this.SubFn3();
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 102;
				this._latestBlock = 4;
				this._t9 = this._Phi == 1?-1:this._Phi == 5?this._t10:0;
				this.SubFn4();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 102;
				this._latestBlock = 5;
				this.SubFn5();
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 102;
				this._latestBlock = 6;
				this._latestPH = 109;
				this._SF1 = new tardis.Go_haxegoruntime_UTF16toRunes(this._goroutine,[],this._t3);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 109;
				this._latestBlock = -1;
				this._t16 = this._SF1.res();
				this._res = this._t16;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 7:
				this._latestPH = 109;
				this._latestBlock = 7;
				this._latestPH = 118;
				throw "goruntime.Runes2String() unrecognised encoding";
				this.SubFn6();
				this._latestPH = 120;
				this._res = this._t19;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 8:
				this._latestPH = 120;
				this._latestBlock = 8;
				this._t20 = this._Phi == 2?-1:this._Phi == 9?this._t21:0;
				this.SubFn7();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 120;
				this._latestBlock = 9;
				this.SubFn8();
				this._Phi = 9;
				break;
			case 10:
				this._latestPH = 120;
				this._latestBlock = 10;
				this._latestPH = 115;
				this._SF3 = new tardis.Go_haxegoruntime_UTF8toRunes(this._goroutine,[],this._t6);
				this._Next = -3;
				return this;
			case -3:
				this._latestPH = 115;
				this._latestBlock = -3;
				this._t27 = this._SF3.res();
				this._res = this._t27;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_Raw2Runes
});
tardis.Go_haxegoruntime_SetFinalizer = function(gr,_bds,p_x,p_f) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,412,"Go_haxegoruntime_SetFinalizer");
	this._bds = _bds;
	this.p_x = p_x;
	this.p_f = p_f;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_SetFinalizer"] = tardis.Go_haxegoruntime_SetFinalizer;
$hxExpose(tardis.Go_haxegoruntime_SetFinalizer, "Go_haxegoruntime_SetFinalizer");
tardis.Go_haxegoruntime_SetFinalizer.__name__ = ["tardis","Go_haxegoruntime_SetFinalizer"];
tardis.Go_haxegoruntime_SetFinalizer.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_SetFinalizer.callFromHaxe = function(p_x,p_f) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_SetFinalizer(0,[],p_x,p_f).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_haxegoruntime_SetFinalizer.callFromRT = function(_gr,p_x,p_f) {
	var _sf = new tardis.Go_haxegoruntime_SetFinalizer(_gr,[],p_x,p_f).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_haxegoruntime_SetFinalizer.call = function(gr,_bds,p_x,p_f) {
	return new tardis.Go_haxegoruntime_SetFinalizer(gr,_bds,p_x,p_f);
}
tardis.Go_haxegoruntime_SetFinalizer.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_SetFinalizer.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.SetFinalizer() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 412;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.SetFinalizer() not yet implemented");
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 412;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_haxegoruntime_SetFinalizer
});
tardis.Go_haxegoruntime_M0 = function(gr,_bds,p_rx,p_typ,p_meth) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,215,"Go_haxegoruntime_M0");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M0"] = tardis.Go_haxegoruntime_M0;
$hxExpose(tardis.Go_haxegoruntime_M0, "Go_haxegoruntime_M0");
tardis.Go_haxegoruntime_M0.__name__ = ["tardis","Go_haxegoruntime_M0"];
tardis.Go_haxegoruntime_M0.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M0.callFromHaxe = function(p_rx,p_typ,p_meth) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M0(0,[],p_rx,p_typ,p_meth).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M0.callFromRT = function(_gr,p_rx,p_typ,p_meth) {
	var _sf = new tardis.Go_haxegoruntime_M0(_gr,[],p_rx,p_typ,p_meth).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M0.call = function(gr,_bds,p_rx,p_typ,p_meth) {
	return new tardis.Go_haxegoruntime_M0(gr,_bds,p_rx,p_typ,p_meth);
}
tardis.Go_haxegoruntime_M0.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M0.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 215;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M0
});
tardis._Go.Go_main_handleMouse = function(gr,_bds) {
	this._Next = 0;
	this._Phi = 0;
	this._t28 = false;
	this._t27 = 0.0;
	this._t26 = 0.0;
	this._t25 = 0.0;
	this._t24 = null;
	this._t23 = 0.0;
	this._t22 = 0.0;
	this._t21 = 0.0;
	this._t20 = null;
	this._t19 = false;
	this._t18 = false;
	this._t17 = 0;
	this._t16 = null;
	this._t15 = null;
	this._t14 = null;
	this._t13 = 0.0;
	this._t12 = 0.0;
	this._t11 = null;
	this._t10 = 0.0;
	this._t9 = 0.0;
	this._t8 = 0.0;
	this._t7 = null;
	this._t6 = 0.0;
	this._t5 = false;
	this._t4 = 0;
	this._t3 = null;
	this._t2 = null;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,35,"Go_main_handleMouse");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_main_handleMouse"] = tardis._Go.Go_main_handleMouse;
tardis._Go.Go_main_handleMouse.__name__ = ["tardis","_Go","Go_main_handleMouse"];
tardis._Go.Go_main_handleMouse.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_main_handleMouse.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_main_handleMouse(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis._Go.Go_main_handleMouse.callFromRT = function(_gr) {
	var _sf = new tardis._Go.Go_main_handleMouse(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis._Go.Go_main_handleMouse.call = function(gr,_bds) {
	return new tardis._Go.Go_main_handleMouse(gr,_bds);
}
tardis._Go.Go_main_handleMouse.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_main_handleMouse.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn11: function() {
		tardis.Go.main_Status.store("awaiting MOUSE_UP");
		this._Next = 5;
	}
	,SubFn10: function() {
		var _t28;
		_t28 = this._t17 == 0;
		this._Next = _t28?7:9;
	}
	,SubFn9: function() {
		tardis.Go.main_Status.store("MOUSE_UP");
		this._Next = 5;
	}
	,SubFn8: function() {
		var _t20;
		var _t21;
		var _t22;
		var _t23;
		var _t24;
		var _t25;
		var _t26;
		var _t27;
		tardis.Go.main_Status.store("MOUSE_MOVE");
		_t20 = this._t0.ref();
		this._latestPH = 49;
		_t21 = _t20[1];
		_t22 = tardis.Go.main_cacheOffsetX.ref();
		_t23 = _t21 + _t22;
		tardis.Go.main_SpriteX.store(_t23);
		_t24 = this._t0.ref();
		this._latestPH = 50;
		_t25 = _t24[2];
		_t26 = tardis.Go.main_cacheOffsetY.ref();
		_t27 = _t25 + _t26;
		tardis.Go.main_SpriteY.store(_t27);
		this._Next = 5;
	}
	,SubFn7: function() {
		this._Next = this._t19?4:1;
	}
	,SubFn6: function() {
		var _t16;
		var _t18;
		this._t0.store(this._t15);
		_t16 = this._t0.ref();
		this._latestPH = 46;
		this._t17 = _t16[0];
		_t18 = this._t17 == 2;
		this._Next = _t18?6:8;
	}
	,SubFn5: function() {
		this._t14 = tardis.Go.main_mouseEvents.ref();
	}
	,SubFn4: function() {
		tardis.Go.main_Status.store("awaiting MOUSE_DOWN");
		this._Next = 1;
	}
	,SubFn3: function() {
		var _t6;
		var _t7;
		var _t8;
		var _t9;
		var _t10;
		var _t11;
		var _t12;
		var _t13;
		tardis.Go.main_Status.store("MOUSE_DOWN");
		_t6 = tardis.Go.main_SpriteX.ref();
		_t7 = this._t0.ref();
		this._latestPH = 41;
		_t8 = _t7[1];
		_t9 = _t6 - _t8;
		tardis.Go.main_cacheOffsetX.store(_t9);
		_t10 = tardis.Go.main_SpriteY.ref();
		_t11 = this._t0.ref();
		this._latestPH = 42;
		_t12 = _t11[2];
		_t13 = _t10 - _t12;
		tardis.Go.main_cacheOffsetY.store(_t13);
		this._Next = 5;
	}
	,SubFn2: function() {
		var _t3;
		var _t4;
		var _t5;
		this._t0.store(this._t2);
		_t3 = this._t0.ref();
		this._latestPH = 38;
		_t4 = _t3[0];
		_t5 = _t4 == 1;
		this._Next = _t5?2:3;
	}
	,SubFn1: function() {
		this._latestPH = 37;
		this._t0 = new tardis.Pointer((function($this) {
			var $r;
			var _v = new Array();
			_v = [0,0.0,0.0];
			$r = _v;
			return $r;
		}(this)));
		this._t1 = tardis.Go.main_mouseEvents.ref();
	}
	,SubFn0: function() {
		this._Next = 1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 35;
				this._latestBlock = 0;
				this._Next = 1;
				this._Phi = 0;
				break;
			case 1:
				this._latestPH = 35;
				this._latestBlock = 1;
				this.SubFn1();
				this._latestPH = 37;
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 37;
				this._latestBlock = -1;
				if(this._t1.hasNoContents()) return this;
				this._t2 = this._t1.receive((function($this) {
					var $r;
					var _v = new Array();
					_v = [0,0.0,0.0];
					$r = _v;
					return $r;
				}(this))).r0;
				this.SubFn2();
				this._Phi = 1;
				break;
			case 2:
				this._latestPH = 37;
				this._latestBlock = 2;
				this.SubFn3();
				this._Phi = 2;
				break;
			case 3:
				this._latestPH = 37;
				this._latestBlock = 3;
				tardis.Go.main_Status.store("awaiting MOUSE_DOWN");
				this._Next = 1;
				this._Phi = 3;
				break;
			case 4:
				this._latestPH = 37;
				this._latestBlock = 4;
				this._t14 = tardis.Go.main_mouseEvents.ref();
				this._latestPH = 45;
				this._Next = -2;
				return this;
			case -2:
				this._latestPH = 45;
				this._latestBlock = -2;
				if(this._t14.hasNoContents()) return this;
				this._t15 = this._t14.receive((function($this) {
					var $r;
					var _v = new Array();
					_v = [0,0.0,0.0];
					$r = _v;
					return $r;
				}(this))).r0;
				this.SubFn6();
				this._Phi = 4;
				break;
			case 5:
				this._latestPH = 45;
				this._latestBlock = 5;
				this._latestPH = 43;
				this._t19 = this._Phi == 2?true:this._Phi == 6?this._t19:this._Phi == 7?false:this._Phi == 9?this._t19:false;
				this._Next = this._t19?4:1;
				this._Phi = 5;
				break;
			case 6:
				this._latestPH = 43;
				this._latestBlock = 6;
				this.SubFn8();
				this._Phi = 6;
				break;
			case 7:
				this._latestPH = 43;
				this._latestBlock = 7;
				tardis.Go.main_Status.store("MOUSE_UP");
				this._Next = 5;
				this._Phi = 7;
				break;
			case 8:
				this._latestPH = 43;
				this._latestBlock = 8;
				this.SubFn10();
				this._Phi = 8;
				break;
			case 9:
				this._latestPH = 43;
				this._latestBlock = 9;
				tardis.Go.main_Status.store("awaiting MOUSE_UP");
				this._Next = 5;
				this._Phi = 9;
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis._Go.Go_main_handleMouse
});
tardis.Go_utf8_FullRune = function(gr,_bds,p_p) {
	this._Next = 0;
	this._t4 = false;
	this._t3 = false;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,753,"Go_utf8_FullRune");
	this._bds = _bds;
	this.p_p = p_p;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_FullRune"] = tardis.Go_utf8_FullRune;
$hxExpose(tardis.Go_utf8_FullRune, "Go_utf8_FullRune");
tardis.Go_utf8_FullRune.__name__ = ["tardis","Go_utf8_FullRune"];
tardis.Go_utf8_FullRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_FullRune.callFromHaxe = function(p_p) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_FullRune(0,[],p_p).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_FullRune.callFromRT = function(_gr,p_p) {
	var _sf = new tardis.Go_utf8_FullRune(_gr,[],p_p).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_FullRune.call = function(gr,_bds,p_p) {
	return new tardis.Go_utf8_FullRune(gr,_bds,p_p);
}
tardis.Go_utf8_FullRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_FullRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t3 = this._t0.r2;
		this._t4 = !this._t3;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 753;
				this._latestBlock = 0;
				this._latestPH = 754;
				this._SF1 = new tardis._Go.Go_utf8_decodeRuneInternal(this._goroutine,[],this.p_p);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 754;
				this._latestBlock = -1;
				this._t0 = this._SF1.res();
				this._t3 = this._t0.r2;
				this._t4 = !this._t3;
				this._latestPH = 755;
				this._res = this._t4;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_FullRune
});
tardis.Go_utf8_ValidString = function(gr,_bds,p_s) {
	this._Next = 0;
	this._t10 = false;
	this._t9 = 0;
	this._t7 = null;
	this._t6 = "";
	this._t5 = false;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = false;
	this._t1 = null;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,965,"Go_utf8_ValidString");
	this._bds = _bds;
	this.p_s = p_s;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf8_ValidString"] = tardis.Go_utf8_ValidString;
$hxExpose(tardis.Go_utf8_ValidString, "Go_utf8_ValidString");
tardis.Go_utf8_ValidString.__name__ = ["tardis","Go_utf8_ValidString"];
tardis.Go_utf8_ValidString.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf8_ValidString.callFromHaxe = function(p_s) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf8_ValidString(0,[],p_s).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf8_ValidString.callFromRT = function(_gr,p_s) {
	var _sf = new tardis.Go_utf8_ValidString(_gr,[],p_s).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf8_ValidString.call = function(gr,_bds,p_s) {
	return new tardis.Go_utf8_ValidString(gr,_bds,p_s);
}
tardis.Go_utf8_ValidString.__super__ = tardis.StackFrameBasis;
tardis.Go_utf8_ValidString.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn4: function() {
		var _t10;
		this._t9 = this._t7.r1;
		this._latestPH = 973;
		_t10 = this._t9 == 1;
		this._Next = _t10?5:1;
	}
	,SubFn3: function() {
		this._latestPH = 972;
		this._t6 = tardis.Force.toRawString(this._goroutine,tardis.Force.toUTF8slice(this._goroutine,this.p_s).subSlice(this._t3,-1));
	}
	,SubFn2: function() {
		var _t5;
		this._t3 = this._t1.r1;
		this._t4 = this._t1.r2;
		this._latestPH = 967;
		_t5 = this._t4 == 65533;
		this._Next = _t5?4:1;
	}
	,SubFn1: function() {
		var _t2;
		this._t1 = (function($this) {
			var $r;
			var _thisK = $this._t0.k;
			$r = $this._t0.k >= $this._t0.v.len()?{ r0 : false, r1 : 0, r2 : 0}:(function($this) {
				var $r;
				var _dr = tardis.Go_utf8_DecodeRune.callFromRT($this._goroutine,$this._t0.v.subSlice(_thisK,-1));
				$this._t0.k += _dr.r1;
				$r = { r0 : true, r1 : js.Boot.__cast(_thisK , Int), r2 : js.Boot.__cast(_dr.r0 , Int)};
				return $r;
			}($this));
			return $r;
		}(this));
		_t2 = this._t1.r0;
		this._Next = _t2?2:3;
	}
	,SubFn0: function() {
		this._latestPH = 966;
		this._t0 = { k : 0, v : tardis.Force.toUTF8slice(this._goroutine,this.p_s)};
		this._Next = 1;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 965;
				this._latestBlock = 0;
				this._latestPH = 966;
				this._t0 = { k : 0, v : tardis.Force.toUTF8slice(this._goroutine,this.p_s)};
				this._Next = 1;
				break;
			case 1:
				this._latestPH = 965;
				this._latestBlock = 1;
				this.SubFn1();
				break;
			case 2:
				this._latestPH = 965;
				this._latestBlock = 2;
				this.SubFn2();
				break;
			case 3:
				this._latestPH = 965;
				this._latestBlock = 3;
				this._latestPH = 978;
				this._res = true;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 4:
				this._latestPH = 978;
				this._latestBlock = 4;
				this._latestPH = 972;
				this._t6 = tardis.Force.toRawString(this._goroutine,tardis.Force.toUTF8slice(this._goroutine,this.p_s).subSlice(this._t3,-1));
				this._latestPH = 972;
				this._SF1 = new tardis.Go_utf8_DecodeRuneInString(this._goroutine,[],this._t6);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 972;
				this._latestBlock = -1;
				this._t7 = this._SF1.res();
				this.SubFn4();
				break;
			case 5:
				this._latestPH = 972;
				this._latestBlock = 5;
				this._latestPH = 974;
				this._res = false;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf8_ValidString
});
tardis.Go_utf16_DecodeRune = function(gr,_bds,p_r1,p_r2) {
	this._Next = 0;
	this._t8 = false;
	this._t7 = false;
	this._t6 = false;
	this._t5 = 0;
	this._t4 = 0;
	this._t3 = 0;
	this._t2 = 0;
	this._t1 = 0;
	this._t0 = false;
	tardis.StackFrameBasis.call(this,gr,479,"Go_utf16_DecodeRune");
	this._bds = _bds;
	this.p_r1 = p_r1;
	this.p_r2 = p_r2;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_utf16_DecodeRune"] = tardis.Go_utf16_DecodeRune;
$hxExpose(tardis.Go_utf16_DecodeRune, "Go_utf16_DecodeRune");
tardis.Go_utf16_DecodeRune.__name__ = ["tardis","Go_utf16_DecodeRune"];
tardis.Go_utf16_DecodeRune.__interfaces__ = [tardis.StackFrame];
tardis.Go_utf16_DecodeRune.callFromHaxe = function(p_r1,p_r2) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_utf16_DecodeRune(0,[],p_r1,p_r2).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_utf16_DecodeRune.callFromRT = function(_gr,p_r1,p_r2) {
	var _sf = new tardis.Go_utf16_DecodeRune(_gr,[],p_r1,p_r2).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_utf16_DecodeRune.call = function(gr,_bds,p_r1,p_r2) {
	return new tardis.Go_utf16_DecodeRune(gr,_bds,p_r1,p_r2);
}
tardis.Go_utf16_DecodeRune.__super__ = tardis.StackFrameBasis;
tardis.Go_utf16_DecodeRune.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn4: function() {
		var _t8;
		_t8 = this.p_r1 < 56320;
		this._Next = _t8?4:2;
	}
	,SubFn3: function() {
		var _t7;
		_t7 = 56320 <= this.p_r2;
		this._Next = _t7?3:2;
	}
	,SubFn2: function() {
		var _t6;
		this._latestPH = 480;
		_t6 = this.p_r2 < 57344;
		this._Next = _t6?1:2;
	}
	,SubFn1: function() {
		var _t1;
		var _t2;
		var _t3;
		var _t4;
		this._latestPH = 481;
		_t1 = tardis.Force.toInt32(this.p_r1 - 55296);
		_t2 = _t1 << tardis.Int64.getLow(new tardis.Int64(0,10));
		_t3 = tardis.Force.toInt32(this.p_r2 - 56320);
		_t4 = tardis.Force.toInt32(_t2 | _t3);
		this._t5 = tardis.Force.toInt32(_t4 + 65536);
	}
	,SubFn0: function() {
		var _t0;
		this._latestPH = 480;
		_t0 = 55296 <= this.p_r1;
		this._Next = _t0?5:2;
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 479;
				this._latestBlock = 0;
				this.SubFn0();
				break;
			case 1:
				this._latestPH = 479;
				this._latestBlock = 1;
				this.SubFn1();
				this._latestPH = 481;
				this._res = this._t5;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 2:
				this._latestPH = 481;
				this._latestBlock = 2;
				this._latestPH = 483;
				this._res = 65533;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			case 3:
				this._latestPH = 483;
				this._latestBlock = 3;
				this.SubFn2();
				break;
			case 4:
				this._latestPH = 483;
				this._latestBlock = 4;
				this.SubFn3();
				break;
			case 5:
				this._latestPH = 483;
				this._latestBlock = 5;
				this.SubFn4();
				break;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_utf16_DecodeRune
});
tardis.Go_haxegoruntime_M3 = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,218,"Go_haxegoruntime_M3");
	this._bds = _bds;
	this.p_rx = p_rx;
	this.p_typ = p_typ;
	this.p_meth = p_meth;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_M3"] = tardis.Go_haxegoruntime_M3;
$hxExpose(tardis.Go_haxegoruntime_M3, "Go_haxegoruntime_M3");
tardis.Go_haxegoruntime_M3.__name__ = ["tardis","Go_haxegoruntime_M3"];
tardis.Go_haxegoruntime_M3.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_M3.callFromHaxe = function(p_rx,p_typ,p_meth,p_a1,p_a2,p_a3) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_M3(0,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_M3.callFromRT = function(_gr,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3) {
	var _sf = new tardis.Go_haxegoruntime_M3(_gr,[],p_rx,p_typ,p_meth,p_a1,p_a2,p_a3).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_M3.call = function(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3) {
	return new tardis.Go_haxegoruntime_M3(gr,_bds,p_rx,p_typ,p_meth,p_a1,p_a2,p_a3);
}
tardis.Go_haxegoruntime_M3.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_M3.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_meth);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 218;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_meth);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_M3
});
tardis._Go.Go_haxegoruntime_funcentry_go = function(gr,_bds,p_arg0) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,423,"Go_haxegoruntime_funcentry_go");
	this._bds = _bds;
	this.p_arg0 = p_arg0;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis._Go.Go_haxegoruntime_funcentry_go"] = tardis._Go.Go_haxegoruntime_funcentry_go;
tardis._Go.Go_haxegoruntime_funcentry_go.__name__ = ["tardis","_Go","Go_haxegoruntime_funcentry_go"];
tardis._Go.Go_haxegoruntime_funcentry_go.__interfaces__ = [tardis.StackFrame];
tardis._Go.Go_haxegoruntime_funcentry_go.callFromHaxe = function(p_arg0) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis._Go.Go_haxegoruntime_funcentry_go(0,[],p_arg0).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcentry_go.callFromRT = function(_gr,p_arg0) {
	var _sf = new tardis._Go.Go_haxegoruntime_funcentry_go(_gr,[],p_arg0).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis._Go.Go_haxegoruntime_funcentry_go.call = function(gr,_bds,p_arg0) {
	return new tardis._Go.Go_haxegoruntime_funcentry_go(gr,_bds,p_arg0);
}
tardis._Go.Go_haxegoruntime_funcentry_go.__super__ = tardis.StackFrameBasis;
tardis._Go.Go_haxegoruntime_funcentry_go.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.funcentry_go() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 423;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.funcentry_go() not yet implemented");
				this._latestPH = 424;
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 424;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis._Go.Go_haxegoruntime_funcentry_go
});
tardis.Go_haxegoruntime_C6 = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,210,"Go_haxegoruntime_C6");
	this._bds = _bds;
	this.p_funcName = p_funcName;
	this.p_a1 = p_a1;
	this.p_a2 = p_a2;
	this.p_a3 = p_a3;
	this.p_a4 = p_a4;
	this.p_a5 = p_a5;
	this.p_a6 = p_a6;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_C6"] = tardis.Go_haxegoruntime_C6;
$hxExpose(tardis.Go_haxegoruntime_C6, "Go_haxegoruntime_C6");
tardis.Go_haxegoruntime_C6.__name__ = ["tardis","Go_haxegoruntime_C6"];
tardis.Go_haxegoruntime_C6.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_C6.callFromHaxe = function(p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_C6(0,[],p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_C6.callFromRT = function(_gr,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	var _sf = new tardis.Go_haxegoruntime_C6(_gr,[],p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_C6.call = function(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6) {
	return new tardis.Go_haxegoruntime_C6(gr,_bds,p_funcName,p_a1,p_a2,p_a3,p_a4,p_a5,p_a6);
}
tardis.Go_haxegoruntime_C6.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_C6.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,this.p_funcName);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 210;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,this.p_funcName);
				this._res = this._t0;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_C6
});
tardis.Go_haxegoruntime_FuncForPC = function(gr,_bds,p_pc) {
	this._Next = 0;
	this._t0 = null;
	tardis.StackFrameBasis.call(this,gr,411,"Go_haxegoruntime_FuncForPC");
	this._bds = _bds;
	this.p_pc = p_pc;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_haxegoruntime_FuncForPC"] = tardis.Go_haxegoruntime_FuncForPC;
$hxExpose(tardis.Go_haxegoruntime_FuncForPC, "Go_haxegoruntime_FuncForPC");
tardis.Go_haxegoruntime_FuncForPC.__name__ = ["tardis","Go_haxegoruntime_FuncForPC"];
tardis.Go_haxegoruntime_FuncForPC.__interfaces__ = [tardis.StackFrame];
tardis.Go_haxegoruntime_FuncForPC.callFromHaxe = function(p_pc) {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_haxegoruntime_FuncForPC(0,[],p_pc).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	return _sf._res;
}
tardis.Go_haxegoruntime_FuncForPC.callFromRT = function(_gr,p_pc) {
	var _sf = new tardis.Go_haxegoruntime_FuncForPC(_gr,[],p_pc).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
	return _sf._res;
}
tardis.Go_haxegoruntime_FuncForPC.call = function(gr,_bds,p_pc) {
	return new tardis.Go_haxegoruntime_FuncForPC(gr,_bds,p_pc);
}
tardis.Go_haxegoruntime_FuncForPC.__super__ = tardis.StackFrameBasis;
tardis.Go_haxegoruntime_FuncForPC.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._t0 = new tardis.Interface(0,"runtime.FuncForPC() not yet implemented");
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 411;
				this._latestBlock = 0;
				this._t0 = new tardis.Interface(0,"runtime.FuncForPC() not yet implemented");
				tardis.Scheduler.panic(this._goroutine,this._t0);
				this._Next = -1;
				return this;
			case -1:
				this._latestPH = 411;
				this._latestBlock = -1;
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return this._res;
	}
	,__class__: tardis.Go_haxegoruntime_FuncForPC
});
tardis.Go_main_MouseGoroutine = function(gr,_bds) {
	this._Next = 0;
	tardis.StackFrameBasis.call(this,gr,23,"Go_main_MouseGoroutine");
	this._bds = _bds;
	tardis.Scheduler.push(gr,this);
};
$hxClasses["tardis.Go_main_MouseGoroutine"] = tardis.Go_main_MouseGoroutine;
$hxExpose(tardis.Go_main_MouseGoroutine, "Go_main_MouseGoroutine");
tardis.Go_main_MouseGoroutine.__name__ = ["tardis","Go_main_MouseGoroutine"];
tardis.Go_main_MouseGoroutine.__interfaces__ = [tardis.StackFrame];
tardis.Go_main_MouseGoroutine.callFromHaxe = function() {
	if(!tardis.Go.doneInit) tardis.Go.init();
	var _sf = new tardis.Go_main_MouseGoroutine(0,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
}
tardis.Go_main_MouseGoroutine.callFromRT = function(_gr) {
	var _sf = new tardis.Go_main_MouseGoroutine(_gr,[]).run();
	while(_sf._incomplete) if(tardis.Scheduler.grStacks[_gr].first() == null) throw "Panic:" + Std.string(tardis.Scheduler.grPanicMsg) + "\nScheduler: null stack entry for goroutine " + _gr + "\n" + tardis.Scheduler.stackDump(); else {
		tardis.Scheduler.currentGR = _gr;
		tardis.Scheduler.grStacks[_gr].first().run();
	}
}
tardis.Go_main_MouseGoroutine.call = function(gr,_bds) {
	return new tardis.Go_main_MouseGoroutine(gr,_bds);
}
tardis.Go_main_MouseGoroutine.__super__ = tardis.StackFrameBasis;
tardis.Go_main_MouseGoroutine.prototype = $extend(tardis.StackFrameBasis.prototype,{
	SubFn0: function() {
		this._latestPH = 24;
		new tardis._Go.Go_main_handleMouse(tardis.Scheduler.makeGoroutine(),[]);
	}
	,run: function() {
		while(true) {
			var _g = this;
			switch(_g._Next) {
			case 0:
				this._latestPH = 23;
				this._latestBlock = 0;
				this._latestPH = 24;
				new tardis._Go.Go_main_handleMouse(tardis.Scheduler.makeGoroutine(),[]);
				this._incomplete = false;
				tardis.Scheduler.pop(this._goroutine);
				return this;
			default:
				tardis.Scheduler.bbi();
			}
		}
	}
	,res: function() {
		return null;
	}
	,__class__: tardis.Go_main_MouseGoroutine
});
tardis.Go = function() { }
$hxClasses["tardis.Go"] = tardis.Go;
$hxExpose(tardis.Go, "Go");
tardis.Go.__name__ = ["tardis","Go"];
tardis.Go.Platform = function() {
	return "js";
}
tardis.Go.init = function() {
	tardis.Go.doneInit = true;
	var gr = tardis.Scheduler.makeGoroutine();
	if(gr != 0) throw "non-zero goroutine number in init";
	var _sfgr = new tardis._Go.Go_haxegoruntime_init(gr,[]).run();
	while(_sfgr._incomplete) tardis.Scheduler.runAll();
	var _sf = new tardis._Go.Go_main_init(gr,[]).run();
	while(_sf._incomplete) tardis.Scheduler.runAll();
	tardis.Scheduler.doneInit = true;
}
tardis.Go.main = function() {
	tardis._Go.Go_main_main.callFromHaxe();
}
tardis.Go.CPos = function(pos) {
	var prefix = "";
	if(pos == 0) return "(pogo.NoPosHash)";
	if(pos < 0) {
		pos = -pos;
		prefix = "near ";
	}
	if(pos > 993) return prefix + "/Users/elliott/go/src/github.com/elliott5/gohaxelib/hxutil/hxutil.go:" + Std.string(pos - 993); else if(pos > 550) return prefix + "/usr/local/go/src/pkg/unicode/utf8/utf8.go:" + Std.string(pos - 550); else if(pos > 442) return prefix + "/usr/local/go/src/pkg/unicode/utf16/utf16.go:" + Std.string(pos - 442); else if(pos > 62) return prefix + "goruntime.go:" + Std.string(pos - 62); else if(pos > 0) return prefix + "main.go:" + Std.string(pos); else return "(invalid pogo.PosHash:" + Std.string(pos) + ")";
}
tardis.TypeInfo = function() { }
$hxClasses["tardis.TypeInfo"] = tardis.TypeInfo;
tardis.TypeInfo.__name__ = ["tardis","TypeInfo"];
tardis.TypeInfo.getName = function(id) {
	switch(id) {
	case 0:
		return "string";
	default:
		return "UNKNOWN";
	}
}
tardis.TypeInfo.typeString = function(i) {
	return tardis.TypeInfo.getName(i.typ);
}
tardis.TypeInfo.getId = function(name) {
	switch(name) {
	case "string":
		return 0;
	default:
		return -1;
	}
}
tardis.TypeInfo.isAssignableTo = function(v,t) {
	if(v == t) return true;
	switch(v) {
	case 0:
		return false;
	default:
		return false;
	}
}
tardis.TypeInfo.isIdentical = function(v,t) {
	if(v == t) return true;
	switch(v) {
	case 0:
		return false;
	default:
		return false;
	}
}
tardis.TypeInfo.isConcrete = function(t) {
	switch(t) {
	case 0:
		return true;
	default:
		return false;
	}
}
tardis.TypeInfo.zeroValue = function(t) {
	switch(t) {
	case 0:
		return "";
	default:
		return null;
	}
}
tardis.TypeInfo.method = function(t,m) {
	tardis.Scheduler.panicFromHaxe("no method found!");
	return null;
}
function $iterator(o) { if( o instanceof Array ) return function() { return HxOverrides.iter(o); }; return typeof(o.iterator) == 'function' ? $bind(o,o.iterator) : o.iterator; };
var $_, $fid = 0;
function $bind(o,m) { if( m == null ) return null; if( m.__id__ == null ) m.__id__ = $fid++; var f; if( o.hx__closures__ == null ) o.hx__closures__ = {}; else f = o.hx__closures__[m.__id__]; if( f == null ) { f = function(){ return f.method.apply(f.scope, arguments); }; f.scope = o; f.method = m; o.hx__closures__[m.__id__] = f; } return f; };
if(Array.prototype.indexOf) HxOverrides.remove = function(a,o) {
	var i = a.indexOf(o);
	if(i == -1) return false;
	a.splice(i,1);
	return true;
};
Math.__name__ = ["Math"];
Math.NaN = Number.NaN;
Math.NEGATIVE_INFINITY = Number.NEGATIVE_INFINITY;
Math.POSITIVE_INFINITY = Number.POSITIVE_INFINITY;
$hxClasses.Math = Math;
Math.isFinite = function(i) {
	return isFinite(i);
};
Math.isNaN = function(i) {
	return isNaN(i);
};
String.prototype.__class__ = $hxClasses.String = String;
String.__name__ = ["String"];
Array.prototype.__class__ = $hxClasses.Array = Array;
Array.__name__ = ["Array"];
Date.prototype.__class__ = $hxClasses.Date = Date;
Date.__name__ = ["Date"];
var Int = $hxClasses.Int = { __name__ : ["Int"]};
var Dynamic = $hxClasses.Dynamic = { __name__ : ["Dynamic"]};
var Float = $hxClasses.Float = Number;
Float.__name__ = ["Float"];
var Bool = $hxClasses.Bool = Boolean;
Bool.__ename__ = ["Bool"];
var Class = $hxClasses.Class = { __name__ : ["Class"]};
var Enum = { };
haxe.Resource.content = [];
flash.display.DisplayObject.GRAPHICS_INVALID = 2;
flash.display.DisplayObject.MATRIX_INVALID = 4;
flash.display.DisplayObject.MATRIX_CHAIN_INVALID = 8;
flash.display.DisplayObject.MATRIX_OVERRIDDEN = 16;
flash.display.DisplayObject.TRANSFORM_INVALID = 32;
flash.display.DisplayObject.BOUNDS_INVALID = 64;
flash.display.DisplayObject.RENDER_VALIDATE_IN_PROGRESS = 1024;
flash.display.DisplayObject.ALL_RENDER_FLAGS = 98;
DefaultAssetLibrary.className = new haxe.ds.StringMap();
DefaultAssetLibrary.path = new haxe.ds.StringMap();
DefaultAssetLibrary.type = new haxe.ds.StringMap();
flash.Lib.HTML_ACCELEROMETER_EVENT_TYPE = "devicemotion";
flash.Lib.HTML_ORIENTATION_EVENT_TYPE = "orientationchange";
flash.Lib.DEFAULT_HEIGHT = 500;
flash.Lib.DEFAULT_WIDTH = 500;
flash.Lib.HTML_DIV_EVENT_TYPES = ["resize","mouseover","mouseout","mousewheel","dblclick","click"];
flash.Lib.HTML_TOUCH_EVENT_TYPES = ["touchstart","touchmove","touchend"];
flash.Lib.HTML_TOUCH_ALT_EVENT_TYPES = ["mousedown","mousemove","mouseup"];
flash.Lib.HTML_WINDOW_EVENT_TYPES = ["keyup","keypress","keydown","resize","blur","focus"];
flash.Lib.NME_IDENTIFIER = "haxe:openfl";
flash.Lib.VENDOR_HTML_TAG = "data-";
flash.Lib.starttime = haxe.Timer.stamp();
flash.display._BitmapData.MinstdGenerator.a = 16807;
flash.display._BitmapData.MinstdGenerator.m = -2147483648 - 1;
flash.display.BitmapDataChannel.ALPHA = 8;
flash.display.BitmapDataChannel.BLUE = 4;
flash.display.BitmapDataChannel.GREEN = 2;
flash.display.BitmapDataChannel.RED = 1;
flash.display.Graphics.TILE_SCALE = 1;
flash.display.Graphics.TILE_ROTATION = 2;
flash.display.Graphics.TILE_RGB = 4;
flash.display.Graphics.TILE_ALPHA = 8;
flash.display.Graphics.TILE_TRANS_2x2 = 16;
flash.display.Graphics.TILE_BLEND_NORMAL = 0;
flash.display.Graphics.TILE_BLEND_ADD = 65536;
flash.display.Graphics.BMP_REPEAT = 16;
flash.display.Graphics.BMP_SMOOTH = 65536;
flash.display.Graphics.CORNER_ROUND = 0;
flash.display.Graphics.CORNER_MITER = 4096;
flash.display.Graphics.CORNER_BEVEL = 8192;
flash.display.Graphics.CURVE = 2;
flash.display.Graphics.END_NONE = 0;
flash.display.Graphics.END_ROUND = 256;
flash.display.Graphics.END_SQUARE = 512;
flash.display.Graphics.LINE = 1;
flash.display.Graphics.MOVE = 0;
flash.display.Graphics.__MAX_DIM = 5000;
flash.display.Graphics.PIXEL_HINTING = 16384;
flash.display.Graphics.RADIAL = 1;
flash.display.Graphics.SCALE_HORIZONTAL = 2;
flash.display.Graphics.SCALE_NONE = 0;
flash.display.Graphics.SCALE_NORMAL = 3;
flash.display.Graphics.SCALE_VERTICAL = 1;
flash.display.Graphics.SPREAD_REPEAT = 2;
flash.display.Graphics.SPREAD_REFLECT = 4;
flash.display.GraphicsPathCommand.LINE_TO = 2;
flash.display.GraphicsPathCommand.MOVE_TO = 1;
flash.display.GraphicsPathCommand.CURVE_TO = 3;
flash.display.GraphicsPathCommand.WIDE_LINE_TO = 5;
flash.display.GraphicsPathCommand.WIDE_MOVE_TO = 4;
flash.display.GraphicsPathCommand.NO_OP = 0;
flash.display.GraphicsPathCommand.CUBIC_CURVE_TO = 6;
flash.events.Event.ACTIVATE = "activate";
flash.events.Event.ADDED = "added";
flash.events.Event.ADDED_TO_STAGE = "addedToStage";
flash.events.Event.CANCEL = "cancel";
flash.events.Event.CHANGE = "change";
flash.events.Event.CLOSE = "close";
flash.events.Event.COMPLETE = "complete";
flash.events.Event.CONNECT = "connect";
flash.events.Event.CONTEXT3D_CREATE = "context3DCreate";
flash.events.Event.DEACTIVATE = "deactivate";
flash.events.Event.ENTER_FRAME = "enterFrame";
flash.events.Event.ID3 = "id3";
flash.events.Event.INIT = "init";
flash.events.Event.MOUSE_LEAVE = "mouseLeave";
flash.events.Event.OPEN = "open";
flash.events.Event.REMOVED = "removed";
flash.events.Event.REMOVED_FROM_STAGE = "removedFromStage";
flash.events.Event.RENDER = "render";
flash.events.Event.RESIZE = "resize";
flash.events.Event.SCROLL = "scroll";
flash.events.Event.SELECT = "select";
flash.events.Event.TAB_CHILDREN_CHANGE = "tabChildrenChange";
flash.events.Event.TAB_ENABLED_CHANGE = "tabEnabledChange";
flash.events.Event.TAB_INDEX_CHANGE = "tabIndexChange";
flash.events.Event.UNLOAD = "unload";
flash.events.Event.SOUND_COMPLETE = "soundComplete";
flash.events.MouseEvent.CLICK = "click";
flash.events.MouseEvent.DOUBLE_CLICK = "doubleClick";
flash.events.MouseEvent.MOUSE_DOWN = "mouseDown";
flash.events.MouseEvent.MOUSE_MOVE = "mouseMove";
flash.events.MouseEvent.MOUSE_OUT = "mouseOut";
flash.events.MouseEvent.MOUSE_OVER = "mouseOver";
flash.events.MouseEvent.MOUSE_UP = "mouseUp";
flash.events.MouseEvent.MOUSE_WHEEL = "mouseWheel";
flash.events.MouseEvent.RIGHT_CLICK = "rightClick";
flash.events.MouseEvent.RIGHT_MOUSE_DOWN = "rightMouseDown";
flash.events.MouseEvent.RIGHT_MOUSE_UP = "rightMouseUp";
flash.events.MouseEvent.ROLL_OUT = "rollOut";
flash.events.MouseEvent.ROLL_OVER = "rollOver";
flash.display.Stage.NAME = "Stage";
flash.display.Stage.OrientationPortrait = 1;
flash.display.Stage.OrientationPortraitUpsideDown = 2;
flash.display.Stage.OrientationLandscapeRight = 3;
flash.display.Stage.OrientationLandscapeLeft = 4;
flash.display.Stage.__acceleration = { x : 0.0, y : 1.0, z : 0.0};
flash.display.Stage.DEFAULT_FRAMERATE = 0.0;
flash.display.Stage.UI_EVENTS_QUEUE_MAX = 1000;
flash.display.Stage.__mouseChanges = [flash.events.MouseEvent.MOUSE_OUT,flash.events.MouseEvent.MOUSE_OVER,flash.events.MouseEvent.ROLL_OUT,flash.events.MouseEvent.ROLL_OVER];
flash.display.Stage.__touchChanges = ["touchOut","touchOver","touchRollOut","touchRollOver"];
flash.display.StageQuality.BEST = "best";
flash.display.StageQuality.HIGH = "high";
flash.display.StageQuality.MEDIUM = "medium";
flash.display.StageQuality.LOW = "low";
flash.errors.Error.DEFAULT_TO_STRING = "Error";
flash.events.TextEvent.LINK = "link";
flash.events.TextEvent.TEXT_INPUT = "textInput";
flash.events.ErrorEvent.ERROR = "error";
flash.events.Listener.sIDs = 1;
flash.events.EventPhase.CAPTURING_PHASE = 0;
flash.events.EventPhase.AT_TARGET = 1;
flash.events.EventPhase.BUBBLING_PHASE = 2;
flash.events.FocusEvent.FOCUS_IN = "focusIn";
flash.events.FocusEvent.FOCUS_OUT = "focusOut";
flash.events.FocusEvent.KEY_FOCUS_CHANGE = "keyFocusChange";
flash.events.FocusEvent.MOUSE_FOCUS_CHANGE = "mouseFocusChange";
flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS = "httpResponseStatus";
flash.events.HTTPStatusEvent.HTTP_STATUS = "httpStatus";
flash.events.IOErrorEvent.IO_ERROR = "ioError";
flash.events.KeyboardEvent.KEY_DOWN = "keyDown";
flash.events.KeyboardEvent.KEY_UP = "keyUp";
flash.events.ProgressEvent.PROGRESS = "progress";
flash.events.ProgressEvent.SOCKET_DATA = "socketData";
flash.events.SecurityErrorEvent.SECURITY_ERROR = "securityError";
flash.events.TimerEvent.TIMER = "timer";
flash.events.TimerEvent.TIMER_COMPLETE = "timerComplete";
flash.events.TouchEvent.TOUCH_BEGIN = "touchBegin";
flash.events.TouchEvent.TOUCH_END = "touchEnd";
flash.events.TouchEvent.TOUCH_MOVE = "touchMove";
flash.events.TouchEvent.TOUCH_OUT = "touchOut";
flash.events.TouchEvent.TOUCH_OVER = "touchOver";
flash.events.TouchEvent.TOUCH_ROLL_OUT = "touchRollOut";
flash.events.TouchEvent.TOUCH_ROLL_OVER = "touchRollOver";
flash.events.TouchEvent.TOUCH_TAP = "touchTap";
flash.filters.DropShadowFilter.DEGREES_FULL_RADIUS = 360.0;
flash.geom.Transform.DEG_TO_RAD = Math.PI / 180.0;
flash.media.Sound.EXTENSION_MP3 = "mp3";
flash.media.Sound.EXTENSION_OGG = "ogg";
flash.media.Sound.EXTENSION_WAV = "wav";
flash.media.Sound.EXTENSION_AAC = "aac";
flash.media.Sound.MEDIA_TYPE_MP3 = "audio/mpeg";
flash.media.Sound.MEDIA_TYPE_OGG = "audio/ogg; codecs=\"vorbis\"";
flash.media.Sound.MEDIA_TYPE_WAV = "audio/wav; codecs=\"1\"";
flash.media.Sound.MEDIA_TYPE_AAC = "audio/mp4; codecs=\"mp4a.40.2\"";
flash.net.URLRequestMethod.DELETE = "DELETE";
flash.net.URLRequestMethod.GET = "GET";
flash.net.URLRequestMethod.HEAD = "HEAD";
flash.net.URLRequestMethod.OPTIONS = "OPTIONS";
flash.net.URLRequestMethod.POST = "POST";
flash.net.URLRequestMethod.PUT = "PUT";
flash.system.ApplicationDomain.currentDomain = new flash.system.ApplicationDomain(null);
flash.system.SecurityDomain.currentDomain = new flash.system.SecurityDomain();
flash.text.Font.DEFAULT_FONT_DATA = "q:55oy6:ascentd950.5y4:dataad84d277.5d564d277.5d564d320.5d293d1024d187.5d1024d442.5d362.5d84d362.5d84d277.5hy6:_widthd651.5y4:xMaxd564y4:xMind84y4:yMaxd746.5y4:yMind0y7:_heightd662.5y7:leadingd168y7:descentd241.5y8:charCodei55y15:leftsideBearingd84y12:advanceWidthd651.5y8:commandsai1i2i2i2i2i2i2i2hg:111oR0d950.5R1ad313.5d528.5d239.5d528.5d196.5d586.25d153.5d644d153.5d744.5d153.5d845d196.25d902.75d239d960.5d313.5d960.5d387d960.5d430d902.5d473d844.5d473d744.5d473d645d430d586.75d387d528.5d313.5d528.5d313.5d450.5d433.5d450.5d502d528.5d570.5d606.5d570.5d744.5d570.5d882d502d960.25d433.5d1038.5d313.5d1038.5d193d1038.5d124.75d960.25d56.5d882d56.5d744.5d56.5d606.5d124.75d528.5d193d450.5d313.5d450.5hR2d626.5R3d570.5R4d56.5R5d573.5R6d-14.5R7d517R8d168R9d241.5R10i111R11d56.5R12d626.5R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:54oR0d950.5R1ad338d610.5d270d610.5d230.25d657d190.5d703.5d190.5d784.5d190.5d865d230.25d911.75d270d958.5d338d958.5d406d958.5d445.75d911.75d485.5d865d485.5d784.5d485.5d703.5d445.75d657d406d610.5d338d610.5d538.5d294d538.5d386d500.5d368d461.75d358.5d423d349d385d349d285d349d232.25d416.5d179.5d484d172d620.5d201.5d577d246d553.75d290.5d530.5d344d530.5d456.5d530.5d521.75d598.75d587d667d587d784.5d587d899.5d519d969d451d1038.5d338d1038.5d208.5d1038.5d140d939.25d71.5d840d71.5d651.5d71.5d474.5d155.5d369.25d239.5d264d381d264d419d264d457.75d271.5d496.5d279d538.5d294hR2d651.5R3d587R4d71.5R5d760R6d-14.5R7d688.5R8d168R9d241.5R10i54R11d71.5R12d651.5R13ai1i3i3i3i3i3i3i3i3i1i2i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3hg:110oR0d950.5R1ad562d686d562d1024d470d1024d470d689d470d609.5d439d570d408d530.5d346d530.5d271.5d530.5d228.5d578d185.5d625.5d185.5d707.5d185.5d1024d93d1024d93d464d185.5d464d185.5d551d218.5d500.5d263.25d475.5d308d450.5d366.5d450.5d463d450.5d512.5d510.25d562d570d562d686hR2d649R3d562R4d93R5d573.5R6d0R7d480.5R8d168R9d241.5R10i110R11d93R12d649R13ai1i2i2i2i3i3i3i3i2i2i2i2i2i3i3i3i3hg:53oR0d950.5R1ad110.5d277.5d507d277.5d507d362.5d203d362.5d203d545.5d225d538d247d534.25d269d530.5d291d530.5d416d530.5d489d599d562d667.5d562d784.5d562d905d487d971.75d412d1038.5d275.5d1038.5d228.5d1038.5d179.75d1030.5d131d1022.5d79d1006.5d79d905d124d929.5d172d941.5d220d953.5d273.5d953.5d360d953.5d410.5d908d461d862.5d461d784.5d461d706.5d410.5d661d360d615.5d273.5d615.5d233d615.5d192.75d624.5d152.5d633.5d110.5d652.5d110.5d277.5hR2d651.5R3d562R4d79R5d746.5R6d-14.5R7d667.5R8d168R9d241.5R10i53R11d79R12d651.5R13ai1i2i2i2i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3i2hg:109oR0d950.5R1ad532.5d571.5d567d509.5d615d480d663d450.5d728d450.5d815.5d450.5d863d511.75d910.5d573d910.5d686d910.5d1024d818d1024d818d689d818d608.5d789.5d569.5d761d530.5d702.5d530.5d631d530.5d589.5d578d548d625.5d548d707.5d548d1024d455.5d1024d455.5d689d455.5d608d427d569.25d398.5d530.5d339d530.5d268.5d530.5d227d578.25d185.5d626d185.5d707.5d185.5d1024d93d1024d93d464d185.5d464d185.5d551d217d499.5d261d475d305d450.5d365.5d450.5d426.5d450.5d469.25d481.5d512d512.5d532.5d571.5hR2d997.5R3d910.5R4d93R5d573.5R6d0R7d480.5R8d168R9d241.5R10i109R11d93R12d997.5R13ai1i3i3i3i3i2i2i2i3i3i3i3i2i2i2i3i3i3i3i2i2i2i2i2i3i3i3i3hg:52oR0d950.5R1ad387d365.5d132d764d387d764d387d365.5d360.5d277.5d487.5d277.5d487.5d764d594d764d594d848d487.5d848d487.5d1024d387d1024d387d848d50d848d50d750.5d360.5d277.5hR2d651.5R3d594R4d50R5d746.5R6d0R7d696.5R8d168R9d241.5R10i52R11d50R12d651.5R13ai1i2i2i2i1i2i2i2i2i2i2i2i2i2i2i2hg:108oR0d950.5R1ad96.5d246d188.5d246d188.5d1024d96.5d1024d96.5d246hR2d284.5R3d188.5R4d96.5R5d778R6d0R7d681.5R8d168R9d241.5R10i108R11d96.5R12d284.5R13ai1i2i2i2i2hg:51oR0d950.5R1ad415.5d621.5d488d637d528.75d686d569.5d735d569.5d807d569.5d917.5d493.5d978d417.5d1038.5d277.5d1038.5d230.5d1038.5d180.75d1029.25d131d1020d78d1001.5d78d904d120d928.5d170d941d220d953.5d274.5d953.5d369.5d953.5d419.25d916d469d878.5d469d807d469d741d422.75d703.75d376.5d666.5d294d666.5d207d666.5d207d583.5d298d583.5d372.5d583.5d412d553.75d451.5d524d451.5d468d451.5d410.5d410.75d379.75d370d349d294d349d252.5d349d205d358d157.5d367d100.5d386d100.5d296d158d280d208.25d272d258.5d264d303d264d418d264d485d316.25d552d368.5d552d457.5d552d519.5d516.5d562.25d481d605d415.5d621.5hR2d651.5R3d569.5R4d78R5d760R6d-14.5R7d682R8d168R9d241.5R10i51R11d78R12d651.5R13ai1i3i3i3i3i3i3i2i3i3i3i3i3i3i2i2i2i3i3i3i3i3i3i2i3i3i3i3i3i3hg:107oR0d950.5R1ad93d246d185.5d246d185.5d705.5d460d464d577.5d464d280.5d726d590d1024d470d1024d185.5d750.5d185.5d1024d93d1024d93d246hR2d593R3d590R4d93R5d778R6d0R7d685R8d168R9d241.5R10i107R11d93R12d593R13ai1i2i2i2i2i2i2i2i2i2i2i2hg:50oR0d950.5R1ad196.5d939d549d939d549d1024d75d1024d75d939d132.5d879.5d231.75d779.25d331d679d356.5d650d405d595.5d424.25d557.75d443.5d520d443.5d483.5d443.5d424d401.75d386.5d360d349d293d349d245.5d349d192.75d365.5d140d382d80d415.5d80d313.5d141d289d194d276.5d247d264d291d264d407d264d476d322d545d380d545d477d545d523d527.75d564.25d510.5d605.5d465d661.5d452.5d676d385.5d745.25d318.5d814.5d196.5d939hR2d651.5R3d549R4d75R5d760R6d0R7d685R8d168R9d241.5R10i50R11d75R12d651.5R13ai1i2i2i2i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3hg:106oR0d950.5R1ad96.5d464d188.5d464d188.5d1034d188.5d1141d147.75d1189d107d1237d16.5d1237d-18.5d1237d-18.5d1159d6d1159d58.5d1159d77.5d1134.75d96.5d1110.5d96.5d1034d96.5d464d96.5d246d188.5d246d188.5d362.5d96.5d362.5d96.5d246hR2d284.5R3d188.5R4d-18.5R5d778R6d-213R7d796.5R8d168R9d241.5R10i106R11d-18.5R12d284.5R13ai1i2i2i3i3i2i2i2i3i3i2i1i2i2i2i2hg:49oR0d950.5R1ad127d939d292d939d292d369.5d112.5d405.5d112.5d313.5d291d277.5d392d277.5d392d939d557d939d557d1024d127d1024d127d939hR2d651.5R3d557R4d112.5R5d746.5R6d0R7d634R8d168R9d241.5R10i49R11d112.5R12d651.5R13ai1i2i2i2i2i2i2i2i2i2i2i2hg:105oR0d950.5R1ad96.5d464d188.5d464d188.5d1024d96.5d1024d96.5d464d96.5d246d188.5d246d188.5d362.5d96.5d362.5d96.5d246hR2d284.5R3d188.5R4d96.5R5d778R6d0R7d681.5R8d168R9d241.5R10i105R11d96.5R12d284.5R13ai1i2i2i2i2i1i2i2i2i2hg:48oR0d950.5R1ad325.5d344d247.5d344d208.25d420.75d169d497.5d169d651.5d169d805d208.25d881.75d247.5d958.5d325.5d958.5d404d958.5d443.25d881.75d482.5d805d482.5d651.5d482.5d497.5d443.25d420.75d404d344d325.5d344d325.5d264d451d264d517.25d363.25d583.5d462.5d583.5d651.5d583.5d840d517.25d939.25d451d1038.5d325.5d1038.5d200d1038.5d133.75d939.25d67.5d840d67.5d651.5d67.5d462.5d133.75d363.25d200d264d325.5d264hR2d651.5R3d583.5R4d67.5R5d760R6d-14.5R7d692.5R8d168R9d241.5R10i48R11d67.5R12d651.5R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:104oR0d950.5R1ad562d686d562d1024d470d1024d470d689d470d609.5d439d570d408d530.5d346d530.5d271.5d530.5d228.5d578d185.5d625.5d185.5d707.5d185.5d1024d93d1024d93d246d185.5d246d185.5d551d218.5d500.5d263.25d475.5d308d450.5d366.5d450.5d463d450.5d512.5d510.25d562d570d562d686hR2d649R3d562R4d93R5d778R6d0R7d685R8d168R9d241.5R10i104R11d93R12d649R13ai1i2i2i2i3i3i3i3i2i2i2i2i2i3i3i3i3hg:47oR0d950.5R1ad260d277.5d345d277.5d85d1119d0d1119d260d277.5hR2d345R3d345R4d0R5d746.5R6d-95R7d746.5R8d168R9d241.5R10i47R11d0R12d345R13ai1i2i2i2i2hg:103oR0d950.5R1ad465d737.5d465d637.5d423.75d582.5d382.5d527.5d308d527.5d234d527.5d192.75d582.5d151.5d637.5d151.5d737.5d151.5d837d192.75d892d234d947d308d947d382.5d947d423.75d892d465d837d465d737.5d557d954.5d557d1097.5d493.5d1167.25d430d1237d299d1237d250.5d1237d207.5d1229.75d164.5d1222.5d124d1207.5d124d1118d164.5d1140d204d1150.5d243.5d1161d284.5d1161d375d1161d420d1113.75d465d1066.5d465d971d465d925.5d436.5d975d392d999.5d347.5d1024d285.5d1024d182.5d1024d119.5d945.5d56.5d867d56.5d737.5d56.5d607.5d119.5d529d182.5d450.5d285.5d450.5d347.5d450.5d392d475d436.5d499.5d465d549d465d464d557d464d557d954.5hR2d650R3d557R4d56.5R5d573.5R6d-213R7d517R8d168R9d241.5R10i103R11d56.5R12d650R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i2i3i3i3i3i2i3i3i3i3i3i3i3i3i2i2i2hg:46oR0d950.5R1ad109.5d897d215d897d215d1024d109.5d1024d109.5d897hR2d325.5R3d215R4d109.5R5d127R6d0R7d17.5R8d168R9d241.5R10i46R11d109.5R12d325.5R13ai1i2i2i2i2hg:102oR0d950.5R1ad380d246d380d322.5d292d322.5d242.5d322.5d223.25d342.5d204d362.5d204d414.5d204d464d355.5d464d355.5d535.5d204d535.5d204d1024d111.5d1024d111.5d535.5d23.5d535.5d23.5d464d111.5d464d111.5d425d111.5d331.5d155d288.75d198.5d246d293d246d380d246hR2d360.5R3d380R4d23.5R5d778R6d0R7d754.5R8d168R9d241.5R10i102R11d23.5R12d360.5R13ai1i2i2i3i3i2i2i2i2i2i2i2i2i2i2i2i3i3i2hg:45oR0d950.5R1ad50d702.5d319.5d702.5d319.5d784.5d50d784.5d50d702.5hR2d369.5R3d319.5R4d50R5d321.5R6d239.5R7d271.5R8d168R9d241.5R10i45R11d50R12d369.5R13ai1i2i2i2i2hg:101oR0d950.5R1ad575.5d721d575.5d766d152.5d766d158.5d861d209.75d910.75d261d960.5d352.5d960.5d405.5d960.5d455.25d947.5d505d934.5d554d908.5d554d995.5d504.5d1016.5d452.5d1027.5d400.5d1038.5d347d1038.5d213d1038.5d134.75d960.5d56.5d882.5d56.5d749.5d56.5d612d130.75d531.25d205d450.5d331d450.5d444d450.5d509.75d523.25d575.5d596d575.5d721d483.5d694d482.5d618.5d441.25d573.5d400d528.5d332d528.5d255d528.5d208.75d572d162.5d615.5d155.5d694.5d483.5d694hR2d630R3d575.5R4d56.5R5d573.5R6d-14.5R7d517R8d168R9d241.5R10i101R11d56.5R12d630R13ai1i2i2i3i3i3i3i2i3i3i3i3i3i3i3i3i1i3i3i3i3i2hg:44oR0d950.5R1ad120d897d225.5d897d225.5d983d143.5d1143d79d1143d120d983d120d897hR2d325.5R3d225.5R4d79R5d127R6d-119R7d48R8d168R9d241.5R10i44R11d79R12d325.5R13ai1i2i2i2i2i2i2hg:100oR0d950.5R1ad465d549d465d246d557d246d557d1024d465d1024d465d940d436d990d391.75d1014.25d347.5d1038.5d285.5d1038.5d184d1038.5d120.25d957.5d56.5d876.5d56.5d744.5d56.5d612.5d120.25d531.5d184d450.5d285.5d450.5d347.5d450.5d391.75d474.75d436d499d465d549d151.5d744.5d151.5d846d193.25d903.75d235d961.5d308d961.5d381d961.5d423d903.75d465d846d465d744.5d465d643d423d585.25d381d527.5d308d527.5d235d527.5d193.25d585.25d151.5d643d151.5d744.5hR2d650R3d557R4d56.5R5d778R6d-14.5R7d721.5R8d168R9d241.5R10i100R11d56.5R12d650R13ai1i2i2i2i2i2i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:43oR0d950.5R1ad471d382d471d660.5d749.5d660.5d749.5d745.5d471d745.5d471d1024d387d1024d387d745.5d108.5d745.5d108.5d660.5d387d660.5d387d382d471d382hR2d858R3d749.5R4d108.5R5d642R6d0R7d533.5R8d168R9d241.5R10i43R11d108.5R12d858R13ai1i2i2i2i2i2i2i2i2i2i2i2i2hg:99oR0d950.5R1ad499.5d485.5d499.5d571.5d460.5d550d421.25d539.25d382d528.5d342d528.5d252.5d528.5d203d585.25d153.5d642d153.5d744.5d153.5d847d203d903.75d252.5d960.5d342d960.5d382d960.5d421.25d949.75d460.5d939d499.5d917.5d499.5d1002.5d461d1020.5d419.75d1029.5d378.5d1038.5d332d1038.5d205.5d1038.5d131d959d56.5d879.5d56.5d744.5d56.5d607.5d131.75d529d207d450.5d338d450.5d380.5d450.5d421d459.25d461.5d468d499.5d485.5hR2d563R3d499.5R4d56.5R5d573.5R6d-14.5R7d517R8d168R9d241.5R10i99R11d56.5R12d563R13ai1i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3hg:42oR0d950.5R1ad481.5d400.5d302d497.5d481.5d595d452.5d644d284.5d542.5d284.5d731d227.5d731d227.5d542.5d59.5d644d30.5d595d210d497.5d30.5d400.5d59.5d351d227.5d452.5d227.5d264d284.5d264d284.5d452.5d452.5d351d481.5d400.5hR2d512R3d481.5R4d30.5R5d760R6d293R7d729.5R8d168R9d241.5R10i42R11d30.5R12d512R13ai1i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2hg:98oR0d950.5R1ad498.5d744.5d498.5d643d456.75d585.25d415d527.5d342d527.5d269d527.5d227.25d585.25d185.5d643d185.5d744.5d185.5d846d227.25d903.75d269d961.5d342d961.5d415d961.5d456.75d903.75d498.5d846d498.5d744.5d185.5d549d214.5d499d258.75d474.75d303d450.5d364.5d450.5d466.5d450.5d530.25d531.5d594d612.5d594d744.5d594d876.5d530.25d957.5d466.5d1038.5d364.5d1038.5d303d1038.5d258.75d1014.25d214.5d990d185.5d940d185.5d1024d93d1024d93d246d185.5d246d185.5d549hR2d650R3d594R4d93R5d778R6d-14.5R7d685R8d168R9d241.5R10i98R11d93R12d650R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i2i2i2i2i2hg:41oR0d950.5R1ad82d247d162d247d237d365d274.25d478d311.5d591d311.5d702.5d311.5d814.5d274.25d928d237d1041.5d162d1159d82d1159d148.5d1044.5d181.25d931.25d214d818d214d702.5d214d587d181.25d474.5d148.5d362d82d247hR2d399.5R3d311.5R4d82R5d777R6d-135R7d695R8d168R9d241.5R10i41R11d82R12d399.5R13ai1i2i3i3i3i3i2i3i3i3i3hg:97oR0d950.5R1ad351d742.5d239.5d742.5d196.5d768d153.5d793.5d153.5d855d153.5d904d185.75d932.75d218d961.5d273.5d961.5d350d961.5d396.25d907.25d442.5d853d442.5d763d442.5d742.5d351d742.5d534.5d704.5d534.5d1024d442.5d1024d442.5d939d411d990d364d1014.25d317d1038.5d249d1038.5d163d1038.5d112.25d990.25d61.5d942d61.5d861d61.5d766.5d124.75d718.5d188d670.5d313.5d670.5d442.5d670.5d442.5d661.5d442.5d598d400.75d563.25d359d528.5d283.5d528.5d235.5d528.5d190d540d144.5d551.5d102.5d574.5d102.5d489.5d153d470d200.5d460.25d248d450.5d293d450.5d414.5d450.5d474.5d513.5d534.5d576.5d534.5d704.5hR2d627.5R3d534.5R4d61.5R5d573.5R6d-14.5R7d512R8d168R9d241.5R10i97R11d61.5R12d627.5R13ai1i3i3i3i3i3i3i2i2i1i2i2i2i3i3i3i3i3i3i2i2i3i3i3i3i2i3i3i3i3hg:40oR0d950.5R1ad317.5d247d250.5d362d218d474.5d185.5d587d185.5d702.5d185.5d818d218.25d931.25d251d1044.5d317.5d1159d237.5d1159d162.5d1041.5d125.25d928d88d814.5d88d702.5d88d591d125d478d162d365d237.5d247d317.5d247hR2d399.5R3d317.5R4d88R5d777R6d-135R7d689R8d168R9d241.5R10i40R11d88R12d399.5R13ai1i3i3i3i3i2i3i3i3i3i2hg:96oR0d950.5R1ad183.5d205d324.5d392d248d392d85d205d183.5d205hR2d512R3d324.5R4d85R5d819R6d632R7d734R8d168R9d241.5R10i96R11d85R12d512R13ai1i2i2i2i2hg:39oR0d950.5R1ad183.5d277.5d183.5d555d98.5d555d98.5d277.5d183.5d277.5hR2d281.5R3d183.5R4d98.5R5d746.5R6d469R7d648R8d168R9d241.5R10i39R11d98.5R12d281.5R13ai1i2i2i2i2hg:95oR0d950.5R1ad522d1194d522d1265.5d-10d1265.5d-10d1194d522d1194hR2d512R3d522R4d-10R5d-170R6d-241.5R7d-160R8d168R9d241.5R10i95R11d-10R12d512R13ai1i2i2i2i2hg:38oR0d950.5R1ad249d622.5d203.5d663d182.25d703.25d161d743.5d161d787.5d161d860.5d214d909d267d957.5d347d957.5d394.5d957.5d436d941.75d477.5d926d514d894d249d622.5d319.5d566.5d573.5d826.5d603d782d619.5d731.25d636d680.5d639d623.5d732d623.5d726d689.5d700d754d674d818.5d627.5d881.5d767d1024d641d1024d569.5d950.5d517.5d995d460.5d1016.75d403.5d1038.5d338d1038.5d217.5d1038.5d141d969.75d64.5d901d64.5d793.5d64.5d729.5d98d673.25d131.5d617d198.5d567.5d174.5d536d162d504.75d149.5d473.5d149.5d443.5d149.5d362.5d205d313.25d260.5d264d352.5d264d394d264d435.25d273d476.5d282d519d300d519d391d475.5d367.5d436d355.25d396.5d343d362.5d343d310d343d277.25d370.75d244.5d398.5d244.5d442.5d244.5d468d259.25d493.75d274d519.5d319.5d566.5hR2d798.5R3d767R4d64.5R5d760R6d-14.5R7d695.5R8d168R9d241.5R10i38R11d64.5R12d798.5R13ai1i3i3i3i3i3i3i2i1i2i3i3i2i3i3i2i2i2i3i3i3i3i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3hg:94oR0d950.5R1ad478d277.5d749.5d556d649d556d429d358.5d209d556d108.5d556d380d277.5d478d277.5hR2d858R3d749.5R4d108.5R5d746.5R6d468R7d638R8d168R9d241.5R10i94R11d108.5R12d858R13ai1i2i2i2i2i2i2i2hg:37oR0d950.5R1ad744.5d695.5d701d695.5d676.25d732.5d651.5d769.5d651.5d835.5d651.5d900.5d676.25d937.75d701d975d744.5d975d787d975d811.75d937.75d836.5d900.5d836.5d835.5d836.5d770d811.75d732.75d787d695.5d744.5d695.5d744.5d632d823.5d632d870d687d916.5d742d916.5d835.5d916.5d929d869.75d983.75d823d1038.5d744.5d1038.5d664.5d1038.5d618d983.75d571.5d929d571.5d835.5d571.5d741.5d618.25d686.75d665d632d744.5d632d228.5d327.5d185.5d327.5d160.75d364.75d136d402d136d467d136d533d160.5d570d185d607d228.5d607d272d607d296.75d570d321.5d533d321.5d467d321.5d402.5d296.5d365d271.5d327.5d228.5d327.5d680d264d760d264d293d1038.5d213d1038.5d680d264d228.5d264d307.5d264d354.5d318.75d401.5d373.5d401.5d467d401.5d561.5d354.75d616d308d670.5d228.5d670.5d149d670.5d102.75d615.75d56.5d561d56.5d467d56.5d374d103d319d149.5d264d228.5d264hR2d973R3d916.5R4d56.5R5d760R6d-14.5R7d703.5R8d168R9d241.5R10i37R11d56.5R12d973R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i1i2i2i2i2i1i3i3i3i3i3i3i3i3hg:93oR0d950.5R1ad311.5d246d311.5d1159d99.5d1159d99.5d1087.5d219d1087.5d219d317.5d99.5d317.5d99.5d246d311.5d246hR2d399.5R3d311.5R4d99.5R5d778R6d-135R7d678.5R8d168R9d241.5R10i93R11d99.5R12d399.5R13ai1i2i2i2i2i2i2i2i2hg:36oR0d950.5R1ad346d1174.5d296d1174.5d295.5d1024d243d1023d190.5d1011.75d138d1000.5d85d978d85d888d136d920d188.25d936.25d240.5d952.5d296d953d296d725d185.5d707d135.25d664d85d621d85d546d85d464.5d139.5d417.5d194d370.5d296d363.5d296d246d346d246d346d362d392.5d364d436d371.75d479.5d379.5d521d393d521d480.5d479.5d459.5d435.75d448d392d436.5d346d434.5d346d648d459.5d665.5d513d710.5d566.5d755.5d566.5d833.5d566.5d918d509.75d966.75d453d1015.5d346d1023d346d1174.5d296d639d296d434d238d440.5d207.5d467d177d493.5d177d537.5d177d580.5d205.25d604.5d233.5d628.5d296d639d346d735d346d951.5d409.5d943d441.75d915.5d474d888d474d843d474d799d443.25d773d412.5d747d346d735hR2d651.5R3d566.5R4d85R5d778R6d-150.5R7d693R8d168R9d241.5R10i36R11d85R12d651.5R13ai1i2i2i3i3i2i3i3i2i3i3i3i3i2i2i2i3i3i2i3i3i2i3i3i3i3i2i1i2i3i3i3i3i1i2i3i3i3i3hg:92oR0d950.5R1ad85d277.5d345d1119d260d1119d0d277.5d85d277.5hR2d345R3d345R4d0R5d746.5R6d-95R7d746.5R8d168R9d241.5R10i92R11d0R12d345R13ai1i2i2i2i2hg:35oR0d950.5R1ad523.5d573.5d378d573.5d336d740.5d482.5d740.5d523.5d573.5d448.5d289d396.5d496.5d542.5d496.5d595d289d675d289d623.5d496.5d779.5d496.5d779.5d573.5d604d573.5d563d740.5d722d740.5d722d817d543.5d817d491.5d1024d411.5d1024d463d817d316.5d817d265d1024d184.5d1024d236.5d817d79d817d79d740.5d255d740.5d297d573.5d136d573.5d136d496.5d316.5d496.5d367.5d289d448.5d289hR2d858R3d779.5R4d79R5d735R6d0R7d656R8d168R9d241.5R10i35R11d79R12d858R13ai1i2i2i2i2i1i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2i2hg:91oR0d950.5R1ad88d246d300d246d300d317.5d180d317.5d180d1087.5d300d1087.5d300d1159d88d1159d88d246hR2d399.5R3d300R4d88R5d778R6d-135R7d690R8d168R9d241.5R10i91R11d88R12d399.5R13ai1i2i2i2i2i2i2i2i2hg:34oR0d950.5R1ad183.5d277.5d183.5d555d98.5d555d98.5d277.5d183.5d277.5d372.5d277.5d372.5d555d287.5d555d287.5d277.5d372.5d277.5hR2d471R3d372.5R4d98.5R5d746.5R6d469R7d648R8d168R9d241.5R10i34R11d98.5R12d471R13ai1i2i2i2i2i1i2i2i2i2hg:90oR0d950.5R1ad57.5d277.5d644d277.5d644d354.5d172d939d655.5d939d655.5d1024d46d1024d46d947d518d362.5d57.5d362.5d57.5d277.5hR2d701.5R3d655.5R4d46R5d746.5R6d0R7d700.5R8d168R9d241.5R10i90R11d46R12d701.5R13ai1i2i2i2i2i2i2i2i2i2i2hg:33oR0d950.5R1ad154.5d897d256d897d256d1024d154.5d1024d154.5d897d154.5d277.5d256d277.5d256d605d246d783.5d165d783.5d154.5d605d154.5d277.5hR2d410.5R3d256R4d154.5R5d746.5R6d0R7d592R8d168R9d241.5R10i33R11d154.5R12d410.5R13ai1i2i2i2i2i1i2i2i2i2i2i2hg:89oR0d950.5R1ad-2d277.5d106.5d277.5d313.5d584.5d519d277.5d627.5d277.5d363.5d668.5d363.5d1024d262d1024d262d668.5d-2d277.5hR2d625.5R3d627.5R4d-2R5d746.5R6d0R7d748.5R8d168R9d241.5R10i89R11d-2R12d625.5R13ai1i2i2i2i2i2i2i2i2i2hg:32oR0d950.5R1ahR2d325.5R3d0R4d0R5d0R6d0R7d0R8d168R9d241.5R10i32R11d0R12d325.5R13ahg:88oR0d950.5R1ad64.5d277.5d173d277.5d358.5d555d545d277.5d653.5d277.5d413.5d636d669.5d1024d561d1024d351d706.5d139.5d1024d30.5d1024d297d625.5d64.5d277.5hR2d701.5R3d669.5R4d30.5R5d746.5R6d0R7d716R8d168R9d241.5R10i88R11d30.5R12d701.5R13ai1i2i2i2i2i2i2i2i2i2i2i2i2hg:87oR0d950.5R1ad34d277.5d136d277.5d293d908.5d449.5d277.5d563d277.5d720d908.5d876.5d277.5d979d277.5d791.5d1024d664.5d1024d507d376d348d1024d221d1024d34d277.5hR2d1012.5R3d979R4d34R5d746.5R6d0R7d712.5R8d168R9d241.5R10i87R11d34R12d1012.5R13ai1i2i2i2i2i2i2i2i2i2i2i2i2i2hg:86oR0d950.5R1ad293d1024d8d277.5d113.5d277.5d350d906d587d277.5d692d277.5d407.5d1024d293d1024hR2d700.5R3d692R4d8R5d746.5R6d0R7d738.5R8d168R9d241.5R10i86R11d8R12d700.5R13ai1i2i2i2i2i2i2i2hg:85oR0d950.5R1ad89d277.5d190.5d277.5d190.5d731d190.5d851d234d903.75d277.5d956.5d375d956.5d472d956.5d515.5d903.75d559d851d559d731d559d277.5d660.5d277.5d660.5d743.5d660.5d889.5d588.25d964d516d1038.5d375d1038.5d233.5d1038.5d161.25d964d89d889.5d89d743.5d89d277.5hR2d749.5R3d660.5R4d89R5d746.5R6d-14.5R7d657.5R8d168R9d241.5R10i85R11d89R12d749.5R13ai1i2i2i3i3i3i3i2i2i2i3i3i3i3i2hg:84oR0d950.5R1ad-3d277.5d628.5d277.5d628.5d362.5d363.5d362.5d363.5d1024d262d1024d262d362.5d-3d362.5d-3d277.5hR2d625.5R3d628.5R4d-3R5d746.5R6d0R7d749.5R8d168R9d241.5R10i84R11d-3R12d625.5R13ai1i2i2i2i2i2i2i2i2hg:83oR0d950.5R1ad548d302d548d400.5d490.5d373d439.5d359.5d388.5d346d341d346d258.5d346d213.75d378d169d410d169d469d169d518.5d198.75d543.75d228.5d569d311.5d584.5d372.5d597d485.5d618.5d539.25d672.75d593d727d593d818d593d926.5d520.25d982.5d447.5d1038.5d307d1038.5d254d1038.5d194.25d1026.5d134.5d1014.5d70.5d991d70.5d887d132d921.5d191d939d250d956.5d307d956.5d393.5d956.5d440.5d922.5d487.5d888.5d487.5d825.5d487.5d770.5d453.75d739.5d420d708.5d343d693d281.5d681d168.5d658.5d118d610.5d67.5d562.5d67.5d477d67.5d378d137.25d321d207d264d329.5d264d382d264d436.5d273.5d491d283d548d302hR2d650R3d593R4d67.5R5d760R6d-14.5R7d692.5R8d168R9d241.5R10i83R11d67.5R12d650R13ai1i2i3i3i3i3i3i3i2i3i3i3i3i3i3i2i3i3i3i3i3i3i2i3i3i3i3i3i3hg:82oR0d950.5R1ad454.5d674d487d685d517.75d721d548.5d757d579.5d820d682d1024d573.5d1024d478d832.5d441d757.5d406.25d733d371.5d708.5d311.5d708.5d201.5d708.5d201.5d1024d100.5d1024d100.5d277.5d328.5d277.5d456.5d277.5d519.5d331d582.5d384.5d582.5d492.5d582.5d563d549.75d609.5d517d656d454.5d674d201.5d360.5d201.5d625.5d328.5d625.5d401.5d625.5d438.75d591.75d476d558d476d492.5d476d427d438.75d393.75d401.5d360.5d328.5d360.5d201.5d360.5hR2d711.5R3d682R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i82R11d100.5R12d711.5R13ai1i3i3i2i2i2i3i3i2i2i2i2i2i3i3i3i3i1i2i2i3i3i3i3i2hg:81oR0d950.5R1ad403.5d346d293.5d346d228.75d428d164d510d164d651.5d164d792.5d228.75d874.5d293.5d956.5d403.5d956.5d513.5d956.5d577.75d874.5d642d792.5d642d651.5d642d510d577.75d428d513.5d346d403.5d346d545d1010.5d678d1156d556d1156d445.5d1036.5d429d1037.5d420.25d1038d411.5d1038.5d403.5d1038.5d246d1038.5d151.75d933.25d57.5d828d57.5d651.5d57.5d474.5d151.75d369.25d246d264d403.5d264d560.5d264d654.5d369.25d748.5d474.5d748.5d651.5d748.5d781.5d696.25d874d644d966.5d545d1010.5hR2d806R3d748.5R4d57.5R5d760R6d-132R7d702.5R8d168R9d241.5R10i81R11d57.5R12d806R13ai1i3i3i3i3i3i3i3i3i1i2i2i2i3i3i3i3i3i3i3i3i3i3hg:80oR0d950.5R1ad201.5d360.5d201.5d641d328.5d641d399d641d437.5d604.5d476d568d476d500.5d476d433.5d437.5d397d399d360.5d328.5d360.5d201.5d360.5d100.5d277.5d328.5d277.5d454d277.5d518.25d334.25d582.5d391d582.5d500.5d582.5d611d518.25d667.5d454d724d328.5d724d201.5d724d201.5d1024d100.5d1024d100.5d277.5hR2d617.5R3d582.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i80R11d100.5R12d617.5R13ai1i2i2i3i3i3i3i2i1i2i3i3i3i3i2i2i2i2hg:79oR0d950.5R1ad403.5d346d293.5d346d228.75d428d164d510d164d651.5d164d792.5d228.75d874.5d293.5d956.5d403.5d956.5d513.5d956.5d577.75d874.5d642d792.5d642d651.5d642d510d577.75d428d513.5d346d403.5d346d403.5d264d560.5d264d654.5d369.25d748.5d474.5d748.5d651.5d748.5d828d654.5d933.25d560.5d1038.5d403.5d1038.5d246d1038.5d151.75d933.5d57.5d828.5d57.5d651.5d57.5d474.5d151.75d369.25d246d264d403.5d264hR2d806R3d748.5R4d57.5R5d760R6d-14.5R7d702.5R8d168R9d241.5R10i79R11d57.5R12d806R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:78oR0d950.5R1ad100.5d277.5d236.5d277.5d567.5d902d567.5d277.5d665.5d277.5d665.5d1024d529.5d1024d198.5d399.5d198.5d1024d100.5d1024d100.5d277.5hR2d766R3d665.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i78R11d100.5R12d766R13ai1i2i2i2i2i2i2i2i2i2i2hg:77oR0d950.5R1ad100.5d277.5d251d277.5d441.5d785.5d633d277.5d783.5d277.5d783.5d1024d685d1024d685d368.5d492.5d880.5d391d880.5d198.5d368.5d198.5d1024d100.5d1024d100.5d277.5hR2d883.5R3d783.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i77R11d100.5R12d883.5R13ai1i2i2i2i2i2i2i2i2i2i2i2i2i2hg:76oR0d950.5R1ad100.5d277.5d201.5d277.5d201.5d939d565d939d565d1024d100.5d1024d100.5d277.5hR2d570.5R3d565R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i76R11d100.5R12d570.5R13ai1i2i2i2i2i2i2hg:75oR0d950.5R1ad100.5d277.5d201.5d277.5d201.5d593d536.5d277.5d666.5d277.5d296d625.5d693d1024d560d1024d201.5d664.5d201.5d1024d100.5d1024d100.5d277.5hR2d671.5R3d693R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i75R11d100.5R12d671.5R13ai1i2i2i2i2i2i2i2i2i2i2i2hg:74oR0d950.5R1ad100.5d277.5d201.5d277.5d201.5d972d201.5d1107d150.25d1168d99d1229d-14.5d1229d-53d1229d-53d1144d-21.5d1144d45.5d1144d73d1106.5d100.5d1069d100.5d972d100.5d277.5hR2d302R3d201.5R4d-53R5d746.5R6d-205R7d799.5R8d168R9d241.5R10i74R11d-53R12d302R13ai1i2i2i3i3i2i2i2i3i3i2hg:73oR0d950.5R1ad100.5d277.5d201.5d277.5d201.5d1024d100.5d1024d100.5d277.5hR2d302R3d201.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i73R11d100.5R12d302R13ai1i2i2i2i2hg:72oR0d950.5R1ad100.5d277.5d201.5d277.5d201.5d583.5d568.5d583.5d568.5d277.5d669.5d277.5d669.5d1024d568.5d1024d568.5d668.5d201.5d668.5d201.5d1024d100.5d1024d100.5d277.5hR2d770R3d669.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i72R11d100.5R12d770R13ai1i2i2i2i2i2i2i2i2i2i2i2i2hg:71oR0d950.5R1ad609.5d917.5d609.5d717d444.5d717d444.5d634d709.5d634d709.5d954.5d651d996d580.5d1017.25d510d1038.5d430d1038.5d255d1038.5d156.25d936.25d57.5d834d57.5d651.5d57.5d468.5d156.25d366.25d255d264d430d264d503d264d568.75d282d634.5d300d690d335d690d442.5d634d395d571d371d508d347d438.5d347d301.5d347d232.75d423.5d164d500d164d651.5d164d802.5d232.75d879d301.5d955.5d438.5d955.5d492d955.5d534d946.25d576d937d609.5d917.5hR2d793.5R3d709.5R4d57.5R5d760R6d-14.5R7d702.5R8d168R9d241.5R10i71R11d57.5R12d793.5R13ai1i2i2i2i2i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3hg:70oR0d950.5R1ad100.5d277.5d529.5d277.5d529.5d362.5d201.5d362.5d201.5d582.5d497.5d582.5d497.5d667.5d201.5d667.5d201.5d1024d100.5d1024d100.5d277.5hR2d589R3d529.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i70R11d100.5R12d589R13ai1i2i2i2i2i2i2i2i2i2i2hg:126oR0d950.5R1ad749.5d615.5d749.5d704.5d697d744d652.25d761d607.5d778d559d778d504d778d431d748.5d425.5d746.5d423d745.5d419.5d744d412d741.5d334.5d710.5d287.5d710.5d243.5d710.5d200.5d729.75d157.5d749d108.5d790.5d108.5d701.5d161d662d205.75d644.75d250.5d627.5d299d627.5d354d627.5d427.5d657.5d432.5d659.5d435d660.5d439d662d446d664.5d523.5d695.5d570.5d695.5d613.5d695.5d655.75d676.5d698d657.5d749.5d615.5hR2d858R3d749.5R4d108.5R5d408.5R6d233.5R7d300R8d168R9d241.5R10i126R11d108.5R12d858R13ai1i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3hg:69oR0d950.5R1ad100.5d277.5d572.5d277.5d572.5d362.5d201.5d362.5d201.5d583.5d557d583.5d557d668.5d201.5d668.5d201.5d939d581.5d939d581.5d1024d100.5d1024d100.5d277.5hR2d647R3d581.5R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i69R11d100.5R12d647R13ai1i2i2i2i2i2i2i2i2i2i2i2i2hg:125oR0d950.5R1ad128d1119d163d1119d233d1119d254.25d1097.5d275.5d1076d275.5d1004.5d275.5d880.5d275.5d802.5d298d767d320.5d731.5d376d718d320.5d705.5d298d670d275.5d634.5d275.5d556d275.5d432d275.5d361d254.25d339.25d233d317.5d163d317.5d128d317.5d128d246d159.5d246d284d246d325.75d282.75d367.5d319.5d367.5d430d367.5d550d367.5d624.5d394.5d653.25d421.5d682d492.5d682d523.5d682d523.5d753.5d492.5d753.5d421.5d753.5d394.5d782.5d367.5d811.5d367.5d887d367.5d1006.5d367.5d1117d325.75d1154d284d1191d159.5d1191d128d1191d128d1119hR2d651.5R3d523.5R4d128R5d778R6d-167R7d650R8d168R9d241.5R10i125R11d128R12d651.5R13ai1i2i3i3i2i3i3i3i3i2i3i3i2i2i2i3i3i2i3i3i2i2i2i3i3i2i3i3i2i2hg:68oR0d950.5R1ad201.5d360.5d201.5d941d323.5d941d478d941d549.75d871d621.5d801d621.5d650d621.5d500d549.75d430.25d478d360.5d323.5d360.5d201.5d360.5d100.5d277.5d308d277.5d525d277.5d626.5d367.75d728d458d728d650d728d843d626d933.5d524d1024d308d1024d100.5d1024d100.5d277.5hR2d788.5R3d728R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i68R11d100.5R12d788.5R13ai1i2i2i3i3i3i3i2i1i2i3i3i3i3i2i2hg:124oR0d950.5R1ad215d241.5d215d1265.5d130d1265.5d130d241.5d215d241.5hR2d345R3d215R4d130R5d782.5R6d-241.5R7d652.5R8d168R9d241.5R10i124R11d130R12d345R13ai1i2i2i2i2hg:67oR0d950.5R1ad659.5d335d659.5d441.5d608.5d394d550.75d370.5d493d347d428d347d300d347d232d425.25d164d503.5d164d651.5d164d799d232d877.25d300d955.5d428d955.5d493d955.5d550.75d932d608.5d908.5d659.5d861d659.5d966.5d606.5d1002.5d547.25d1020.5d488d1038.5d422d1038.5d252.5d1038.5d155d934.75d57.5d831d57.5d651.5d57.5d471.5d155d367.75d252.5d264d422d264d489d264d548.25d281.75d607.5d299.5d659.5d335hR2d715R3d659.5R4d57.5R5d760R6d-14.5R7d702.5R8d168R9d241.5R10i67R11d57.5R12d715R13ai1i2i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3hg:123oR0d950.5R1ad523.5d1119d523.5d1191d492.5d1191d368d1191d325.75d1154d283.5d1117d283.5d1006.5d283.5d887d283.5d811.5d256.5d782.5d229.5d753.5d158.5d753.5d128d753.5d128d682d158.5d682d230d682d256.75d653.25d283.5d624.5d283.5d550d283.5d430d283.5d319.5d325.75d282.75d368d246d492.5d246d523.5d246d523.5d317.5d489.5d317.5d419d317.5d397.5d339.5d376d361.5d376d432d376d556d376d634.5d353.25d670d330.5d705.5d275.5d718d331d731.5d353.5d767d376d802.5d376d880.5d376d1004.5d376d1075d397.5d1097d419d1119d489.5d1119d523.5d1119hR2d651.5R3d523.5R4d128R5d778R6d-167R7d650R8d168R9d241.5R10i123R11d128R12d651.5R13ai1i2i2i3i3i2i3i3i2i2i2i3i3i2i3i3i2i2i2i3i3i2i3i3i3i3i2i3i3i2hg:66oR0d950.5R1ad201.5d667.5d201.5d941d363.5d941d445d941d484.25d907.25d523.5d873.5d523.5d804d523.5d734d484.25d700.75d445d667.5d363.5d667.5d201.5d667.5d201.5d360.5d201.5d585.5d351d585.5d425d585.5d461.25d557.75d497.5d530d497.5d473d497.5d416.5d461.25d388.5d425d360.5d351d360.5d201.5d360.5d100.5d277.5d358.5d277.5d474d277.5d536.5d325.5d599d373.5d599d462d599d530.5d567d571d535d611.5d473d621.5d547.5d637.5d588.75d688.25d630d739d630d815d630d915d562d969.5d494d1024d368.5d1024d100.5d1024d100.5d277.5hR2d702.5R3d630R4d100.5R5d746.5R6d0R7d646R8d168R9d241.5R10i66R11d100.5R12d702.5R13ai1i2i2i3i3i3i3i2i1i2i2i3i3i3i3i2i1i2i3i3i3i3i3i3i3i3i2i2hg:122oR0d950.5R1ad56.5d464d493.5d464d493.5d548d147.5d950.5d493.5d950.5d493.5d1024d44d1024d44d940d390d537.5d56.5d537.5d56.5d464hR2d537.5R3d493.5R4d44R5d560R6d0R7d516R8d168R9d241.5R10i122R11d44R12d537.5R13ai1i2i2i2i2i2i2i2i2i2i2hg:65oR0d950.5R1ad350d377d213d748.5d487.5d748.5d350d377d293d277.5d407.5d277.5d692d1024d587d1024d519d832.5d182.5d832.5d114.5d1024d8d1024d293d277.5hR2d700.5R3d692R4d8R5d746.5R6d0R7d738.5R8d168R9d241.5R10i65R11d8R12d700.5R13ai1i2i2i2i1i2i2i2i2i2i2i2i2hg:121oR0d950.5R1ad329.5d1076d290.5d1176d253.5d1206.5d216.5d1237d154.5d1237d81d1237d81d1160d135d1160d173d1160d194d1142d215d1124d240.5d1057d257d1015d30.5d464d128d464d303d902d478d464d575.5d464d329.5d1076hR2d606R3d575.5R4d30.5R5d560R6d-213R7d529.5R8d168R9d241.5R10i121R11d30.5R12d606R13ai1i3i3i2i2i2i3i3i2i2i2i2i2i2i2hg:64oR0d950.5R1ad381d755.5d381d827d416.5d867.75d452d908.5d514d908.5d575.5d908.5d610.75d867.5d646d826.5d646d755.5d646d685.5d610d644.25d574d603d513d603d452.5d603d416.75d644d381d685d381d755.5d653.5d905d623.5d943.5d584.75d961.75d546d980d494.5d980d408.5d980d354.75d917.75d301d855.5d301d755.5d301d655.5d355d593d409d530.5d494.5d530.5d546d530.5d585d549.25d624d568d653.5d606d653.5d540.5d725d540.5d725d908.5d798d897.5d839.25d841.75d880.5d786d880.5d697.5d880.5d644d864.75d597d849d550d817d510d765d444.5d690.25d409.75d615.5d375d527.5d375d466d375d409.5d391.25d353d407.5d305d439.5d226.5d490.5d182.25d573.25d138d656d138d752.5d138d832d166.75d901.5d195.5d971d250d1024d302.5d1076d371.5d1103.25d440.5d1130.5d519d1130.5d583.5d1130.5d645.75d1108.75d708d1087d760d1046.5d805d1102d742.5d1150.5d668.75d1176.25d595d1202d519d1202d426.5d1202d344.5d1169.25d262.5d1136.5d198.5d1074d134.5d1011.5d101d929.25d67.5d847d67.5d752.5d67.5d661.5d101.5d579d135.5d496.5d198.5d434d263d370.5d347.5d336.75d432d303d526.5d303d632.5d303d723.25d346.5d814d390d875.5d470d913d519d932.75d576.5d952.5d634d952.5d695.5d952.5d827d873d903d793.5d979d653.5d982d653.5d905hR2d1024R3d952.5R4d67.5R5d721R6d-178R7d653.5R8d168R9d241.5R10i64R11d67.5R12d1024R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i2i2i2i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i2i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i2hg:120oR0d950.5R1ad562d464d359.5d736.5d572.5d1024d464d1024d301d804d138d1024d29.5d1024d247d731d48d464d156.5d464d305d663.5d453.5d464d562d464hR2d606R3d572.5R4d29.5R5d560R6d0R7d530.5R8d168R9d241.5R10i120R11d29.5R12d606R13ai1i2i2i2i2i2i2i2i2i2i2i2i2hg:63oR0d950.5R1ad195.5d897d297d897d297d1024d195.5d1024d195.5d897d294d823.5d198.5d823.5d198.5d746.5d198.5d696d212.5d663.5d226.5d631d271.5d588d316.5d543.5d345d517d357.75d493.5d370.5d470d370.5d445.5d370.5d401d337.75d373.5d305d346d251d346d211.5d346d166.75d363.5d122d381d73.5d414.5d73.5d320.5d120.5d292d168.75d278d217d264d268.5d264d360.5d264d416.25d312.5d472d361d472d440.5d472d478.5d454d512.75d436d547d391d590d347d633d323.5d656.5d313.75d669.75d304d683d300d695.5d297d706d295.5d721d294d736d294d762d294d823.5hR2d543.5R3d472R4d73.5R5d760R6d0R7d686.5R8d168R9d241.5R10i63R11d73.5R12d543.5R13ai1i2i2i2i2i1i2i2i3i3i2i3i3i3i3i3i3i2i3i3i3i3i3i3i2i3i3i3i3i2hg:119oR0d950.5R1ad43d464d135d464d250d901d364.5d464d473d464d588d901d702.5d464d794.5d464d648d1024d539.5d1024d419d565d298d1024d189.5d1024d43d464hR2d837.5R3d794.5R4d43R5d560R6d0R7d517R8d168R9d241.5R10i119R11d43R12d837.5R13ai1i2i2i2i2i2i2i2i2i2i2i2i2i2hg:62oR0d950.5R1ad108.5d520d108.5d429d749.5d661.5d749.5d744.5d108.5d977d108.5d886d623.5d703.5d108.5d520hR2d858R3d749.5R4d108.5R5d595R6d47R7d486.5R8d168R9d241.5R10i62R11d108.5R12d858R13ai1i2i2i2i2i2i2i2hg:118oR0d950.5R1ad30.5d464d128d464d303d934d478d464d575.5d464d365.5d1024d240.5d1024d30.5d464hR2d606R3d575.5R4d30.5R5d560R6d0R7d529.5R8d168R9d241.5R10i118R11d30.5R12d606R13ai1i2i2i2i2i2i2i2hg:61oR0d950.5R1ad108.5d559d749.5d559d749.5d643d108.5d643d108.5d559d108.5d763d749.5d763d749.5d848d108.5d848d108.5d763hR2d858R3d749.5R4d108.5R5d465R6d176R7d356.5R8d168R9d241.5R10i61R11d108.5R12d858R13ai1i2i2i2i2i1i2i2i2i2hg:117oR0d950.5R1ad87d803d87d464d179d464d179d799.5d179d879d210d918.75d241d958.5d303d958.5d377.5d958.5d420.75d911d464d863.5d464d781.5d464d464d556d464d556d1024d464d1024d464d938d430.5d989d386.25d1013.75d342d1038.5d283.5d1038.5d187d1038.5d137d978.5d87d918.5d87d803hR2d649R3d556R4d87R5d560R6d-14.5R7d473R8d168R9d241.5R10i117R11d87R12d649R13ai1i2i2i2i3i3i3i3i2i2i2i2i2i3i3i3i3hg:60oR0d950.5R1ad749.5d520d233.5d703.5d749.5d886d749.5d977d108.5d744.5d108.5d661.5d749.5d429d749.5d520hR2d858R3d749.5R4d108.5R5d595R6d47R7d486.5R8d168R9d241.5R10i60R11d108.5R12d858R13ai1i2i2i2i2i2i2i2hg:116oR0d950.5R1ad187.5d305d187.5d464d377d464d377d535.5d187.5d535.5d187.5d839.5d187.5d908d206.25d927.5d225d947d282.5d947d377d947d377d1024d282.5d1024d176d1024d135.5d984.25d95d944.5d95d839.5d95d535.5d27.5d535.5d27.5d464d95d464d95d305d187.5d305hR2d401.5R3d377R4d27.5R5d719R6d0R7d691.5R8d168R9d241.5R10i116R11d27.5R12d401.5R13ai1i2i2i2i2i2i3i3i2i2i2i3i3i2i2i2i2i2i2hg:59oR0d950.5R1ad120d494.5d225.5d494.5d225.5d621.5d120d621.5d120d494.5d120d897d225.5d897d225.5d983d143.5d1143d79d1143d120d983d120d897hR2d345R3d225.5R4d79R5d529.5R6d-119R7d450.5R8d168R9d241.5R10i59R11d79R12d345R13ai1i2i2i2i2i1i2i2i2i2i2i2hg:115oR0d950.5R1ad453.5d480.5d453.5d567.5d414.5d547.5d372.5d537.5d330.5d527.5d285.5d527.5d217d527.5d182.75d548.5d148.5d569.5d148.5d611.5d148.5d643.5d173d661.75d197.5d680d271.5d696.5d303d703.5d401d724.5d442.25d762.75d483.5d801d483.5d869.5d483.5d947.5d421.75d993d360d1038.5d252d1038.5d207d1038.5d158.25d1029.75d109.5d1021d55.5d1003.5d55.5d908.5d106.5d935d156d948.25d205.5d961.5d254d961.5d319d961.5d354d939.25d389d917d389d876.5d389d839d363.75d819d338.5d799d253d780.5d221d773d135.5d755d97.5d717.75d59.5d680.5d59.5d615.5d59.5d536.5d115.5d493.5d171.5d450.5d274.5d450.5d325.5d450.5d370.5d458d415.5d465.5d453.5d480.5hR2d533.5R3d483.5R4d55.5R5d573.5R6d-14.5R7d518R8d168R9d241.5R10i115R11d55.5R12d533.5R13ai1i2i3i3i3i3i3i3i2i3i3i3i3i3i3i2i3i3i3i3i3i3i2i3i3i3i3i3i3hg:58oR0d950.5R1ad120d897d225.5d897d225.5d1024d120d1024d120d897d120d494.5d225.5d494.5d225.5d621.5d120d621.5d120d494.5hR2d345R3d225.5R4d120R5d529.5R6d0R7d409.5R8d168R9d241.5R10i58R11d120R12d345R13ai1i2i2i2i2i1i2i2i2i2hg:114oR0d950.5R1ad421d550d405.5d541d387.25d536.75d369d532.5d347d532.5d269d532.5d227.25d583.25d185.5d634d185.5d729d185.5d1024d93d1024d93d464d185.5d464d185.5d551d214.5d500d261d475.25d307.5d450.5d374d450.5d383.5d450.5d395d451.75d406.5d453d420.5d455.5d421d550hR2d421R3d421R4d93R5d573.5R6d0R7d480.5R8d168R9d241.5R10i114R11d93R12d421R13ai1i3i3i3i3i2i2i2i2i2i3i3i3i3i2hg:57oR0d950.5R1ad112.5d1008.5d112.5d916.5d150.5d934.5d189.5d944d228.5d953.5d266d953.5d366d953.5d418.75d886.25d471.5d819d479d682d450d725d405.5d748d361d771d307d771d195d771d129.75d703.25d64.5d635.5d64.5d518d64.5d403d132.5d333.5d200.5d264d313.5d264d443d264d511.25d363.25d579.5d462.5d579.5d651.5d579.5d828d495.75d933.25d412d1038.5d270.5d1038.5d232.5d1038.5d193.5d1031d154.5d1023.5d112.5d1008.5d313.5d692d381.5d692d421.25d645.5d461d599d461d518d461d437.5d421.25d390.75d381.5d344d313.5d344d245.5d344d205.75d390.75d166d437.5d166d518d166d599d205.75d645.5d245.5d692d313.5d692hR2d651.5R3d579.5R4d64.5R5d760R6d-14.5R7d695.5R8d168R9d241.5R10i57R11d64.5R12d651.5R13ai1i2i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:113oR0d950.5R1ad151.5d744.5d151.5d846d193.25d903.75d235d961.5d308d961.5d381d961.5d423d903.75d465d846d465d744.5d465d643d423d585.25d381d527.5d308d527.5d235d527.5d193.25d585.25d151.5d643d151.5d744.5d465d940d436d990d391.75d1014.25d347.5d1038.5d285.5d1038.5d184d1038.5d120.25d957.5d56.5d876.5d56.5d744.5d56.5d612.5d120.25d531.5d184d450.5d285.5d450.5d347.5d450.5d391.75d474.75d436d499d465d549d465d464d557d464d557d1237d465d1237d465d940hR2d650R3d557R4d56.5R5d573.5R6d-213R7d517R8d168R9d241.5R10i113R11d56.5R12d650R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i2i2i2i2i2hg:56oR0d950.5R1ad325.5d669.5d253.5d669.5d212.25d708d171d746.5d171d814d171d881.5d212.25d920d253.5d958.5d325.5d958.5d397.5d958.5d439d919.75d480.5d881d480.5d814d480.5d746.5d439.25d708d398d669.5d325.5d669.5d224.5d626.5d159.5d610.5d123.25d566d87d521.5d87d457.5d87d368d150.75d316d214.5d264d325.5d264d437d264d500.5d316d564d368d564d457.5d564d521.5d527.75d566d491.5d610.5d427d626.5d500d643.5d540.75d693d581.5d742.5d581.5d814d581.5d922.5d515.25d980.5d449d1038.5d325.5d1038.5d202d1038.5d135.75d980.5d69.5d922.5d69.5d814d69.5d742.5d110.5d693d151.5d643.5d224.5d626.5d187.5d467d187.5d525d223.75d557.5d260d590d325.5d590d390.5d590d427.25d557.5d464d525d464d467d464d409d427.25d376.5d390.5d344d325.5d344d260d344d223.75d376.5d187.5d409d187.5d467hR2d651.5R3d581.5R4d69.5R5d760R6d-14.5R7d690.5R8d168R9d241.5R10i56R11d69.5R12d651.5R13ai1i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hg:112oR0d950.5R1ad185.5d940d185.5d1237d93d1237d93d464d185.5d464d185.5d549d214.5d499d258.75d474.75d303d450.5d364.5d450.5d466.5d450.5d530.25d531.5d594d612.5d594d744.5d594d876.5d530.25d957.5d466.5d1038.5d364.5d1038.5d303d1038.5d258.75d1014.25d214.5d990d185.5d940d498.5d744.5d498.5d643d456.75d585.25d415d527.5d342d527.5d269d527.5d227.25d585.25d185.5d643d185.5d744.5d185.5d846d227.25d903.75d269d961.5d342d961.5d415d961.5d456.75d903.75d498.5d846d498.5d744.5hR2d650R3d594R4d93R5d573.5R6d-213R7d480.5R8d168R9d241.5R10i112R11d93R12d650R13ai1i2i2i2i2i2i3i3i3i3i3i3i3i3i1i3i3i3i3i3i3i3i3hgh";
flash.text.Font.DEFAULT_FONT_SCALE = 9.0;
flash.text.Font.DEFAULT_FONT_NAME = "Bitstream_Vera_Sans";
flash.text.Font.DEFAULT_CLASS_NAME = "flash.text.Font";
flash.text.Font.__registeredFonts = new Array();
flash.text.TextField.mDefaultFont = "Bitstream_Vera_Sans";
flash.text.FontInstance.mSolidFonts = new haxe.ds.StringMap();
flash.text.TextFieldAutoSize.CENTER = "CENTER";
flash.text.TextFieldAutoSize.LEFT = "LEFT";
flash.text.TextFieldAutoSize.NONE = "NONE";
flash.text.TextFieldAutoSize.RIGHT = "RIGHT";
flash.text.TextFieldType.DYNAMIC = "DYNAMIC";
flash.text.TextFieldType.INPUT = "INPUT";
flash.ui.Keyboard.NUMBER_0 = 48;
flash.ui.Keyboard.NUMBER_1 = 49;
flash.ui.Keyboard.NUMBER_2 = 50;
flash.ui.Keyboard.NUMBER_3 = 51;
flash.ui.Keyboard.NUMBER_4 = 52;
flash.ui.Keyboard.NUMBER_5 = 53;
flash.ui.Keyboard.NUMBER_6 = 54;
flash.ui.Keyboard.NUMBER_7 = 55;
flash.ui.Keyboard.NUMBER_8 = 56;
flash.ui.Keyboard.NUMBER_9 = 57;
flash.ui.Keyboard.A = 65;
flash.ui.Keyboard.B = 66;
flash.ui.Keyboard.C = 67;
flash.ui.Keyboard.D = 68;
flash.ui.Keyboard.E = 69;
flash.ui.Keyboard.F = 70;
flash.ui.Keyboard.G = 71;
flash.ui.Keyboard.H = 72;
flash.ui.Keyboard.I = 73;
flash.ui.Keyboard.J = 74;
flash.ui.Keyboard.K = 75;
flash.ui.Keyboard.L = 76;
flash.ui.Keyboard.M = 77;
flash.ui.Keyboard.N = 78;
flash.ui.Keyboard.O = 79;
flash.ui.Keyboard.P = 80;
flash.ui.Keyboard.Q = 81;
flash.ui.Keyboard.R = 82;
flash.ui.Keyboard.S = 83;
flash.ui.Keyboard.T = 84;
flash.ui.Keyboard.U = 85;
flash.ui.Keyboard.V = 86;
flash.ui.Keyboard.W = 87;
flash.ui.Keyboard.X = 88;
flash.ui.Keyboard.Y = 89;
flash.ui.Keyboard.Z = 90;
flash.ui.Keyboard.NUMPAD_0 = 96;
flash.ui.Keyboard.NUMPAD_1 = 97;
flash.ui.Keyboard.NUMPAD_2 = 98;
flash.ui.Keyboard.NUMPAD_3 = 99;
flash.ui.Keyboard.NUMPAD_4 = 100;
flash.ui.Keyboard.NUMPAD_5 = 101;
flash.ui.Keyboard.NUMPAD_6 = 102;
flash.ui.Keyboard.NUMPAD_7 = 103;
flash.ui.Keyboard.NUMPAD_8 = 104;
flash.ui.Keyboard.NUMPAD_9 = 105;
flash.ui.Keyboard.NUMPAD_MULTIPLY = 106;
flash.ui.Keyboard.NUMPAD_ADD = 107;
flash.ui.Keyboard.NUMPAD_ENTER = 108;
flash.ui.Keyboard.NUMPAD_SUBTRACT = 109;
flash.ui.Keyboard.NUMPAD_DECIMAL = 110;
flash.ui.Keyboard.NUMPAD_DIVIDE = 111;
flash.ui.Keyboard.F1 = 112;
flash.ui.Keyboard.F2 = 113;
flash.ui.Keyboard.F3 = 114;
flash.ui.Keyboard.F4 = 115;
flash.ui.Keyboard.F5 = 116;
flash.ui.Keyboard.F6 = 117;
flash.ui.Keyboard.F7 = 118;
flash.ui.Keyboard.F8 = 119;
flash.ui.Keyboard.F9 = 120;
flash.ui.Keyboard.F10 = 121;
flash.ui.Keyboard.F11 = 122;
flash.ui.Keyboard.F12 = 123;
flash.ui.Keyboard.F13 = 124;
flash.ui.Keyboard.F14 = 125;
flash.ui.Keyboard.F15 = 126;
flash.ui.Keyboard.BACKSPACE = 8;
flash.ui.Keyboard.TAB = 9;
flash.ui.Keyboard.ENTER = 13;
flash.ui.Keyboard.SHIFT = 16;
flash.ui.Keyboard.CONTROL = 17;
flash.ui.Keyboard.CAPS_LOCK = 18;
flash.ui.Keyboard.ESCAPE = 27;
flash.ui.Keyboard.SPACE = 32;
flash.ui.Keyboard.PAGE_UP = 33;
flash.ui.Keyboard.PAGE_DOWN = 34;
flash.ui.Keyboard.END = 35;
flash.ui.Keyboard.HOME = 36;
flash.ui.Keyboard.LEFT = 37;
flash.ui.Keyboard.RIGHT = 39;
flash.ui.Keyboard.UP = 38;
flash.ui.Keyboard.DOWN = 40;
flash.ui.Keyboard.INSERT = 45;
flash.ui.Keyboard.DELETE = 46;
flash.ui.Keyboard.NUMLOCK = 144;
flash.ui.Keyboard.BREAK = 19;
flash.ui.Keyboard.SEMICOLON = 186;
flash.ui.Keyboard.EQUAL = 187;
flash.ui.Keyboard.COMMA = 188;
flash.ui.Keyboard.MINUS = 189;
flash.ui.Keyboard.PERIOD = 190;
flash.ui.Keyboard.SLASH = 191;
flash.ui.Keyboard.BACKQUOTE = 192;
flash.ui.Keyboard.LEFTBRACKET = 219;
flash.ui.Keyboard.BACKSLASH = 220;
flash.ui.Keyboard.RIGHTBRACKET = 221;
flash.ui.Keyboard.DOM_VK_CANCEL = 3;
flash.ui.Keyboard.DOM_VK_HELP = 6;
flash.ui.Keyboard.DOM_VK_BACK_SPACE = 8;
flash.ui.Keyboard.DOM_VK_TAB = 9;
flash.ui.Keyboard.DOM_VK_CLEAR = 12;
flash.ui.Keyboard.DOM_VK_RETURN = 13;
flash.ui.Keyboard.DOM_VK_ENTER = 14;
flash.ui.Keyboard.DOM_VK_SHIFT = 16;
flash.ui.Keyboard.DOM_VK_CONTROL = 17;
flash.ui.Keyboard.DOM_VK_ALT = 18;
flash.ui.Keyboard.DOM_VK_PAUSE = 19;
flash.ui.Keyboard.DOM_VK_CAPS_LOCK = 20;
flash.ui.Keyboard.DOM_VK_ESCAPE = 27;
flash.ui.Keyboard.DOM_VK_SPACE = 32;
flash.ui.Keyboard.DOM_VK_PAGE_UP = 33;
flash.ui.Keyboard.DOM_VK_PAGE_DOWN = 34;
flash.ui.Keyboard.DOM_VK_END = 35;
flash.ui.Keyboard.DOM_VK_HOME = 36;
flash.ui.Keyboard.DOM_VK_LEFT = 37;
flash.ui.Keyboard.DOM_VK_UP = 38;
flash.ui.Keyboard.DOM_VK_RIGHT = 39;
flash.ui.Keyboard.DOM_VK_DOWN = 40;
flash.ui.Keyboard.DOM_VK_PRINTSCREEN = 44;
flash.ui.Keyboard.DOM_VK_INSERT = 45;
flash.ui.Keyboard.DOM_VK_DELETE = 46;
flash.ui.Keyboard.DOM_VK_0 = 48;
flash.ui.Keyboard.DOM_VK_1 = 49;
flash.ui.Keyboard.DOM_VK_2 = 50;
flash.ui.Keyboard.DOM_VK_3 = 51;
flash.ui.Keyboard.DOM_VK_4 = 52;
flash.ui.Keyboard.DOM_VK_5 = 53;
flash.ui.Keyboard.DOM_VK_6 = 54;
flash.ui.Keyboard.DOM_VK_7 = 55;
flash.ui.Keyboard.DOM_VK_8 = 56;
flash.ui.Keyboard.DOM_VK_9 = 57;
flash.ui.Keyboard.DOM_VK_SEMICOLON = 59;
flash.ui.Keyboard.DOM_VK_EQUALS = 61;
flash.ui.Keyboard.DOM_VK_A = 65;
flash.ui.Keyboard.DOM_VK_B = 66;
flash.ui.Keyboard.DOM_VK_C = 67;
flash.ui.Keyboard.DOM_VK_D = 68;
flash.ui.Keyboard.DOM_VK_E = 69;
flash.ui.Keyboard.DOM_VK_F = 70;
flash.ui.Keyboard.DOM_VK_G = 71;
flash.ui.Keyboard.DOM_VK_H = 72;
flash.ui.Keyboard.DOM_VK_I = 73;
flash.ui.Keyboard.DOM_VK_J = 74;
flash.ui.Keyboard.DOM_VK_K = 75;
flash.ui.Keyboard.DOM_VK_L = 76;
flash.ui.Keyboard.DOM_VK_M = 77;
flash.ui.Keyboard.DOM_VK_N = 78;
flash.ui.Keyboard.DOM_VK_O = 79;
flash.ui.Keyboard.DOM_VK_P = 80;
flash.ui.Keyboard.DOM_VK_Q = 81;
flash.ui.Keyboard.DOM_VK_R = 82;
flash.ui.Keyboard.DOM_VK_S = 83;
flash.ui.Keyboard.DOM_VK_T = 84;
flash.ui.Keyboard.DOM_VK_U = 85;
flash.ui.Keyboard.DOM_VK_V = 86;
flash.ui.Keyboard.DOM_VK_W = 87;
flash.ui.Keyboard.DOM_VK_X = 88;
flash.ui.Keyboard.DOM_VK_Y = 89;
flash.ui.Keyboard.DOM_VK_Z = 90;
flash.ui.Keyboard.DOM_VK_CONTEXT_MENU = 93;
flash.ui.Keyboard.DOM_VK_NUMPAD0 = 96;
flash.ui.Keyboard.DOM_VK_NUMPAD1 = 97;
flash.ui.Keyboard.DOM_VK_NUMPAD2 = 98;
flash.ui.Keyboard.DOM_VK_NUMPAD3 = 99;
flash.ui.Keyboard.DOM_VK_NUMPAD4 = 100;
flash.ui.Keyboard.DOM_VK_NUMPAD5 = 101;
flash.ui.Keyboard.DOM_VK_NUMPAD6 = 102;
flash.ui.Keyboard.DOM_VK_NUMPAD7 = 103;
flash.ui.Keyboard.DOM_VK_NUMPAD8 = 104;
flash.ui.Keyboard.DOM_VK_NUMPAD9 = 105;
flash.ui.Keyboard.DOM_VK_MULTIPLY = 106;
flash.ui.Keyboard.DOM_VK_ADD = 107;
flash.ui.Keyboard.DOM_VK_SEPARATOR = 108;
flash.ui.Keyboard.DOM_VK_SUBTRACT = 109;
flash.ui.Keyboard.DOM_VK_DECIMAL = 110;
flash.ui.Keyboard.DOM_VK_DIVIDE = 111;
flash.ui.Keyboard.DOM_VK_F1 = 112;
flash.ui.Keyboard.DOM_VK_F2 = 113;
flash.ui.Keyboard.DOM_VK_F3 = 114;
flash.ui.Keyboard.DOM_VK_F4 = 115;
flash.ui.Keyboard.DOM_VK_F5 = 116;
flash.ui.Keyboard.DOM_VK_F6 = 117;
flash.ui.Keyboard.DOM_VK_F7 = 118;
flash.ui.Keyboard.DOM_VK_F8 = 119;
flash.ui.Keyboard.DOM_VK_F9 = 120;
flash.ui.Keyboard.DOM_VK_F10 = 121;
flash.ui.Keyboard.DOM_VK_F11 = 122;
flash.ui.Keyboard.DOM_VK_F12 = 123;
flash.ui.Keyboard.DOM_VK_F13 = 124;
flash.ui.Keyboard.DOM_VK_F14 = 125;
flash.ui.Keyboard.DOM_VK_F15 = 126;
flash.ui.Keyboard.DOM_VK_F16 = 127;
flash.ui.Keyboard.DOM_VK_F17 = 128;
flash.ui.Keyboard.DOM_VK_F18 = 129;
flash.ui.Keyboard.DOM_VK_F19 = 130;
flash.ui.Keyboard.DOM_VK_F20 = 131;
flash.ui.Keyboard.DOM_VK_F21 = 132;
flash.ui.Keyboard.DOM_VK_F22 = 133;
flash.ui.Keyboard.DOM_VK_F23 = 134;
flash.ui.Keyboard.DOM_VK_F24 = 135;
flash.ui.Keyboard.DOM_VK_NUM_LOCK = 144;
flash.ui.Keyboard.DOM_VK_SCROLL_LOCK = 145;
flash.ui.Keyboard.DOM_VK_COMMA = 188;
flash.ui.Keyboard.DOM_VK_PERIOD = 190;
flash.ui.Keyboard.DOM_VK_SLASH = 191;
flash.ui.Keyboard.DOM_VK_BACK_QUOTE = 192;
flash.ui.Keyboard.DOM_VK_OPEN_BRACKET = 219;
flash.ui.Keyboard.DOM_VK_BACK_SLASH = 220;
flash.ui.Keyboard.DOM_VK_CLOSE_BRACKET = 221;
flash.ui.Keyboard.DOM_VK_QUOTE = 222;
flash.ui.Keyboard.DOM_VK_META = 224;
flash.ui.Keyboard.DOM_VK_KANA = 21;
flash.ui.Keyboard.DOM_VK_HANGUL = 21;
flash.ui.Keyboard.DOM_VK_JUNJA = 23;
flash.ui.Keyboard.DOM_VK_FINAL = 24;
flash.ui.Keyboard.DOM_VK_HANJA = 25;
flash.ui.Keyboard.DOM_VK_KANJI = 25;
flash.ui.Keyboard.DOM_VK_CONVERT = 28;
flash.ui.Keyboard.DOM_VK_NONCONVERT = 29;
flash.ui.Keyboard.DOM_VK_ACEPT = 30;
flash.ui.Keyboard.DOM_VK_MODECHANGE = 31;
flash.ui.Keyboard.DOM_VK_SELECT = 41;
flash.ui.Keyboard.DOM_VK_PRINT = 42;
flash.ui.Keyboard.DOM_VK_EXECUTE = 43;
flash.ui.Keyboard.DOM_VK_SLEEP = 95;
flash.utils.Endian.BIG_ENDIAN = "bigEndian";
flash.utils.Endian.LITTLE_ENDIAN = "littleEndian";
flash.utils.Uuid.UID_CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
haxe.Template.splitter = new EReg("(::[A-Za-z0-9_ ()&|!+=/><*.\"-]+::|\\$\\$([A-Za-z0-9_-]+)\\()","");
haxe.Template.expr_splitter = new EReg("(\\(|\\)|[ \r\n\t]*\"[^\"]*\"[ \r\n\t]*|[!+=/><*.&|-]+)","");
haxe.Template.expr_trim = new EReg("^[ ]*([^ ]+)[ ]*$","");
haxe.Template.expr_int = new EReg("^[0-9]+$","");
haxe.Template.expr_float = new EReg("^([+-]?)(?=\\d|,\\d)\\d*(,\\d*)?([Ee]([+-]?\\d+))?$","");
haxe.Template.globals = { };
haxe.Unserializer.DEFAULT_RESOLVER = Type;
haxe.Unserializer.BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789%:";
haxe.ds.ObjectMap.count = 0;
js.Browser.window = typeof window != "undefined" ? window : null;
js.Browser.document = typeof window != "undefined" ? window.document : null;
openfl.Assets.cache = new openfl.AssetCache();
openfl.Assets.libraries = new haxe.ds.StringMap();
openfl.Assets.initialized = false;
openfl.display.Tilesheet.TILE_SCALE = 1;
openfl.display.Tilesheet.TILE_ROTATION = 2;
openfl.display.Tilesheet.TILE_RGB = 4;
openfl.display.Tilesheet.TILE_ALPHA = 8;
openfl.display.Tilesheet.TILE_TRANS_2x2 = 16;
openfl.display.Tilesheet.TILE_BLEND_NORMAL = 0;
openfl.display.Tilesheet.TILE_BLEND_ADD = 65536;
openfl.display.Tilesheet.TILE_BLEND_MULTIPLY = 131072;
openfl.display.Tilesheet.TILE_BLEND_SCREEN = 262144;
tardis.Scheduler.doneInit = false;
tardis.Scheduler.grStacks = new Array();
tardis.Scheduler.grInPanic = new Array();
tardis.Scheduler.grPanicMsg = new Array();
tardis.Scheduler.panicStackDump = "";
tardis.Scheduler.entryCount = 0;
tardis.Scheduler.currentGR = 0;
tardis.Go.main_MOUSE_UP = 0;
tardis.Go.main_MOUSE_MOVE = 2;
tardis.Go.main_MOUSE_DOWN = 1;
tardis.Go.utf8_RuneSelf = 128;
tardis.Go.utf8_RuneError = 65533;
tardis.Go.utf8_MaxRune = 1114111;
tardis.Go.utf8_UTFMax = 4;
tardis.Go.haxegoruntime_init_36_guard = new tardis.Pointer(false);
tardis.Go.haxegoruntime_ZiLen = new tardis.Pointer(0);
tardis.Go.main_mouseEvents = new tardis.Pointer(null);
tardis.Go.main_cacheOffsetY = new tardis.Pointer(0.0);
tardis.Go.main_cacheOffsetX = new tardis.Pointer(0.0);
tardis.Go.main_init_36_guard = new tardis.Pointer(false);
tardis.Go.main_SpriteY = new tardis.Pointer(0.0);
tardis.Go.main_Status = new tardis.Pointer("");
tardis.Go.main_SpriteX = new tardis.Pointer(0.0);
tardis.Go.utf16_init_36_guard = new tardis.Pointer(false);
tardis.Go.utf8_init_36_guard = new tardis.Pointer(false);
tardis.Go.hxutil_init_36_guard = new tardis.Pointer(false);
tardis.Go.doneInit = false;
ApplicationMain.main();
function $hxExpose(src, path) {
	var o = typeof window != "undefined" ? window : exports;
	var parts = path.split(".");
	for(var ii = 0; ii < parts.length-1; ++ii) {
		var p = parts[ii];
		if(typeof o[p] == "undefined") o[p] = {};
		o = o[p];
	}
	o[parts[parts.length-1]] = src;
}
})();
