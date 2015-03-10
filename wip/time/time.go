// Go's offers extensive support for times and durations;
// here are some examples.

package main

import (
	"strconv"
	"time"
)

func p(s, i string) {
	println(s, i)
}

func main() {

	// We'll start by getting the current time.
	now := time.Now()
	p("now", now.String())

	// You can extract the various components of the time
	// value as expected.
	println("now => Year", now.Year(), "Month", now.Month().String(), "Day", now.Day(),
		"Hour", now.Hour(), "Minute", now.Minute(), "Second", now.Second(),
		"Nanosecond", now.Nanosecond(), "Location", now.Location().String(),
		// The Monday-Sunday `Weekday` is also available.
		"Weekday", now.Weekday().String())

	// You can build a `time` struct by providing the
	// year, month, day, etc. Times are always associated
	// with a `Location`, i.e. time zone.
	then := time.Date(
		2009, 11, 17, 20, 34, 58, 651387237, time.UTC)

	p("then =>", then.String())

	// You can extract the various components of the time
	// value as expected.
	p("Year", strconv.Itoa(then.Year()))
	p("Month", then.Month().String())
	p("Day", strconv.Itoa(then.Day()))
	p("Hour", strconv.Itoa(then.Hour()))
	p("Minute", strconv.Itoa(then.Minute()))
	p("Second", strconv.Itoa(then.Second()))
	p("Nanosecond", strconv.Itoa(then.Nanosecond()))
	p("Location", then.Location().String())

	// The Monday-Sunday `Weekday` is also available.
	p("Weekday", then.Weekday().String())

	// These methods compare two times, testing if the
	// first occurs before, after, or at the same time
	// as the second, respectively.
	p("Before", strconv.FormatBool(then.Before(now)))
	p("After", strconv.FormatBool(then.After(now)))
	p("Equal", strconv.FormatBool(then.Equal(now)))

	// The `Sub` methods returns a `Duration` representing
	// the interval between two times.
	diff := now.Sub(then)
	p("diff", diff.String())

	// We can compute the length of the duration in
	// various units.
	p("Hours", strconv.FormatFloat(diff.Hours(), 'g', -1, 64))
	p("Minutes", strconv.FormatFloat(diff.Minutes(), 'g', -1, 64))
	p("Seconds", strconv.FormatFloat(diff.Seconds(), 'g', -1, 64))
	p("Nanoseconds", strconv.FormatInt(diff.Nanoseconds(), 10))

	// You can use `Add` to advance a time by a given
	// duration, or with a `-` to move backwards by a
	// duration.
	p("Add(diff)", then.Add(diff).String())
	p("Add(-diff)", then.Add(-diff).String())

}
