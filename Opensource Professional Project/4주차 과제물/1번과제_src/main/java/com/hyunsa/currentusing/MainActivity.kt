/*
* 프로젝트명 : 4주과제-1
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 3.29.
* 프로그램 설명 : 버튼속성 부여
 */


package com.hyunsa.currentusing

import android.animation.ObjectAnimator
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.CheckBox

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val enabled_chk = findViewById<CheckBox>(R.id.enable_chk)
        val clickable_chk = findViewById<CheckBox>(R.id.clickable_chk)
        val rotate_chk = findViewById<CheckBox>(R.id.rotate_chk)
        val main_button = findViewById<Button>(R.id.button)
        enabled_chk.setOnCheckedChangeListener{ _, isChecked ->
            main_button.isEnabled = isChecked
        }
        clickable_chk.setOnCheckedChangeListener{ _, isChecked ->
            main_button.isClickable = isChecked
        }
        rotate_chk.setOnCheckedChangeListener{ _, isChecked ->
            if (isChecked) {
                main_button.rotation = 90F
            }
            else {
                main_button.rotation = 0F
            }
        }
    }
}