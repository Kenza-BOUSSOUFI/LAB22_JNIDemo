# LAB22_JNIDemo

# Emulateur utilisé : pixel 6, API : 36

# Démonstration:

https://github.com/user-attachments/assets/6be9a155-818b-4ce0-9dac-3d039de64780




# Vérification des logs natifs dans Logcat:

<img width="1827" height="386" alt="image" src="https://github.com/user-attachments/assets/da178cfb-9a2e-46e8-902d-edc30304ec8a" />

# Test 2 : valeur négative

Appel de  factorial(-5)

Résultat  : -1

<img width="830" height="747" alt="image" src="https://github.com/user-attachments/assets/9fcc2665-24a9-4848-9988-da78cebcc06f" />


# Test 3 : chaîne vide

Appel de reverseString("")

Le résultat : une chaîne vide.

<img width="1598" height="657" alt="image" src="https://github.com/user-attachments/assets/e4f4049e-6b14-46d4-90e4-61d25cd467bd" />

# Test 4 : tableau vide

Appel de sumArray(new int[]{})

Le résultat  est 0

<img width="1598" height="667" alt="image" src="https://github.com/user-attachments/assets/4759b311-6053-441f-b4af-633b86d8c34f" />



# Analyse d'apk avec Ghidra

# Étape 1 — Générer l'APK

<img width="493" height="561" alt="image" src="https://github.com/user-attachments/assets/8cefdeec-51c9-46d0-87f0-61c16e9909df" />

# Étape 2 — Décompiler avec JADX

Le dossier lib/ contenant les fichiers .so

<img width="1917" height="996" alt="image" src="https://github.com/user-attachments/assets/53bb6de9-9365-40df-8909-f17bbb8571e9" />


Le fichier libnative-lib.so de l'architecture x86_64 a été sélectionné pour l'analyse, car l'application a été exécutée sur 

un émulateur Android Studio tournant sur une machine Windows avec processeur Intel/AMD 64-bit, ce qui correspond à l'architecture native de l'émulateur.


# Étape 3 — Analyser avec Ghidra

1 - Extraire le fichier .so depuis JADX:

Dans JADX, clic droit sur x86_64/libnative-lib.so → Save → enregistre dans l'emplacement soueté.

2 - Ouvrir Ghidra et créer un projet, Lancer Ghidra → File → New Project Non-Shared Project → Next

<img width="982" height="738" alt="image" src="https://github.com/user-attachments/assets/29b87cd7-31c7-423f-9ee4-e6e1f0ed8fa7" />

3 — Importer le fichier .so

File → Import File → sélectionne libnative-lib.so

Ghidra détecte automatiquement :

Format : ELF

Language : x86:LE:64:default


<img width="972" height="732" alt="image" src="https://github.com/user-attachments/assets/d9419cff-654f-4d48-a3f1-2ad864fac09f" />

<img width="981" height="733" alt="image" src="https://github.com/user-attachments/assets/79c84306-81ae-421a-a6a7-256de76eead8" />



4 — Analyser

Double-clique sur le fichier dans le projet, Une fenêtre s'ouvre → clique Yes pour analyser

Laisse toutes les options par défaut → Analyze, Attends que l'analyse se termine 


<img width="1920" height="953" alt="image" src="https://github.com/user-attachments/assets/bf3b4ac9-48ad-43e2-a192-3b6be3098875" />


5 — Trouver tes fonctions JNI

Dans le panneau gauche Symbol Tree → Functions → cherche :

Java_com_example_lab22_1jnidemo_MainActivity_factorial

Java_com_example_lab22_1jnidemo_MainActivity_helloFromJNI

Java_com_example_lab22_1jnidemo_MainActivity_reverseString

Java_com_example_lab22_1jnidemo_MainActivity_sumArray

# Avec un Clique sur chacune, on va voir le code désassemblé et la reconstruction C par Ghidra.

<img width="1666" height="892" alt="image" src="https://github.com/user-attachments/assets/1c7b412e-b3ed-40e3-a76e-2039cd95e7b2" />

<img width="1662" height="707" alt="image" src="https://github.com/user-attachments/assets/c9fcfc56-8f6d-45c6-99f7-b61cdf055d59" />

<img width="1915" height="992" alt="image" src="https://github.com/user-attachments/assets/c7764836-75ce-4706-9933-86c78727e83a" />

<img width="1920" height="993" alt="image" src="https://github.com/user-attachments/assets/4ebf4657-c05b-4337-b64b-35abfa18b32b" />
















