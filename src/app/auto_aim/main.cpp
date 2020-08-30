#include <iostream>

#include "behavior.hpp"
#include "camera.hpp"
#include "robot.hpp"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"
#include "vision.hpp"
#include "obj_detector.hpp"

int main(int argc, char const* argv[]) {
  (void)argc;
  (void)argv;

  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  auto file_sink =
      std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/auto_aim.log", true);

  spdlog::sinks_init_list sink_list = {console_sink, file_sink};

  spdlog::set_default_logger(
      std::make_shared<spdlog::logger>("default", sink_list));

  spdlog::flush_on(spdlog::level::debug);
  spdlog::set_level(spdlog::level::trace);

  SPDLOG_WARN("***** Running Auto Aim. *****");

  // Test only. TOOD: Remove.
  TestTree();
  TestOpenCV();
  TestVideoWrite();

  ObjectDetector detector(0);
  Robot bot("/dev/tty");

  // Init behavior.
  // Run true tree.
  exit(0);
}
