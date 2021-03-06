#ifndef COUNTER_NODE_HPP
#define COUNTER_NODE_HPP

#include "ros/ros.h"
#include "std_msgs/Int16.h"

#include "sample4.h"

class CounterNode {
 private:
  ros::NodeHandle nh_;
  Counter counter_;
  ros::Publisher counter_pub_;
  ros::Subscriber sub_;

 public:
  CounterNode() {
    counter_pub_ = nh_.advertise<std_msgs::Int16>("counter", 1000);
    sub_ = nh_.subscribe("increment", 1, &CounterNode::callback, this);
  }

  void callback(const std_msgs::Int16ConstPtr& message)
  {
    std_msgs::Int16 msg;
    msg.data = counter_.Increment();
    counter_pub_.publish(msg);
  }

};

#endif // COUNTER_NODE_HPP
