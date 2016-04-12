Ubuntu Open Source Android/Cordova examples for the nRF8001 chipset
===================================================================

These examples should help you get started with Android application development that interacts with Arduino hardware by means of the Nordic nRF8001 Bluetooth LE chipset.
We use the IMUduino in our examples, but any nRF8001 module that works with Arduino will do, such as the Adafruit nRF8001 module.

# Setting up the Android SDK #

You will need the Android API available in your environment path.
You can download Android Studio, and run the 'android' command from within the /sdk/tools folder
This will open up the Android SDK Manager, where you can install the Android SDK Tools, Android SDK Platform-tools, Android SDK Build-tools, and Android 4.4.2 (API19) or higher API

Once the Android SDK is installed, make sure the /sdk/tools, and /sdk/platform-tools are in in your environment's PATH variable.
You may need to restart your command line window (terminal) if you have to manually add these paths.

On Ubuntu 14.04, we did this by appending the following to our .bashrc file:

```
# Android SDK paths
export PATH="$PATH:$HOME/android-studio/sdk/platform-tools"
export PATH="$PATH:$HOME/android-studio/sdk/tools"
```

Make sure to install the Java JDK for your machine.
Ubuntu Linux machines can use the OpenJDK:

```
sudo apt-get install openjdk-7-jdk
```

We will need to make sure the JAVA_HOME environment variable is set. 
On Ubuntu 14.04, we appended it to our .bashrc file as follows:

```
# Make the JDK binaries available
export JAVA_HOME="/usr/lib/jvm/default-java"
export PATH="$PATH:$JAVA_HOME";
```

# Installing Node and NPM #
If you haven't yet, install nodejs and npm. 
You may need to symlink the 'nodejs' binary as 'node' in order to make your 'node' command work.

On Ubuntu 14.04, we were able to install via the package manager as follows:

```
sudo apt-get update && sudo apt-get install nodejs && sudo apt-get isntall npm
```

...And we configured configured NPM to save plugins in a directory that doesn't need the 'sudo' command.

```
npm config set prefix ~/npm
```

...Our .bashrc file then needed to have the new path added (append this to .bashrc)

```
# npm config, since we dont want to sudo for global npm installs
export PATH="$PATH:$HOME/npm/bin"
```

On Mac and Windows, you may simply download NodeJS and follow their instructions for installation.

# Installing Cordova and Ionic packages #
We can now create our example project, and install the needed dependencies. 
Note: If you are on a 64-bit version of Ubuntu, you will need to install the ia32-libs package via apt-get

Let's start by installing some NPM packages we need.

We need the Cordova npm package. This provides a means of building Android apps using HTML + scripting.
The -g flag tells npm to make this package available to all projects globally.

```
npm install -g cordova
```

Next, we install the Ionic Framework npm package by running the following:

```
npm install -g ionic
```

Let's create our project now!

(For a more thorough reading on installation and set up, see the Ionic Framework installation guide at http://ionicframework.com/docs/guide/installation.html )


We can checkout a copy of the example bleUART code from our github repository with the following command:

```
git clone https://github.com/zrecommerce/imuduino-btle.git
```

The sample bleUART project is located in the Cordova/bleUART/ folder. You may view and edit the HTML and script files in the Cordova/bleUART/www folder.


Note, after creating a new Ionic project, you may need to run the following from within the Ionic project folder:

```
chmod +x hooks/after_prepare/010_add_platform_class.js
```
...Otherwise, trying to add a platform will fail (file isn't executable by default).

Note, when running the example ionic apps, you may need to add the 'android' or 'ios' platforms
```
ionic platform add android [ios]
```

Note, to install the evothings cordova plugin, run the following from within the Ionic project folder:

```
ionic plugin add cordova-plugin-ble
```

To upload the Ionic app to Android devices, connect a USB cable, enable USB debugging on your Android device, then run the following from within your Ionic project:

```
ionic run android
```