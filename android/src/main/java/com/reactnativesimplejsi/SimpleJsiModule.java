package com.reactnativesimplejsi;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = SimpleJsiModule.NAME)
public class SimpleJsiModule extends ReactContextBaseJavaModule {
    public static final String NAME = "SimpleJsi";

    public SimpleJsiModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }


    static {
        try {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("cpp");
        } catch (Exception ignored) {
        }
    }

/*    // Example method
    // See https://reactnative.dev/docs/native-modules-android
    @ReactMethod
    public void multiply(int a, int b, Promise promise) {
        promise.resolve(nativeMultiply(a, b));
    }

    public static native int nativeMultiply(int a, int b);*/

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  private native void nativeInstall(long jsi);

  public void installLib(JavaScriptContextHolder reactContext) {

    if (reactContext.get() != 0) {
      this.nativeInstall(
        reactContext.get()
      );
    } else {
      Log.e("SimpleJsiModule", "JSI Runtime is not available in debug mode");
    }

  }


}
