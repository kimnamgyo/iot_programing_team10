## **Codes**

	'Hybus-Smart4412' 리눅스 타겟 시스템 활용 실습 코드와 러시안 룰렛 게임 코드

## **코드 파일 설명**

### **2024-05-23**

* **load.c**
	* 러시안 룰렛에 쓰일 총알 장전 코드의 프로토타입
   	* 타겟 시스템 Dot Matrix 이용
   
* **timer.c**
  	* 타이머코드 프로토타입
  	* 타겟 시스템 7-Segment 이용
---

### **2024-05-30**

* **led.c**
  	* 타겟 시스템 LED 학습
  	* led 활용해 플레이어 표시하려 했지만, clcd가 더 효과적일 것 같다는 의견으로 플레이어 표시는 clcd로 결정

---

### **2024-06-04**

* **player.c**
  	* 플레이어 차례 표시와 tact switch를 누를 시 턴이 넘어가는 코드
  	* 타겟시스템 clcd, tact switch 이용

---

### **2024-06-11**

* **bullet.c**
	* 기존의 load 코드보다 활용하기 쉽게 코드 개선
   	* 타겟 시스템 Dot Matrix 이용
  
* **timer2.c**
	* 기존의 timer 코드가 게임 활용에 어려워 새로운 코드로 교체
  	* 타겟 시스템 7-Segment 이용
---

### **2024-06-13**

* **russian_roulette.c**
  	* 전의 코드들을 합해 완성
