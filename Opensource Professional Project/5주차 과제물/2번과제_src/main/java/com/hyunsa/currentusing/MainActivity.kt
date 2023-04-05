/*
* 프로젝트명 : 간단한 웹 브라우저 만들기
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 4. 5.
* 프로그램 설명 : 웹 브라우저
 */


package com.hyunsa.currentusing

import android.annotation.SuppressLint
import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.SystemClock
import android.provider.MediaStore.Audio.Radio
import android.view.View
import android.view.View.OnFocusChangeListener
import android.webkit.WebSettings
import android.webkit.WebView
import android.webkit.WebViewClient
import android.widget.*
import java.time.Month
import java.time.Year

class MainActivity : AppCompatActivity() {
    @SuppressLint("SetJavaScriptEnabled")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val edtUrl = findViewById<EditText>(R.id.edtUrl)
        val btnGo = findViewById<Button>(R.id.btnGo)
        val btnBack = findViewById<Button>(R.id.btnBack)
        val web = findViewById<WebView>(R.id.webView1)
        web.webViewClient = SimpleWebViewClient()
        val webSet = web.settings
        webSet.builtInZoomControls = true
        webSet.javaScriptEnabled = true
        btnGo.setOnClickListener {
            web.loadUrl(edtUrl.text.toString())
        }
        btnBack.setOnClickListener {
            web.goBack()
        }
    }
    class SimpleWebViewClient:WebViewClient() {
        override fun shouldOverrideUrlLoading(view: WebView?, url: String?): Boolean {
            return super.shouldOverrideUrlLoading(view, url)
        }
    }
}