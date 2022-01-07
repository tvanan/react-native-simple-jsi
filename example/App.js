/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * @format
 * @flow strict-local
 */

import * as React from 'react';
import {
  SafeAreaView,
  ScrollView,
  StatusBar,
  StyleSheet,
  Text,
  useColorScheme,
  View,
} from 'react-native';

import {
  Colors,
  DebugInstructions,
  Header,
  LearnMoreLinks,
  ReloadInstructions,
} from 'react-native/Libraries/NewAppScreen';

import global from 'react-native-simple-jsi'




export default function App() {
   const [result, setResult] = React.useState();

  React.useEffect(() => {
    setResult(global.helloWorld())
  }, []);

  return (
    <View>
      <Text>Result</Text>
    </View>
  );
}

