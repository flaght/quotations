//  Copyright (c) 2016-2017 The quotations Authors. All rights reserved.
//  Created on: 2017年2月6日 Author: kerry

#ifndef QUOTATIONS_PUB_QUOTATIONS_PROTO_BUF_H_
#define QUOTATIONS_PUB_QUOTATIONS_PROTO_BUF_H_

#include "basic/basictypes.h"
#include "logic/base_values.h"


namespace quotations_logic{
namespace net_reply {
class RealTime {
 public:
  RealTime()
      : change_(NULL),
        pchg_(NULL),
        opening_today_price_(NULL),
        closed_yesterday_price_(NULL),
        current_price_(NULL),
        current_unix_time_(NULL),
        high_price_(NULL),
        low_price_(NULL),
        exchange_name_(NULL),
        platform_name_(NULL),
        symbol_(NULL),
        type_(NULL),
        value_(NULL) {
  }

  void set_change(const double change) {
    change_ = new base_logic::FundamentalValue(change);
  }

  void set_pchg(const double pchg) {
    pchg_ = new base_logic::FundamentalValue(pchg);
  }

  void set_opening_today_price(const double opening_today_price) {
    opening_today_price_ = new base_logic::FundamentalValue(
        opening_today_price);
  }

  void set_closed_yesterday_price(const double closed_yesterday_price) {
    closed_yesterday_price_ = new base_logic::FundamentalValue(
        closed_yesterday_price);
  }

  void set_current_price(const double current_price) {
    current_price_ = new base_logic::FundamentalValue(current_price);
  }

  void set_current_unix_time(const int64 current_unix_time) {
    current_unix_time_ = new base_logic::FundamentalValue(current_unix_time);
  }

  void set_high_price(const double high_price) {
    high_price_ = new base_logic::FundamentalValue(high_price);
  }

  void set_low_price(const double low_price) {
    low_price_ = new base_logic::FundamentalValue(low_price);
  }

  void set_exchange_name(const std::string& exchange_name) {
    exchange_name_ = new base_logic::StringValue(exchange_name);
  }

  void set_platform_name(const std::string& platform_name) {
    platform_name_ = new base_logic::StringValue(platform_name);
  }

  void set_symbol(const std::string& symbol) {
    symbol_ = new base_logic::StringValue(symbol);
  }

  void set_type(const int32 type) {
    type_ = new base_logic::FundamentalValue(type);
  }

  ~RealTime() {
    if (value_) {
      delete value_;
      value_ = NULL;
    }
  }
  base_logic::DictionaryValue* get() {
    value_ = new base_logic::DictionaryValue();
    if (change_ != NULL)
      value_->Set(L"change", change_);
    if (pchg_ != NULL)
      value_->Set(L"pchg", pchg_);
    if (type_ != NULL)
      value_->Set(L"type", type_);
    if (opening_today_price_ != NULL)
      value_->Set(L"openingTodayPrice", opening_today_price_);
    if (closed_yesterday_price_ != NULL)
      value_->Set(L"closedYesterdayPrice", closed_yesterday_price_);
    if (current_price_ != NULL)
      value_->Set(L"currentPrice", current_price_);
    if (current_unix_time_ != NULL)
      value_->Set(L"priceTime", current_unix_time_);
    if (high_price_ != NULL)
      value_->Set(L"highPrice", high_price_);
    if (low_price_ != NULL)
      value_->Set(L"lowPrice", low_price_);
    if (exchange_name_ != NULL)
      value_->Set(L"exchangeName", exchange_name_);
    if (platform_name_ != NULL)
      value_->Set(L"platformName", platform_name_);
    if (symbol_ != NULL)
      value_->Set(L"symbol", symbol_);
    return value_;
  }
 private:
  base_logic::FundamentalValue* change_;
  base_logic::FundamentalValue* pchg_;
  base_logic::FundamentalValue* opening_today_price_;
  base_logic::FundamentalValue* closed_yesterday_price_;
  base_logic::FundamentalValue* current_price_;
  base_logic::FundamentalValue* current_unix_time_;
  base_logic::FundamentalValue* high_price_;
  base_logic::FundamentalValue* low_price_;
  base_logic::FundamentalValue* type_;
  base_logic::StringValue* exchange_name_;
  base_logic::StringValue* platform_name_;
  base_logic::StringValue* symbol_;
  base_logic::DictionaryValue* value_;
};

}

}
#endif
