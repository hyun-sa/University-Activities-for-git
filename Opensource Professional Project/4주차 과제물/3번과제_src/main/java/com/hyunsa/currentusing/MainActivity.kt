/*
* 프로젝트명 : 4주과제-3
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 3.29.
* 프로그램 설명 : 이미지 회전
 */


package com.hyunsa.currentusing

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.ImageView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val rotate_button = findViewById<Button>(R.id.button_rotate)
        val image_view = findViewById<ImageView>(R.id.imageView2)
        rotate_button.setOnClickListener(){
            image_view.rotation += 10F
        }
    }
}