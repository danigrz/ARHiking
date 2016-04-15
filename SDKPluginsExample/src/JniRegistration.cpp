#include <jni.h>

#include "Plugin.h"
#include "jniHelper.h"
#include "FaceDetectionPlugin.h"
#include "FaceDetectionPluginConnector.h"
#include "BarcodePlugin.h"

JavaVM* pluginJavaVM;

extern "C" JNIEXPORT jlongArray JNICALL Java_com_wikitude_architect_PluginManager_createNativePlugins(JNIEnv *env, jobject thisObj, jstring jPluginName) {

	env->GetJavaVM(&pluginJavaVM);

	int numberOfPlugins = 1;

    jlong cPluginsArray[numberOfPlugins];
    
    JavaStringResource pluginName(env, jPluginName);
    
    if (pluginName.str == "face_detection") {
        FaceDetectionPluginConnector* connector = new FaceDetectionPluginConnector();
        cPluginsArray[0] = (jlong) new FaceDetectionPlugin(640, 480, connector);
    } else if (pluginName.str == "barcode") {
    	cPluginsArray[0] = (jlong) new BarcodePlugin(640, 480);
    }
    
    jlongArray jPluginsArray = env->NewLongArray(numberOfPlugins);
    if (jPluginsArray != nullptr) {
        env->SetLongArrayRegion(jPluginsArray, 0, numberOfPlugins, cPluginsArray);
    }
    
    return jPluginsArray;
}
