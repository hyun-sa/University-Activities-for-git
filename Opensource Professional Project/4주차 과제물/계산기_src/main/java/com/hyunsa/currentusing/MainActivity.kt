/*
* 프로젝트명 : 계산기 만들기
* 작성자 : 2019038004 조민우
* 작성일 : 2023. 3.29.
* 프로그램 설명 : 계산기
 */


package com.hyunsa.currentusing

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View.OnFocusChangeListener
import android.widget.*

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val input_num_a = findViewById<EditText>(R.id.num_a)
        val input_num_b = findViewById<EditText>(R.id.num_b)
        val input_1 = findViewById<Button>(R.id.input_1)
        val input_2 = findViewById<Button>(R.id.input_2)
        val input_3 = findViewById<Button>(R.id.input_3)
        val input_4 = findViewById<Button>(R.id.input_4)
        val input_5 = findViewById<Button>(R.id.input_5)
        val input_6 = findViewById<Button>(R.id.input_6)
        val input_7 = findViewById<Button>(R.id.input_7)
        val input_8 = findViewById<Button>(R.id.input_8)
        val input_9 = findViewById<Button>(R.id.input_9)
        val input_10 = findViewById<Button>(R.id.input_10)
        val plus_btn = findViewById<Button>(R.id.plus)
        val minus_btn = findViewById<Button>(R.id.minus)
        val mul_btn = findViewById<Button>(R.id.multi)
        val div_btn = findViewById<Button>(R.id.divide)
        val prt_result = findViewById<TextView>(R.id.result)
        var count_focus : Int = 0
        input_num_a.inputType = 0
        input_num_b.inputType = 0

        input_num_a.onFocusChangeListener = OnFocusChangeListener { v, hasFocus ->
            if (hasFocus)
            {
                count_focus = 1
                var temp = input_num_a.text.toString()
                var temp_int : Int = 0
                input_1.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 1
                    input_num_a.setText(temp_int.toString())
                }
                input_2.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 2
                    input_num_a.setText(temp_int.toString())
                }
                input_3.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 3
                    input_num_a.setText(temp_int.toString())
                }
                input_4.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 4
                    input_num_a.setText(temp_int.toString())
                }
                input_5.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 5
                    input_num_a.setText(temp_int.toString())
                }
                input_6.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 6
                    input_num_a.setText(temp_int.toString())
                }
                input_7.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 7
                    input_num_a.setText(temp_int.toString())
                }
                input_8.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 8
                    input_num_a.setText(temp_int.toString())
                }
                input_9.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 9
                    input_num_a.setText(temp_int.toString())
                }
                input_10.setOnClickListener() {
                    temp = input_num_a.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    input_num_a.setText(temp_int.toString())
                }
            }
        }
        input_num_b.onFocusChangeListener = OnFocusChangeListener { v, hasFocus ->
            if (hasFocus)
            {
                count_focus = 1
                var temp = input_num_b.text.toString()
                var temp_int : Int = 0
                input_1.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 1
                    input_num_b.setText(temp_int.toString())
                }
                input_2.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 2
                    input_num_b.setText(temp_int.toString())
                }
                input_3.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 3
                    input_num_b.setText(temp_int.toString())
                }
                input_4.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 4
                    input_num_b.setText(temp_int.toString())
                }
                input_5.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 5
                    input_num_b.setText(temp_int.toString())
                }
                input_6.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 6
                    input_num_b.setText(temp_int.toString())
                }
                input_7.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 7
                    input_num_b.setText(temp_int.toString())
                }
                input_8.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 8
                    input_num_b.setText(temp_int.toString())
                }
                input_9.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    temp_int += 9
                    input_num_b.setText(temp_int.toString())
                }
                input_10.setOnClickListener() {
                    temp = input_num_b.text.toString()
                    temp_int = temp.toInt()
                    temp_int *= 10
                    input_num_b.setText(temp_int.toString())
                }
            }
        }
        if (count_focus == 0) {
            input_1.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_2.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_3.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_4.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_5.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_6.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_7.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_8.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_9.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
            input_10.setOnClickListener() {
                Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show()
            }
        }
        plus_btn.setOnClickListener(){
            val temp_a = input_num_a.text.toString()
            val temp_b = input_num_b.text.toString()
            val result = temp_a.toInt() + temp_b.toInt()
            prt_result.text = result.toString()
            input_num_a.setText("0")
            input_num_b.setText("0")
        }
        minus_btn.setOnClickListener(){
            val temp_a = input_num_a.text.toString()
            val temp_b = input_num_b.text.toString()
            val result = temp_a.toInt() - temp_b.toInt()
            prt_result.text = result.toString()
            input_num_a.setText("0")
            input_num_b.setText("0")
        }
        mul_btn.setOnClickListener(){
            val temp_a = input_num_a.text.toString()
            val temp_b = input_num_b.text.toString()
            val result = temp_a.toInt() * temp_b.toInt()
            prt_result.text = result.toString()
            input_num_a.setText("0")
            input_num_b.setText("0")
        }
        div_btn.setOnClickListener(){
            val temp_a = input_num_a.text.toString()
            val temp_b = input_num_b.text.toString()
            var result : Float = 0F
            if (temp_b.toInt() != 0)
            {
                result = temp_a.toFloat() / temp_b.toInt()
            }
            else
            {
                Toast.makeText(this, "Devided by Zero", Toast.LENGTH_SHORT).show()
                result = 0F
            }
            prt_result.text = result.toString()
            input_num_a.setText("0")
            input_num_b.setText("0")
        }
    }

}