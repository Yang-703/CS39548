// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAuth, GoogleAuthProvider } from "firebase/auth";
import { getFirestore } from "firebase/firestore";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyA1h23qcCRq53BHO2VhJWTITPQeCQnQybw",
  authDomain: "final-web-dev-fad9c.firebaseapp.com",
  projectId: "final-web-dev-fad9c",
  storageBucket: "final-web-dev-fad9c.firebasestorage.app",
  messagingSenderId: "402109367573",
  appId: "1:402109367573:web:536e6aa6c3e0cffad2951c"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
export const db = getFirestore(app);
export const auth = getAuth(app);
export const google = new GoogleAuthProvider();