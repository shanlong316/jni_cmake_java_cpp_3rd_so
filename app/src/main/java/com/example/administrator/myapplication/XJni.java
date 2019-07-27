package com.example.administrator.myapplication;

public class XJni {

    static {
        System.loadLibrary("xjni");
    }

    public static native String getStr(String s);
}