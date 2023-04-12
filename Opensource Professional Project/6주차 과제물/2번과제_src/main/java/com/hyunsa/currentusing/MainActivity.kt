/*
* 프로젝트명 : 간단한 그림판 만들기
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 4.12.
* 프로그램 설명 : 간단한 그림판
 */


package com.hyunsa.currentusing

import android.annotation.SuppressLint
import android.content.Context
import android.graphics.Canvas
import android.graphics.Color
import android.graphics.Paint
import android.icu.util.Calendar
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import android.view.MotionEvent
import android.view.View
import android.widget.*
import java.io.FileInputStream
import java.io.FileOutputStream
import java.io.IOException
import kotlin.math.pow
import kotlin.math.sqrt

const val LINE = 1
const val CIRCLE = 2
var curShape = LINE

open class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        title = "간단 그림판"

        }
    open class MyGraphicView(context: Context) : View(context) {
        var startX = -1
        var startY = -1
        var stopX = -1
        var stopY = -1
        @SuppressLint("ClickableViewAccessibility")
        override fun onTouchEvent(event: MotionEvent?): Boolean {
            val comp = event?.action
            if (comp == MotionEvent.ACTION_DOWN) {
                startX = event.x.toInt()
                startY = event.y.toInt()
            }
            else if (comp == MotionEvent.ACTION_MOVE || comp == MotionEvent.ACTION_UP) {
                stopX = event.x.toInt()
                stopY = event.y.toInt()
                this.invalidate()
            }
            return true
        }

        @SuppressLint("DrawAllocation")
        override fun onDraw(canvas: Canvas) {
            val paint:Paint = Paint()
            paint.isAntiAlias = true
            paint.strokeWidth = 5F
            paint.style = Paint.Style.STROKE
            paint.color= Color.RED
            if (curShape == LINE) {
                canvas.drawLine(startX.toFloat(), startY.toFloat(), stopX.toFloat(),
                    stopY.toFloat(), paint)
            }
            else if (curShape == CIRCLE) {
                val radius = sqrt((stopX - startX).toDouble().pow(2.0) + (stopY - startY).toDouble().pow(2.0))
                canvas.drawCircle(startX.toFloat(), startY.toFloat(), radius.toFloat(), paint)
            }
        }
    }

    override fun onCreateOptionsMenu(menu: Menu): Boolean {
        super.onCreateOptionsMenu(menu)
        menu.add(0, 1, 0, "선 그리기")
        menu.add(0, 2, 0, "원 그리기")
        return true
    }

    override fun onOptionsItemSelected(item: MenuItem): Boolean {
        if (item.itemId == 1) {
            curShape = LINE
            return true
        }
        else if (item.itemId == 2) {
            curShape = CIRCLE
            return true
        }
        return super.onOptionsItemSelected(item)
    }
}