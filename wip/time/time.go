// Go's offers extensive support for times and durations;
// here are some examples.

package main

//import "fmt"
import (
	_ "github.com/tardisgo/tardisgo/golibruntime/runtime"
	_ "github.com/tardisgo/tardisgo/golibruntime/sync"
	_ "github.com/tardisgo/tardisgo/golibruntime/sync/atomic"
	_ "github.com/tardisgo/tardisgo/golibruntime/syscall"
	_ "github.com/tardisgo/tardisgo/golibruntime/time"
	"time"
)

func p(s string, i interface{}) {
	println(s, i)
}

func main() {

	// We'll start by getting the current time.
	now := time.Now()
	//p("now", now)

	// You can extract the various components of the time
	// value as expected.
	println("Now(): Year", now.Year(), "Month", now.Month(), "Day", now.Day(),
		"Hour", now.Hour(), "Minute", now.Minute(), "Second", now.Second(),
		"Nanosecond", now.Nanosecond(), "Location", now.Location(),
		// The Monday-Sunday `Weekday` is also available.
		"Weekday", now.Weekday())

	// You can build a `time` struct by providing the
	// year, month, day, etc. Times are always associated
	// with a `Location`, i.e. time zone.
	then := time.Date(
		2009, 11, 17, 20, 34, 58, 651387237, time.UTC)

	p("then", then)
	/*
		// You can extract the various components of the time
		// value as expected.
		p("Year", then.Year())
		p("Month", then.Month())
		p("Day", then.Day())
		p("Hour", then.Hour())
		p("Minute", then.Minute())
		p("Second", then.Second())
		p("Nanosecond", then.Nanosecond())
		p("Location", then.Location())

		// The Monday-Sunday `Weekday` is also available.
		p("Weekday", then.Weekday())

		// These methods compare two times, testing if the
		// first occurs before, after, or at the same time
		// as the second, respectively.
		p("Before", then.Before(now))
		p("After", then.After(now))
		p("Equal", then.Equal(now))

		// The `Sub` methods returns a `Duration` representing
		// the interval between two times.
		diff := now.Sub(then)
		p("diff", diff)

		// We can compute the length of the duration in
		// various units.
		p("Hours", diff.Hours())
		p("Minutes", diff.Minutes())
		p("Seconds", diff.Seconds())
		p("Nanoseconds", diff.Nanoseconds())

		// You can use `Add` to advance a time by a given
		// duration, or with a `-` to move backwards by a
		// duration.
		p("Add(diff)", then.Add(diff))
		p("Add(-diff)", then.Add(-diff))
	*/
}
