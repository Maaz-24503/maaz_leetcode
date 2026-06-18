class Solution {
public:
    double angleClock(int hour, int minutes) {
        hour = hour % 12;
        double hourHand = hour + ((minutes*1.0) / 60.0);
        double minuteHand = ((minutes*1.0) / 60.0) * 12.0;
        double difference = abs(minuteHand - hourHand);
        double angle = (difference / 12.0) * 360.0;
        return min(angle, 360 - angle);
    }
};