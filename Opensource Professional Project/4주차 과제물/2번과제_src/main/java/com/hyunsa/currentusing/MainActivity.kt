/*
* 프로젝트명 : 4주과제-2
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 3.29.
* 프로그램 설명 : 에디트텍스트 토스트메시지 출력
 */


package com.hyunsa.currentusing

import android.animation.ObjectAnimator
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.text.Editable
import android.text.TextWatcher
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val edit_text = findViewById<EditText>(R.id.edit_text_1)
        edit_text.addTextChangedListener(object : TextWatcher {
            override fun beforeTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Toast
                    .makeText(this@MainActivity, edit_text.text, Toast.LENGTH_SHORT)
                    .show()
            }

            override fun onTextChanged(p0: CharSequence?, p1: Int, p2: Int, p3: Int) {
                Toast
                    .makeText(this@MainActivity, edit_text.text, Toast.LENGTH_SHORT)
                    .show()
            }

            override fun afterTextChanged(p0: Editable?) {
                Toast
                    .makeText(this@MainActivity, edit_text.text, Toast.LENGTH_SHORT)
                    .show()
            }
        })
    }
}