#include <jni.h>
#include <string>
#include <algorithm>
#include <climits>
#include <android/log.h>

#define TAG "LAB22_JNI_DEMO"
#define LOG_INFO(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOG_ERR(...)  __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

// Fonction 1 : retourne un message depuis la couche native
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lab22_1jnidemo_MainActivity_helloFromJNI(
        JNIEnv* env,
        jobject /* instance */) {

    LOG_INFO("helloFromJNI invoquee depuis le code natif");
    return env->NewStringUTF("Bonjour depuis C++ via JNI !");
}

// Fonction 2 : calcule le factoriel avec detection de depassement
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_lab22_1jnidemo_MainActivity_factorial(
        JNIEnv* env,
        jobject /* instance */,
        jint nombre) {

    if (nombre < 0) {
        LOG_ERR("Valeur invalide : nombre negatif recu");
        return -1;
    }

    long long resultat = 1;
    for (int i = 1; i <= nombre; i++) {
        resultat *= i;
        if (resultat > INT_MAX) {
            LOG_ERR("Depassement entier pour nombre=%d", nombre);
            return -2;
        }
    }

    LOG_INFO("Factoriel(%d) = %lld calcule cote natif", nombre, resultat);
    return static_cast<jint>(resultat);
}

// Fonction 3 : inverse une chaine transmise depuis Java
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_lab22_1jnidemo_MainActivity_reverseString(
        JNIEnv* env,
        jobject /* instance */,
        jstring input) {

    if (input == nullptr) {
        LOG_ERR("Parametre nul recu pour reverseString");
        return env->NewStringUTF("Echec : parametre null");
    }

    const char* buffer = env->GetStringUTFChars(input, nullptr);
    if (buffer == nullptr) {
        LOG_ERR("Echec de lecture de la chaine Java");
        return env->NewStringUTF("Echec JNI");
    }

    std::string texte(buffer);
    env->ReleaseStringUTFChars(input, buffer);

    std::reverse(texte.begin(), texte.end());

    LOG_INFO("Chaine inversee : %s", texte.c_str());
    return env->NewStringUTF(texte.c_str());
}

// Fonction 4 : calcule la somme des elements d'un tableau Java
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_lab22_1jnidemo_MainActivity_sumArray(
        JNIEnv* env,
        jobject /* instance */,
        jintArray tableau) {

    if (tableau == nullptr) {
        LOG_ERR("Tableau recu est null");
        return -1;
    }

    jsize taille = env->GetArrayLength(tableau);
    jint* valeurs = env->GetIntArrayElements(tableau, nullptr);

    if (valeurs == nullptr) {
        LOG_ERR("Impossible de lire les elements du tableau");
        return -2;
    }

    long long total = 0;
    for (jsize i = 0; i < taille; i++) {
        total += valeurs[i];
    }

    env->ReleaseIntArrayElements(tableau, valeurs, 0);

    if (total > INT_MAX) {
        LOG_ERR("Depassement lors du calcul de la somme");
        return -3;
    }

    LOG_INFO("Somme calculee = %lld", total);
    return static_cast<jint>(total);
}