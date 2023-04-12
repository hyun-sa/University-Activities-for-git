/*
* 프로젝트명 : 간단한 일기장 만들기
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 4.12.
* 프로그램 설명 : 간단한 일기장
 */


package com.hyunsa.currentusing

import android.annotation.SuppressLint
import android.content.Context
import android.icu.util.Calendar
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.*
import java.io.FileInputStream
import java.io.FileOutputStream
import java.io.IOException

class MainActivity : AppCompatActivity() {
    @SuppressLint("SetJavaScriptEnabled")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "간단 일기장"

        val dp = findViewById<DatePicker>(R.id.datePicker1)
        val edtDiary = findViewById<EditText>(R.id.edtDiary)
        val btnWrite = findViewById<Button>(R.id.btnWrite)

        var cal = Calendar.getInstance()
        var cYear = cal.get(Calendar.YEAR)
        var cMonth = cal.get(Calendar.MONTH)
        var cDay = cal.get(Calendar.DAY_OF_MONTH)
        var fileName:String = ""


        fun readDiary(fName:String): String? {
            var diaryStr: String? = null
            var inFS:FileInputStream
            try {
                inFS = openFileInput(fName)
                var txt:ByteArray = ByteArray(500)
                inFS.read(txt)
                inFS.close()
                diaryStr = txt.toString().trim()
                btnWrite.text = "수정하기"
            } catch (e: IOException){
                edtDiary.hint = "일기 없음"
                btnWrite.text = "새로 저장"
            }
            return diaryStr
        }

        dp.init(cYear, cMonth, cDay, DatePicker.OnDateChangedListener { datePicker, year, month, day ->
            fileName = year.toString() + "_" + (month+1).toString() + "_" + day.toString() + ".txt"
            val str = readDiary(fileName)
            edtDiary.setText(str)
            btnWrite.isEnabled = true
            })

        btnWrite.setOnClickListener {
            try {
                val outFS:FileOutputStream = openFileOutput(fileName, Context.MODE_PRIVATE)
                val str:String = edtDiary.text.toString()
                outFS.write(str.toByteArray())
                outFS.close()
                Toast.makeText(applicationContext, fileName+"이 저장됨", Toast.LENGTH_SHORT).show()
            } catch (e:IOException) {
            }
        }

        }
}