/*
* 프로젝트명 : 캘린더뷰 만들기
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 4. 5.
* 프로그램 설명 : 캘린더뷰
 */


package com.hyunsa.currentusing

import android.graphics.Color
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.os.SystemClock
import android.provider.MediaStore.Audio.Radio
import android.view.View
import android.view.View.OnFocusChangeListener
import android.widget.*
import java.time.Month
import java.time.Year

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "시간 예약"

        val btnStart = findViewById<Button>(R.id.btnStart)
        val btnEnd = findViewById<Button>(R.id.btnEnd)
        val rdoCal = findViewById<RadioButton>(R.id.rdoCal)
        val rdoTime = findViewById<RadioButton>(R.id.rdoTime)
        val chrono = findViewById<Chronometer>(R.id.chronometer1)
        val tPicker = findViewById<TimePicker>(R.id.timePicker1)
        val calView = findViewById<CalendarView>(R.id.calendarView1)
        val tvYear = findViewById<TextView>(R.id.tvYear)
        val tvMonth = findViewById<TextView>(R.id.tvMonth)
        val tvDay = findViewById<TextView>(R.id.tvDay)
        val tvHour = findViewById<TextView>(R.id.tvHour)
        val tvMinute = findViewById<TextView>(R.id.tvMinute)
        var selectYear : Int = 0
        var selectMonth : Int = 0
        var selectDay : Int = 0
        tPicker.visibility = View.INVISIBLE
        calView.visibility = View.INVISIBLE
        rdoCal.setOnClickListener {
            tPicker.visibility = View.INVISIBLE
            calView.visibility = View.VISIBLE
        }
        rdoTime.setOnClickListener {
            tPicker.visibility = View.VISIBLE
            calView.visibility = View.INVISIBLE
        }
        calView.setOnDateChangeListener { view, year, month, dayOfMonth ->
            selectYear=year
            selectMonth=month+1
            selectDay=dayOfMonth
        }
        btnStart.setOnClickListener {
            chrono.base = SystemClock.elapsedRealtime()
            chrono.start()
            chrono.setTextColor(Color.RED)
        }
        btnEnd.setOnClickListener {
            chrono.stop()
            chrono.setTextColor(Color.BLUE)
            tvYear.text = selectYear.toString()
            tvMonth.text = selectMonth.toString()
            tvDay.text = selectDay.toString()
            tvHour.text = tPicker.currentHour.toString()
            tvMinute.text = tPicker.currentMinute.toString()
        }
    }
}